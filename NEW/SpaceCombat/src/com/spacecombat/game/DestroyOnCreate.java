package com.spacecombat.game;

import com.spacecombat.Component;

public class DestroyOnCreate extends Component {
	public float destroyAfter;
	public DestroyOnCreate (float l)
	{
		destroyAfter = l;
	}
	
	public void onCreate ()
	{
		gameObject.destroyAfter(destroyAfter);
	}
}
