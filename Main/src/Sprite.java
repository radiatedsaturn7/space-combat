import java.awt.*;
import java.util.*;

public class Sprite
{
	public Image m_iImage;
	public int m_iFrame;//Frame at which we are drawing
	public String m_sName;//Optional naming of sprite, alternative for searching
	protected boolean m_bSetFrame;
	public boolean m_bDonePlaying;
	public boolean m_bIsVisible;
	public int Start, End;
	public int m_iSpriteLoop;
	public boolean m_bIsSolid;
	public boolean m_bApplyGravity;
	public boolean m_bDidCompoundGravity;
	public int m_iCompoundedGravity;
	public Direction m_dDirection;
	public boolean m_bDelete;
	public int m_iFaction;
	public boolean m_bOnGround;
	public Time m_tDeathTime;
	
	public boolean m_bIsPlayer;
	
	//public Point pos;
	public Point m_pSpeed;
	public Point m_pMaxSpeed;
	public Rectangle m_rcBoundingBox;
	
	public Animation m_aCurrentAnimation;
	public ArrayList m_alAnimations;
	
	public Time m_tLastFrameUpdate;
	
	public Sprite()
	{
		m_iImage = Util.m_imExplosionImage;
		m_iFrame = 0;//Frame at which we are drawing
		m_sName = "";//Optional naming of sprite, alternative for searching
		m_bSetFrame = false;
		m_bDonePlaying = false;
		m_bIsVisible = false;
		m_bIsSolid = false;
		Start = 0;
		End = 0;
		m_iSpriteLoop = 0;
		//pos = new Point(s.pos);
		m_pSpeed = new Point();
		m_pMaxSpeed = new Point();
		//A BOUNDING BOX IS DIFFERENT THAN A POSITION
		m_rcBoundingBox = new Rectangle();
		m_bApplyGravity = false;
		m_bDidCompoundGravity = true;
		m_iCompoundedGravity = 0;
		m_bDelete = false;
		m_iFaction = 0;
		m_bOnGround = true;
		m_dDirection = new Direction();
		
		m_aCurrentAnimation = new Animation("default",1,1,true,1);
		
		m_alAnimations = new ArrayList();
		m_tLastFrameUpdate = new Time();
		m_tDeathTime = null;
		m_bIsPlayer = false;
	}
	
	public Sprite(Sprite s)
	{
		m_iImage = s.m_iImage;
		m_iFrame = s.m_iFrame;//Frame at which we are drawing
		m_sName = s.m_sName;//Optional naming of sprite, alternative for searching
		m_bSetFrame = s.m_bSetFrame;
		m_bDonePlaying = s.m_bDonePlaying;
		m_bIsVisible = s.m_bIsVisible;
		m_bIsSolid = s.m_bIsSolid;
		Start = s.Start;
		End = s.End;
		m_iSpriteLoop = s.m_iSpriteLoop;
		//pos = new Point(s.pos);
		m_pSpeed = new Point(s.m_pSpeed);
		m_pMaxSpeed = new Point(s.m_pMaxSpeed);
		//A BOUNDING BOX IS DIFFERENT THAN A POSITION
		m_rcBoundingBox = new Rectangle(s.m_rcBoundingBox);
		m_bApplyGravity = s.m_bApplyGravity;
		m_bDidCompoundGravity = s.m_bDidCompoundGravity;
		m_iCompoundedGravity = s.m_iCompoundedGravity;
		m_bDelete = s.m_bDelete;
		m_iFaction = s.m_iFaction;
		m_bOnGround = s.m_bOnGround;
		
		m_dDirection = new Direction(s.m_dDirection);
		
		if (s.m_aCurrentAnimation != null)
			m_aCurrentAnimation = new Animation (s.m_aCurrentAnimation);
		else
			m_aCurrentAnimation = new Animation("default",1,1,true,1);
		
		m_alAnimations = s.m_alAnimations;
		m_tLastFrameUpdate = s.m_tLastFrameUpdate;
		m_tDeathTime = s.m_tDeathTime;
		m_bIsPlayer = s.m_bIsPlayer;
	}
	public Sprite(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		Init(Pos, Size, image, frame, solid, applygravity);
		m_iFrame = 0;
		m_bSetFrame = false;
	}
	
	public void Init(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		m_bIsVisible = true;
		m_rcBoundingBox = new Rectangle (Pos.x, Pos.y, Size.x, Size.y);
		m_pSpeed = new Point(0,0);
		m_pMaxSpeed= new Point(8,8);
		m_iImage = image;	
		m_iFrame = frame;		
		m_tLastFrameUpdate = new Time();
		m_bDonePlaying = false;
		m_bIsSolid = solid;
		m_bApplyGravity = applygravity;
		m_bDidCompoundGravity = false;
		m_iCompoundedGravity = 0;
		m_dDirection = new Direction();
		m_dDirection.Right();
		m_bDelete = false;
		m_iFaction = 0;
		m_bOnGround = false;
		m_tDeathTime = null;
	}
	
	public boolean IsOnGround()
	{
		return m_bOnGround;	
	}
	
	public void SetAnimations(ArrayList A)
	{
		m_alAnimations = new ArrayList();
		for (int x = 0; x < A.size(); x++)
		{
			m_alAnimations.add((Animation)(A.get(x)));
		}
	}

