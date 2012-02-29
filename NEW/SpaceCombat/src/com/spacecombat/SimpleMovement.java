package com.spacecombat;

public class SimpleMovement extends Component 
{
	private Vector3 speed;
	private RigidBody rigidBody;
		
	public void setSpeed (Vector3 speed)
	{
		this.speed = speed;		
	}
	
	public void update ()
	{
		if (rigidBody == null)
		{
			rigidBody = gameObject.getRigidBody();
			return;
		}
		
		rigidBody.speed.x = speed.x;
		rigidBody.speed.y = speed.y;
		rigidBody.speed.z = speed.z;
	}
}
