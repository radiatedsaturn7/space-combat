package com.spacecombat;

public class RigidBody extends Component 
{	
	public Vector3 speed = new Vector3(0,0,0);
	public Collider collider = null;	
	
	public void update ()
	{	
		//System.out.println(speed + " * " + Time.getDeltaTime());
		gameObject.transform.position.x += (((float)speed.x) * Time.getDeltaTime());
		gameObject.transform.position.y += (((float)speed.y) * Time.getDeltaTime());
		gameObject.transform.position.z += (((float)speed.z) * Time.getDeltaTime());				
	}
	
	public void setCollider (Collider collider)
	{
		this.collider = collider;
		collider.setRigidBody(this);
	}
	
	public Collider getCollider ()
	{
		return this.collider;
	}
	
	public String toString ()
	{
		StringBuffer s = new StringBuffer();
		//
		if (gameObject != null)
		{
			s.append("RigidBody.position=");
			s.append(gameObject.transform.position);
			s.append("\n");
		}
		
		s.append("RigidBody.speed=");
		s.append(speed.toString());
		s.append("\n");
		return s.toString();
	}
}
