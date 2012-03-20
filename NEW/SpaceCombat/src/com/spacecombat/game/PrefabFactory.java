package com.spacecombat.game;

import java.io.InputStream;

import android.content.Context;

import com.spacecombat.Animation;
import com.spacecombat.BoxCollider;
import com.spacecombat.CanvasGraphic;
import com.spacecombat.Collider;
import com.spacecombat.Component;
import com.spacecombat.FixedJoint;
import com.spacecombat.GameObject;
import com.spacecombat.GenericGraphic;
import com.spacecombat.GraphicAnimation;
import com.spacecombat.Level;
import com.spacecombat.R;
import com.spacecombat.RigidBody;
import com.spacecombat.Util;
import com.spacecombat.Vector2;
import com.spacecombat.R.drawable;
import com.spacecombat.ai.AIScript;
import com.spacecombat.ai.AIScriptFive;
import com.spacecombat.ai.AIScriptFour;
import com.spacecombat.ai.AIScriptOne;
import com.spacecombat.ai.AIScriptThree;
import com.spacecombat.ai.AIScriptTwo;
import com.spacecombat.ai.AllyAI;
import com.spacecombat.weapons.FlameThrower;
import com.spacecombat.weapons.HellGun;
import com.spacecombat.weapons.Laser;
import com.spacecombat.weapons.LockingWeaponHandler;
import com.spacecombat.weapons.MachineGun;
import com.spacecombat.weapons.Phaser;
import com.spacecombat.weapons.PulseCannon;
import com.spacecombat.weapons.Weapon;
import com.spacecombat.weapons.WeaponController;
import com.spacecombat.weapons.WeaponHandler;

public class PrefabFactory {
	private static boolean useOpenGl = false;
	private static int defaultFps = 17;

	private static final String[] enemyTargets = { "player", "ally" };

	private static final Vector2 shootDown = new Vector2(0, 200);
	private static final Vector2 shootDownLeft = new Vector2(-8, 8);
	private static final Vector2 shootDownRight = new Vector2(8, 8);
	private static final Vector2 shootLeft = new Vector2(-8, 0);
	private static final Vector2 shootRight = new Vector2(8, 0);
	private static final Vector2 shootUpLeft = new Vector2(-8, -8);
	private static final Vector2 shootUpRight = new Vector2(8, -8);
	private static final Vector2 shootUp = new Vector2(0, -8);

	private static Context context;

