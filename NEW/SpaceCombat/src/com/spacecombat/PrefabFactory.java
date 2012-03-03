package com.spacecombat;

import java.io.InputStream;

import com.nea.nehe.lesson06.R;

import android.content.Context;

public class PrefabFactory 
{
	private static boolean useOpenGl = false;
	private static int defaultFps = 17;
	
	private static final String [] enemyTargets = {"player","ally"}; 
	
	private static final Vector3 shootDown = new Vector3(0,200,0);
	private static final Vector3 shootDownLeft = new Vector3(-8,8,0);
	private static final Vector3 shootDownRight = new Vector3(8,8,0);
	private static final Vector3 shootLeft = new Vector3(-8,0,0);
	private static final Vector3 shootRight = new Vector3(8,0,0);
	private static final Vector3 shootUpLeft = new Vector3(-8,-8,0);
	private static final Vector3 shootUpRight = new Vector3(8,-8,0);
	private static final Vector3 shootUp = new Vector3(0,-8,0);
	
	private static Context context;
	
	public static void setContext (Context c)
	{
		PrefabFactory.context = c;
	}
	
	public static GameObject createPlayer (String name, Vector3 position, String playerType)
	{				
		//Load the texture for the cube once during Surface creation
		GenericGraphic graphic = createGraphic(playerType, PrefabFactory.getImage(playerType));
		Animation idle = new Animation("idle",0,5,true,defaultFps,32,32);
		idle.setFrameIncrement(2);
		Animation death = new Animation("death",0,1,true,defaultFps,32,32);
		
		GraphicAnimation glIdle = new GraphicAnimation(graphic, idle);
		GraphicAnimation glDeath = new GraphicAnimation(graphic, death);
		glIdle.play();
		
		Weapon w = new Laser(shootUp);
		//WeaponHandler wh = new WeaponHandler();
		
		RigidBody rigidBody = new RigidBody();
		Collider collider = new BoxCollider(new Vector3(32,32,0));
		collider.setTags(new String [] {"Player","Ally"});
		rigidBody.setCollider(collider);

		HealthController hc = new HealthController();
		hc.setHealth(100);
		
		GameObject o = new GameObject();		
		o.setName(name);		
		o.setTags(new String [] {"Player","Ally"});
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;
		o.setRigidBody(rigidBody);
		o.addComponent(hc);
		o.addComponent(w);
		//o.addComponent(wh);
		
		o.addComponent(glIdle);
		o.addComponent(glDeath);

		return o;
	}
	
	public static GameObject createAlly (String name, Vector3 position, String allyType, String weapon)
	{		
		//Load the texture for the cube once during Surface creation
		GenericGraphic graphic = createGraphic(allyType, PrefabFactory.getImage(allyType));
		Animation idle = new Animation("idle",0,5,true,defaultFps,32,32);
		idle.setFrameIncrement(2);
		Animation death = new Animation("death",0,1,true,defaultFps,32,32);
		
		GraphicAnimation glIdle = new GraphicAnimation(graphic, idle);
		GraphicAnimation glDeath = new GraphicAnimation(graphic, death);
		glIdle.play();
			
		Weapon w = null;
		if (weapon.equals("laser"))
		{
			w = new Laser(shootUp);
		}
		if (weapon.equals("machinegun"))
		{
			w = new MachineGun(shootUp);
		}
		
		
		RigidBody rigidBody = new RigidBody();
		Collider collider = new BoxCollider(new Vector3(32,32,0));
		collider.setTags(new String [] {"Player","Ally"});
		
		rigidBody.setCollider(collider);
		
		HealthController hc = new HealthController();
		hc.setHealth(100);
		
		GameObject o = new GameObject();
		o.setName(name);
		o.setTags(new String [] {"Ally"});
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;
		o.setRigidBody(rigidBody);
		
		AIScript ai = new AllyAI(w);
		o.addComponent(ai);
		o.addComponent(w);
		o.addComponent(hc);
		
		o.addComponent(glIdle);
		o.addComponent(glDeath);

		return o;
	}
	
