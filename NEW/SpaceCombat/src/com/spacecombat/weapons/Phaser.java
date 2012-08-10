package com.spacecombat.weapons;

import com.spacecombat.GameObject;
import com.spacecombat.Vector2;
import com.spacecombat.game.PrefabFactory;
import com.spacecombat.game.ShotCollision;

public class Phaser extends Weapon //
{
	private static final String name = "phaser";
	private static final float damage = 10;
	private static final float shotSpeed = 128;
	private static final float life = 6;
	private static final float accuracy = 0;
	private static final int powerUpType = 0;

	public Phaser(final Vector2 direction, final float reloadTime) {
		super(Phaser.name, Phaser.damage, Phaser.accuracy, reloadTime, 0,
				reloadTime, Phaser.life, Phaser.shotSpeed, direction, false, powerUpType);
	}
 
	public Phaser(final Vector2 direction, final float reloadTime,
			final int magazineSize, final float magazineReloadTime) {
		super(Phaser.name, Phaser.damage, 0, reloadTime, magazineSize,
				magazineReloadTime, Phaser.life, Phaser.shotSpeed, direction,
				false, powerUpType);
	}

	
	@Override
	protected boolean fire(final Vector2 position) {
		GameObject g = PrefabFactory.createShot("phaser", position,
				this.shotSpeedVector, this.tags,
				this.baseDamage, this.powerLevel, Phaser.life);


		GameObject.create(g);
		return true;
	}
}
