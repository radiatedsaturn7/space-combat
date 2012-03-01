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
	private float searchTime = 1.0f;
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
		
		if (w != null && w.canShoot())
		{
			w.shoot();
		}
	}
	
	public boolean canSearch ()
	{
		return (Time.getTime() > nextSearch);
	}
	
	public void search ()
	{
		t = GameObject.findAllByTags(targets);
		
		if (t == null || t.size() == 0)
		{
			System.out.println("TARGETTING:NULL");
			w.setShootDirection(defaultDirection);
			go = null;			
			return;
		}
		
		int x = Util.RandomNumber(0, t.size()-1);
				
		go = t.get(x);
		System.out.println("TARGETTING:"+go.getName());
		
		temp.x = (go.transform.position.x - gameObject.transform.position.x);
		temp.y = (go.transform.position.y - gameObject.transform.position.y);
		temp.z = -(go.transform.position.z - gameObject.transform.position.z);
		
		w.setShootDirection(temp);
		
		nextSearch = Time.getTime() + searchTime;		
	}
}