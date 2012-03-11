package com.spacecombat;

public class WeaponHandler extends Component {
	private final Weapon w;

	public WeaponHandler(final Weapon w) {
		this.w = w;
	}

	@Override
	public void update() {
		if (this.w != null && this.w.canShoot()) {
			this.w.shoot();
		}
	}
}
