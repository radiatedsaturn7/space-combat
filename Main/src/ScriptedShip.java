import java.awt.*;

public class ScriptedShip extends Character
{
	public boolean m_bSwitch;
	public int m_iScript;
	public boolean m_bTravelDown;
	public boolean m_bReverse;
	public int m_iScriptShot;
	private boolean m_bScriptInitialized;
	private int m_iCount; //REMOVE! REPLACE W/ TIME!!!
	private int m_iShotCount;
	Rectangle r1 = new Rectangle();
	Rectangle r2 = new Rectangle();
	Time m_tLastShotTime = new Time();
	Time m_tReloadTime = new Time();
	
	public ScriptedShip(ScriptedShip c)
	{
		super(((Character)(c)));
	}
	public ScriptedShip(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		super (Pos, Size, image, frame, solid, applygravity);
		m_bTravelDown = true;
		m_bReverse = false;
		m_bScriptInitialized = false;
		m_bSwitch=false;
		m_iShotCount = 0;
		m_tLastShotTime = new Time();
		m_tReloadTime = new Time();
		m_tReloadTime.m_iSeconds = 2;
		m_tReloadTime.m_iMilliseconds = 500;
	}
	public ScriptedShip(){
	}
	public void AI()
	{
		Time t = null;
		boolean shoot = false;
		if (Time.AddTime(m_tLastShotTime, m_tReloadTime).IsLessThan(Util.m_tTime))
			shoot = true;
		if (shoot)
		{
			//System.out.println("SHOOT");
			m_tLastShotTime = new Time(Util.m_tTime);
			if (m_iScriptShot == 1)
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 0,m_pSpeed.y + 16),99,t);
			if  (m_iScriptShot == 2)
			{
				if (m_iShotCount  == 0)
				{
					m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 5,m_pSpeed.y + 16),99,t);
					m_iShotCount++;
				}
				else
				{
					m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + -5,m_pSpeed.y + 16),99,t);
					m_iShotCount = 0;
				}
			}
			if  (m_iScriptShot == 3)
			{
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 0,m_pSpeed.y + 16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 5,m_pSpeed.y + 16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + -5,m_pSpeed.y + 16),99,t);
			}
			if  (m_iScriptShot == 4)
			{
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 5,m_pSpeed.y + 16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + -5,m_pSpeed.y + 16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 10,m_pSpeed.y + 16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + -10,m_pSpeed.y + 16),99,t);
			}
			if  (m_iScriptShot == 5)
			{
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 0,m_pSpeed.y + 16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 5,m_pSpeed.y + 16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + -5,m_pSpeed.y +16),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + 15,m_pSpeed.y + 1),99,t);
				m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point (m_pSpeed.x + -15,m_pSpeed.y + 1),99,t);
			}
			if  (m_iScriptShot == 6)
			{
				int opp1 = m_rcBoundingBox.x - ((Sprite)(Util.m_alSprite.get(0))).m_rcBoundingBox.x;
				int adj1 = m_rcBoundingBox.y - ((Sprite)(Util.m_alSprite.get(0))).m_rcBoundingBox.y;
				/*if (Util.m_alSprite.get(0) instanceof Character && Util.m_alSprite.get(1) instanceof Character)
				{
					if (((Character)(Util.m_alSprite.get(0))).m_bIsPlayer && (((Character)(Util.m_alSprite.get(0)))).m_bIsPlayer)
					{
						int opp2 = m_rcBoundingBox.x - ((Sprite)(Util.m_alSprite.get(1))).m_rcBoundingBox.x;
						int adj2 = m_rcBoundingBox.y - ((Sprite)(Util.m_alSprite.get(1))).m_rcBoundingBox.y;
						if (adj1 != 0)
							m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point ((int)(16 * Math.cos(Math.atan((double)(opp1/adj1)))),(int)(16 * Math.sin(Math.atan((double)(opp1/adj1))))),99,t);
						if (adj2 != 0)
							m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point ((int)(16 * Math.cos(Math.atan((double)(opp2/adj2)))),(int)(16 * Math.sin(Math.atan((double)(opp2/adj2))))),99,t);
					}
					else
					{
						if (adj1 != 0)
							m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point ((int)(16 * Math.cos(Math.atan((double)(opp1/adj1)))),(int)(16 * Math.sin(Math.atan((double)(opp1/adj1))))),99,t);
					}
				}
				else
				{*/
					if (adj1 > 0)
					{
						if (opp1 > 0)
							m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point ((int)(-16 * Math.sin(Math.atan((double)(opp1/adj1)))),(int)(-16 * Math.cos(Math.atan((double)(opp1/adj1))))),99,t);
						if (opp1 < 0)
							m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point ((int)(-16 * Math.sin(Math.atan((double)(opp1/adj1)))),(int)(-16 * Math.cos(Math.atan((double)(opp1/adj1))))),99,t);
					}
					if (adj1 < 0)
					{
						if (opp1 > 0)
							m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point ((int)(16 * Math.sin(Math.atan((double)(opp1/adj1)))),(int)(16 * Math.cos(Math.atan((double)(opp1/adj1))))),99,t);
						if (opp1 < 0)
							m_wWeapon.Shoot(new Point(m_rcBoundingBox.x,m_rcBoundingBox.y),new Point ((int)(16 * Math.sin(Math.atan((double)(opp1/adj1)))),(int)(16 * Math.cos(Math.atan((double)(opp1/adj1))))),99,t);
					}
				//}
			}
		}
		
		if (!m_bScriptInitialized)
			InitializeScript(m_iScript);
		if (m_iScript == 1)
			ScriptOne();
		if (m_iScript == 2)
			ScriptTwo();
		if (m_iScript == 3)
			ScriptThree();
		if (m_iScript == 4)
			ScriptFour();
		if (m_iScript == 5)
			ScriptFive();
		if (m_iScript == 6)
			ScriptSix();
		if (m_iScript == 7)
			ScriptSeven();
		if (m_iScript == 8)
			ScriptEight();
		if (m_iScript == 9)
			ScriptNine();
		if (m_iScript == 10)
			ScriptTen();
		if (m_iScript == 11)
			ScriptEleven();
		if (m_iScript == 12)
			ScriptTwelve();
		if (m_iScript == 13)
			ScriptThirteen();
	}
	public void ScriptOne()
	{
		//WEAVE
		if (m_bReverse)
			m_pSpeed.x = -m_pSpeed.x;
		if (m_pSpeed.y < m_pMaxSpeed.y)
			m_pSpeed.y++;
		if (m_iCount < 120 && m_iCount >= 0)
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
			m_iCount++;
		}
		else if (m_iCount < 240 && m_iCount >= 120)
		{
			if (m_pSpeed.x > -m_pMaxSpeed.x)
				m_pSpeed.x--;
			m_iCount++;
		}
		else
			m_iCount = 0;
		if (m_bReverse)
			m_pSpeed.x = -m_pSpeed.x;
	}
	public void ScriptTwo()
	{
		//JUMP L/R
		r1.x = m_rcBoundingBox.x;
		if (!m_bReverse)
		{
			if (m_rcBoundingBox.intersects(r2))
			{
				if (m_pSpeed.x > 0)
					m_pSpeed.x--;
				if (m_pSpeed.y < m_pMaxSpeed.y)
					m_pSpeed.y++;
			}
			else if (m_rcBoundingBox.intersects(r1))
			{
				if (m_pSpeed.x < m_pMaxSpeed.x)
					m_pSpeed.x++;
				if (m_pSpeed.y > 0)
					m_pSpeed.y--;
			}
		}
		else
		{
			if (m_rcBoundingBox.intersects(r2))
			{
				if (m_pSpeed.x < 0)
					m_pSpeed.x++;
				if (m_pSpeed.y < m_pMaxSpeed.y)
					m_pSpeed.y++;
			}
			else if (m_rcBoundingBox.intersects(r1))
			{
				if (m_pSpeed.x > -m_pMaxSpeed.x)
					m_pSpeed.x--;
				if (m_pSpeed.y > 0)
					m_pSpeed.y--;
			}
		}
	}
	public void ScriptThree()
	{
		if (m_pSpeed.y < m_pMaxSpeed.y)
			m_pSpeed.y++;
		if (m_bSwitch)
		{
			if (m_pSpeed.x > -m_pMaxSpeed.x)
				m_pSpeed.x--;
		}
		else
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
		}
		if (!m_bReverse)
		{
			if (m_rcBoundingBox.intersects(r1))
				m_bSwitch = false;
			if (m_rcBoundingBox.intersects(r2))
				m_bSwitch = true;
		}
		else
		{
			if (m_rcBoundingBox.intersects(r1))
				m_bSwitch = true;
			if (m_rcBoundingBox.intersects(r2))
				m_bSwitch = false;
		}
	}
	public void ScriptFour()
	{
	}
	public void ScriptFive()
	{
	}
	public void ScriptSix()
	{
	}
	public void ScriptSeven()
	{
	}
	public void ScriptEight()
	{
	}
	public void ScriptNine()
	{
	}
	public void ScriptTen()
	{
	}
	public void ScriptEleven()
	{
	}
	public void ScriptTwelve()
	{
	}
	public void ScriptThirteen()
	{
	}
	public void InitializeScript(int Script)
	{
		if (Script == 2)
		{
			r1.x = m_rcBoundingBox.x;
			r1.y = (int)(Util.m_rcScreen.height / 2) - m_rcBoundingBox.height;
			r1.width = m_rcBoundingBox.width;
			r1.height = m_rcBoundingBox.height;
			if (!m_bReverse)
				r2.x = Util.m_rcScreen.width - m_rcBoundingBox.width;
			else
				r2.x = Util.m_rcScreen.x + m_rcBoundingBox.width;
			r2.y = (int)(Util.m_rcScreen.height / 2) - m_rcBoundingBox.height;
			r2.width = m_rcBoundingBox.width;
			r2.height = m_rcBoundingBox.height;
		}
		if (Script == 3)
		{

			r1.x = m_rcBoundingBox.x;
			r1.y = Util.m_rcScreen.y;
			r1.width = m_rcBoundingBox.width;
			r1.height = Util.m_rcScreen.height;
			if (!m_bReverse)
				r2.x = Util.m_rcScreen.width - m_rcBoundingBox.width;
			else
				r2.x = Util.m_rcScreen.x + m_rcBoundingBox.width;
			r2.y = Util.m_rcScreen.x;
			r2.width = m_rcBoundingBox.width;
			r2.height = Util.m_rcScreen.height;
		}
		m_bScriptInitialized=true;
	}
	public void Update()
	{
		AI();
		super.Update();
		if (m_rcBoundingBox.y > Util.m_rcScreen.y + Util.m_rcScreen.height && m_bTravelDown)
			m_bDelete = true;
		if (m_rcBoundingBox.y + m_rcBoundingBox.height < Util.m_rcScreen.y  && !m_bTravelDown)
			m_bDelete = true;
		//HACK something wrong with a script...this will temp fix it
		if (m_rcBoundingBox.x + m_rcBoundingBox.width < Util.m_rcScreen.x)
			m_bDelete = true;
		if (m_rcBoundingBox.x > Util.m_rcScreen.x + Util.m_rcScreen.width)
			m_bDelete = true;
	}
	public void Paint(Graphics g)
	{
		//g.setColor(Color.red);
		//g.drawRect(r1.x,r1.y,r1.width,r1.height);
		//g.setColor(Color.blue);	
		//g.drawRect(r2.x,r2.y,r2.width,r2.height);
		//if (m_pSpeed.y != 0)
		//	super.DrawBoundingBox(g);
		super.Paint(g);
	}
}
