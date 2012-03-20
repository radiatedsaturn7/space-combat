package com.spacecombat.game;

import com.spacecombat.Collision;
import com.spacecombat.Component;
import com.spacecombat.GameObject;

public class SpawnOnCollision extends Component {
	
	private GameObject go;
	private boolean isFired;
	
	public SpawnOnCollision (GameObject go) 
	{
		this.go = go;
		this.isFired = false;
	}

	public void  collide (final Collision collision)
	{
		if (collision.getWhatIHit().getName().equals("TopOfScreen"))
		{
			if (isFired)
			{
				return;
			}
			isFired = true;
			
			GameObject.create(go);
			gameObject.destroy();
		}
	}
}
