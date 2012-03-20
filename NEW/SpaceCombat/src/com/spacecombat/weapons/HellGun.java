package com.spacecombat.weapons;

import com.spacecombat.GameObject;
import com.spacecombat.Util;
import com.spacecombat.Vector2;
import com.spacecombat.game.PrefabFactory;

public class HellGun extends Weapon {

	private static final String name = "HellGun";
	private static final float damage = 5;
	private static final float reloadTime = 1f;
	private static final float shotSpeed = 0;
	private static final float life = .3f;
	private static final float accuracy = 0;
	private static final int magazineSize = 0;
	private static final float magazineReloadTime = 1;

	public HellGun(final Vector2 direction) {
		super(HellGun.name, HellGun.damage, HellGun.accuracy,
				HellGun.reloadTime, HellGun.magazineSize,
				HellGun.magazineReloadTime, HellGun.life,
				HellGun.shotSpeed, direction, true);
	}

	@Override
	protected void fire(Vector2 position) {

		int draw = 4;
		int count = 0;
		
		int boom = 0;
		float originalX = gameObject.transform.position.x;

		for (float y = gameObject.transform.position.y; y > 0; y-=32)
		{
			gameObject.transform.position.x = originalX;
			if (this.powerLevel > 2 * count && count >= 1 && draw > 0)
			{
				draw--;
			}

			this.shotSpeedVector.y = -32;

			count++;
			position.y -= 32;
			GameObject.create(PrefabFactory.createShot("hell", position,
					this.shotSpeedVector, this.gameObject.getTags(),
					this.baseDamage + (25 * this.powerLevel), draw, HellGun.life));
			
			if (count % 5 == 0)
			{
				boom++;
			}
			
			for (int x = 0; x < boom; x++)
			{
				this.shotSpeedVector.x = Util.randomNumber(0, 32)-16;				
				GameObject.create(PrefabFactory.createShot("hell", position,
						this.shotSpeedVector, this.gameObject.getTags(),
						this.baseDamage + (25 * this.powerLevel), draw, HellGun.life));
			}
		}
	}

}
