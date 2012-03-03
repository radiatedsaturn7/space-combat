package com.spacecombat;

import java.io.InputStream;

import android.R;

public class Phaser extends Weapon //
{
	private static final String name = "phaser";
	private static final float damage = 10;	
	private static final float shotSpeed = 128;
	private static final float life = 5;
	private static final float accuracy = 0;

	public Phaser (Vector3 direction, float reloadTime)
	{
		super(name, damage, 0, reloadTime, 0, reloadTime, life, shotSpeed, direction, false);		
	}
	
	public Phaser (Vector3 direction, float reloadTime, int magazineSize, float magazineReloadTime)
	{		
		super(name, damage, 0, reloadTime, magazineSize, magazineReloadTime, life, shotSpeed, direction, false);		
	}
	
	@Override
	protected void fire(Vector3 position) 
	{
		// TODO Auto-generated method stub
		GameObject.create(PrefabFactory.createShot("phaser",position, shotSpeedVector, gameObject.getTags(), baseDamage, powerLevel, life));			
	}
}
