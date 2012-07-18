package com.spacecombat;

import java.io.InputStream;

public abstract class Weapon extends Component
{
	protected int baseDamage;
	protected int powerLevel;
	protected int maxPowerLevel;
	protected float reloadTime;
	protected float lastShotTime;
	protected String name;
	protected InputStream shotImage;
	
	public Weapon(String name, int damage, InputStream shotImage, long reloadTime)
	{
		this.name = name;
		baseDamage = damage;
		lastShotTime = Time.getTime();
		powerLevel = 1;
		maxPowerLevel = 9;
		this.shotImage = shotImage;
		this.reloadTime = reloadTime;
	}
	
	public InputStream getShotImage ()
	{
		return shotImage;
	}
		
	public boolean canShoot()
	{
		if (lastShotTime + reloadTime < Time.getTime())
		{
			return true;
		}
		return false;
	}
	
	public abstract void shoot(Vector3 position, Vector3 speed, String [] tags, int life, InputStream is);
}
