package com.spacecombat.game;

import com.spacecombat.BoxCollider;
import com.spacecombat.Collider;
import com.spacecombat.Component;
import com.spacecombat.GameObject;
import com.spacecombat.RigidBody;
import com.spacecombat.Vector2;

public class LoadLevelOnDestroy extends Component {

	private final String level;

	public LoadLevelOnDestroy (final String level) 
	{
		this.level = level;
	}

	boolean fired = false;
	@Override
	public void destroy ()
	{
		if (!fired)
		{			
			fired = true;
			final LoadLevelAfter lloc = new LoadLevelAfter(level,5);
			//final FixedJoint fj = new FixedJoint(level);

			final GameObject spawner = new GameObject();
			final RigidBody r = new RigidBody();
			final Collider c = new BoxCollider(new Vector2(800,64));
			r.setCollider(c);
			spawner.setRigidBody(r);				
			spawner.transform.position.x = this.gameObject.transform.position.x;
			spawner.transform.position.y = this.gameObject.transform.position.y-32;
			spawner.addComponent(lloc);				
			GameObject.create(spawner);

		}
	}
}
