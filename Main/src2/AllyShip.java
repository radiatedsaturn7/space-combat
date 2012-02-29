import java.awt.*;
import java.util.*;

public class AllyShip extends Character {
	
	public int m_iID;
	public int m_iFormationID;
	public int m_iSpacing;
	public int m_iGive;
	public int m_iFormation;
	public int m_iRoamFormation;
	public int m_iSide;
	public Rectangle m_rcFollowBox;
	public Rectangle m_rcDodge;
	
	public AllyShip(AllyShip c)
	{
		super(((Character)(c)));
	}
	public AllyShip(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		super (Pos, Size, image, frame, solid, applygravity);
		m_iSpacing = 32;
		m_iGive = 5;
		m_dDirection.Left();
		m_iHealth = 100;
		m_iMagic = 100;
		m_iStrength = 0;
		m_iDefense = 0;
		m_iMagicStrength = 0;
		m_iMagicDefense = 0;
		m_iSpeed = 0;
		m_iEndurance = 0;
		m_iLuck = 0;
		m_iDetermination = 0;
		m_bIsPlayer = false;
		m_iEXP = 0;
		m_iMEXP = 0;
		m_iWEXP = 0;
		m_rcDodge = new Rectangle();
		m_iFormationID = 0;
	}
	public AllyShip(){

	}
	public void AI ()
	{
		m_iSide = m_iFormationID % (2 * Util.m_iNumOfPlayers);
	//	if (m_iSide > 1)
	//		m_iSide = (m_iSide)%2;
				
		if (CanShoot())
			Shoot();
		
	//	System.out.println(m_iID);
		
		//if (m_iRoamFormation == 0 || CheckDodge())
		//	Dodge();
		if (m_rcFollowBox != null)
		{
			if (m_iFormation == 1 || m_iRoamFormation == 1)
				Wedge();
			if (m_iFormation == 2 || m_iRoamFormation == 2)
				Line();
			if (m_iFormation == 3 || m_iRoamFormation == 3)
				Column();
			if (m_iFormation == 4 || m_iRoamFormation == 4)
				Cover();
		}
		if (m_iFormation == 5)
			Roam();
	}
	public void Dodge()
	{
		Rectangle Top = new Rectangle();
		Rectangle Bottom = new Rectangle();
		Rectangle Left = new Rectangle();
		Rectangle Right = new Rectangle();
		
		Top.x = m_rcBoundingBox.x - (m_rcBoundingBox.width*2);
		Top.y = m_rcBoundingBox.y - 512;
		Top.width = m_rcBoundingBox.width*5;
		Top.height = 512;
		Bottom.x = m_rcBoundingBox.x - (m_rcBoundingBox.width*2);
		Bottom.y = m_rcBoundingBox.y + m_rcBoundingBox.height;
		Bottom.width = m_rcBoundingBox.width*5;
		Bottom.height = 128;
		Left.x = m_rcBoundingBox.x - (m_rcBoundingBox.width*2);
		Left.y = m_rcBoundingBox.y - 512;
		Left.width = (m_rcBoundingBox.width*2);
		Left.height = 512 + m_rcBoundingBox.height + 128;
		Right.x = m_rcBoundingBox.x + (m_rcBoundingBox.width*2);
		Right.y = m_rcBoundingBox.y - 512;
		Right.width = m_rcBoundingBox.width*2;
		Right.height = 512 + m_rcBoundingBox.height + 128;
		for(int x =0; x < Util.m_alSprite.size(); x++)
		{
			Sprite s = (Sprite)(Util.m_alSprite.get(x));
			if (s.m_iFaction != m_iFaction)
			{
				if (s.m_rcBoundingBox.intersects(Top) || s.m_rcBoundingBox.intersects(Bottom))
				{
					
					if (s.m_rcBoundingBox.intersects(Top))
					{
						if (m_pSpeed.y > -m_pMaxSpeed.y)
							m_pSpeed.x--;
					}
					else if (s.m_rcBoundingBox.intersects(Bottom))
					{
						if (m_pSpeed.x < m_pMaxSpeed.x)
							m_pSpeed.x++;
					}
					if (s.m_rcBoundingBox.intersects(Right))
					{
						if (m_pSpeed.x < m_pMaxSpeed.x)
							m_pSpeed.x++;
					}
					else if (s.m_rcBoundingBox.intersects(Left))
					{
						if (m_pSpeed.x > -m_pMaxSpeed.x)
							m_pSpeed.x--;
					}
					else
					{
						if (m_pSpeed.x < m_pMaxSpeed.x)
							m_pSpeed.x++;
					}
					break;
				}
				else if (s.m_rcBoundingBox.intersects(Right))
				{
					if (m_pSpeed.x < m_pMaxSpeed.x)
						m_pSpeed.x++;
					break;
				}
				else if (s.m_rcBoundingBox.intersects(Left))
				{
					if (m_pSpeed.x > -m_pMaxSpeed.x)
						m_pSpeed.x--;
					break;
				}
			}
		}
	}
	
