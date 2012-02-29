package com.spacecombat;

public class Vector3
{
    public float x = 0;
    public float y = 0;
    public float z = 0;

    public Vector3 () {}
    public Vector3(float x, float y, float z)
    {
    	this.x = x;
    	this.y = y;
    	this.z = z;
    }
    
    public Vector3(Vector3 v)
    {
    	this.x = v.x;
    	this.y = v.y;
    	this.z = v.z;
    }
    
    public String toString ()
    {
    	return "(" + x + ", " + y + ", " + z +")";
    }
    
    public Vector3 toNormalize ()
    {
    	float l = (float)Math.sqrt(x*x + y*y + z*z);
    	return new Vector3(x/l,y/l,z/l);
    }
    
    public void normalize()
    {
    	float l = (float)Math.sqrt(x*x + y*y + z*z);
    	x = x/l;
    	y = y/l;
    	z = z/l;
    	
    }
}