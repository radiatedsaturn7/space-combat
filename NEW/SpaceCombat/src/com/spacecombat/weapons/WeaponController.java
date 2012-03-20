package com.spacecombat.weapons;

import com.spacecombat.ClickListener;
import com.spacecombat.Collision;
import com.spacecombat.Component;
import com.spacecombat.Input;
import com.spacecombat.Time;
import com.spacecombat.game.PowerUp;

public class WeaponController extends Component implements ClickListener {
	public Weapon [] weapons;
	public int selectedWeapon = 0;
	
	public float nextWeaponSelect = 0.0f;
	public float weaponSelectTime = 1.0f;
	
	
	public WeaponController (int x, Weapon [] weapons)
	{
		this.selectedWeapon = x;
		this.weapons = weapons;
		Input.subscribeListener(this);
	}

	@Override
	public void collide(final Collision collision) {
		
		if (collision.getWhatIHit().hasTag(new String [] {"PowerUp"})) {
			
			final PowerUp powerUp = (PowerUp) collision.getWhatIHit().getComponent(PowerUp.class);
			
			if (powerUp != null && weapons != null)
			{
				weapons[selectedWeapon].powerUp();					
			}

			collision.getWhatIHit().destroy();
		}
	}

	@Override
	public void onClick(float x, float y) 
	{		
		if (Time.getTime() < nextWeaponSelect)
		{
			return;
		}
		
		if (y > 700)
		{
			nextWeaponSelect = weaponSelectTime + Time.getTime(); 
					
			selectedWeapon++;
			if (selectedWeapon >= weapons.length)
			{
				selectedWeapon = 0;
			}
			
			for (int z = 0; z < weapons.length; z++)
			{
				weapons[z].setEnabled(false);
			}
			
			weapons[selectedWeapon].setEnabled(true);
		}
	}
	
	public Weapon getSelectedWeapon()
	{
		return weapons[selectedWeapon];
	}
}