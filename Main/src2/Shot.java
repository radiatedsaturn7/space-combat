import java.awt.*;

public class Shot extends Sprite
{
	int m_iDamage;

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
	}
	
	public void Update()
	{
		//System.out.println(m_iFaction);
		super.Update();
		
		if (m_rcBoundingBox.y < Util.m_rcScreen.y)
		{
			m_bDelete = true;
		}
	}
	public void CollideWith (Sprite S)
	{
		
		if (S instanceof Shot  && m_iFaction != S.m_iFaction)
		{
			S.m_bDelete = true;
		}
		else if (S instanceof Character && m_iFaction != S.m_iFaction)
		{
			((Character)(S)).TakeDamage(m_iDamage,'P');
			m_bDelete = true;
		}
		//System.out.println("Collision Shot");
	}
	public void Paint (Graphics g)
	{
		g.setColor(Color.red);
		g.drawRect(m_rcBoundingBox.x, m_rcBoundingBox.y, m_rcBoundingBox.width, m_rcBoundingBox.height);

	}
}
