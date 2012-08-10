package com.spacecombat;

import java.util.List;

import com.spacecombat.ai.AllyAI;
import com.spacecombat.game.LevelLoader;

public class Engine implements ClickListener {
	private String startingLevel = "level1";
	
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
	private final int collisionFrameRate = 10;
	
	private final boolean useMultithreadedGameLoop = true;
	private final boolean runGameLoop = true;	
	private final boolean useGameFrameRate = true;
	private final int updateFrameRate = 32;
	

	private float lastTimeCheck = 0;
	

	private int frames = 0;
	private final Object lock = new Object();

	private GameObject xGameObject1;
	private GameObject yGameObject1;

	/** The Activity Context ( NEW ) */

	List<GameObject> gameObjects = GameObject.getAllGameObjects();

	/**
	 * * Instance the Cube object and set the Activity Context handed over
	 */
	public Engine() {
		
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
	}
	
	public static void exit()
	{		
	}
	
	public void createGameObjects() {		
		synchronized (this.lock)
		{
			GameObject.clear();
			Input.clear();
			AllyAI.clear();
			Input.subscribeListener(this);
			LevelLoader.loadLevel(startingLevel,true);		
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
	}

