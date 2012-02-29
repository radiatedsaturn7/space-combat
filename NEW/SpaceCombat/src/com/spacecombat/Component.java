package com.spacecombat;

public class Component 
{
	protected GameObject gameObject = null;	
	protected boolean isEnabled = true;
		
	public void onCreate () {}
	public void onStart () {}
	public void update () {}
	public void draw () {}
	
	public void onBeforeDestroy() {}
	
	public void destroy () 
	{
		if (gameObject != null)
		{
			gameObject.removeComponent(this);
		}
	}
	
	public void setEnabled (boolean enabled)
	{
		isEnabled = enabled;
	}
	
	public boolean isEnabled ()
	{
		return isEnabled;
	}
	
	public void collide (Collision collision) {}	
	public void setGameObject(GameObject o) { gameObject = o; }
}
