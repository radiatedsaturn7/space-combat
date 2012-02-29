import java.awt.*;

public class Controls
{
	public boolean m_bUp;
	public boolean m_bDown;
	public boolean m_bLeft;
	public boolean m_bRight;
	public boolean m_bA;
	public boolean m_bB;
	public boolean m_bX;
	public boolean m_bY;
	public boolean m_bL;
	public boolean m_bR;
	public boolean m_bStart;
	public boolean m_bSelect;
	
	public boolean m_bRUp;
	public boolean m_bRDown;
	public boolean m_bRLeft;
	public boolean m_bRRight;
	public boolean m_bRA;
	public boolean m_bRB;
	public boolean m_bRX;
	public boolean m_bRY;
	public boolean m_bRL;
	public boolean m_bRR;
	public boolean m_bRStart;
	public boolean m_bRSelect;
	
	public Controls()
	{
	 	m_bUp = false;
	 	m_bDown = false;
	 	m_bLeft = false;
	 	m_bRight = false;
		m_bA = false;
		m_bB = false;
		m_bX = false;
		m_bY = false;
		m_bL = false;
		m_bR = false;
		m_bStart = false;
		m_bSelect = false;
		m_bRUp = false;
	 	m_bRDown = false;
	 	m_bRLeft = false;
	 	m_bRRight = false;
		m_bRA = false;
		m_bRB = false;
		m_bRX = false;
		m_bRY = false;
		m_bRL = false;
		m_bRR = false;
		m_bRStart = false;
		m_bRSelect = false;
	}
	public Controls(Controls c)
	{
	 	m_bUp = c.m_bUp;
	 	m_bDown = c.m_bDown;
	 	m_bLeft = c.m_bLeft;
	 	m_bRight = c.m_bRight;
		m_bA = c.m_bA;
		m_bB = c.m_bB;
		m_bX = c.m_bX;
		m_bY = c.m_bY;
		m_bL = c.m_bL;
		m_bR = c.m_bR;
		m_bStart = c.m_bStart;
		m_bSelect = c.m_bSelect;
		m_bRUp = c.m_bRUp;
	 	m_bRDown = c.m_bRDown;
	 	m_bRLeft = c.m_bRLeft;
	 	m_bRRight = c.m_bRRight;
		m_bRA = c.m_bRA;
		m_bRB = c.m_bRB;
		m_bRX = c.m_bRX;
		m_bRY = c.m_bRY;
		m_bRL = c.m_bRL;
		m_bRR = c.m_bRR;
		m_bRStart = c.m_bRStart;
		m_bRSelect = c.m_bRSelect;
	}
	
