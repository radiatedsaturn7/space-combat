import java.awt.*;
import java.util.*;

public class Entity_AllySpawnPoint extends Entity
{
	public int m_iAllyNumberToSpawnHere;
	public Entity_AllySpawnPoint(Entity_AllySpawnPoint e)
	{
		super((Entity)(e));
		m_iAllyNumberToSpawnHere = e.m_iAllyNumberToSpawnHere;
	}
	public Entity_AllySpawnPoint(int x, int y, int w, int h, Point p, int i)
	{
		super(x,y,w,h,p);
		m_iAllyNumberToSpawnHere = i;
	}
	public void Update()
	{
		super.Update();
		int headunit = 0;
			
		AllyShip m = new AllyShip(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y), new Point(32,32), Util.m_mMain.GetImage("PSentinel.gif") ,1, false, false);
		if (m_iAllyNumberToSpawnHere % 5 == 0)
		{
			m = new AllyShip(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y), new Point(32,32), Util.m_mMain.GetImage( "PCalumniator.gif") ,1, false, false);
			m.AddImage(Util.m_mMain.GetImage( "PCalumniatorNV.gif"));
		}
		if (m_iAllyNumberToSpawnHere % 5 == 1)
		{
			m = new AllyShip(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y), new Point(32,32), Util.m_mMain.GetImage( "PExemplar.gif") ,1, false, false);
			m.AddImage(Util.m_mMain.GetImage( "PExemplarNV.gif"));
		}
		if (m_iAllyNumberToSpawnHere % 5 == 2)
		{
			m = new AllyShip(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y), new Point(32,32), Util.m_mMain.GetImage( "PPariah.gif") ,1, false, false);
			m.AddImage(Util.m_mMain.GetImage( "PPariahNV.gif"));
		}
		if (m_iAllyNumberToSpawnHere % 5 == 3)
		{
			m = new AllyShip(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y), new Point(32,32), Util.m_mMain.GetImage( "PPaladin.gif") ,1, false, false);
			m.AddImage(Util.m_mMain.GetImage( "PPaladinNV.gif"));
		}
		if (m_iAllyNumberToSpawnHere % 5 == 4)
		{
			m = new AllyShip(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y), new Point(32,32), Util.m_mMain.GetImage( "PRenegade.gif") ,1, false, false);
			m.AddImage(Util.m_mMain.GetImage( "PRenegadeNV.gif"));
		}

		ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("UP",1,1,false,3);
			AnimationList.add(a);
			a = new Animation("RIGHT",2,2,false,3);
			AnimationList.add(a);
			a = new Animation("DOWN",3,3,false,3);
			AnimationList.add(a);
			a = new Animation("LEFT",4,4,false,3);
			AnimationList.add(a);
			a = new Animation("IDLE",5,5,false,3);
			AnimationList.add(a);
			a = new Animation("UPRIGHT",6,6,false,3);
			AnimationList.add(a);
			a = new Animation("DOWNRIGHT",7,7,false,3);
			AnimationList.add(a);
			a = new Animation("UPLEFT",8,8,false,3);
			AnimationList.add(a);
			a = new Animation("DOWNLEFT",9,9,false,3);
			AnimationList.add(a);
			m.SetAnimations(AnimationList);
			m.PlayAnimation("IDLE");
		
		m.m_tWeaponRotateTime.AddSeconds(1);
		Weapon w = new GravityGun("GravityGun",100,50,0);
		w.m_tReloadTime = new Time();
		w.m_tReloadTime.AddMilliseconds(500);
		w.m_tMissileReloadTime.AddMilliseconds(1000);
		m.AddWeapon(w);
		
		w = new HellGun("HellGun",10,50,0);
		w.m_tReloadTime = new Time();
		w.m_tReloadTime.AddMilliseconds(1500);
		w.m_tMissileReloadTime.AddMilliseconds(1000);
		m.AddWeapon(w);
		
		w = new PulseLaser("PulseLaser",15,50,0);
		w.m_tReloadTime = new Time();
		w.m_tReloadTime.AddMilliseconds(300);
		w.m_tMissileReloadTime.AddMilliseconds(1000);
		m.AddWeapon(w);
		
		w = new Laser("Laser",15,50,0);
		w.m_tReloadTime = new Time();
		w.m_tReloadTime.AddMilliseconds(50);
		w.m_tMissileReloadTime.AddMilliseconds(1000);
		m.AddWeapon(w);
		
		w = new FlameThrower("FlameThrower",20,50,0);
		w.m_tReloadTime = new Time();
		w.m_tReloadTime.AddMilliseconds(50);
		w.m_tMissileReloadTime.AddMilliseconds(1000);
		m.AddWeapon(w);
		
		w = new MachineGun("MachineGun",10,50,0);
		w.m_tReloadTime = new Time();
		w.m_tReloadTime.AddMilliseconds(10);
		w.m_tMissileReloadTime.AddMilliseconds(1000);
		m.AddWeapon(w);
		
		m.SetWeapon("GravityGun");
		for (int i = 0; i < m_iAllyNumberToSpawnHere; i++)
			m.WeaponRotate();
		
		if (Util.m_iSetup[3] == 1)
		{
			m.m_iHealth = 50;
			m.m_iMaxHealth = 50;
		}
		if (Util.m_iSetup[3] == 2)
		{
			m.m_iHealth = 100;
			m.m_iMaxHealth = 100;
		}
		if (Util.m_iSetup[3] == 3)
		{
			m.m_iHealth = 150;
			m.m_iMaxHealth = 150;
		}
		if (Util.m_iSetup[3] == 4)
		{
			m.m_iHealth = 200;
			m.m_iMaxHealth = 200;
		}
		if (Util.m_iSetup[3] == 5)
		{
			m.m_iHealth = 300;
			m.m_iMaxHealth = 300;
		}
		if (Util.m_iSetup[3] == 6)
		{
			m.m_iHealth = 500;
			m.m_iMaxHealth = 500;
		}
		
		/*
		if (x % 5 == 0)
		{
			m.m_iFormation = 5;
			m.m_iRoamFormation = 5;
			m.m_iFormationID = x/3;
			m.m_iID = x;
			m.m_iFaction = 0;
			m.m_bHeadUnit = true;
			Util.m_alSprite.add(m);
			headunit = Util.m_alSprite.size()-1;
		}
		else
		{*/
		
			//int headunit = 0;
			if (Util.m_iNumOfPlayers != 0)
			{
				headunit = m_iAllyNumberToSpawnHere%Util.m_iNumOfPlayers;
				m.m_rcFollowBox = ((Sprite)(Util.m_alSprite.get(headunit))).m_rcBoundingBox;
			}
			m.m_rcFollowBox = ((Sprite)(Util.m_alSprite.get(headunit))).m_rcBoundingBox;
			m.m_iFormation = 5;
			m.m_iRoamFormation = 0;
			m.m_iFormationID = m_iAllyNumberToSpawnHere;
			m.m_iID = m_iAllyNumberToSpawnHere;
			m.m_iFaction = 0;
			Util.m_alSprite.add(m);
			Util.m_iNumOfAllys++;
		//}
	}
}
