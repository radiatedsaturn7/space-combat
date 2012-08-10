package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Pool;
import com.spacecombat.Poolable;
import com.spacecombat.RigidBody;
import com.spacecombat.Time;

public class RotateEachSecond extends Component {
	private float degreesPerSec;
	
	public RotateEachSecond (float degreesPerSec)
	{
		this.degreesPerSec = degreesPerSec;
	}

	@Override
	public void update() {
		this.gameObject.transform.rotation.x += degreesPerSec * Time.getDeltaTime();
	}
}
