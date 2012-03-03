package com.spacecombat;

import java.util.List;

public class LockingWeaponHandler extends Component 
{
	private Weapon w;
	private GameObject go = null;
	private Vector3 defaultDirection;
	private Vector3 temp;
	private String [] targets = null;
	private List<GameObject> t;
	private float searchTime = 2.0f;
	private float nextSearch = 0.0f;
	
	public LockingWeaponHandler (Weapon w, String [] targets)
	{
		this.w = w;
		Vector3 t = new Vector3(w.getShotDirection());
		this.defaultDirection = t;
		this.targets = targets;
		temp = new Vector3();
	}
		
	public void update ()
	{
		if (go == null && canSearch())
		{
			search();
			if (go == null)
			{
				w.setShootDirection(defaultDirection);
			}
		}
		
		if (go != null)
		{
			calculateTrajectory();
		}
		
		if (w != null && w.canShoot())
		{
			w.shoot();
		}
	}
	
	public boolean canSearch ()
	{
		return (Time.getTime() > nextSearch);
	}
	
	public void calculateTrajectory ()
	{		
		temp.x = (go.transform.position.x - gameObject.transform.position.x);
		temp.y = (go.transform.position.y - gameObject.transform.position.y);
		temp.z = -(go.transform.position.z - gameObject.transform.position.z);
		
		temp.x -= gameObject.getRigidBody().speed.x;
		temp.y -= gameObject.getRigidBody().speed.y;
		temp.z -= gameObject.getRigidBody().speed.z;
		
		w.setShootDirection(temp);
	}
	
	public void search ()
	{
		nextSearch = Time.getTime() + searchTime;		
		t = GameObject.findAllByTags(targets);
		
		if (t == null || t.size() == 0)
		{
			System.out.println("TARGETTING:NULL");
			w.setShootDirection(defaultDirection);
			go = null;			
			return;
		}
		
		int x = Util.randomNumber(0, t.size()-1);
				
		go = t.get(x);				
	}
}