package com.spacecombat.game;

import com.spacecombat.Component;

public class PositionEchoer extends Component {
	public void update ()
	{
		System.out.println(gameObject.getName() + " AT " + gameObject.transform.position);
	}
}
