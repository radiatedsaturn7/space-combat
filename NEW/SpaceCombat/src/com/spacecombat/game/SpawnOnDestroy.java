package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;

public class SpawnOnDestroy extends Component {

	private final GameObject go;
	private boolean isFired;

	public SpawnOnDestroy (final GameObject go) 
	{
		this.go = go;
		this.isFired = false;
	}

	@Override
	public void  onBeforeDestroy ()
	{
		if (this.isFired)
		{
			return;
		}

		this.isFired = true;

		GameObject.create(this.go);

		this.gameObject.destroy();
	}
}