	public void SetPosition(Point p)
	{
		//pos = new Point();
		//pos.x = p.x;
		//pos.y = p.y;
		m_rcBoundingBox.x = p.x;
		m_rcBoundingBox.y = p.y;
	}
	public void SetPosition(int x, int y)
	{
		//pos = new Point();
		//pos.x = x;
		//pos.y = y;
		m_rcBoundingBox.x = x;
		m_rcBoundingBox.y = y;
	}
	public void PlayAnimation(String s)
	{
		if (m_alAnimations == null)
			return;
		m_bDonePlaying = false;
		m_iSpriteLoop = 0;
		for (int x = 0; x < m_alAnimations.size(); x++)
		{
			Animation a = (Animation)(m_alAnimations.get(x));
			if (s.equals(a.m_sName))
				m_aCurrentAnimation=new Animation(a);
		}
		if (m_aCurrentAnimation==null)
			m_aCurrentAnimation=new Animation();
		m_iFrame = m_aCurrentAnimation.m_iStartFrame-1;
	//	m_tLastFrameUpdate = new Time();
	}
	public void PlayAnimation(int x)
	{
		if (x < m_alAnimations.size() && x >= 0)
		{
			Animation a = (Animation)(m_alAnimations.get(x));
			m_aCurrentAnimation=new Animation(a);
		}
		if (m_aCurrentAnimation==null)
			m_aCurrentAnimation=new Animation();
		m_iFrame = m_aCurrentAnimation.m_iStartFrame-1;
	}
	public void Reset()
	{
		m_iSpriteLoop = 0;
		m_iFrame = 0;
		m_bSetFrame = false;	

	}
	
	public void Paint(Graphics g)
	{
		g.drawImage(m_iImage, 
				(int)m_rcBoundingBox.x, 
				(int)m_rcBoundingBox.y, 
				(int)(m_rcBoundingBox.x + m_rcBoundingBox.width), 
				(int)(m_rcBoundingBox.y + m_rcBoundingBox.height),
				
				(int)(1), 
				(int)(1 + (m_rcBoundingBox.height * m_iFrame) + m_iFrame), 
				(int)(1 + m_rcBoundingBox.width),
				(int)((m_rcBoundingBox.height+1)*(m_iFrame+1)),
		
				 null, null);
	}
	
	public void DrawBoundingBox(Graphics g)
	{
		g.setColor(Color.red);
		g.drawRect(m_rcBoundingBox.x, m_rcBoundingBox.y, m_rcBoundingBox.width, m_rcBoundingBox.height);
	}

	public void PaintAnimation(Graphics g)
	{
		if (!m_bIsVisible)
			return;
			
		Time Temp =new Time(m_tLastFrameUpdate);
		if (m_aCurrentAnimation == null)
		{
			m_aCurrentAnimation = new Animation();
		}
		int i = (int)1000/m_aCurrentAnimation.m_iFPS;
		Temp.AddMilliseconds(i);

		if  (Util.m_tTime.IsGreaterThan(Temp))
		{	
			m_tLastFrameUpdate = new Time(Util.m_tTime);
			m_iFrame++;
			if (m_iFrame >= m_aCurrentAnimation.m_iEndFrame && m_aCurrentAnimation.m_bLoop == true)
			{
				m_iFrame = m_aCurrentAnimation.m_iStartFrame;
				m_iSpriteLoop++;
			}
			else if (m_iFrame >= m_aCurrentAnimation.m_iEndFrame)
			{
				m_bDonePlaying = true;
				m_iFrame--;
			}
		}
		Paint(g);
	}	
	
	public void Update()
	{
		if (m_tDeathTime != null)
		{
			if (m_tDeathTime.IsLessThan(Util.m_tTime))
			{
				m_bDelete = true;
			}
		}

		if (m_pSpeed == null)
		{
			m_pSpeed = new Point();
		}
		if (m_bDidCompoundGravity && m_iCompoundedGravity < 9)
			m_iCompoundedGravity++;
		else
			m_iCompoundedGravity = 0;
		//pos.x += speed.x;
		//pos.y += speed.y;
		m_rcBoundingBox.x += m_pSpeed.x;
		m_rcBoundingBox.y += m_pSpeed.y;
	}
	
	public void CollideWith (Sprite S)
	{
		if (S.m_iFaction == m_iFaction)
		{
			return;
		}
		else if (S.m_bIsSolid)
		{
			m_pSpeed.x = (int)(1/2)*(-m_pSpeed.x);
			m_pSpeed.y = (int)(1/2)*(-m_pSpeed.y);
			S.m_pSpeed.x = (int)(1/2)*(-S.m_pSpeed.x);
			S.m_pSpeed.y = (int)(1/2)*(-S.m_pSpeed.y);
		}
	}
	
	public boolean IsColliding(Rectangle B)
	{
		if (this.m_rcBoundingBox.intersects(B))
		{
			return true;
		}
		return false;
	}
	
	public boolean CollidesWith(Rectangle R)
	{
		if (this.m_rcBoundingBox.intersects(R))
		{
			return true;
		}
		return false;
	}
	
	public String GetName()
	{
		return m_sName;
	}
}