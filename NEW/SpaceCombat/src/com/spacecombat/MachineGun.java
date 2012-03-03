package com.spacecombat;

import java.io.InputStream;

public class MachineGun extends Weapon 
{

	private static final String name = "MachineGun";
	private static final float damage = 10;	
	private static final float reloadTime = 0.3f;
	private static final float shotSpeed = 128;
	private static final float life = 5;
	private static final float accuracy = 40;
	private static final int magazineSize = 5;
	private static final float magazineReloadTime = 1;
	
	public MachineGun(Vector3 direction) 
	{
		super(name, damage, accuracy, reloadTime, magazineSize, magazineReloadTime, life, shotSpeed, direction, true);
	}

	@Override
	protected void fire(Vector3 position) 
	{
		GameObject.create(PrefabFactory.createShot("bullet",position, shotSpeedVector, gameObject.getTags(), baseDamage, powerLevel, life));
	}

}
