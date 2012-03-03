package com.spacecombat;

import java.io.InputStream;

public abstract class Weapon extends Component
{
	protected float baseDamage;
	protected int powerLevel;
	protected int maxPowerLevel;
	protected float reloadTime;
	protected float nextShotTime;
	protected String name;
	protected float shotSpeed;
	protected float life;
	protected Vector3 shotSpeedVector;
	protected float accuracy;
	protected boolean usePhysics = true;
	protected int magazineSize;
	protected int shots;
	protected float magazineReloadTime;
		
	public Weapon(String name, float damage, float accuracy, float reloadTime, int magazineSize, float magazineReloadTime, float life, float shotSpeed, Vector3 shootDirection, boolean usePhysics)
	{
		this.name = name;
		this.baseDamage = damage;
		this.nextShotTime = 0;
		this.powerLevel = 1;
		this.maxPowerLevel = 9;
		this.reloadTime = reloadTime;
		this.accuracy = accuracy;
		this.shotSpeed = shotSpeed;				
		this.life = life;
		this.usePhysics = usePhysics;
		this.shots = 0;
		this.magazineSize = magazineSize;
		this.magazineReloadTime = magazineReloadTime;
		setShootDirection(shootDirection);
	}
			
	public boolean canShoot()
	{
		if (Time.getTime() > nextShotTime)
		{
			return true;
		}
		return false;
	}
	
	public void setShootDirection (Vector3 v)
	{
		v.normalize();
		
		if (shotSpeedVector == null)
		{
			shotSpeedVector = new Vector3();
		}
		
		this.shotSpeedVector.x = v.x * shotSpeed;
		this.shotSpeedVector.y = v.y * shotSpeed;
		this.shotSpeedVector.z = v.z * shotSpeed;
	}
	
	public Vector3 getShotDirection ()
	{
		return shotSpeedVector;
	}
	
	public void shoot ()
	{
		if (!canShoot())
		{
			return;
		}
			
		shots++;		
		
		if (shots > magazineSize)
		{												
			nextShotTime = Time.getTime() + magazineReloadTime;			
			shots = 0;
		}
		else
		{
			nextShotTime = Time.getTime() + reloadTime;
		}

		
		if (usePhysics)
		{
			shotSpeedVector.x += gameObject.getRigidBody().speed.x;
			shotSpeedVector.y += gameObject.getRigidBody().speed.y;
			shotSpeedVector.z += gameObject.getRigidBody().speed.z;
		}
		
		float randomX = Util.randomNumber(0,accuracy);
		float randomY = Util.randomNumber(0,accuracy);
		
		int upDown = Util.randomNumber(0, 1);
		int leftRight = Util.randomNumber(0, 1);
		
		if (upDown == 1)
		{
			randomY = -randomY;
		}
		if (leftRight == 1)
		{
			randomX = -randomX;
		}
		
		shotSpeedVector.x += randomX;
		shotSpeedVector.y += randomY;
		
		fire(gameObject.transform.position);

		shotSpeedVector.x -= randomX;
		shotSpeedVector.y -= randomY;
				
		if (usePhysics)
		{
			shotSpeedVector.x -= gameObject.getRigidBody().speed.x;
			shotSpeedVector.y -= gameObject.getRigidBody().speed.y;
			shotSpeedVector.z -= gameObject.getRigidBody().speed.z;
		}

	}
	
	protected abstract void fire (Vector3 position);
}
