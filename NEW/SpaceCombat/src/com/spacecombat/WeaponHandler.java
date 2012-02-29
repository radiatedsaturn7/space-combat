package com.spacecombat;

public class WeaponHandler extends Component 
{
	private Weapon w;
	
	public WeaponHandler (Weapon w)
	{
		this.w = w;
	}
		
	public void update ()
	{
		if (w != null && w.canShoot())
		{
			w.shoot();
		}
	}
}
