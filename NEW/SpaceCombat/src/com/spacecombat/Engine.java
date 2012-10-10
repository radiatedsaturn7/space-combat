package com.spacecombat;

import java.util.List;

import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;

import com.spacecombat.ai.AllyAI;
import com.spacecombat.game.HealthController;
import com.spacecombat.game.LevelLoader;
import com.spacecombat.weapons.ChargeLaser;
import com.spacecombat.weapons.FlameThrower;
import com.spacecombat.weapons.Laser;
import com.spacecombat.weapons.LockingLaser;
import com.spacecombat.weapons.MachineGun;
import com.spacecombat.weapons.MissileLauncher;
import com.spacecombat.weapons.PulseCannon;
import com.spacecombat.weapons.Weapon;

public class Engine implements ClickListener {
	public static boolean created = false;
	private String startingLevel = "level1";
	private static boolean ready = false;
	 
	// this is da master list of all components0
	// private int fps = 60;
	// private int sleepTime; //calculated
  
	private class DrawLoop extends Thread {
		@Override
		public void run() {			
			while (true) {
				//System.out.println("DRAW Loop!"); 
				 
				drawLoop();
			}  
		}
	}

	private class UpdateLoop extends Thread {
		@Override
		public void run() {
			while (true) {
				//System.out.println("UPDATE");
				updateLoop();
			}
		}
	}	

	private class CollisionLoop extends Thread {
		@Override
		public void run() {
			while (true) {
				//System.out.println("COLLIDE");
				collisionLoop();
			}
		}
	}

	private final boolean useInputStep = false;
	private boolean canRun = true;

	private final boolean useMultithreadedDrawLoop = false;
	private final boolean runDrawLoop = true;
	private final boolean useFrameRate = false;
	private final boolean printFrameRate = false;
	private final int drawFrameRate = 32;	

	private final boolean useMultithreadedCollisionLoop = true;
	private final boolean useCollisionFrameRate = true; 
	private final int collisionFrameRate = 6;
	
	private final boolean useMultithreadedGameLoop = true;
	private final boolean runGameLoop = true;	
	private final boolean useGameFrameRate = true;
	private final int updateFrameRate = 32;
	

	private float lastTimeCheck = 0;
	

	private int frames = 0;
	private final Object lock = new Object();

	private GameObject xGameObject1;
	private GameObject yGameObject1;
	private static FinishListener finishListener = null;

	/** The Activity Context ( NEW ) */

	List<GameObject> gameObjects = GameObject.getAllGameObjects();

	/**
	 * * Instance the Cube object and set the Activity Context handed over
	 */
	public Engine(FinishListener f) {
		
		if (this.useMultithreadedDrawLoop) {
			final Thread drawLoop = new DrawLoop();
			//System.out.println("Drawing Started");
			drawLoop.start();
		}

		if (this.useMultithreadedGameLoop) {
			final Thread gameLoop = new UpdateLoop();
			gameLoop.start();
		}

		if (this.useMultithreadedCollisionLoop) {
			final Thread collisionLoop = new CollisionLoop();
			collisionLoop.start();
		}

		Input.subscribeListener(this);
		finishListener = f;
	}
	
	public static void exit()
	{		
		finishListener.onExit();
	}
	
	public void createGameObjects(SharedPreferences preferences) {		
		synchronized (this.lock)
		{
			GameObject.clear();
			Input.clear();
			AllyAI.clear();
			Input.subscribeListener(this);
			
			String levelToLoad = preferences.getString("lastLevel", startingLevel);
			
			
			System.out.println("LOADING:"+levelToLoad);
			
			LevelLoader.loadLevel(levelToLoad,true);
			
			ready = true;
			
			GameObject player = GameObject.findByName("player");
			if (player != null)
			{
				Weapon cl = (Weapon) player.getComponent(ChargeLaser.class);
				Weapon ft = (Weapon) player.getComponent(FlameThrower.class);		
				Weapon l = (Weapon) player.getComponent(Laser.class);
				Weapon ll = (Weapon) player.getComponent(LockingLaser.class);		
				Weapon mg = (Weapon) player.getComponent(MachineGun.class);
				Weapon ml = (Weapon) player.getComponent(MissileLauncher.class);
				Weapon pc = (Weapon) player.getComponent(PulseCannon.class);		

				cl.setPowerLevel(preferences.getInt("chargeLaser", cl.getPowerLevel()));
				ft.setPowerLevel(preferences.getInt("flameThrower", ft.getPowerLevel()));
				l.setPowerLevel(preferences.getInt("laser", l.getPowerLevel()));
				ll.setPowerLevel(preferences.getInt("lockingLaser", ll.getPowerLevel()));
				mg.setPowerLevel(preferences.getInt("machineGun", mg.getPowerLevel()));
				ml.setPowerLevel(preferences.getInt("missileLauncher", ml.getPowerLevel()));
				pc.setPowerLevel(preferences.getInt("pulseCannon", pc.getPowerLevel()));

				HealthController hc = (HealthController) player.getComponent(HealthController.class);
				hc.setHealth(preferences.getInt("health", hc.getHealth()));
				hc.setMaxHealth(preferences.getInt("maxHealth", hc.getMaxHealth()));
			}
		}
	}

