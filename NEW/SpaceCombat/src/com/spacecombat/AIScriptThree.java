package com.spacecombat;

public class AIScriptThree extends AIScript 
{
	private RigidBody rigidBody;	
	private Vector3 accel = new Vector3(2,2,0);
	private Vector3 maxSpeed = new Vector3(32,32,0);

	public AIScriptThree (boolean isReverse)
	{
		if (isReverse)
		{
			maxSpeed.y = maxSpeed.y * .5f;
		}
	}
	
	public void onCreate ()
	{		
		rigidBody = gameObject.getRigidBody();
	}
	
	public void update ()
	{
		if (rigidBody == null)
		{
			return;
		}
		
		if (rigidBody.speed.y < maxSpeed.y)
		{
			rigidBody.speed.y+=accel.y;
		}
	}
}
