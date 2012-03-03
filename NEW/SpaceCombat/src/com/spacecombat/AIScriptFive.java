package com.spacecombat;

public class AIScriptFive extends AIScript {

	private RigidBody rigidBody;
	
		private Vector3 accel = new Vector3(2,2,0);
		private Vector3 maxSpeed = new Vector3(32,32,0);
		private GameObject target;

		public AIScriptFive (String [] targets)
		{
			target = GameObject.findRandomByTags(targets);			
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
			
			if (target != null)
			{
				gameObject.transform.position.x = target.transform.position.x;
			}
			
			if (rigidBody.speed.y < maxSpeed.y)
			{
				rigidBody.speed.y+=accel.y;
			}
		}
}
