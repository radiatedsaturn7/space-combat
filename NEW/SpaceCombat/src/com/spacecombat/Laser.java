package com.spacecombat;

import java.io.InputStream;

public class Laser extends Weapon
{
	private static final String name = "laser";
	private static final float damage = 10;	
	private static final float reloadTime = 1;
	private static final float shotSpeed = 128;
	private static final float life = 5;
	private static final float accuracy = 32;
	private static final int magazineSize = 3;
	private static final float magazineReloadTime = 2;
	
	public Laser(Vector3 direction) 
	{
		super(name, damage, accuracy, reloadTime, magazineSize, magazineReloadTime, life, shotSpeed, direction, true);
	}
	
	protected void fire (Vector3 position) 
	{
		GameObject.create(PrefabFactory.createShot("laser",position, shotSpeedVector, gameObject.getTags(), baseDamage, powerLevel, life));			
	}	
}
