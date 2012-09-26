package com.spacecombat.game;

import java.util.Arrays;

import com.spacecombat.Audio;
import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Tags;
import com.spacecombat.Time;

public class HealthController extends Component {
	public int health;
	public int maxHealth;
	public boolean dying = false;
	public boolean addedTag = false;
	private Audio audio;

	private final static String powerUpTag = "PowerUp";
		
	public HealthController (Audio a) 
	{
		audio = a;
	}
	
	public void destroy ()
	{
		if (audio != null)
		{
			audio.destroy();
		}
	}
	public void collide(final GameObject whatIHit) {
		
		if (!whatIHit.hasTag(this.gameObject.getTags())) {
			final ShotCollision sc = (ShotCollision) whatIHit.getComponent(ShotCollision.class);					

			if (sc != null)
			{				
				this.health -= sc.getDamage();
			}
			
			if (this.health <= 0 && !this.dying) 
			{
				if (audio != null)
				{
					audio.playOnce();
				}
				
				this.dying = true;				
				this.gameObject.playAnimation("death");
				this.gameObject.destroyAfter(this.gameObject.getCurrentAnimation().getDuration());
			}
		}
				
		if (whatIHit.hasTag(Tags.powerup)) {
			final PowerUp powerUp = (PowerUp) whatIHit.getComponent(PowerUp.class);

			if (powerUp != null && powerUp.type == 7)
			{
				this.health = this.maxHealth;
			}
		}
	}

	@Override
	public void onAfterUpdate ()
	{
		//shield recharger
		if (this.gameObject.getName().equals(Tags.player))
		{			
			this.health += 2 * Time.getDeltaTime();
			if (this.health > this.maxHealth)
			{
				this.health = this.maxHealth;
			}
		}

		if (this.dying && !this.addedTag)
		{
			if (this.gameObject.hasTag(Tags.enemy))
			{
				PlayerData.score += this.maxHealth;
			}
			this.gameObject.addTag(Tags.dying);
			this.addedTag = true;
		}
	}

	public int getHealth ()
	{
		return health;
	}
	
	public int getMaxHealth ()
	{
		return maxHealth;
	}
	
	public void setHealth(final int health) {
		this.health = health;
		this.maxHealth = health;
	}
	
	public void setMaxHealth(int maxHealth)
	{
		this.maxHealth = maxHealth;
	}
}