	public static void HandleControls()
	{
		for (int x = 0; x < Util.m_iNumOfPlayers; x++)
		{
			Sprite S = (Sprite)Util.m_alSprite.get(x);

			if (S instanceof Character)
				if (((Character)(S)).m_iHealth<=0 || ((Character)(S)).m_bIsPlayer == false)
					continue;
			if (S.m_tDeathTime != null)
				continue;
			
			if (Util.m_cPlayerControls[x].m_bUp)
			{
				/*
				if (S.m_bDonePlaying || !S.m_aCurrentAnimation.m_sName.equals("WALK"))
				{
					S.PlayAnimation("UP");
				}
				*/
				if (!(Util.m_cPlayerControls[x].m_bR || Util.m_cPlayerControls[x].m_bL))
					S.m_dDirection.Up();
				if (S.m_pSpeed.y > -8)
					S.m_pSpeed.y-=1;
				
			}
			if (Util.m_cPlayerControls[x].m_bDown)
			{
				/*
				if (S.m_bDonePlaying || !S.m_aCurrentAnimation.m_sName.equals("WALK"))
				{
						S.PlayAnimation("DOWN");
				}
				*/
				if (!(Util.m_cPlayerControls[x].m_bR || Util.m_cPlayerControls[x].m_bL))
					S.m_dDirection.Down();
				if (S.m_pSpeed.y < 8)
					S.m_pSpeed.y+=1;
				
			}
			if (Util.m_cPlayerControls[x].m_bLeft)
			{
				/*
				if (S.m_bDonePlaying || !S.m_aCurrentAnimation.m_sName.equals("WALK"))
				{
					S.PlayAnimation("LEFT");
				}
				*/
				if (!(Util.m_cPlayerControls[x].m_bR || Util.m_cPlayerControls[x].m_bL))
					S.m_dDirection.Left();
				if (S.m_pSpeed.x > -8)
					S.m_pSpeed.x-=1;
				
			}
			if (Util.m_cPlayerControls[x].m_bRight)
			{
				/*
				if (S.m_bDonePlaying || !S.m_aCurrentAnimation.m_sName.equals("WALK"))
				{
						S.PlayAnimation("RIGHT");
				}
				*/
				if (!(Util.m_cPlayerControls[x].m_bR || Util.m_cPlayerControls[x].m_bL))
					S.m_dDirection.Right();
				if (S.m_pSpeed.x < 8)
					S.m_pSpeed.x+=1;
				
			}
			if (Util.m_cPlayerControls[x].m_bA)
			{
				Time t = new Time();
				if (((Character)(S)).m_wWeapon.m_sName.equals("GravityGun"))
				{
					t.AddMilliseconds(400);
					t.Update();
				}
				else if (((Character)(S)).m_wWeapon.m_sName.equals("FlameThrower"))
				{
					t.AddMilliseconds(600);
					t.Update();
				}
				else if (((Character)(S)).m_wWeapon.m_sName.equals("PulseLaser"))
				{
					t.AddMilliseconds(200);
					t.Update();
				}
				else
					t = null;
				if (((Character)(S)).m_wWeapon.CanShoot())
					((Character)(S)).m_wWeapon.Shoot(
							new Point(S.m_rcBoundingBox.x,S.m_rcBoundingBox.y - 37),
							new Point(S.m_pSpeed.x,-16 + S.m_pSpeed.y),0,t
						);
			}
			if (Util.m_cPlayerControls[x].m_bB)
			{
				if (((Character)(S)).CanRotateWeapon())
					((Character)(S)).WeaponRotate();
			}
			
			if (!Util.m_cPlayerControls[x].m_bUp && !Util.m_cPlayerControls[x].m_bDown)
			{
				if (S.m_pSpeed.y > 0)
					S.m_pSpeed.y--;
				if (S.m_pSpeed.y < 0)
					S.m_pSpeed.y++;
			}
			if (!Util.m_cPlayerControls[x].m_bLeft && !Util.m_cPlayerControls[x].m_bRight)
			{
				if (S.m_pSpeed.x > 0)
					S.m_pSpeed.x--;
				if (S.m_pSpeed.x < 0)
					S.m_pSpeed.x++;
			}
		if (S.m_pSpeed.y > 0)
		{
			if (S.m_pSpeed.x > 0)
				S.PlayAnimation("DOWNRIGHT");
			else if (S.m_pSpeed.x < 0)
				S.PlayAnimation("DOWNLEFT");
			else
				S.PlayAnimation("DOWN");
		}
		else if (S.m_pSpeed.y < 0)
		{
			if (S.m_pSpeed.x > 0)
				S.PlayAnimation("UPRIGHT");
			else if (S.m_pSpeed.x < 0)
				S.PlayAnimation("UPLEFT");
			else
				S.PlayAnimation("UP");
		}
		else if (S.m_pSpeed.x > 0)
			S.PlayAnimation("RIGHT");
		else if (S.m_pSpeed.x < 0)
			S.PlayAnimation("LEFT");
		else
			S.PlayAnimation("IDLE");
		}
			
	}
	
	
	public static void HandleKeyDownControls(Event e, int key)
	{
		if (Util.m_alPrintText.size() > 0 && key == Event.ENTER && Util.m_alPrintText.get(0) instanceof TextBox)
		{
			Util.m_alPrintText.remove(0);
		}
		else if (Util.m_alPrintText.size() > 0)
		{
			//return false;
			return;
		}
	  	if(key == 't'/*Event.UP*/)
	  	{
		    Util.m_cPlayerControls[0].m_bUp = true;
		    Util.m_cPlayerControls[0].m_bRUp = true;
		}
		if(key == 'g'/*Event.DOWN*/)
		{	
			Util.m_cPlayerControls[0].m_bDown = true;
			Util.m_cPlayerControls[0].m_bRDown = true;
		}
		if(key == 'f'/*Event.LEFT*/)
		{	
			Util.m_cPlayerControls[0].m_bLeft = true;
		 	Util.m_cPlayerControls[0].m_bRLeft = true;
		}
		if(key == 'h'/*Event.RIGHT*/)
		{	
			Util.m_cPlayerControls[0].m_bRight = true;
		 	Util.m_cPlayerControls[0].m_bRRight = true;
		}
		if(key == 'e'/*Event.ENTER*/)
	 	{	
	 		Util.m_cPlayerControls[0].m_bStart = true; 	
	 		Util.m_cPlayerControls[0].m_bRStart = true;
	 	}	
		if(key == 'w')
	 	{	
	 		Util.m_cPlayerControls[0].m_bA = true; 	
	 		Util.m_cPlayerControls[0].m_bRA = true;
	 	}
		if(key == 'a')
	 	{	
	 		Util.m_cPlayerControls[0].m_bB = true; 	
	 		Util.m_cPlayerControls[0].m_bRB = true;
	 	}
		if(key == 's')
	 	{	
	 		Util.m_cPlayerControls[0].m_bX = true; 	
	 		Util.m_cPlayerControls[0].m_bRX = true;
	 	}
		if(key == 'd')
	 	{	
	 		Util.m_cPlayerControls[0].m_bY = true; 	
	 		Util.m_cPlayerControls[0].m_bRY = true;
	 	}
		
		if(key == '8'/*Event.UP*/)
	  	{
		    Util.m_cPlayerControls[1].m_bUp = true;
		    Util.m_cPlayerControls[1].m_bRUp = true;
		}
		if(key == '5'/*Event.DOWN*/)
		{	
			Util.m_cPlayerControls[1].m_bDown = true;
			Util.m_cPlayerControls[1].m_bRDown = true;
		}
		if(key == '4'/*Event.LEFT*/)
		{	
			Util.m_cPlayerControls[1].m_bLeft = true;
		 	Util.m_cPlayerControls[1].m_bRLeft = true;
		}
		if(key == '6'/*Event.RIGHT*/)
		{	
			Util.m_cPlayerControls[1].m_bRight = true;
		 	Util.m_cPlayerControls[1].m_bRRight = true;
		}
		if(key == '0'/*Event.ENTER*/)
	 	{	
	 		Util.m_cPlayerControls[1].m_bStart = true; 	
	 		Util.m_cPlayerControls[1].m_bRStart = true;
	 	}	
		if(key == 'i')
	 	{	
	 		Util.m_cPlayerControls[1].m_bA = true; 	
	 		Util.m_cPlayerControls[1].m_bRA = true;
	 	}
		if(key == 'j')
	 	{	
	 		Util.m_cPlayerControls[1].m_bB = true; 	
	 		Util.m_cPlayerControls[1].m_bRB = true;
	 	}
		if(key == 'k')
	 	{	
	 		Util.m_cPlayerControls[1].m_bX = true; 	
	 		Util.m_cPlayerControls[1].m_bRX = true;
	 	}
		if(key == 'l')
	 	{	
	 		Util.m_cPlayerControls[1].m_bY = true; 	
	 		Util.m_cPlayerControls[1].m_bRY = true;
	 	}

		/*
	 	else if (Util.m_cPlayerControls[0].m_bRStart)
		{
			Util.m_cPlayerControls[0].m_bStart = false;
		}
		*/
	  	//return false;
	}
	public static void HandleKeyUpControls(Event e, int key)
	{
		if(key == 't'/*Event.UP*/)
	  	{
		    Util.m_cPlayerControls[0].m_bUp = false;
		    Util.m_cPlayerControls[0].m_bRUp = false;
		}
		if(key == 'g'/*Event.DOWN*/)
		{	
			Util.m_cPlayerControls[0].m_bDown = false;
			Util.m_cPlayerControls[0].m_bRDown = false;
		}
		if(key == 'f'/*Event.LEFT*/)
		{	
			Util.m_cPlayerControls[0].m_bLeft = false;
		 	Util.m_cPlayerControls[0].m_bRLeft = false;
		}
		if(key == 'h'/*Event.RIGHT*/)
		{	
			Util.m_cPlayerControls[0].m_bRight = false;
		 	Util.m_cPlayerControls[0].m_bRRight = false;
		}
		if(key == 'e'/*Event.ENTER*/)
	 	{	
	 		Util.m_cPlayerControls[0].m_bStart = false; 	
	 		Util.m_cPlayerControls[0].m_bRStart = false;
	 	}	
		if(key == 'w')
	 	{	
	 		Util.m_cPlayerControls[0].m_bA = false; 	
	 		Util.m_cPlayerControls[0].m_bRA = false;
	 	}
		if(key == 'a')
	 	{	
	 		Util.m_cPlayerControls[0].m_bB = false; 	
	 		Util.m_cPlayerControls[0].m_bRB = false;
	 	}
		if(key == 's')
	 	{	
	 		Util.m_cPlayerControls[0].m_bX = false; 	
	 		Util.m_cPlayerControls[0].m_bRX = false;
	 	}
		if(key == 'd')
	 	{	
	 		Util.m_cPlayerControls[0].m_bY = false; 	
	 		Util.m_cPlayerControls[0].m_bRY = false;
	 	}
		
		if(key == '8'/*Event.UP*/)
	  	{
		    Util.m_cPlayerControls[1].m_bUp = false;
		    Util.m_cPlayerControls[1].m_bRUp = false;
		}
		if(key == '5'/*Event.DOWN*/)
		{	
			Util.m_cPlayerControls[1].m_bDown = false;
			Util.m_cPlayerControls[1].m_bRDown = false;
		}
		if(key == '4'/*Event.LEFT*/)
		{	
			Util.m_cPlayerControls[1].m_bLeft = false;
		 	Util.m_cPlayerControls[1].m_bRLeft = false;
		}
		if(key == '6'/*Event.RIGHT*/)
		{	
			Util.m_cPlayerControls[1].m_bRight = false;
		 	Util.m_cPlayerControls[1].m_bRRight = false;
		}
		if(key == '0'/*Event.ENTER*/)
	 	{	
	 		Util.m_cPlayerControls[1].m_bStart = false; 	
	 		Util.m_cPlayerControls[1].m_bRStart = false;
	 	}	
		if(key == 'i')
	 	{	
	 		Util.m_cPlayerControls[1].m_bA = false; 	
	 		Util.m_cPlayerControls[1].m_bRA = false;
	 	}
		if(key == 'j')
	 	{	
	 		Util.m_cPlayerControls[1].m_bB = false; 	
	 		Util.m_cPlayerControls[1].m_bRB = false;
	 	}
		if(key == 'k')
	 	{	
	 		Util.m_cPlayerControls[1].m_bX = false; 	
	 		Util.m_cPlayerControls[1].m_bRX = false;
	 	}
		if(key == 'l')
	 	{	
	 		Util.m_cPlayerControls[1].m_bY = false; 	
	 		Util.m_cPlayerControls[1].m_bRY = false;
	 	}
	  	//return true;
	}
}