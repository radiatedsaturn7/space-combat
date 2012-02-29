import java.awt.*;

public class ScriptedShip extends Character
{
	public int m_iScript;
	public boolean m_bTravelDown;
	public boolean m_bReverse;
	private boolean m_bScriptInitialized;
	private int m_iCount;
	Rectangle r1 = new Rectangle();
	Rectangle r2 = new Rectangle();
	
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
	}
	public ScriptedShip(){
	}
	public void AI()
	{
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
		if (m_iScript == 13)
			ScriptTwelve();
		if (m_iScript == 12)
			ScriptTwelve();
		if (m_iScript == 13)
			ScriptThirteen();	
	}
	public void ScriptOne()
	{
		if (m_bReverse)
			m_pSpeed.x = -m_pSpeed.x;
		if (m_pSpeed.y < m_pMaxSpeed.y)
			m_pSpeed.y++;
		if (m_iCount < 30 && m_iCount >= 0)
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
			m_iCount++;
		}
		else if (m_iCount < 60 && m_iCount >= 30)
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
		if (!m_bReverse)
		{
			if (m_rcBoundingBox.intersects(r1))
			{
				if (m_pSpeed.x < m_pMaxSpeed.x)
					m_pSpeed.x++;
			}
			if (m_rcBoundingBox.intersects(r2))
			{
				if (m_pSpeed.x > -m_pMaxSpeed.x)
					m_pSpeed.x--;
			}
		}
		else
		{
			if (m_rcBoundingBox.intersects(r1))
			{
				if (m_pSpeed.x > -m_pMaxSpeed.x)
					m_pSpeed.x--;
			}
			if (m_rcBoundingBox.intersects(r2))
			{
				if (m_pSpeed.x < m_pMaxSpeed.x)
					m_pSpeed.x++;
			}
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
				r2.x = Util.m_rcScreen.width + m_rcBoundingBox.width;
			r2.y = Util.m_rcScreen.x;
			r2.width = m_rcBoundingBox.width;
			r2.height = Util.m_rcScreen.height;
		}
		m_bScriptInitialized=true;
	}
	public void Update()
	{
		System.out.println(m_pSpeed.y);
		AI();
		super.Update();
		if (m_rcBoundingBox.y > Util.m_rcScreen.height && m_bTravelDown)
			m_bDelete = true;
		if (m_rcBoundingBox.y < 0-m_rcBoundingBox.height  && !m_bTravelDown)
			m_bDelete = true;
	}
	public void Paint(Graphics g)
	{
		g.setColor(Color.red);
		g.drawRect(r1.x,r1.y,r1.width,r1.height);
		g.setColor(Color.blue);	
		g.drawRect(r2.x,r2.y,r2.width,r2.height);
		if (m_pSpeed.y != 0)
			super.DrawBoundingBox(g);
		super.Paint(g);
	}
}
