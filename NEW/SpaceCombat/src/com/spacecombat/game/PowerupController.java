package com.spacecombat.game;

import com.spacecombat.Camera;
import com.spacecombat.ClickListener;
import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Input;
import com.spacecombat.Tags;
import com.spacecombat.Time;
import com.spacecombat.Util;
import com.spacecombat.Vector2;
import com.spacecombat.weapons.Weapon;
import com.spacecombat.weapons.WeaponController;

public class PowerupController extends Component {
	public WeaponController [] weapons = null;
	public boolean createAlly = false;
	
	public PowerupController (final WeaponController [] weapons)
	{
		if (weapons == null)
		{
			throw new RuntimeException("can't have null weapons");
		}
		this.weapons = weapons;
	}
	
	private final static int powerUpTag = Tags.powerup;
	@Override
	public void collide(final GameObject whatIHit) {
		if (whatIHit.hasTag(powerUpTag)) {			
			final PowerUp powerUp = (PowerUp) whatIHit.getComponent(PowerUp.class);
			
			if (weapons == null)
			{
				return;
			}
			
			for (int x = 0; x < this.weapons.length; x++)
			{
				if (powerUp == null || this.weapons == null || this.weapons[x] == null)
				{
					continue;
				}
				
				for (int y = 0; y < weapons[x].weapons.length; y++)
				{
					if (powerUp.type == this.weapons[x].weapons[y].getPowerUpType())
					{
						this.weapons[x].selectedWeapon = y;
						this.weapons[x].getSelectedWeapon().powerUp();						
					}
				}
			}
			
			if (powerUp != null)
			{
				//createAlly = true;
			}	
		}
	}
	
	public void update ()
	{
		if (createAlly)
		{
			System.out.println("creating ally!");
			int type = Util.randomNumber(0, 5);
			int gun = Util.randomNumber(0, 3);
			
			String sType = "pariah";
			String sGun = "laser";
			
			if (type == 0)
				sType = "calumniator";
			if (type == 1)
				sType = "exemplar";
			if (type == 2)			
				sType = "paladin";
			if (type == 3)			
				sType = "pariah";
			if (type == 4)		
				sType = "sentinel";
			if (type == 5)			
				sType = "renegade";

			if (gun == 0)
				sGun = "laser";
			if (gun == 1)
				sGun = "machinegun";
			if (gun == 2)
				sGun = "flamethrower";
			if (gun == 3)
				sGun = "pulsecannon";
			
			System.out.println("Creating:"+sType+" "+sGun);
			GameObject.create(PrefabFactory.createAlly("renegade", new Vector2(200,800+Camera.mainCamera.gameObject.transform.position.y), sType, 5, sGun));
			createAlly = false;
		}
	}
}
