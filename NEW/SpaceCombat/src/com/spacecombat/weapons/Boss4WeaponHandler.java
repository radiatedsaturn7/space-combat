package com.spacecombat.weapons;

import com.spacecombat.Component;
import com.spacecombat.game.HealthController;

public class Boss4WeaponHandler extends Component {
	private final Weapon [] w;
	private final HealthController hc;

	public Boss4WeaponHandler(final Weapon [] w, final HealthController hc) {
		this.w = w;
		this.hc = hc;
	}

	@Override
	public void update() {
		for (int x = 0; x < w.length; x++)
		{
			float percentage = ((float)hc.health) / ((float)hc.maxHealth);
			if (x < 6)
			{
				if (this.w[x] != null && this.w[x].canShoot()) {
					this.w[x].shoot();
				}
			}			
			
			if (percentage < .66 && x < 11)
			{
				if (this.w[x] != null && this.w[x].canShoot()) {
					this.w[x].shoot();
				}
			}
			
			if (percentage < .33 && x < 12)
			{
				if (this.w[x] != null && this.w[x].canShoot()) {
					this.w[x].shoot();
				}
			}
		}
	}
}
