package com.spacecombat;

public class DestroyOnOutOfBounds extends Component 
{
	public void update ()
	{
		if (gameObject.transform.position.y > 128)
		{
			gameObject.destroy();
		}
		
		if (gameObject.transform.position.y < 128)
		{
			gameObject.destroy();
		}
		
		if (gameObject.transform.position.x > 528)
		{
			gameObject.destroy();
		}
		
		if (gameObject.transform.position.x < -128)
		{
			gameObject.destroy();
		}
	}
}
