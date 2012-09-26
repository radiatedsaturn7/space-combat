package com.spacecombat.weapons;

import com.spacecombat.Component;
import com.spacecombat.game.HealthController;

public class Boss5WeaponHandler extends Component {
	private final Weapon [] w;
	private final HealthController hc;

	public Boss5WeaponHandler(final Weapon [] w, final HealthController hc) {
		this.w = w;
		this.hc = hc;
	}

	@Override
	public void update() {
		for (int x = 0; x < w.length; x++)
		{
			float percentage = ((float)hc.health) / ((float)hc.maxHealth);
			if (x < 16)
			{
				if (this.w[x] != null && this.w[x].canShoot()) {
					this.w[x].shoot();
				}
			}			
			
			if (percentage < .66 && x < 18)
			{
				if (this.w[x] != null && this.w[x].canShoot()) {
					this.w[x].shoot();
				}
			}
			
			if (percentage < .33 && x < 23)
			{
				if (this.w[x] != null && this.w[x].canShoot()) {
					this.w[x].shoot();
				}
			}
		}
	}
}
