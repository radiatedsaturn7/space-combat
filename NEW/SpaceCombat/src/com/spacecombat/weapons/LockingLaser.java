package com.spacecombat.weapons;

import com.spacecombat.GameObject;
import com.spacecombat.Vector2;
import com.spacecombat.game.PrefabFactory;

public class LockingLaser extends Weapon
{
	private static final String name = "lockinglaser";
	private static final float damage = 50;
	private static final float reloadTime = .5f;
	private static final float magazineReloadTime = 1;
	private static final float shotSpeed = 256;
	private static final float life = 5;
	private static final float accuracy = 0;
	private static final int magazineSize = 5;
	private static final int powerUpType = 2;

	public LockingLaser(final Vector2 direction) {
		super(LockingLaser.name, LockingLaser.damage, LockingLaser.accuracy, LockingLaser.reloadTime, LockingLaser.magazineSize,
				LockingLaser.magazineReloadTime, LockingLaser.life, LockingLaser.shotSpeed, direction, false, powerUpType);
	}

	@Override
	protected void fire(final Vector2 position) {
		GameObject.create(PrefabFactory.createShot("lockingLaser", position,
				this.shotSpeedVector, this.tags,
				this.baseDamage, this.powerLevel, LockingLaser.life));
	}
}