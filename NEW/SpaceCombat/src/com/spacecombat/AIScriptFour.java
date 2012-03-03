package com.spacecombat;

public class AIScriptFour extends AIScript {

	private RigidBody rigidBody;
	
		private Vector3 accel = new Vector3(2,2,0);
		private Vector3 maxSpeed = new Vector3(64,160,0);
		private GameObject target;

		public AIScriptFour (String [] targets)
		{
			target = GameObject.findRandomByTags(targets);			
		}
		
		public void onCreate ()
		{		
			rigidBody = gameObject.getRigidBody();
		}
		
		private final int give = 8;
		public void update ()
		{
			if (rigidBody == null)
			{
				return;
			}
			if (target != null)
			{
				if (gameObject.transform.position.x > target.transform.position.x + give)
				{
					if (rigidBody.speed.x > -maxSpeed.x)
					{
						rigidBody.speed.x-=accel.x;
					}
				}
				else if (gameObject.transform.position.x < target.transform.position.x - give)
				{
					if (rigidBody.speed.x < maxSpeed.x)
					{
						rigidBody.speed.x+=accel.x;
					}
				}
				else
				{
					if (rigidBody.speed.x < 0)
					{
						rigidBody.speed.x+=accel.x;
					}
					else if (rigidBody.speed.x > 0)
					{
						rigidBody.speed.x-=accel.x;
					}
				}
			}
			
			if (rigidBody.speed.y < maxSpeed.y)
			{
				rigidBody.speed.y+=accel.y;
			}
		}
}
