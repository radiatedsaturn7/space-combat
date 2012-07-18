package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;

public class HealthController extends Component {
	public int health;
	public int maxHealth;
	public boolean dying = false;
	public boolean addedTag = false;

	private final static String powerUpTag = "PowerUp";
	@Override
	public void collide(final GameObject whatIHit) {		
		if (!whatIHit.hasTag(this.gameObject.getTags())) {

			final ShotCollision sc = (ShotCollision) whatIHit.getComponent(ShotCollision.class);					

			if (sc != null)
			{
				this.health -= sc.getDamage();
			}

			if (this.health <= 0 && !this.dying) 
			{
				this.dying = true;				
				this.gameObject.playAnimation("death");
				this.gameObject.destroyAfter(this.gameObject.getCurrentAnimation().getDuration());
			}
		}
				
		if (whatIHit.hasTag(powerUpTag)) {
			final PowerUp powerUp = (PowerUp) whatIHit.getComponent(PowerUp.class);

			if (powerUp != null && powerUp.type == 1)
			{
				this.health = this.maxHealth;
			}
		}
	}

	@Override
	public void onAfterUpdate ()
	{
		if (this.dying && !this.addedTag)
		{
			this.gameObject.addTag("dying");
			this.addedTag = true;
		}
	}

	public void setHealth(final int health) {
		this.health = health;
		this.maxHealth = health;
	}
}