	public static GameObject createShot (String name, Vector3 position, Vector3 speed, String [] tags, float damage, int power, float life)
	{
		//Load the texture for the cube once during Surface creation
		GenericGraphic graphic = createGraphic("laser", PrefabFactory.getImage(name));

		Animation animation = null;
		
		if (name.equals("phaser"))
		{
			animation = new Animation("idle",0,6,true,defaultFps,32,32);
		}
		else
		{
			new Animation("idle",power,power,true,defaultFps,32,32);
		}
		
		GraphicAnimation glIdle = new GraphicAnimation(graphic, animation);
		glIdle.play();

		ShotCollision sc = new ShotCollision();
		sc.setDamage(damage);
		
		RigidBody rigidBody = new RigidBody();
		Collider collider = new BoxCollider(new Vector3(32,32,0));
		collider.setTags(tags);
		rigidBody.setCollider(collider);

		GameObject o = new GameObject();
		o.setName("Laser");
		
		String [] newTags = new String [tags.length+1];
		for (int x = 0; x < tags.length; x++)
		{
			newTags[x] = tags[x];
		}
		newTags[tags.length] = "shot";
		o.setTags(newTags);
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;
		o.setRigidBody(rigidBody);
		o.addComponent(sc);
		
		SimpleMovement basicShotMovement = null;
		basicShotMovement = new SimpleMovement();
		basicShotMovement.setSpeed(speed);
				
		o.addComponent(glIdle);
		o.addComponent(basicShotMovement);

		o.destroyAfter(life);
		
		return o;
	}

	public static GameObject createEnemy (String name, Vector3 position, int enemyType, int scriptType, boolean reverse)
	{
		//Load the texture for the cube once during Surface creation
		GenericGraphic graphic = createGraphic("enemy", PrefabFactory.getImage("enemy"));
		
		int startFrame = (enemyType-1)*8+6;
		int endFrame = startFrame+1;
		Animation idle = new Animation("idle",startFrame,endFrame,true,defaultFps,32,32);
		Animation death = new Animation("death",startFrame-6,startFrame,false,defaultFps,32,32);
		
		GraphicAnimation glIdle = new GraphicAnimation(graphic, idle);
		GraphicAnimation glDeath = new GraphicAnimation(graphic, death);
		glIdle.play();
		
		RigidBody rigidBody = new RigidBody();
		Collider collider = new BoxCollider(new Vector3(32,32,0));
		collider.setTags(new String [] {"Enemy"});
		rigidBody.setCollider(collider);
		
		GameObject o = new GameObject();
		o.setName(name);
		o.setTags(new String [] {"Enemy"});
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;
		o.setRigidBody(rigidBody);
		
		
		Component ai = null;
		if (scriptType == 1)
		{
			ai = new AIScriptOne(reverse);
		}
		else if (scriptType == 2)
		{
			ai = new AIScriptTwo(reverse);
		}
		else if (scriptType == 3)
		{
			ai = new AIScriptThree(reverse);
		}
		else if (scriptType == 4)
		{
			ai = new AIScriptFour(enemyTargets);
		}
		else if (scriptType == 5)
		{
			ai = new AIScriptFive(enemyTargets);
		}
		else
		{
			ai = new AIScript();
		}

		HealthController hc = new HealthController();
		hc.setHealth(100);

		if (enemyType == 1)
		{
			Weapon w = new Phaser(shootDown,4);
			WeaponHandler wh = new WeaponHandler(w);
			hc.setHealth(100);
						
			o.addComponent(w);
			o.addComponent(wh);			
		}
		if (enemyType == 2)
		{
			Weapon w = new Phaser(shootDown,3);
			WeaponHandler wh = new WeaponHandler(w);
			hc.setHealth(100);
						
			o.addComponent(w);
			o.addComponent(wh);
		}
		if (enemyType == 3)
		{
			Weapon w = new Phaser(shootDown,4);
			LockingWeaponHandler wh = new LockingWeaponHandler(w,enemyTargets);
			hc.setHealth(150);
						
			o.addComponent(w);
			o.addComponent(wh);
		}
		if (enemyType == 4)
		{
			Weapon w = new Phaser(shootDown,3);
			LockingWeaponHandler wh = new LockingWeaponHandler(w,enemyTargets);
			hc.setHealth(150);
						
			o.addComponent(w);
			o.addComponent(wh);
		}
		if (enemyType == 5 || enemyType == 6)
		{
			hc.setHealth(200);
			
			Weapon w = new Phaser(shootLeft,4);			
			WeaponHandler wh = new WeaponHandler(w);
			o.addComponent(w);
			o.addComponent(wh);
			
			Weapon w2 = new Phaser(shootDownLeft,4);			
			WeaponHandler wh2 = new WeaponHandler(w2);
			o.addComponent(w2);
			o.addComponent(wh2);	
			
			if (enemyType == 5)
			{
				Weapon w3 = new Phaser(shootDown,4);			
				WeaponHandler wh3 = new WeaponHandler(w2);
				o.addComponent(w3);
				o.addComponent(wh3);
			}
			if (enemyType == 6)
			{
				Weapon w3 = new Phaser(shootDown,4);			
				LockingWeaponHandler wh3 = new LockingWeaponHandler(w3,enemyTargets);
				o.addComponent(w3);
				o.addComponent(wh3);
			}
			
			Weapon w4 = new Phaser(shootDownRight,4);			
			WeaponHandler wh4 = new WeaponHandler(w4);
			o.addComponent(w4);
			o.addComponent(wh4);
			
			Weapon w5 = new Phaser(shootRight,4);	
			WeaponHandler wh5 = new WeaponHandler(w5);
			o.addComponent(w5);
			o.addComponent(wh5);			
			
		}
		if (enemyType == 7 || enemyType == 8)
		{
			hc.setHealth(250);
			
			Weapon w3 = null;
			if (enemyType == 7)
			{
				w3 = new Phaser(shootDown,0.3f,8,5);
			}
			else
			{
				w3 = new Phaser(shootDown,0.3f,14,5);
			}
			LockingWeaponHandler wh3 = new LockingWeaponHandler(w3,enemyTargets);
			o.addComponent(w3);
			o.addComponent(wh3);
		}
		if (enemyType == 9 || enemyType == 10)
		{
			hc.setHealth(250);
			
			float speed = 4.0f;
			if (enemyType == 10)
			{
				speed = 3.0f;
			}
			Weapon w = new Phaser(shootUpLeft,speed);			
			WeaponHandler wh = new WeaponHandler(w);
			o.addComponent(w);
			o.addComponent(wh);
			
			Weapon w2 = new Phaser(shootUpRight,speed);			
			WeaponHandler wh2 = new WeaponHandler(w2);
			o.addComponent(w2);
			o.addComponent(wh2);
			
			Weapon w3 = new Phaser(shootDownLeft,speed);			
			WeaponHandler wh3 = new WeaponHandler(w3);
			o.addComponent(w3);
			o.addComponent(wh3);
			
			Weapon w4 = new Phaser(shootDownRight,speed);			
			WeaponHandler wh4 = new WeaponHandler(w4);
			o.addComponent(w4);
			o.addComponent(wh4);
		}
		if (enemyType == 11 || enemyType == 12)
		{
			hc.setHealth(100);
			
			Weapon w = null;
			if (enemyType == 11)
			{
				w = new Phaser(shootDown,0.3f,2,2);	
			}
			if (enemyType == 12)
			{
				w = new Phaser(shootDown,0.3f,2,1);	
			}
			LockingWeaponHandler wh = new LockingWeaponHandler(w,enemyTargets);
						
			o.addComponent(w);
			o.addComponent(wh);
		}
		if (enemyType == 13)
		{
			hc.setHealth(50);
		}
		
		o.addComponent(glIdle);
		o.addComponent(glDeath);
		o.addComponent(ai);
		o.addComponent(hc);

		return o;
	}
	
