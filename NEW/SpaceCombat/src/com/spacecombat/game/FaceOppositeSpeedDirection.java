package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.Pool;
import com.spacecombat.Poolable;
import com.spacecombat.RigidBody;

public class FaceOppositeSpeedDirection extends Component {
	private RigidBody rigidBody;
	
	public FaceOppositeSpeedDirection (final RigidBody r)
	{
		this.rigidBody = r;
	}

	@Override
	public void update() {
		this.gameObject.transform.rotation.x = rigidBody.speed.getAngle() + 180; 
		//System.out.println("ROT:"+this.gameObject.transform.rotation.x);
	}
}
