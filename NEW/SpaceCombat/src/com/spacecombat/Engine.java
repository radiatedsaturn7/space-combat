package com.spacecombat;

import java.util.List;

import com.spacecombat.game.LevelLoader;

public class Engine implements ClickListener {
	// this is da master list of all components

	// private int fps = 60;
	// private int sleepTime; //calculated

	private class DrawLoop extends Thread {
		@Override
		public void run() {
			while (true) {
				drawLoop();
			}
		}
	}

	private class UpdateLoop extends Thread {
		@Override
		public void run() {
			while (true) {
				updateLoop();
			}
		}
	}

	private final boolean useInputStep = false;
	private boolean canRun = true;

	private final boolean useMultithreadedDrawLoop = false;
	private final boolean runDrawLoop = true;

	private final boolean useFrameRate = true;
	private final int drawFrameRate = 32;
	private final boolean useMultithreadedGameLoop = true;
	private final boolean runGameLoop = true;

	private final boolean useGameFrameRate = true;
	private final int updateFrameRate = 32;
	private final boolean printFrameRate = false;

	private float lastTimeCheck = 0;

	private int frames = 0;
	private final Object lock = new Object();

	private GameObject xGameObject;
	private GameObject yGameObject;
	private int x = 0;
	private int y = 0;

	/** The Activity Context ( NEW ) */

	List<GameObject> gameObjects = GameObject.getAllGameObjects();

	/**
	 * * Instance the Cube object and set the Activity Context handed over
	 */
	public Engine() {
		if (this.useMultithreadedDrawLoop) {
			final Thread drawLoop = new DrawLoop();
			drawLoop.start();
		}

		if (this.useMultithreadedGameLoop) {
			final Thread gameLoop = new UpdateLoop();
			gameLoop.start();
		}

		Input.subscribeListener(this);
	}

	public void createGameObjects() {		

		synchronized (this.lock)
		{
			LevelLoader.loadLevel("level1");			
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
		synchronized (this.lock) {		
			for (x = 0; x < this.gameObjects.size(); x++) {
				this.gameObjects.get(x).draw();
			}
		}
	}



	@Override
	public void onClick(final float x, final float y) 
	{
		this.canRun = true;
	}

	public void updateLoop() {
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
			for (this.x = 0; this.x < this.gameObjects.size(); this.x++) {

				this.xGameObject = this.gameObjects.get(this.x);

				this.xGameObject.update();

				//skip objects not on the screen for collision
				if (this.xGameObject.transform.position.y < Camera.mainCamera.gameObject.transform.position.y - 128)
				{
					continue;
				}
				if (this.xGameObject.transform.position.y > Camera.mainCamera.gameObject.transform.position.y + 864)
				{
					continue;
				}


				if (this.xGameObject.getRigidBody() == null
						|| this.xGameObject.getRigidBody().getCollider() == null) {
					continue;
				}//

				for (this.y = this.x + 1; this.y < this.gameObjects.size(); this.y++) {
					this.yGameObject = this.gameObjects.get(this.y);

					if (this.yGameObject.getRigidBody() == null
							|| this.yGameObject.getRigidBody().getCollider() == null) {
						continue;
					}

					final boolean collision = this.xGameObject
							.getRigidBody()
							.getCollider()
							.collidesWith(
									this.yGameObject.getRigidBody().getCollider());

					if (collision) {
						this.xGameObject.collide(this.yGameObject);
						this.yGameObject.collide(this.xGameObject);
					}
				}
			}
		}

		synchronized (this.lock)
		{
			for (this.x = 0; this.x < this.gameObjects.size(); this.x++) {
				this.xGameObject = this.gameObjects.get(this.x);
				this.xGameObject.onAfterUpdate();
			}
		}


		int size = this.gameObjects.size();

		synchronized (this.lock) {
			for (this.x = 0; this.x < size; this.x++) {
				if (this.gameObjects.get(this.x).isDestroyed()) {
					this.gameObjects.remove(this.x);
					this.x--;
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