	public static GameObject createAlly(final String name,
			final Vector2 position, final String allyType, final String weapon) {
		// Load the texture for the cube once during Surface creation
		final GenericGraphic graphic = PrefabFactory.createGraphic(allyType,
				PrefabFactory.getImage(allyType));
				
		final Animation idle = new Animation("idle", 0, 5, true,
				PrefabFactory.defaultFps, 32, 32);
		
		idle.setFrameIncrement(2);
		final Animation death = new Animation("death", 0, 1, true,
				PrefabFactory.defaultFps, 32, 32);
		
		final Animation left = new Animation("left", 3, 3, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation upleft = new Animation("upleft", 8, 8, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation up = new Animation("up", 0, 0, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation upright = new Animation("upright", 6, 6, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation right = new Animation("right", 1, 1, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation downright = new Animation("downright", 5, 5, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation down = new Animation("down", 2, 2, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation downleft = new Animation("downleft", 7, 7, true,
				PrefabFactory.defaultFps, 32, 32);
		

		final GraphicAnimation glIdle = new GraphicAnimation(graphic, idle);
		final GraphicAnimation glDeath = new GraphicAnimation(graphic, death);
		final GraphicAnimation glLeft = new GraphicAnimation(graphic, left);
		final GraphicAnimation glUpLeft = new GraphicAnimation(graphic, upleft);
		final GraphicAnimation glUp = new GraphicAnimation(graphic, up);
		final GraphicAnimation glUpRight = new GraphicAnimation(graphic, upright);
		final GraphicAnimation glRight = new GraphicAnimation(graphic, right);
		final GraphicAnimation glDownRight = new GraphicAnimation(graphic, downright);
		final GraphicAnimation glDown = new GraphicAnimation(graphic, down);
		final GraphicAnimation glDownLeft = new GraphicAnimation(graphic, downleft);
		
		glIdle.play();

		Weapon w = null;
		if (weapon.equals("laser")) {
			w = new Laser(PrefabFactory.shootUp);
		}
		if (weapon.equals("machinegun")) {
			w = new MachineGun(PrefabFactory.shootUp);
		}
		if (weapon.equals("flamethrower")) {
			w = new FlameThrower(PrefabFactory.shootUp);
		}
		if (weapon.equals("pulsecannon")) {
			w = new PulseCannon(PrefabFactory.shootUp);
		}
		if (weapon.equals("hellgun")) {
			w = new HellGun(PrefabFactory.shootUp);
		}

		final RigidBody rigidBody = new RigidBody();
		final Collider collider = new BoxCollider(new Vector2(32, 32));
		collider.setTags(new String[] { "Player", "Ally" });

		rigidBody.setCollider(collider);

		final GameObject o = new GameObject();
		o.setName(name);
		o.setTags(new String[] { "Ally" });
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;
		o.setRigidBody(rigidBody);

		final AllyAI ai = new AllyAI(allyType,w);
		o.addComponent(ai);
		o.addComponent(w);		
		
		final HealthController hc = new HealthController();
		if (allyType.equals("calumniator"))
		{
			ai.setSpeed(new Vector2(80, 64));
			ai.setAccel(new Vector2(12,8));
			hc.setHealth(120);
		}
		else if (allyType.equals("exemplar"))
		{
			ai.setSpeed(new Vector2(64, 80));
			ai.setAccel(new Vector2(8,12));
			hc.setHealth(120);
		}
		else if (allyType.equals("hunter"))
		{
			ai.setSpeed(new Vector2(64, 64));
			ai.setAccel(new Vector2(8,8));
			hc.setHealth(150);
		}
		else if (allyType.equals("paladin"))
		{
			ai.setSpeed(new Vector2(110, 64));
			ai.setAccel(new Vector2(20,6));
			hc.setHealth(80);
		}
		else if (allyType.equals("pariah"))
		{
			ai.setSpeed(new Vector2(64, 110));
			ai.setAccel(new Vector2(6,20));
			hc.setHealth(80);
		}
		else if (allyType.equals("renegade"))
		{
			ai.setSpeed(new Vector2(80, 80));
			ai.setAccel(new Vector2(12,12));
			hc.setHealth(100);
		}
		else if (allyType.equals("sentinel"))
		{
			ai.setSpeed(new Vector2(50, 50));
			ai.setAccel(new Vector2(6,6));
			hc.setHealth(150);
		}
		else
		{
			ai.setSpeed(new Vector2(64, 64));
			ai.setAccel(new Vector2(8,8));
			hc.setHealth(150);
		}
		o.addComponent(hc);

		o.addComponent(glIdle);
		o.addComponent(glDeath);
		o.addComponent(glLeft);
		o.addComponent(glUpLeft);
		o.addComponent(glUp);
		o.addComponent(glUpRight);
		o.addComponent(glRight);
		o.addComponent(glDownRight);
		o.addComponent(glDown);
		o.addComponent(glDownLeft);

		return o;
	}

	public static GameObject createEnemy(final String name,
			final Vector2 position, final int enemyType, final int scriptType,
			final boolean reverse) {
		// Load the texture for the cube once during Surface creation
		final GenericGraphic graphic = PrefabFactory.createGraphic("enemy",
				PrefabFactory.getImage("enemy"));

		final int startFrame = (enemyType - 1) * 8 + 6;
		final int endFrame = startFrame + 1;
		final Animation idle = new Animation("idle", startFrame, endFrame,
				true, PrefabFactory.defaultFps, 32, 32);
		final Animation death = new Animation("death", startFrame - 6,
				startFrame-1, false, PrefabFactory.defaultFps, 32, 32);

		final GraphicAnimation glIdle = new GraphicAnimation(graphic, idle);
		final GraphicAnimation glDeath = new GraphicAnimation(graphic, death);
		glIdle.play();

		final RigidBody rigidBody = new RigidBody();
		final Collider collider = new BoxCollider(new Vector2(32, 32));
		collider.setTags(new String[] { "Enemy" });
		rigidBody.setCollider(collider);

		final GameObject o = new GameObject();
		o.setName(name);
		o.setTags(new String[] { "Enemy" });
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;
		o.setRigidBody(rigidBody);

		Component ai = null;
		if (scriptType == 1) {
			ai = new AIScriptOne(reverse);
		} else if (scriptType == 2) {
			ai = new AIScriptTwo(reverse);
		} else if (scriptType == 3) {
			ai = new AIScriptThree(reverse);
		} else if (scriptType == 4) {
			ai = new AIScriptFour(PrefabFactory.enemyTargets);
		} else if (scriptType == 5) {
			ai = new AIScriptFive(PrefabFactory.enemyTargets);
		} else {
			ai = new AIScript();
		}

		final HealthController hc = new HealthController();
		hc.setHealth(100);

		if (enemyType == 1) {
			final Weapon w = new Phaser(PrefabFactory.shootDown, 4);
			final WeaponHandler wh = new WeaponHandler(w);
			hc.setHealth(100);

			o.addComponent(w);
			o.addComponent(wh);
		}
		if (enemyType == 2) {
			final Weapon w = new Phaser(PrefabFactory.shootDown, 3);
			final WeaponHandler wh = new WeaponHandler(w);
			hc.setHealth(100);

			o.addComponent(w);
			o.addComponent(wh);
		}
		if (enemyType == 3) {
			final Weapon w = new Phaser(PrefabFactory.shootDown, 4);
			final LockingWeaponHandler wh = new LockingWeaponHandler(w,
					PrefabFactory.enemyTargets);
			hc.setHealth(150);

			o.addComponent(w);
			o.addComponent(wh);
			
			GameObject powerup = PrefabFactory.createPowerUp(new Vector2(-32,200), 0, true);
			o.addComponent(new SpawnOnDestroy(powerup));
		}
		if (enemyType == 4) {
			final Weapon w = new Phaser(PrefabFactory.shootDown, 3);
			final LockingWeaponHandler wh = new LockingWeaponHandler(w,
					PrefabFactory.enemyTargets);
			hc.setHealth(150);

			o.addComponent(w);
			o.addComponent(wh);
		}
		if (enemyType == 5 || enemyType == 6) {
			hc.setHealth(200);

			final Weapon w = new Phaser(PrefabFactory.shootLeft, 4);
			final WeaponHandler wh = new WeaponHandler(w);
			o.addComponent(w);
			o.addComponent(wh);

			final Weapon w2 = new Phaser(PrefabFactory.shootDownLeft, 4);
			final WeaponHandler wh2 = new WeaponHandler(w2);
			o.addComponent(w2);
			o.addComponent(wh2);

			if (enemyType == 5) {
				final Weapon w3 = new Phaser(PrefabFactory.shootDown, 4);
				final WeaponHandler wh3 = new WeaponHandler(w2);
				o.addComponent(w3);
				o.addComponent(wh3);
			}
			if (enemyType == 6) {
				final Weapon w3 = new Phaser(PrefabFactory.shootDown, 4);
				final LockingWeaponHandler wh3 = new LockingWeaponHandler(w3,
						PrefabFactory.enemyTargets);
				o.addComponent(w3);
				o.addComponent(wh3);
			}

			final Weapon w4 = new Phaser(PrefabFactory.shootDownRight, 4);
			final WeaponHandler wh4 = new WeaponHandler(w4);
			o.addComponent(w4);
			o.addComponent(wh4);

			final Weapon w5 = new Phaser(PrefabFactory.shootRight, 4);
			final WeaponHandler wh5 = new WeaponHandler(w5);
			o.addComponent(w5);
			o.addComponent(wh5);

		}
		if (enemyType == 7 || enemyType == 8) {
			hc.setHealth(250);

			Weapon w3 = null;
			if (enemyType == 7) {
				w3 = new Phaser(PrefabFactory.shootDown, 0.3f, 8, 5);
			} else {
				w3 = new Phaser(PrefabFactory.shootDown, 0.3f, 14, 5);
			}
			final LockingWeaponHandler wh3 = new LockingWeaponHandler(w3,
					PrefabFactory.enemyTargets);
			o.addComponent(w3);
			o.addComponent(wh3);
		}
		if (enemyType == 9 || enemyType == 10) {
			hc.setHealth(250);

			float speed = 4.0f;
			if (enemyType == 10) {
				speed = 3.0f;
			}
			final Weapon w = new Phaser(PrefabFactory.shootUpLeft, speed);
			final WeaponHandler wh = new WeaponHandler(w);
			o.addComponent(w);
			o.addComponent(wh);

			final Weapon w2 = new Phaser(PrefabFactory.shootUpRight, speed);
			final WeaponHandler wh2 = new WeaponHandler(w2);
			o.addComponent(w2);
			o.addComponent(wh2);

			final Weapon w3 = new Phaser(PrefabFactory.shootDownLeft, speed);
			final WeaponHandler wh3 = new WeaponHandler(w3);
			o.addComponent(w3);
			o.addComponent(wh3);

			final Weapon w4 = new Phaser(PrefabFactory.shootDownRight, speed);
			final WeaponHandler wh4 = new WeaponHandler(w4);
			o.addComponent(w4);
			o.addComponent(wh4);
		}
		if (enemyType == 11 || enemyType == 12) {
			hc.setHealth(100);

			Weapon w = null;
			if (enemyType == 11) {
				w = new Phaser(PrefabFactory.shootDown, 0.3f, 2, 2);
			}
			if (enemyType == 12) {
				w = new Phaser(PrefabFactory.shootDown, 0.3f, 2, 1);
			}
			final LockingWeaponHandler wh = new LockingWeaponHandler(w,
					PrefabFactory.enemyTargets);

			o.addComponent(w);
			o.addComponent(wh);
		}
		
		if (enemyType == 13) {
			hc.setHealth(50);
		}
		
		if (Util.randomNumber(0, 3) == 1)
		{
			GameObject explosion1 = PrefabFactory.createExplosion(o.transform.position);
			o.addComponent(new SpawnOnDestroy(explosion1));
			
			GameObject explosion2 = PrefabFactory.createExplosion(o.transform.position);
			o.addComponent(new SpawnOnDestroy(explosion2));
			
			GameObject explosion3 = PrefabFactory.createExplosion(o.transform.position);
			o.addComponent(new SpawnOnDestroy(explosion3));
		}
		
		o.addComponent(new DestroyOnOutOfBounds());
		o.addComponent(glIdle);
		o.addComponent(glDeath);
		o.addComponent(ai);
		o.addComponent(hc);

		return o;
	}

	private static GameObject createExplosion(Vector2 position) {
		GameObject o = new GameObject();
		o.setName("Explosion");
		
		final GenericGraphic graphic = PrefabFactory.createGraphic("explosion", PrefabFactory.getImage("explosion"));
		final Animation explosion = new Animation("explode", 0, 8, false,
				PrefabFactory.defaultFps, 47, 42);
		
		final GraphicAnimation glLeft = new GraphicAnimation(graphic, explosion);
		o.addComponent(glLeft);
		
		final RigidBody r = new RigidBody();
		
		SimpleMovement sm = new SimpleMovement(r,Util.randomNumber(0,64)-32,Util.randomNumber(0, 64)-32);
		SetPositionOnCreate spoc = new SetPositionOnCreate(position);
		
		o.addComponent(r);
		o.addComponent(sm);
		o.addComponent(spoc);
		o.addComponent(new DestroyOnCreate(1));

		o.playAnimation("explode");
		return o;
	}

	public static GenericGraphic createGraphic(final String name,
			final InputStream is) {
		final CanvasGraphic temp = new CanvasGraphic();
		temp.create(name, is);
		return temp;
	}

	public static GameObject createLevel(final int[] map, final int mapWidth,
			final int mapHeight, String wadName) {
		final GenericGraphic graphic = PrefabFactory.createGraphic(wadName, PrefabFactory.getImage(wadName));
		
		final Level l = new Level();
		System.out.println("WAD:"+wadName);
		l.createLevel(map, mapWidth, mapHeight, graphic, 64, 64);
		
		GameObject o = new GameObject();		
		o.setName("Level");
		o.setTags(new String[] { "level" });
		o.addComponent(l);
		o.transform.position.x = 0;
		o.transform.position.y = 0;
		l.alignBottom();		
		
		RigidBody rigidBody = new RigidBody();
		o.addComponent(rigidBody);
		
		SimpleMovement s = new SimpleMovement(rigidBody, 0, 10.0f);
		o.addComponent(s);
		
		return o;
	}

	public static GameObject createPlayer(final String name,
			final Vector2 position, final String playerType) {
		
		final GameObject o = new GameObject();
		o.setName(name);
		o.setTags(new String[] { "Player", "Ally" });
		
		// Load the texture for the cube once during Surface creation
		final GenericGraphic graphic = PrefabFactory.createGraphic(playerType,
				PrefabFactory.getImage(playerType));
		final Animation idle = new Animation("idle", 0, 5, true,
				PrefabFactory.defaultFps, 32, 32);
		idle.setFrameIncrement(2);
		final Animation death = new Animation("death", 0, 1, true,
				PrefabFactory.defaultFps, 32, 32);

		final GraphicAnimation glIdle = new GraphicAnimation(graphic, idle);
		final GraphicAnimation glDeath = new GraphicAnimation(graphic, death);
		glIdle.play();
		o.addComponent(glIdle);
		o.addComponent(glDeath);
		
		final Animation left = new Animation("left", 3, 3, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation upleft = new Animation("upleft", 8, 8, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation up = new Animation("up", 0, 0, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation upright = new Animation("upright", 6, 6, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation right = new Animation("right", 1, 1, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation downright = new Animation("downright", 5, 5, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation down = new Animation("down", 2, 2, true,
				PrefabFactory.defaultFps, 32, 32);
		final Animation downleft = new Animation("downleft", 7, 7, true,
				PrefabFactory.defaultFps, 32, 32);

		final GraphicAnimation glLeft = new GraphicAnimation(graphic, left);
		final GraphicAnimation glUpLeft = new GraphicAnimation(graphic, upleft);
		final GraphicAnimation glUp = new GraphicAnimation(graphic, up);
		final GraphicAnimation glUpRight = new GraphicAnimation(graphic, upright);
		final GraphicAnimation glRight = new GraphicAnimation(graphic, right);
		final GraphicAnimation glDownRight = new GraphicAnimation(graphic, downright);
		final GraphicAnimation glDown = new GraphicAnimation(graphic, down);
		final GraphicAnimation glDownLeft = new GraphicAnimation(graphic, downleft);

		o.addComponent(glLeft);
		o.addComponent(glUpLeft);
		o.addComponent(glUp);
		o.addComponent(glUpRight);
		o.addComponent(glRight);
		o.addComponent(glDownRight);
		o.addComponent(glDown);
		o.addComponent(glDownLeft);

		final RigidBody rigidBody = new RigidBody();
		o.setRigidBody(rigidBody);
		
		final BoxCollider collider = new BoxCollider(new Vector2(32, 32));
		collider.setTags(new String[] { "Player", "Ally" });
		rigidBody.setCollider(collider);

		final HealthController hc = new HealthController();
		hc.setHealth(100);
		o.addComponent(hc);
		
		Weapon [] weapons = new Weapon[5];
		weapons[0] = new Laser(PrefabFactory.shootUp);
		o.addComponent(weapons[0]);
		
		weapons[1] = new MachineGun(PrefabFactory.shootUp);
		o.addComponent(weapons[1]);
		
		weapons[2] = new FlameThrower(PrefabFactory.shootUp);
		o.addComponent(weapons[2]);
		
		weapons[3] = new PulseCannon(PrefabFactory.shootUp);
		o.addComponent(weapons[3]);
		
		weapons[4] = new HellGun(PrefabFactory.shootUp);
		o.addComponent(weapons[4]);
		
		WeaponController wc = new WeaponController(0,weapons);
		o.addComponent(wc);
		
		final Component playerInput = new PlayerInput(wc,collider);
		o.addComponent(playerInput);
				
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;

		return o;
	}

	public static GameObject createShot(final String name,
			final Vector2 position, final Vector2 speed, final String[] tags,
			final float damage, final int power, final float life) {
		// Load the texture for the cube once during Surface creation
		
		final GenericGraphic graphic = PrefabFactory.createGraphic(name,
				PrefabFactory.getImage(name));

		Animation animation = null;

		if (name.equals("phaser")) {
			animation = new Animation("idle", 0, 6, true, PrefabFactory.defaultFps, 32, 32);
		}
		else if (name.equals("pulse") || name.equals("hell"))
		{
			if (power < 0)		
			{
				animation = new Animation("idle", 0, 4, false,PrefabFactory.defaultFps, 32, 32);
			}
			else
			{
				animation = new Animation("idle", power, 4, false,PrefabFactory.defaultFps, 32, 32);
			}
		}
		else if (name.equals("flame"))
		{
			animation = new Animation("idle", 0, 3, false, (int) Math.ceil(4.0f/life), 32, 32);
		}
		else {
			if (power <= 9)
			{
				animation = new Animation("idle", power, power, true, PrefabFactory.defaultFps,32, 32);
			}
			else
			{
				animation = new Animation("idle", 9, 9, true, PrefabFactory.defaultFps,32, 32);
			}
		}

		final GraphicAnimation glIdle = new GraphicAnimation(graphic, animation);
		glIdle.play();

		final ShotCollision sc = new ShotCollision();
		sc.setDamage(damage);

		final RigidBody rigidBody = new RigidBody();
		final Collider collider = new BoxCollider(new Vector2(32, 32));
		collider.setTags(tags);
		rigidBody.setCollider(collider);

		final GameObject o = new GameObject();
		o.setName("Laser");

		final String[] newTags = new String[tags.length + 1];
		for (int x = 0; x < tags.length; x++) {
			newTags[x] = tags[x];
		}
		newTags[tags.length] = "shot";
		o.setTags(newTags);
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;
		o.setRigidBody(rigidBody);
		o.addComponent(sc);

		SimpleMovement basicShotMovement = null;
		basicShotMovement = new SimpleMovement(rigidBody, speed.x, speed.y);

		o.addComponent(glIdle);
		o.addComponent(basicShotMovement);

		o.addComponent(new DestroyOnOutOfBounds());
		o.destroyAfter(life);

		return o;
	}
	
	public static GameObject createSpawner (GameObject level, float spawnX, float spawnY, GameObject objectToCreate)
	{
		GameObject spawner = new GameObject();
		spawner.setName("levelLoader " + Util.randomNumber(0, 10000));
		RigidBody r = new RigidBody();
		Collider c = new BoxCollider(new Vector2(800,32));
		r.setCollider(c);
		spawner.setRigidBody(r);
		spawner.addComponent(new SpawnOnCollision(objectToCreate));
		spawner.addComponent(new FixedJoint(level));
		
		spawner.transform.position.x = spawnX;
		spawner.transform.position.y = spawnY;
		
		System.out.println("CREATED SPAWNER:" + spawner.transform.position); 
		return spawner;
	}

	public static GameObject createPowerUp (final Vector2 position, final int type, final boolean canChange) {
		// Load the texture for the cube once during Surface creation

		GameObject o = new GameObject();
		o.setName("PowerUp");
		o.setTags(new String [] {"PowerUp"});
		GenericGraphic graphic = PrefabFactory.createGraphic("powerup", PrefabFactory.getImage("powerup"));

		Animation animation = new Animation("PowerUp", 0, 2, true, PrefabFactory.defaultFps,	32, 32);
		Animation animation2 = new Animation("Health", 3, 5, true, PrefabFactory.defaultFps,	32, 32);
		Animation animation3 = new Animation("Missile", 6, 8, true, PrefabFactory.defaultFps,	32, 32);

		GraphicAnimation glIdle = new GraphicAnimation(graphic, animation);
		GraphicAnimation glIdle2 = new GraphicAnimation(graphic, animation2);
		GraphicAnimation glIdle3 = new GraphicAnimation(graphic, animation3);

		o.addComponent(glIdle);
		o.addComponent(glIdle2);
		o.addComponent(glIdle3);
		
		glIdle.play();
		glIdle2.setEnabled(false);
		glIdle3.setEnabled(false);
		
		BoxCollider collider = new BoxCollider(new Vector2(32, 32));
		collider.setTags(new String [] {"PowerUp"});
		
		RigidBody rigidBody = new RigidBody();
		rigidBody.setCollider(collider);
		o.setRigidBody(rigidBody);
		
		SimpleMovement sm = new SimpleMovement(rigidBody, 32, 32);
		o.addComponent(sm);
				
		PowerUp p = new PowerUp(sm, type, canChange);
		o.addComponent(p);
		o.addComponent(new DestroyOnOutOfBounds());
		o.transform.position.x = position.x;
		o.transform.position.y = position.y;								

		return o;
	}
	
	public static GameObject createTopOfScreen ()
	{
		GameObject go = new GameObject();
		go.setName("TopOfScreen");
		go.transform.position.x = 0;
		go.transform.position.y = -32;
		RigidBody r = new RigidBody();
		Collider c = new BoxCollider(new Vector2(800,32));
		r.setCollider(c);
		go.setRigidBody(r);
		return go;
	}

	public static InputStream getImage(final String name) {
		if (name.equals("calumniator")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.pcalumniator);
		}
		if (name.equals("exemplar")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.pexemplar);
		}
		if (name.equals("hunter")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.phunter);
		}
		if (name.equals("paladin")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.ppaladin);
		}
		if (name.equals("pariah")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.ppariah);
		}
		if (name.equals("sentinel")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.psentinel);
		}
		if (name.equals("renegade")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.prenegade);
		}
		if (name.equals("laser")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.hlaser);
		}
		if (name.equals("bullet")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.hmgun);
		}
		if (name.equals("flame")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.hflame);
		}
		if (name.equals("pulse")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.hpulse);
		}
		if (name.equals("phaser")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.helaser);
		}
		if (name.equals("enemy")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.enemy);
		}
		if (name.equals("powerup")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.powerup);
		}
		if (name.equals("wad3")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.wad3);
		}
		if (name.equals("hell")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.hhell);
		}
		if (name.equals("explosion")) {
			return PrefabFactory.context.getResources().openRawResource(
					R.drawable.exp1);
		}
		return null;
	}
	
	public static GameObject createRandomLevel ()
	{
		GameObject o = new GameObject();
		o.addComponent(new RandomSpawner());
		return o;
	}

	public static void setContext(final Context c) {
		PrefabFactory.context = c;
	}
}