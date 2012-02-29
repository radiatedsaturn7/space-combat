import java.awt.*;

public class Bouncer extends Character
{
	public int walk;
	public Bouncer(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		super(Pos, Size, image, frame, solid, applygravity);
		walk = 0;
	}
	public void AI ()
	{
		Rectangle rcWalkable = new Rectangle();
		
		boolean walk = false;;
		//can i jump?
		
		if (m_dDirection.IsLeft())
		{
			rcWalkable.x = m_rcBoundingBox.x - (int)(m_rcBoundingBox.width/4);
			rcWalkable.y = m_rcBoundingBox.y;
			rcWalkable.width = (int)(m_rcBoundingBox.width/4);
			rcWalkable.height = m_rcBoundingBox.height;
		}
		else if (m_dDirection.IsRight())
		{
			rcWalkable.x = m_rcBoundingBox.x + m_rcBoundingBox.width;
			rcWalkable.y = m_rcBoundingBox.y;
			rcWalkable.width = (int)(m_rcBoundingBox.width/4);
			rcWalkable.height = m_rcBoundingBox.height;
		}
		else
		{
			m_pSpeed.x = 0;
			m_dDirection.Up();
		}

		if (!(Util.m_lCurrentLevel.IsColliding(rcWalkable)))
		{
			walk=true;
		}
		
		
		if (walk)
		{
			//speed.y = 0;
			//System.out.println("WALK");
					if (m_dDirection.IsLeft())
						m_pSpeed.x = -4;
					else if (m_dDirection.IsRight())
						m_pSpeed.x = 4;
		}
		else
		{
			//System.out.println("BEHIND");
					if (m_dDirection.IsLeft())
						m_dDirection.Right();
					else if (m_dDirection.IsRight())
						m_dDirection.Left();
		}
		/*
		Sprite Player1 = (Sprite)(Util.m_alSprite.get(0));
		if (Player1.CollidesWith(rcSight))
			System.out.println("Gotcha!");
		else
			System.out.println("Where are you?");
		*/

	}
	
	public void Update ()
	{
		super.Update();
		AI();
	}
	public void CollideWith(Sprite S)
	{
		super.CollideWith(S);
		m_dDirection.Reverse();
		if (S.m_iFaction == m_iFaction)
		{
			return;
		}
		if (S instanceof Character)
		{
			TakeDamage(10, 'P');
			if (S.m_rcBoundingBox.x > m_rcBoundingBox.x)
			{
				//S.speed.x = -8;
				//S.speed.y = -20;
			}
			else
			{
				//S.speed.x = 8;
				//S.speed.y = -20;
			}
		}
		//System.out.println("Collision Bouncer");
	}
}
