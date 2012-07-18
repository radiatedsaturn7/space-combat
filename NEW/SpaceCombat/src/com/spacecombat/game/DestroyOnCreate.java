package com.spacecombat.game;

import com.spacecombat.Component;

public class DestroyOnCreate extends Component {
	public float destroyAfter;
	public DestroyOnCreate (final float l)
	{
		this.destroyAfter = l;
	}

	@Override
	public void onCreate ()
	{
		this.gameObject.destroyAfter(this.destroyAfter);
	}
}