	/**
	 * Here we do our drawing
	 */
	public void drawLoop() {
				
		if (this.useFrameRate) {
			try {
				Thread.sleep(1000 / this.drawFrameRate);
			} catch (final InterruptedException e) {
				e.printStackTrace();
			}
		}

		if (this.printFrameRate) {
			if (this.lastTimeCheck == 0) {
				this.lastTimeCheck = Time.getTime();
			}

			this.frames++;
			if (Time.getTime() - this.lastTimeCheck > 1) {
				System.out.println("FPS:" + this.frames);
				this.frames = 0;
				this.lastTimeCheck = Time.getTime();
			}
		}

		if (!this.runDrawLoop) {
			return;
		}

		int x = 0; 
		//System.out.println("Waiting To Draw");
		synchronized (this.lock) {
			//System.out.println("Draw");
			for (x = 0; x < this.gameObjects.size(); x++) {
				this.gameObjects.get(x).draw();
				this.gameObjects.get(x).onGUI();
			}
			
			//GUI.draw();
		}
	}

	@Override
	public void onClick(final float x, final float y) 
	{
		this.canRun = true; 
	}

	public void checkCollision(GameObject xGameObject,int start)
	{
		//skip objects not on the screen for collision
		if (xGameObject.transform.position.y < Camera.mainCamera.gameObject.transform.position.y - 128)
		{
			return;
		}
		if (xGameObject.transform.position.y > Camera.mainCamera.gameObject.transform.position.y + 864)
		{
			return;
		}
		if (xGameObject.getRigidBody() == null
				|| xGameObject.getRigidBody().getCollider() == null) {
			return;
		}

		for (int y = start; y < this.gameObjects.size(); y++) {
			this.yGameObject1 = this.gameObjects.get(y);

			if (this.yGameObject1.getRigidBody() == null
					|| this.yGameObject1.getRigidBody().getCollider() == null) {
				continue;
			}

			final boolean collision = this.xGameObject1
					.getRigidBody()
					.getCollider()
					.collidesWith(
							this.yGameObject1.getRigidBody().getCollider());

			if (collision) {
				this.xGameObject1.collide(this.yGameObject1);
				this.yGameObject1.collide(this.xGameObject1);
			}
		}
	}

	public void collisionLoop() {
		if (!ready)
		{
			return;
		}
		
		synchronized (this.lock) {
			for (int x = 0; x < this.gameObjects.size(); x++) {				
				this.xGameObject1 = this.gameObjects.get(x);
				checkCollision(xGameObject1,x+1);
			}
		}		
		
		if (this.useMultithreadedCollisionLoop && this.useCollisionFrameRate) {
			try {
				Thread.currentThread();
				Thread.sleep(1000 / this.collisionFrameRate);
			} catch (final InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public void updateLoop() 
	{		
		
		Input.update();
		if (this.useInputStep)
		{
			if (!this.canRun) {
				return;
			}			
			this.canRun = false;
		}
		Time.tick();

		if (!this.runGameLoop) {
			return;
		}


		synchronized (this.lock) {			
			for (int x = 0; x < this.gameObjects.size(); x++) {
				this.xGameObject1 = this.gameObjects.get(x);

				this.xGameObject1.update();

				if (!useMultithreadedCollisionLoop)
				{
					checkCollision(xGameObject1,x+1);
				}
			}	
		}

		synchronized (this.lock)
			{
				for (int x = 0; x < this.gameObjects.size(); x++) {
					this.xGameObject1 = this.gameObjects.get(x);
					this.xGameObject1.onAfterUpdate();
				}
			}


			int size = this.gameObjects.size();

			synchronized (this.lock) {
				for (int x = 0; x < size; x++) {
					if (this.gameObjects.get(x).isDestroyed()) {
						this.gameObjects.get(x).release();
						this.gameObjects.remove(x);
						x--;
						size = this.gameObjects.size();
					}
				}
			}

			if (this.useMultithreadedGameLoop && this.useGameFrameRate) {
				try {
					Thread.currentThread();
					Thread.sleep(1000 / this.updateFrameRate);
				} catch (final InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

	
	public void toBackground(Editor editor) {
		ready = false;
		/*
		GameObject player = GameObject.findByName("player");
		
		if (player != null)
		{
			Weapon cl = (Weapon) player.getComponent(ChargeLaser.class);
			Weapon ft = (Weapon) player.getComponent(FlameThrower.class);		
			Weapon l = (Weapon) player.getComponent(Laser.class);
			Weapon ll = (Weapon) player.getComponent(LockingLaser.class);		
			Weapon mg = (Weapon) player.getComponent(MachineGun.class);
			Weapon ml = (Weapon) player.getComponent(MissileLauncher.class);
			Weapon pc = (Weapon) player.getComponent(PulseCannon.class);		

			editor.putInt("chargeLaser", cl.getPowerLevel());
			editor.putInt("flameThrower", ft.getPowerLevel());
			editor.putInt("laser", l.getPowerLevel());
			editor.putInt("lockingLaser", ll.getPowerLevel());
			editor.putInt("machineGun", mg.getPowerLevel());
			editor.putInt("missileLauncher", ml.getPowerLevel());
			editor.putInt("pulseCannon", pc.getPowerLevel());

			HealthController hc = (HealthController) player.getComponent(HealthController.class);
			editor.putInt("health", hc.getHealth());
			editor.putInt("maxHealth", hc.getMaxHealth());
		}
		
		editor.putString("lastLevel", LevelLoader.getLastLevelLoaded());
		*/
		Time.pause();
		
		List<GameObject> gos = GameObject.getAllGameObjects();
		for (int x = 0; x < gos.size(); x++)
		{
			Audio a = (Audio)gos.get(x).getComponent(Audio.class);
			if (a != null)
			{
				a.pause();
			}
		}
		
	}

	public void fromBackground(SharedPreferences preferences) {
		ready = true;
		/*
		List<GameObject> gos = GameObject.getAllGameObjects();
		for (int x = 0; x < gos.size(); x++)
		{
			Audio a = (Audio)gos.get(x).getComponent(Audio.class);
			if (a != null)
			{
				a.play();
			}
		}
		 */
		Time.unPause();
	}
}

