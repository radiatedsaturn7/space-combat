package com.spacecombat;

public class AIScriptTwo extends AIScript
{

	private RigidBody rigidBody;		
	private Vector3 maxSpeed = new Vector3(32,32,0);	
	//private int count = 0;
	//private int maxCount = 120;
	private boolean isReverse = false;
	
	private Vector3 maxPosition = new Vector3(480-32,400,0);

	public AIScriptTwo (boolean isReverse)
	{
		this.isReverse = isReverse;
	}
	
	public void onCreate ()
	{
		rigidBody = gameObject.getRigidBody();	
	}
	
	public void update ()
	{
		if (rigidBody == null)
		{
			rigidBody = gameObject.getRigidBody();	
		}
		
		if (!isReverse)
		{
			if (gameObject.transform.position.y < maxPosition.y)
			{
				if (rigidBody.speed.x > 0)
				{
					rigidBody.speed.x=0;
				}
				if (rigidBody.speed.y < maxSpeed.y)
				{
					rigidBody.speed.y=maxSpeed.y;
				}
			}
			else if (gameObject.transform.position.x < maxPosition.x)
			{
				if (rigidBody.speed.x < maxSpeed.x)
				{
					rigidBody.speed.x=maxSpeed.x;
				}
				if (rigidBody.speed.y > 0)
				{
					rigidBody.speed.y=0;
				}
			}
			else
			{
				if (rigidBody.speed.x > 0)
				{
					rigidBody.speed.x=0;
				}
				if (rigidBody.speed.y < maxSpeed.y)
				{
					rigidBody.speed.y=maxSpeed.y;
				}
			}
		}
		else if (isReverse)
		{
			if (gameObject.transform.position.y < maxPosition.y)
			{
				if (rigidBody.speed.x > 0)
				{
					rigidBody.speed.x=0;
				}
				if (rigidBody.speed.y < maxSpeed.y)
				{
					rigidBody.speed.y=maxSpeed.y;
				}
			}
			else if (gameObject.transform.position.x > 0)
			{
				if (rigidBody.speed.x > -maxSpeed.x)
				{
					rigidBody.speed.x=-maxSpeed.x;
				}
				if (rigidBody.speed.y > 0)
				{
					rigidBody.speed.y=0;
				}
			}
			else
			{
				if (rigidBody.speed.x < 0)
				{
					rigidBody.speed.x=0;
				}
				if (rigidBody.speed.y < maxSpeed.y)
				{
					rigidBody.speed.y=maxSpeed.y;
				}
			}
		}
	}
}
