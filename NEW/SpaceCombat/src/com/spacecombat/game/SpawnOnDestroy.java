package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;

public class SpawnOnDestroy extends Component {
	
	private GameObject go;
	private boolean isFired;
	
	public SpawnOnDestroy (GameObject go) 
	{
		this.go = go;
		this.isFired = false;
	}

	public void  onBeforeDestroy ()
	{
		if (isFired)
		{
			return;
		}

		isFired = true;

		System.out.println("Creating " + go.getName());
		GameObject.create(go);
		
		gameObject.destroy();
	}
}