	public static GameObject createLevel (int [] map, int mapWidth, int mapHeight, InputStream wad, String wadName)
	{
		GenericGraphic graphic = createGraphic(wadName, wad);		
		Level l = new Level();
		l.createLevel(map, mapWidth, mapHeight, graphic, 64, 64);
		GameObject o = new GameObject();
		o.setName("Level");
		o.setTags(new String [] {"level"});
		o.addComponent(l);
		return o;
	}
	
	public static GenericGraphic createGraphic (String name, InputStream is)
	{
			CanvasGraphic temp = new CanvasGraphic();
			temp.create(name,is);
			return temp;
	}
		
	public static InputStream getImage (String name)
	{
		if (name.equals("renegade"))
		{
			return context.getResources().openRawResource(R.drawable.prenegade);
		}
		if (name.equals("laser"))
		{
			return context.getResources().openRawResource(R.drawable.hlaser);
		}
		if (name.equals("bullet"))
		{
			return context.getResources().openRawResource(R.drawable.hmgun);
		}
		if (name.equals("phaser"))
		{
			return context.getResources().openRawResource(R.drawable.helaser);
		}
		if (name.equals("enemy"))
		{
			return context.getResources().openRawResource(R.drawable.enemy);
		}
		if (name.equals("enemy"))
		{
			return context.getResources().openRawResource(R.drawable.wad3);
		}
		return null;
	}
}
