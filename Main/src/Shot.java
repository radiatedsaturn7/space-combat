import java.awt.*;

public class Shot extends Sprite
{
	int m_iDamage;
	Time m_tLife;
	Time m_tCreationTime;

	public Shot (Shot s)
	{
		super(((Sprite)(s)));
		m_iDamage = s.m_iDamage;
	}
	public Shot(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		super (Pos, Size, image, frame, solid, applygravity);
		m_iDamage = 10;
		m_iFaction = 0;
		m_tCreationTime = new Time(Util.m_tTime);
		m_tLife = null;
	}
	
	public void Update()
	{
		//System.out.println(m_iFaction);
		super.Update();
		
		if (m_tLife != null)
		{
			if (Time.AddTime(m_tCreationTime, m_tLife).IsLessThan(Util.m_tTime))
			m_bDelete = true;
		}
		if (m_rcBoundingBox.y + m_rcBoundingBox.height < Util.m_rcScreen.y)
		{
			m_bDelete = true;
		}
		if (m_rcBoundingBox.y > Util.m_rcScreen.y + Util.m_rcScreen.height)
		{
			m_bDelete = true;
		}
		if (m_rcBoundingBox.x + m_rcBoundingBox.width < Util.m_rcScreen.x)
		{
			m_bDelete = true;
		}
		if (m_rcBoundingBox.x > Util.m_rcScreen.x + Util.m_rcScreen.width)
		{
			m_bDelete = true;
		}
	}
	public void CollideWith (Sprite S)
	{
		/*
		if (S instanceof Shot  && m_iFaction != S.m_iFaction)
		{
			S.m_bDelete = true;
		}
		*/
		if (S instanceof Character && m_iFaction != S.m_iFaction)
		{
			((Character)(S)).TakeDamage(m_iDamage,'P');
			m_bDelete = true;
		}
		//System.out.println("Collision Shot");
	}
	/*
	public void Paint (Graphics g)
	{
		super.Paint(g);
		g.setColor(Color.red);
		g.drawRect(m_rcBoundingBox.x, m_rcBoundingBox.y, m_rcBoundingBox.width, m_rcBoundingBox.height);

	}*/
}
