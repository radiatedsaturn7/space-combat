package com.spacecombat;

public class MovementUpdater extends Component 
{
	public void update ()
	{
		if (gameObject != null)
		{
			gameObject.transform.rotation.x+=1;
			//gameObject.transform.rotation.y+=.3;
			//gameObject.transform.rotation.z+=.4;
			
			gameObject.transform.position.x+=.2;
			//gameObject.transform.position.y+=.3;
			//gameObject.transform.position.z+=.4;						
		}
		
	}
}
