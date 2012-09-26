package com.spacecombat.game;


import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Tags;

public class ShotCollision extends Component {
	public float damage = 1;

		
	@Override
	public void collide(final GameObject whatIHit) {

		if (whatIHit.getName().equalsIgnoreCase("topOfScreen") || whatIHit.hasTag(Tags.topOfScreen | Tags.shot | Tags.node |Tags.powerup | Tags.dying))
		{
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
