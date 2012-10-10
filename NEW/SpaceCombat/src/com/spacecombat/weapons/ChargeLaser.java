package com.spacecombat.weapons;

import com.spacecombat.ClickListener;
import com.spacecombat.GameObject;
import com.spacecombat.Input;
import com.spacecombat.Time;
import com.spacecombat.Vector2;
import com.spacecombat.game.PrefabFactory;

public class ChargeLaser extends Weapon {

	private static final String name = "laser";
	private static final float damage = 100;
	private static final float reloadTime = .1f;
	private static final float shotSpeed = 256;
	private static final float life = 5;
	private static final float accuracy = 0;
	private static final int magazineSize = 3;
	private static final float magazineReloadTime = .01f;
	private static final int powerUpType = 6;
	private static float baseChargeTime = 2.0f;
	
	private static float chargeRate = 1;
	private float lastShot;

	public ChargeLaser(final Vector2 direction) {
		super(ChargeLaser.name, ChargeLaser.damage, ChargeLaser.accuracy, ChargeLaser.reloadTime,
				ChargeLaser.magazineSize, ChargeLaser.magazineReloadTime, ChargeLaser.life,
				ChargeLaser.shotSpeed, direction, false, powerUpType);
	}

	@Override
	protected boolean fire(final Vector2 position) {
		boolean fired = false;
		float charge = getCharge();
		
		int tempPowerLevel = powerLevel;
		boolean isOdd = false;
		if (powerLevel % 2 == 1)
		{
			tempPowerLevel = powerLevel - 1;
			isOdd = true;
		}
		
		tempPowerLevel /= 2;
		position.x -= 32 * tempPowerLevel;
		if (!isOdd)
			position.x += 16;
		
		int workingPowerLevel = getMaxCharge();
		boolean adding = false;
		boolean firstAdd = true;
		
		//System.out.println("CHARGE SHOT");
	
		for (int x = 0; x < powerLevel; x++)
		{
			if (adding)
			{
				if (!isOdd && firstAdd)
				{
					//this makes it zero next time around
					workingPowerLevel = -1;
					firstAdd = false;
				}
				workingPowerLevel++;
			}
			else
			{
				workingPowerLevel--;
				if (workingPowerLevel == 0)
				{
					adding = true;
				}
			}
			
			//System.out.println(workingPowerLevel);
			if (charge >= baseChargeTime + workingPowerLevel)
			{
				fired = true;
				GameObject.create(PrefabFactory.createShot("chargeLaser", position,
						this.shotSpeedVector, this.tags,
						this.baseDamage + (10 * (this.powerLevel-1)), this.powerLevel, ChargeLaser.life));
				
			}
			position.x += 32; 
		}
		lastShot = Time.getTime();
		return fired;
	}
	
	public void powerUp()
	{
		super.powerUp();
		//this.chargeRate += .1;
	}
	
	public float getCharge ()
	{
		float charge = 0;
		float time = Time.getTime() - lastShot;
		charge = chargeRate * time;
		return charge;
	}
	
	public int getMaxCharge ()
	{
		boolean isOdd = false;
		if (powerLevel % 2 == 1)
		{
			isOdd = true;
		}
		
		int workingPowerLevel = (int) Math.floor(((float)powerLevel)/2.0f);
		if (isOdd){
		workingPowerLevel += 1;
		}
		return workingPowerLevel;
	}
	
	public float getChargePercentage()
	{
		float percentage = 0.0f;
		percentage = getCharge() / (((float) baseChargeTime) + ((float)getMaxCharge())-1);
		
		//System.out.println("CHARGE PERCENTAGE:");
		//System.out.println(percentage + " = " + getCharge() + " / (" + baseChargeTime + " + " + getMaxCharge() + ")");
		
		if (percentage > 1)
			percentage = 1;
		return percentage;
	}
}
