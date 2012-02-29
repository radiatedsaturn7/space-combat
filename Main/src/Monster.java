import java.awt.*;
import java.util.*;

public class Monster extends Character
{
	Rectangle rcSight = new Rectangle();
	Rectangle rcWalkable = new Rectangle();
	Rectangle LEFT = new Rectangle();
	Rectangle RIGHT = new Rectangle();
	Rectangle CENTER = new Rectangle();
	int hold = 0;
	int spacing = 0;
	
	public Monster(Monster m)
	{
		super(((Character)(m)));
		rcSight = new Rectangle(m.rcSight);
		rcWalkable = new Rectangle(m.rcWalkable);
		hold = m.hold;
	}
	
	public Monster(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		super(Pos, Size, image, frame, solid, applygravity);
		hold = 10;
	}
	public void AI ()
	{
		Sprite player = (Sprite)(Util.m_alSprite.get(0));
		
		boolean jump = false;
		boolean canjump = false;
		boolean groundunderneath = false;
		boolean shoot = false;
		boolean walk = true;
		boolean walktoplayer = false;
		boolean wander = true;
		boolean canwalk = false;

		rcSight.x = m_rcBoundingBox.x + ((int)(m_rcBoundingBox.width / 2));
		rcSight.y = m_rcBoundingBox.y - (int)(m_rcBoundingBox.height/2);
		rcSight.height = m_rcBoundingBox.height* 2;
		rcSight.width = 400;

		LEFT.x = m_rcBoundingBox.x - 500;
		LEFT.y = m_rcBoundingBox.y - 300;
		LEFT.width = 300 + spacing;
		LEFT.height = 600;
			
		RIGHT.x = m_rcBoundingBox.x + m_rcBoundingBox.width + 200 - spacing;
		RIGHT.y = m_rcBoundingBox.y - 300;
		RIGHT.width = 300;
		RIGHT.height = 600;
		
		if (m_iFaction != player.m_iFaction)
		{
				LEFT.x = m_rcBoundingBox.x - 200;
				LEFT.y = m_rcBoundingBox.y - 50;
				LEFT.width = 50;
				LEFT.height = 100;
			
				RIGHT.x = m_rcBoundingBox.x + m_rcBoundingBox.width + 150;
				RIGHT.y = m_rcBoundingBox.y - 50;
				RIGHT.width = 50;
				RIGHT.height = 100;
		}
		
		CENTER.x = LEFT.x + LEFT.width;
		CENTER.y = LEFT.y;
		CENTER.width = RIGHT.x - CENTER.x;
		CENTER.height = LEFT.height;
		
		
		if (m_dDirection.IsLeft())
		{
			rcSight.x -= 400;
		}
				
		for (int x = 0; x < Util.m_alSprite.size(); x++)
		{
			Sprite s = (Sprite)(Util.m_alSprite.get(x));
			if (s.IsColliding(rcSight) && s.m_iFaction != m_iFaction)
				shoot = true;
		}
		
		if (player.IsColliding(LEFT))
		{
			m_dDirection.Left();
			rcWalkable.x = m_rcBoundingBox.x - (int)(m_rcBoundingBox.width/4);
			rcWalkable.y = m_rcBoundingBox.y;
			rcWalkable.width = (int)(m_rcBoundingBox.width/4);
			rcWalkable.height = m_rcBoundingBox.height;
			walktoplayer = true;
			wander = false;
		}
		else if (player.IsColliding(RIGHT))
		{
			m_dDirection.Right();
			rcWalkable.x = m_rcBoundingBox.x + m_rcBoundingBox.width;
			rcWalkable.y = m_rcBoundingBox.y;
			rcWalkable.width = (int)(m_rcBoundingBox.width/4);
			rcWalkable.height = m_rcBoundingBox.height;
			walktoplayer = true;
			wander = false;
		}
		else if (shoot)
		{
			wander = false;
		}
		else
		{
			wander = true;
			m_pSpeed.x = 0;
			walk = false;
		}
		
		if (player.IsColliding(CENTER))
			wander = false;
		int o = rcWalkable.y;
		int ceiling = 0;
		//can i jump?
		for (int z = -2; z < 6; z++)
		{
			rcWalkable.y = o - (32 * z);
			if (!(Util.m_lCurrentLevel.IsColliding(rcWalkable)))
			{
				canjump = true;
				ceiling = z;
				if (z == 0)
					canwalk = true;
			}
			else if (z == 0)
				jump = true;
			else if (z < 0)
				groundunderneath = true;
		}
		
		
		rcWalkable.x = m_rcBoundingBox.x;
		rcWalkable.y = m_rcBoundingBox.y;
		rcWalkable.width = m_rcBoundingBox.width;
		rcWalkable.height = m_rcBoundingBox.height;
		//see if there is a ceiling above the player
		for (int z = 0; z < ceiling; z++)
		{
			rcWalkable.y = o - (32 * z);
			if ((Util.m_lCurrentLevel.IsColliding(rcWalkable)))
			{
				canjump = false;
				ceiling = z;
			}
		}
		if (!jump && walk)
		{
			if (hold > 50)
				m_pSpeed.y = 0;
			if (m_dDirection.IsLeft())
				m_pSpeed.x = -1;
			else if (m_dDirection.IsRight())
				m_pSpeed.x = 1;
		}
		if ((jump || (player.IsOnGround() && player.m_rcBoundingBox.y < m_rcBoundingBox.y - 31)) && canjump && groundunderneath)
		{
				m_pSpeed.y = -20;
				hold = 0;
		}
		else if (walktoplayer)
		{

		}
		else if (wander)
		{
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
			
							if (canwalk)
				{
				}
	
			if (!(Util.m_lCurrentLevel.IsColliding(rcWalkable)))
			{
				walk=true;
			}
			
			
			if (walk)
			{
				//speed.y = 0;

						if (m_dDirection.IsLeft())
							m_pSpeed.x = -1;
						else if (m_dDirection.IsRight())
							m_pSpeed.x = 1;
			}
			else
			{
						if (m_dDirection.IsLeft())
							m_dDirection.Right();
						else if (m_dDirection.IsRight())
							m_dDirection.Left();
			}
		}
		else
		{
			if (hold > 50)
				m_pSpeed.y = 0;
		}
		if (hold < 51)
			hold++;
		
		if (shoot)
		{
		ArrayList AnimationList = new ArrayList();
				Animation a = new Animation();
				Shot sh = new Shot(new Point(m_rcBoundingBox.x, m_rcBoundingBox.y),new Point(32,32),Toolkit.getDefaultToolkit().getImage( "shot.gif" ), 1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("PRINT",0,0,true,17);
					AnimationList.add(a);
					sh.SetAnimations(AnimationList);
					sh.PlayAnimation("PRINT");
					if (m_dDirection.IsLeft())
					{
						sh.m_rcBoundingBox.x -= 37;
						sh.m_pSpeed.x = -8;
					}
					else
					{
						sh.m_rcBoundingBox.x += 37;
						sh.m_pSpeed.x = 8;
					}
					sh.m_iFaction = m_iFaction;
				Util.m_alSprite.add(sh);
				}
	}
	
	public void Update ()
	{
		super.Update();
		AI();
	}
	public void DrawBoundingBox(Graphics g)
	{
		g.setColor(Color.red);
		g.drawRect(m_rcBoundingBox.x, m_rcBoundingBox.y, m_rcBoundingBox.width, m_rcBoundingBox.height);
		g.setColor(Color.green);
		g.drawRect(rcSight.x, rcSight.y, rcSight.width, rcSight.height);
		g.setColor(Color.yellow);
		g.drawRect(rcWalkable.x, rcWalkable.y, rcWalkable.width, rcWalkable.height);
		g.setColor(Color.white);
		g.drawRect(LEFT.x, LEFT.y, LEFT.width, LEFT.height);
		g.setColor(Color.white);
		g.drawRect(RIGHT.x, RIGHT.y, RIGHT.width, RIGHT.height);
		g.setColor(Color.black);
		g.drawRect(CENTER.x, CENTER.y, CENTER.width, CENTER.height);

	}
}
