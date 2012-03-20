package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.Time;
import com.spacecombat.Util;

public class PowerUp extends Component  
{
	public float nextChange = 0.0f;
	public float changeTime = 2.0f;
	public boolean canChange = true;
	
	public float movementTime = 2.0f;
	public float nextMovementChange = 0.0f;
		
	public int type;
	public final int maxTypes = 2;
	
	public SimpleMovement sm;
	
	public PowerUp (SimpleMovement sm, int type, boolean canChange)
	{
		this.sm = sm;
		this.type = type;
		this.canChange = canChange;
				
		if (Util.randomNumber(0, 1) == 1)
		{
			sm.setSpeed(-sm.getSpeedX(), sm.getSpeedY());
		}
	}
	
	public int getType ()
	{
		return type;
	}
	
	public void update ()
	{
		if (this.canChange && Time.getTime() > nextChange)
		{
			change();
		}
		
		if (Time.getTime() > nextMovementChange)
		{
			nextMovementChange = Time.getTime() + movementTime;
			
			sm.setSpeed(-sm.getSpeedX(), sm.getSpeedY());
		}
	}
	
	public void change ()
	{
		nextChange = Time.getTime() + changeTime;		
		type++;
		
		if (type > maxTypes)
		{
			type = 0;
		}
		
		if (type == 0)
		{
			gameObject.playAnimation("PowerUp");
		}
		if (type == 1)
		{
			gameObject.playAnimation("Health");
		}
		if (type == 2)
		{
			gameObject.playAnimation("Missile");
		}
	}
}