package com.spacecombat;

public class BoxCollider extends Collider
{
	
	public Vector3 size = new Vector3();
	
	public BoxCollider (Vector3 size)
	{
		this.size = size; 
	}
		
	public boolean collidesWith (BoxCollider boxCollider)
	{
		if (rigidBody.gameObject == null)
		{
			throw new RuntimeException("gameObject is null -- can't perform collision");
		}
		
		if (boxCollider.getRigidBody().gameObject == null)
		{
			throw new RuntimeException("boxCollider.gameObject is null -- can't perform collision");			
		}
		
		
		
		if (rigidBody.gameObject.transform.position.x + size.x >= boxCollider.getRigidBody().gameObject.transform.position.x &&
			rigidBody.gameObject.transform.position.y + size.y >= boxCollider.getRigidBody().gameObject.transform.position.y &&
			rigidBody.gameObject.transform.position.x <= boxCollider.getRigidBody().gameObject.transform.position.x + boxCollider.size.x &&
			rigidBody.gameObject.transform.position.y <= boxCollider.getRigidBody().gameObject.transform.position.y + boxCollider.size.y)			
		{
				return true;
		}
		
		return false;
	}
}
