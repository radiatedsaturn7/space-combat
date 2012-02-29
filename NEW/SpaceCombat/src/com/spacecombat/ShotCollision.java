package com.spacecombat;

public class ShotCollision extends Component
{
	public int damage = 1;
	
	public void setDamage (int damage)
	{
		this.damage = damage;
	}
	
	public int getDamage ()
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
