package com.spacecombat;

public class Transform 
{
    public Vector3 position;
    public Vector3 rotation;
    public Vector3 scale;

	public Transform ()
	{
	    position = new Vector3(0,0,0);
	    rotation = new Vector3(0,0,0);
	    scale = new Vector3(1,1,1);
	}
}