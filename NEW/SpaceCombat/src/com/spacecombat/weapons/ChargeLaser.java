package com.spacecombat.weapons;

import com.spacecombat.ClickListener;
import com.spacecombat.GameObject;
import com.spacecombat.Input;
import com.spacecombat.Time;
import com.spacecombat.Vector2;
import com.spacecombat.game.PrefabFactory;

public class ChargeLaser extends Weapon {

	private static final String name = "laser";
	private static final float damage = 100;
	private static final float reloadTime = .1f;
	private static final float shotSpeed = 256;
	private static final float life = 5;
	private static final float accuracy = 0;
	private static final int magazineSize = 3;
	private static final float magazineReloadTime = .01f;
	private static final int powerUpType = 6;
	
	private static float charge = 0;
	private static float chargeRate = 1;
	private float lastShot;

	public ChargeLaser(final Vector2 direction) {
		super(ChargeLaser.name, ChargeLaser.damage, ChargeLaser.accuracy, ChargeLaser.reloadTime,
				ChargeLaser.magazineSize, ChargeLaser.magazineReloadTime, ChargeLaser.life,
				ChargeLaser.shotSpeed, direction, false, powerUpType);
	}

	@Override
	protected boolean fire(final Vector2 position) {
		float time = Time.getTime() - lastShot;
		lastShot = Time.getTime();
		charge = chargeRate * time;
		boolean fired = false;
		
		if (charge >= 2)
		{
			fired = true;
			GameObject.create(PrefabFactory.createShot("chargeLaser", position,
					this.shotSpeedVector, this.tags,
					this.baseDamage + (10 * (this.powerLevel-1)), this.powerLevel, ChargeLaser.life));
		}
		if (charge >= 4 && powerLevel > 4)
		{
			position.x -= 32;
			GameObject.create(PrefabFactory.createShot("chargeLaser", position,
					this.shotSpeedVector, this.tags,
					this.baseDamage + (10 * (this.powerLevel-1)), this.powerLevel, ChargeLaser.life));
			position.x += 64;
			GameObject.create(PrefabFactory.createShot("chargeLaser", position,
					this.shotSpeedVector, this.tags,
					this.baseDamage + (10 * (this.powerLevel-1)), this.powerLevel, ChargeLaser.life));
			position.x -= 32;
		}
		if (charge >= 6 && powerLevel > 8)
		{
			position.x -= 64;
			GameObject.create(PrefabFactory.createShot("chargeLaser", position,
					this.shotSpeedVector, this.tags,
					this.baseDamage + (10 * (this.powerLevel-1)), this.powerLevel, ChargeLaser.life));
			position.x += 128;
			GameObject.create(PrefabFactory.createShot("chargeLaser", position,
					this.shotSpeedVector, this.tags,
					this.baseDamage + (10 * (this.powerLevel-1)), this.powerLevel, ChargeLaser.life));			
		}
		
		return fired;
	}
	
	public void powerUp()
	{
		super.powerUp();
		this.chargeRate += .1;
	}
}
