import java.awt.*;
import java.util.*;

public class Entity_EnemySpawnPoint extends Entity 
{
	public int m_iKind;
	public int m_iScript;
	public int m_iScriptShot;
	public boolean m_bReverse;
	public boolean m_bTravelDown;
	public Entity_EnemySpawnPoint(Entity_EnemySpawnPoint e)
	{
		super((Entity)e);
		m_iKind = e.m_iKind;
		m_iScript = e.m_iScript;
		m_iScriptShot = e.m_iScriptShot;
		m_bReverse = e.m_bReverse;
		m_bTravelDown = e.m_bTravelDown;
	}
	public Entity_EnemySpawnPoint(int x, int y, int w, int h, Point p, int kind, int script, int scriptshot, boolean reverse, boolean traveldown)
	{
		super(x,y,w,h,p);
		m_iKind = kind;
		m_iScript = script;
		m_iScriptShot = scriptshot;
		m_bReverse = reverse;
		m_bTravelDown = traveldown;
	}
	public void Update()
	{
		super.Update();
		ScriptedShip m2 = new ScriptedShip(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y), new Point(32,32), Util.m_imEnemyImage ,1, true, false);
		m2.m_pBattlePos = new Point(m_rcBoundingBox.x,m_rcBoundingBox.y);
		m2.AddImage(Util.m_imEnemyImageNV);
		if (Util.m_iVision == 1)
			m2.SetImage(1);
		m2.m_wWeapon = new Phaser("Phaser", 10,10,99);
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("IDLE", (m_iKind*8-2),(m_iKind*8),true,20);
			AnimationList.add(a);
			a = new Animation("DIE1",((m_iKind-1)*8)+1,(m_iKind*8-2),false,48);
			AnimationList.add(a);
			a = new Animation("DIE2",((m_iKind-1)*8)+1,(m_iKind*8-2),false,48);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
			m2.PlayAnimation("IDLE");
		m2.m_iScript = m_iScript;
		m2.m_iScriptShot = m_iScriptShot;
		m2.m_iFaction = 99;
		m2.m_bTravelDown = m_bTravelDown;
		m2.m_bReverse = m_bReverse;
		if (m_bTravelDown)
		{
			m2.m_pMaxSpeed.y = 2;
			m2.m_pMaxSpeed.x = 2;
			m2.m_pSpeed.y = 0;
			m2.m_pSpeed.y = 2;
		}
		else
		{
			m2.m_pMaxSpeed.y = -2;
			m2.m_pMaxSpeed.x = 2;
			m2.m_pSpeed.y = 0;
			m2.m_pSpeed.y = -2;
		}
		Util.m_alSprite.add(m2);
		System.out.println("ENEMY CREATED");
	}
}
