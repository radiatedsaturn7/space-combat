package com.spacecombat;

import java.io.InputStream;
import com.nea.nehe.lesson06.R;

import android.content.Context;

import java.util.LinkedList;
import java.util.List;


public class Engine
{
	//this is da master list of all components

	//private int fps = 60;
	//private int sleepTime; //calculated

	private int width = 0;
	private int height = 0;

	private boolean hasDrawn = false;
	private boolean useMultithreadedDrawLoop = false;
	private boolean runDrawLoop = true;
	private boolean useFrameRate = false;
	private int drawFrameRate = 32;	

	private boolean useMultithreadedGameLoop = true;
	private boolean runGameLoop = true;
	private boolean useGameFrameRate = false;			
	private int updateFrameRate = 32;
	
	private boolean printFrameRate = true;
	private float lastTimeCheck = 0;
	private int frames = 0;
	
	private Object lock = new Object();
	
	/** The Activity Context ( NEW ) */
	private Context context;
	List<GameObject> gameObjects = GameObject.getAllGameObjects();			
	
	/**	 * Instance the Cube object and set 
	 * the Activity Context handed over
	 */
	public Engine(Context context) {
		this.context = context;		
		System.out.println("STARTING");

		if (useMultithreadedGameLoop)
		{
			Thread gameLoop = new UpdateLoop();
			gameLoop.start();			
		}
		
		if (useMultithreadedDrawLoop)
		{
			Thread drawLoop = new DrawLoop();
			drawLoop.start();
		}
	}
	
	public void createGameObjects ()
	{		
		int [] map = 
			{
				0,0,1,0,0,0,0,0,
				0,0,1,0,0,0,0,0,
				0,0,1,0,0,0,0,0,
				0,0,1,0,0,0,0,0,
				0,0,1,0,0,0,0,0,
				0,0,1,0,0,0,0,0,
				0,0,1,0,0,0,0,0,
				5,5,4,5,5,5,5,5,
				0,0,1,0,0,0,0,0,
				0,0,1,0,0,0,0,0,
				0,0,3,0,0,0,0,0,
				0,0,1,0,6,0,0,0,
				0,0,2,0,6,0,0,0,
				0,0,1,0,0,0,0,0,
			};
		

		//GameObject.create(PrefabFactory.createLevel(map, 8, 14, wad, "wad3"));

		GameObject.create(PrefabFactory.createPlayer("Player1",new Vector3(200,600,0),"renegade"));
		
		//GameObject.create(PrefabFactory.createAlly("Ally1",new Vector3(400,700,0),"renegade","laser"));
		//GameObject.create(PrefabFactory.createAlly("Ally1",new Vector3(0,700,0),"renegade","machinegun"));
		
		//GameObject.create(PrefabFactory.createEnemy("E1",new Vector3(0,0,0),13,3,false));		
		GameObject.create(PrefabFactory.createEnemy("E2",new Vector3(0,0,0),1,5,true));
		
		/*
		GameObject.create(PrefabFactory.createEnemy("E3",new Vector3(80,0,0),3,0,false));		
		GameObject.create(PrefabFactory.createEnemy("E4",new Vector3(120,0,0),4,0,false));
		GameObject.create(PrefabFactory.createEnemy("E5",new Vector3(160,0,0),5,0,false));
		GameObject.create(PrefabFactory.createEnemy("E6",new Vector3(200,0,0),6,0,false));
		GameObject.create(PrefabFactory.createEnemy("E7",new Vector3(240,0,0),7,0,false));
		GameObject.create(PrefabFactory.createEnemy("E8",new Vector3(280,0,0),8,0,false));
		GameObject.create(PrefabFactory.createEnemy("E7",new Vector3(320,0,0),9,0,false));
		GameObject.create(PrefabFactory.createEnemy("E8",new Vector3(360,0,0),10,0,false));
		GameObject.create(PrefabFactory.createEnemy("E7",new Vector3(0,200,0),11,0,false));
		GameObject.create(PrefabFactory.createEnemy("E8",new Vector3(200,200,0),12,0,false));
		GameObject.create(PrefabFactory.createEnemy("E8",new Vector3(360,200,0),13,0,false));
		 */
	}

	/**
	 * Here we do our drawing
	 */
	public void drawLoop() 
	{		
		if (useFrameRate)
		{
			try
			{				
				Thread.sleep(1000/drawFrameRate);
			}
			catch (InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		
		if (printFrameRate)
		{
			if (lastTimeCheck == 0)
			{
				lastTimeCheck = Time.getTime();
			}
			
			frames++;
			if (Time.getTime() - lastTimeCheck > 1)
			{				
				System.out.println("FPS:" + frames);								
				frames = 0;
				lastTimeCheck = Time.getTime();
			}
		}
		
		if (!runDrawLoop)
		{
			return;
		}
		
		int x = 0; 
		synchronized (lock)
		{
			for (x = 0; x < gameObjects.size(); x++)		
			{			
				gameObjects.get(x).draw();			
			}
		}
		
		hasDrawn = true;
	}
	
	public void updateLoop ()
	{
		if (!hasDrawn)
		{
			return;
		}
		
		Time.tick();
		
		if (!runGameLoop)
		{
			return;
		}
		
		synchronized (lock)
		{
		for (int x = 0; x < gameObjects.size(); x++)		
		{
			GameObject xGameObject = gameObjects.get(x);

			xGameObject.update();

			if (xGameObject.getRigidBody() == null || xGameObject.getRigidBody().getCollider() == null)
			{
				continue;
			}
			
			int y = 0;
			for (y = x+1; y < gameObjects.size(); y++)
			{
				GameObject yGameObject = gameObjects.get(y);
				
				if (yGameObject.getRigidBody() == null || yGameObject.getRigidBody().getCollider() == null)
				{
					continue;
				}
				
				if (xGameObject.getRigidBody().getCollider().collidesWith(yGameObject.getRigidBody().getCollider()))
				{					
					xGameObject.collide(new Collision(xGameObject,yGameObject));
					yGameObject.collide(new Collision(yGameObject,xGameObject));
				}
			}
		}

		//DONT TOUCH
		int size = gameObjects.size();
		for (int x = 0; x < size; x++)
		{
			if (gameObjects.get(x).isDestroyed())
			{						
				gameObjects.remove(x);
				x--;
				size = gameObjects.size();
			}
		}
		}

		
		if (useMultithreadedGameLoop && useGameFrameRate)
		{
			try 
			{
				Thread.currentThread().sleep(1000/updateFrameRate);
			} 
			catch (InterruptedException e) 
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	private class UpdateLoop extends Thread
	{
		public void run ()
		{
			while (true)
			{	
				updateLoop();
			}
		}
	}
	
	private class DrawLoop extends Thread
	{
		public void run ()
		{
			while (true)
			{	
				drawLoop();
			}
		}
	}
}
