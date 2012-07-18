package com.spacecombat.game;


import com.spacecombat.Component;
import com.spacecombat.GameObject;

public class ShotCollision extends Component {
	public float damage = 1;

		
	@Override
	public void collide(final GameObject whatIHit) {

		if (whatIHit.getName().equalsIgnoreCase("TopOfScreen") || whatIHit.hasTag("shot") || whatIHit.hasTag("node") || whatIHit.hasTag("powerup") || whatIHit.hasTag("powerup") || whatIHit.hasTag("dying")) {
			return;
		}

		if (!(whatIHit.hasTag(this.gameObject.getTags()))) {
			this.gameObject.destroy();
		}
	}

	public float getDamage() {
		return this.damage;
	}

	public void setDamage(final float damage) {
		this.damage = damage;
	}
}