	public boolean CheckDodge()
	{
		m_rcDodge.x = m_rcBoundingBox.x - (m_rcBoundingBox.width*2);
		m_rcDodge.width = m_rcBoundingBox.width*5;
		m_rcDodge.y = m_rcBoundingBox.y - 512;
		m_rcDodge.height = 512 + m_rcBoundingBox.height + 128;
		for(int x =0; x < Util.m_alSprite.size(); x++)
		{
			Sprite s = (Sprite)(Util.m_alSprite.get(x));
			if (s.m_rcBoundingBox.intersects(m_rcDodge) &&
				s.m_iFaction != m_iFaction)
			{
				m_iRoamFormation = 0;
				return true;
			}
		}
		m_iRoamFormation = -1;
		return false;
	}

	public void Paint(Graphics g)
	{
		super.Paint(g);
	}
	public void Update()
	{
		if (m_pSpeed.y > 0)
		{
			if (m_pSpeed.x > 0)
				PlayAnimation("DOWNRIGHT");
			else if (m_pSpeed.x < 0)
				PlayAnimation("DOWNLEFT");
			else
				PlayAnimation("DOWN");
		}
		else if (m_pSpeed.y < 0)
		{
			if (m_pSpeed.x > 0)
				PlayAnimation("UPRIGHT");
			else if (m_pSpeed.x < 0)
				PlayAnimation("UPLEFT");
			else
				PlayAnimation("UP");
		}
		else if (m_pSpeed.x > 0)
			PlayAnimation("RIGHT");
		else if (m_pSpeed.x < 0)
			PlayAnimation("LEFT");
		else
			PlayAnimation("IDLE");
		AI();
		super.Update();
	}
	public boolean CanShoot()
	{
		for(int x =0; x < Util.m_alSprite.size(); x++)
		{
			Sprite s = (Sprite)(Util.m_alSprite.get(x));
			if (s.m_rcBoundingBox.x + s.m_rcBoundingBox.width > m_rcBoundingBox.x &&
				s.m_rcBoundingBox.x < m_rcBoundingBox.x + m_rcBoundingBox.width &&
				s.m_rcBoundingBox.y < m_rcBoundingBox.y &&
				s.m_iFaction != m_iFaction && Util.RandomNumber(0,100) == 0)
				return true;
		}
		return false;
	}
	public void Shoot()
	{
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation();
			Shot sh = new Shot(new Point(m_rcBoundingBox.x, m_rcBoundingBox.y),new Point(32,32),Util.m_imShotImage, 1, false, false);
				AnimationList = new ArrayList();
				a = new Animation("PRINT",0,0,true,17);
				AnimationList.add(a);
				sh.SetAnimations(AnimationList);
				sh.PlayAnimation("PRINT");
					sh.m_rcBoundingBox.x -= 0;
					sh.m_pSpeed.x = m_pSpeed.x;
					sh.m_rcBoundingBox.y -= 37;
					sh.m_pSpeed.y = -16 + m_pSpeed.y;

			Util.m_alSprite.add(sh);
	}
	public void Wedge()
	{
		int neg = 1;
		int fix = Util.m_iNumOfPlayers;
		if (m_iSide % 2 == 1)
		{
			neg = -1; //switch the side the ally appears on
		}
		if (m_rcBoundingBox.x < m_rcFollowBox.x + neg*m_rcFollowBox.width + (neg*m_iSpacing * m_iFormationID/fix - m_iGive))
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
			m_dDirection.Right();
		}
		else if (m_rcBoundingBox.x > m_rcFollowBox.x + neg*m_rcFollowBox.width + (neg*m_iSpacing * m_iFormationID/fix + m_iGive))
		{
			if (m_pSpeed.x > -m_pMaxSpeed.x)
				m_pSpeed.x--;
			m_dDirection.Left();
		}
		else
		{
			if (m_pSpeed.x < 0)
				m_pSpeed.x++;
			if (m_pSpeed.x > 0)
				m_pSpeed.x--;
		}
		if (m_rcBoundingBox.y < m_rcFollowBox.y + m_rcFollowBox.height + (m_iSpacing * m_iFormationID/fix - m_iGive))
		{
			if (m_pSpeed.y < m_pMaxSpeed.y)
				m_pSpeed.y++;
			m_dDirection.Down();

		}
		else if (m_rcBoundingBox.y > m_rcFollowBox.y + m_rcFollowBox.height + (m_iSpacing * m_iFormationID/fix + m_iGive))
		{
			if (m_pSpeed.y > -m_pMaxSpeed.y)
				m_pSpeed.y--;
			m_dDirection.Up();
		}
		else
		{
			if (m_pSpeed.y < 0)
				m_pSpeed.y++;
			if (m_pSpeed.y > 0)
				m_pSpeed.y--;
		}
	}
	public void Line()
	{
		int neg = 1;
		int fix = Util.m_iNumOfPlayers;
		if (m_iSide % 2 == 1)
		{
			neg = -1; //switch the side the ally appears on
		}
		if (m_rcBoundingBox.x < m_rcFollowBox.x + neg*m_rcFollowBox.width + (neg*m_iSpacing * m_iFormationID/fix - m_iGive))
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
			m_dDirection.Right();

		}
		else if (m_rcBoundingBox.x > m_rcFollowBox.x + neg*m_rcFollowBox.width + (neg*m_iSpacing * m_iFormationID/fix + m_iGive))
		{
			if (m_pSpeed.x > -m_pMaxSpeed.x)
				m_pSpeed.x--;
			m_dDirection.Left();
		}
		else
		{
			if (m_pSpeed.x < 0)
				m_pSpeed.x++;
			if (m_pSpeed.x > 0)
				m_pSpeed.x--;
		}
		if (m_rcBoundingBox.y < m_rcFollowBox.y - m_iGive)
		{
			if (m_pSpeed.y < m_pMaxSpeed.y)
				m_pSpeed.y++;
			m_dDirection.Down();
		}
		else if (m_rcBoundingBox.y > m_rcFollowBox.y +  m_iGive)
		{
			if (m_pSpeed.y > -m_pMaxSpeed.y)
				m_pSpeed.y--;
			m_dDirection.Up();
		}
		else
		{
			if (m_pSpeed.y < 0)
				m_pSpeed.y++;
			if (m_pSpeed.y > 0)
				m_pSpeed.y--;
		}
	}
	public void Column()
	{
		int neg = 1;
		int fix = Util.m_iNumOfPlayers;
		if (m_iSide % 2 == 1)
		{
			neg = -2; //switch the side the ally appears on
		}
		if (m_rcBoundingBox.x < m_rcFollowBox.x + neg*m_rcFollowBox.width + (neg*m_iSpacing - m_iGive))
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
			m_dDirection.Right();

		}
		else if (m_rcBoundingBox.x > m_rcFollowBox.x + neg*m_rcFollowBox.width + (neg*m_iSpacing + m_iGive))
		{
			if (m_pSpeed.x > -m_pMaxSpeed.x)
				m_pSpeed.x--;
			m_dDirection.Left();
		}
		else
		{
			if (m_pSpeed.x < 0)
				m_pSpeed.x++;
			if (m_pSpeed.x > 0)
				m_pSpeed.x--;
			PlayAnimation("IDLE");
		}
		if (m_rcBoundingBox.y < m_rcFollowBox.y + m_rcFollowBox.height + (m_iSpacing * m_iFormationID/fix - m_iGive))
		{
			if (m_pSpeed.y < m_pMaxSpeed.y)
				m_pSpeed.y++;
			m_dDirection.Down();

		}
		else if (m_rcBoundingBox.y > m_rcFollowBox.y + m_rcFollowBox.height + (m_iSpacing * m_iFormationID/fix + m_iGive))
		{
			if (m_pSpeed.y > -m_pMaxSpeed.y)
				m_pSpeed.y--;
			m_dDirection.Up();
		}
		else
		{
			if (m_pSpeed.y < 0)
				m_pSpeed.y++;
			if (m_pSpeed.y > 0)
				m_pSpeed.y--;
		}
	}
	public void Cover()
	{
		if (m_rcBoundingBox.x < m_rcFollowBox.x - (m_iSpacing * m_iFormationID) - m_iGive - ((int)m_rcBoundingBox.width/2))
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
			m_dDirection.Right();

		}
		else if (m_rcBoundingBox.x > m_rcFollowBox.x + m_rcFollowBox.width + (m_iSpacing * m_iFormationID) + m_iGive - ((int)m_rcBoundingBox.width/2))
		{
			if (m_pSpeed.x > -m_pMaxSpeed.x)
				m_pSpeed.x--;
			m_dDirection.Left();
		}
		else
		{
			if (m_pSpeed.x < 0)
				m_pSpeed.x++;
			if (m_pSpeed.x > 0)
				m_pSpeed.x--;
		}
		if (m_rcBoundingBox.y < m_rcFollowBox.y - m_iSpacing * m_iFormationID  - m_iGive - ((int)m_rcBoundingBox.height/2))
		{
			if (m_pSpeed.y < m_pMaxSpeed.y)
				m_pSpeed.y++;
			m_dDirection.Down();

		}
		else if (m_rcBoundingBox.y > m_rcFollowBox.y + m_rcFollowBox.height + m_iSpacing * m_iFormationID + m_iGive - ((int)m_rcBoundingBox.height/2))
		{
			if (m_pSpeed.y > -m_pMaxSpeed.y)
				m_pSpeed.y--;
			m_dDirection.Up();
		}
		else
		{
			if (m_pSpeed.y < 0)
				m_pSpeed.y++;
			if (m_pSpeed.y > 0)
				m_pSpeed.y--;
		}
	}
	public void Roam()
	{
		Sprite s = null;
		int x = 0;
		int start = (int)(Util.m_alSprite.size()*m_iID/Util.m_iNumOfAllys);
		x = start+2;
		boolean didnotfindenemy = false;
		while (true)
		{
			if (x >= Util.m_alSprite.size())
				x = 0;
			if (x == start)
			{
				didnotfindenemy = true;
				break;
			}
			s = ((Sprite)(Util.m_alSprite.get(x)));
			if (s.m_iFaction != m_iFaction)
			{
				m_iRoamFormation = 5;
				break;
			}
			x++;
		}
		if (didnotfindenemy)
		{
			
			m_iRoamFormation = 2;
			if (Util.m_alSprite.size() >= Util.m_iNumOfPlayers)
			{
				if (m_rcFollowBox == null && Util.m_iNumOfPlayers > 1)
				{
					int i = Util.RandomNumber(0,Util.m_iNumOfPlayers-1);
					m_rcFollowBox = ((Sprite)(Util.m_alSprite.get(i))).m_rcBoundingBox;
				}
				else
				{
					m_rcFollowBox = ((Sprite)(Util.m_alSprite.get(0))).m_rcBoundingBox;
				}
			}
		}
	
		
		if (m_iRoamFormation != 5)
			return;
		
		if (m_rcBoundingBox.x < s.m_rcBoundingBox.x)
		{
			if (m_pSpeed.x < m_pMaxSpeed.x)
				m_pSpeed.x++;
		}
		else if (m_rcBoundingBox.x > s.m_rcBoundingBox.x)
		{
			if (m_pSpeed.x > -m_pMaxSpeed.x)
				m_pSpeed.x--;
		}
		else
		{
			if (m_pSpeed.x < 0)
				m_pSpeed.x++;
			if (m_pSpeed.x > 0)
				m_pSpeed.x--;
		}
		if (m_rcBoundingBox.y < s.m_rcBoundingBox.y + 256)
		{
			if (m_pSpeed.y < m_pMaxSpeed.y)
				m_pSpeed.y++;
				
		}
		else if (m_rcBoundingBox.y > s.m_rcBoundingBox.y + 256)
		{
			if (m_pSpeed.y > -m_pMaxSpeed.y)
				m_pSpeed.y--;
		}
		else
		{
			if (m_pSpeed.y < 0)
				m_pSpeed.y++;
			if (m_pSpeed.y > 0)
				m_pSpeed.y--;
		}
	}
}
