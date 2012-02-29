package com.spacecombat;

import java.io.InputStream;

public abstract class Weapon extends Component
{
	protected float baseDamage;
	protected int powerLevel;
	protected int maxPowerLevel;
	protected float reloadTime;
	protected float lastShotTime;
	protected String name;
	protected InputStream shotImage;
	protected float shotSpeed;
	protected float life;
	protected Vector3 shotSpeedVector;
		
	public Weapon(String name, float damage, InputStream shotImage, float reloadTime, float life, float shotSpeed, Vector3 shootDirection)
	{
		this.name = name;
		baseDamage = damage;
		lastShotTime = Time.getTime();
		powerLevel = 1;
		maxPowerLevel = 9;
		lastShotTime = 0;
		this.shotImage = shotImage;
		this.reloadTime = reloadTime;
		this.shotSpeed = shotSpeed;				
		this.life = life;
		
		setShootDirection(shootDirection);		
	}
	
	public InputStream getShotImage ()
	{
		return shotImage;
	}
		
	public boolean canShoot()
	{
		//System.out.println((lastShotTime + reloadTime) + " < " + Time.getTime());
		if (lastShotTime + reloadTime < Time.getTime())
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
		shotSpeedVector.x += gameObject.getRigidBody().speed.x;
		shotSpeedVector.y += gameObject.getRigidBody().speed.y;
		shotSpeedVector.z += gameObject.getRigidBody().speed.z;
		
		fire(gameObject.transform.position,shotImage);
		
		shotSpeedVector.x -= gameObject.getRigidBody().speed.x;
		shotSpeedVector.y -= gameObject.getRigidBody().speed.y;
		shotSpeedVector.z -= gameObject.getRigidBody().speed.z;

	}
	
	protected abstract void fire (Vector3 position, InputStream is);
}
