package com.spacecombat.game;

import com.spacecombat.Component;
import com.spacecombat.Vector2;

public class SetPositionOnCreate extends Component {

	private Vector2 position;
	
	public SetPositionOnCreate(Vector2 position) 
	{
		this.position = position;
	}
	
	public void onCreate ()
	{
		gameObject.transform.position = new Vector2(position.x,position.y);
		System.out.println(gameObject.getName() + " Set position to " + gameObject.transform.position);
	}
}