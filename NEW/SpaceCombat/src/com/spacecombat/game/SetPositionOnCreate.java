package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.Vector2;

public class SetPositionOnCreate extends Component {

	private final Vector2 position;

	public SetPositionOnCreate(final Vector2 position) 
	{
		this.position = position;
	}

	@Override
	public void onCreate ()
	{
		this.gameObject.transform.position = new Vector2(this.position.x,this.position.y);
	}
}
