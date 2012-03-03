package com.spacecombat;

public class ShotCollision extends Component
{
	public float damage = 1;
	
	public void setDamage (float damage)
	{
		this.damage = damage;
	}
	
	public float getDamage ()
	{
		return damage;
	}
	
	public void collide (Collision collision)
	{
		if (collision.getWhatIHit() == null)
		{
			//System.out.println("Something Wrong");
		}
		else
		{
			//System.out.println("Shot hit " + whatIHit.getName() );
		}
		
		if (collision.getWhatIHit().hasTag("shot"))
		{
			return;
		}
		
		if (!(collision.getWhatIHit().hasTag(collision.getMe().getTags())))
		{
			collision.getMe().destroy();
		}
	}
}
