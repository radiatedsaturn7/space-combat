package com.spacecombat;

public class Laser extends Weapon {
	private static final String name = "laser";
	private static final float damage = 10;
	private static final float reloadTime = .5f;
	private static final float shotSpeed = 128;
	private static final float life = 5;
	private static final float accuracy = 32;
	private static final int magazineSize = 3;
	private static final float magazineReloadTime = 2;

	public Laser(final Vector2 direction) {
		super(Laser.name, Laser.damage, Laser.accuracy, Laser.reloadTime,
				Laser.magazineSize, Laser.magazineReloadTime, Laser.life,
				Laser.shotSpeed, direction, true);
	}

	@Override
	protected void fire(final Vector2 position) {
		GameObject.create(PrefabFactory.createShot("laser", position,
				this.shotSpeedVector, this.gameObject.getTags(),
				this.baseDamage, this.powerLevel, Laser.life));
	}
}
