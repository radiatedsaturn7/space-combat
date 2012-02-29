/* COPYRIGHT 2005 ROB PISKULE
 *ALL RIGHTS RESERVED
 *
 *OPEN SOURCE< LEAVE ALL CREDITS AT TOP!*/

//FIX POWER UP SPRITE
//FIX ENEMY SHOT SO IT WILL SHOOT AT ANYONE

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.awt.geom.Line2D;


public class DMain extends Applet implements Runnable, MouseListener
{
	static final long serialVersionUID = 1;
	//DEFINES
	int STARTING = 0;
	int SPLASH = 1;
	int NEWGAME = 2;
	int LOADGAME = 3;
	int OPTIONS = 4;
	int RUNNING = 5;
	int DEMO = 6;
	int END = 7;
	
	int _tempenemyrate;
	int _temppowerrate;
	int _tempstarrate;
	boolean _tempenemies;
	
	//OTHER
	boolean m_bUseButtonToggle = false;
	boolean m_bStartNewThread = true;
	
	static int m_iPointerSelection = 0;
	
	private Image dbImage;
	private Graphics dbg;
	
	Sprite s;
	
	Line2D.Float G_l;
	ArrayList m_alAllEntities = new ArrayList();
	
	public int m_iGameStatus;
	
	/*
	public static Image GetImage(URL u, String s)
	{
		return Applet.getImage(u,s);
	}
	*/
	
	public void init()
	{
		Util.m_iGravity = 0;
		m_iGameStatus = STARTING;
		Util.m_cPlayerControls[0] = new Controls();
		Util.m_cPlayerControls[1] = new Controls();
		Time t = new Time(); //time = 0
		Util.SetTime(t); //set global time to 0
		Util.CodeBase = getCodeBase();
		Util.m_iNumOfPlayers= 1;
		Util.m_iNumOfAllys = 5;
		_tempstarrate = 0;
		_tempenemyrate = 0;
		_temppowerrate = 0;
		_tempenemies = false;
				int camsizex = 150;
		int camsizey = 100;
		Util.m_rcCamera = new Camera();
		Util.m_rcScreen = new Rectangle();
		Util.m_pGlobalOffset = new Point();
		Util.m_pScrollSpeed = new Point();
		Util.m_rcScreen.x = 0;
		Util.m_rcScreen.y = 0;
		
		Util.m_rcScreen.width = 800;
		Util.m_rcScreen.height = 600;
		
		Util.m_rcCamera.width = camsizex;
		Util.m_rcCamera.height = camsizey;
		Util.m_rcCamera.x = (int)((Util.m_rcScreen.width/2)-(Util.m_rcCamera.width/2));
		Util.m_rcCamera.y = (int)((Util.m_rcScreen.height/2)-(Util.m_rcCamera.height/2));
		Util.m_pGlobalOffset.x = -124;
		Util.m_pGlobalOffset.y = -2024;
		Util.m_pScrollSpeed.x = 0;
		Util.m_pScrollSpeed.y = 0;
		this.resize(Util.m_rcScreen.width,Util.m_rcScreen.height);
		Util.m_imEnemyImage = getImage(getCodeBase(), "Enemy.gif");
		Util.m_imShotImage = getImage(getCodeBase(), "Helaser.gif");
		Util.m_imLaserImage = getImage(getCodeBase(), "Hlaser.gif");
		Util.m_imBulletImage = getImage(getCodeBase(), "Hmgun.gif");
		Util.m_imFlameImage = getImage(getCodeBase(), "Hflame.gif");
		Util.m_imPulseImage = getImage(getCodeBase(), "Hpulse.gif");
		Util.m_imHellImage = getImage(getCodeBase(), "Hhell.gif");
		Util.m_imGravImage = getImage(getCodeBase(), "Hgrav.gif");
		Util.m_imExplosionImage = getImage(getCodeBase(), "Exp1.gif");
		Util.m_imParticleImage = getImage(getCodeBase(), "Particle.gif");
		Util.m_imPowerUpImage = getImage(getCodeBase(), "PowerUp.gif");
		Util.m_imMissileImage = getImage(getCodeBase(), "Hmissile.gif");
		
		Util.m_imEnemyImageNV = getImage(getCodeBase(), "EnemyNV.gif");
		Util.m_imShotImageNV = getImage(getCodeBase(), "HelaserNV.gif");
		Util.m_imLaserImageNV = getImage(getCodeBase(), "HlaserNV.gif");
		Util.m_imBulletImageNV = getImage(getCodeBase(), "HmgunNV.gif");
		Util.m_imFlameImageNV = getImage(getCodeBase(), "HflameNV.gif");
		Util.m_imPulseImageNV = getImage(getCodeBase(), "HpulseNV.gif");
		Util.m_imHellImageNV = getImage(getCodeBase(), "HhellNV.gif");
		Util.m_imGravImageNV = getImage(getCodeBase(), "HgravNV.gif");
		Util.m_imExplosionImageNV = getImage(getCodeBase(), "Exp1NV.gif");
		Util.m_imParticleImageNV = getImage(getCodeBase(), "ParticleNV.gif");
		Util.m_imPowerUpImageNV = getImage(getCodeBase(), "PowerUpNV.gif");
		Util.m_imMissileImageNV = getImage(getCodeBase(), "HmissileNV.gif");
		Util.m_lCurrentLevel = null;
		Util.m_alHUD = new ArrayList();
		
		Util.m_iVision = 0;
		
		Util.m_iKills = new int[2];
		Util.m_iKills[0] = 0;
		Util.m_iKills[1] = 0;
	
		if (!m_bStartNewThread)
		{
			return;
		}
		//THINGS WE ONLY WANT TO DO ONCE!
		Util.m_iSetup = new int[8];
		Util.m_iSetup[0] = 1;//players
		Util.m_iSetup[1] = 3;//ship
		Util.m_iSetup[2] = 4;//gun
		Util.m_iSetup[3] = 2;//hp
		Util.m_iSetup[4] = 7;//ship
		Util.m_iSetup[5] = 4;//gun
		Util.m_iSetup[6] = 2;//hp
		Util.m_iSetup[7] = 5;//difficulty
		Util.m_iDifficulty = 3;
		m_bStartNewThread = false;
		Thread th = new Thread (this);
		th.start ();
	}

	public void start ()
	{
		//when the window is re opened, do this
	}

	public void stop()
	{
		//when the window is minimized, do this
	}

	public void destroy()
	{

	}

	public void run ()
	{
		Thread.currentThread().setPriority(Thread.MIN_PRIORITY);
		while (true)
		{
			repaint();
			try
			{
				Thread.sleep (35);
				Util.m_tTime.AddMilliseconds(35);
			}
			catch (InterruptedException ex)
			{
			}
			Thread.currentThread().setPriority(Thread.NORM_PRIORITY);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	public void Starting(Graphics g)
	{
		Animation a = new Animation();
		ArrayList  AnimationList = new ArrayList();
		Sprite s = new Sprite();
		Util.m_alPrintText  = new ArrayList();
		
		/*
		s = new Sprite(new Point(0,0), new Point(64,48), getImage(getCodeBase(), "Loading.jpg") ,1, false, false);
			AnimationList = new ArrayList();
			a = new Animation("PRINT",0,1,true,17);
			AnimationList.add(a);
			s.SetAnimations(AnimationList);
			s.PlayAnimation("PRINT");
		Util.m_alSprite.add(s);
		*/

			Util.m_alPrintText.add(new Text("Start", 140,100));
			Util.m_alPrintText.add(new Text("Load", 140,120));
			Util.m_alPrintText.add(new Text("Options", 140,140));
			Util.m_alSprite = new ArrayList();
			
			s = new Sprite(new Point(0,0), new Point(800,600), getImage(getCodeBase(), "Splash.gif") ,1, false, false);
				AnimationList = new ArrayList();
				a = new Animation("PRINT",0,0,true,1);
				AnimationList.add(a);
				s.SetAnimations(AnimationList);
				s.PlayAnimation("PRINT");
			Util.m_alSprite.add(s);
			s = new Sprite(new Point(0,100),new Point(135,480),getImage(getCodeBase(), "Cursor.jpg"), 1, false, false);
				AnimationList = new ArrayList();
				a = new Animation("PRINT",0,0,true,17);
				AnimationList.add(a);
				s.SetAnimations(AnimationList);
				s.PlayAnimation("PRINT");
			Util.m_alSprite.add(s);
			
			m_iGameStatus = SPLASH;

	}
	public void Splash(Graphics g)
	{
		//System.out.println(Util.m_cPlayerControls[0].m_bDown);
		Sprite pointer = ((Sprite)(Util.m_alSprite.get(1)));
		if (Util.m_cPlayerControls[0].m_bDown)
		{
			if (pointer.m_rcBoundingBox.y < 130)
			pointer.m_rcBoundingBox.y++;
		}
		else if (Util.m_cPlayerControls[0].m_bUp)
		{
			if (pointer.m_rcBoundingBox.y > 90)
			pointer.m_rcBoundingBox.y--;
		}
			
		if (pointer.m_rcBoundingBox.y < 105)
		{
			//NEW GAME
			Util.SetAllTextColor(Color.black);
			Util.SetTextColor(0,Color.yellow);
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_alPrintText = new ArrayList();
				Util.m_alSprite = new ArrayList();
				Util.m_cPlayerControls[0].m_bStart = false;
				m_iGameStatus = NEWGAME;
			}
		}
				
		if (pointer.m_rcBoundingBox.y >= 105 && pointer.m_rcBoundingBox.y < 120)
		{
			//LOAD GAME
			Util.SetAllTextColor(Color.black);
			Util.SetTextColor(1,Color.yellow);
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_alPrintText = new ArrayList();
				Util.m_alSprite = new ArrayList();
				Util.m_cPlayerControls[0].m_bStart = false;
				m_iGameStatus = LOADGAME;
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 120)
		{
			//OPTIONS
			Util.SetAllTextColor(Color.black);
			Util.SetTextColor(2,Color.yellow);	
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_alPrintText = null;
				Util.m_alPrintText = new ArrayList();
				
				Util.m_alPrintText.add(new Text("Players", 100,80));
				
					Util.m_alPrintText.add(new Text("One Player", 140,100));
				
				Util.m_alPrintText.add(new Text("Player One Setup", 100,120));
				
					Util.m_alPrintText.add(new Text("Sentinel", 140,140));
					Util.m_alPrintText.add(new Text("Pulse Laser", 140,160));
					Util.m_alPrintText.add(new Text("Health : 100%", 140,180));
					
				Util.m_alPrintText.add(new Text("Player Two Setup", 100,200));
					
					Util.m_alPrintText.add(new Text("Hunter", 140,220));
					Util.m_alPrintText.add(new Text("Pulse Laser", 140,240));
					Util.m_alPrintText.add(new Text("Health : 100%", 140,260));
					
				Util.m_alPrintText.add(new Text("Difficulty", 100,280));
					Util.m_alPrintText.add(new Text("Easy", 140,300));
					
				Util.m_alPrintText.add(new Text("Exit Options", 100,320));
					
				Util.m_alSprite = new ArrayList();
				
				s = new Sprite(new Point(0,0), new Point(800,600), getImage(getCodeBase(), "Options.gif") ,1, false, false);
					ArrayList AnimationList = new ArrayList();
					Animation a = new Animation("PRINT",0,0,true,1);
					AnimationList.add(a);
					s.SetAnimations(AnimationList);
					s.PlayAnimation("PRINT");
				Util.m_alSprite.add(s);
				s = new Sprite(new Point(0,100),new Point(135,480),getImage(getCodeBase(), "Cursor.jpg"), 1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("PRINT",0,0,true,17);
					AnimationList.add(a);
					s.SetAnimations(AnimationList);
					s.PlayAnimation("PRINT");
				Util.m_alSprite.add(s);
				Util.m_cPlayerControls[0].m_bStart = false;
				m_iGameStatus = OPTIONS;
			}
		}
		
	}
	public void Loadgame(Graphics g)
	{
		/*
		Util.m_alPrintText = new ArrayList();
		Util.m_alSprite = new ArrayList();
		m_iGameStatus = RUNNING;
		*/
	}
	public void Options(Graphics g)
	{
		Sprite pointer = ((Sprite)(Util.m_alSprite.get(1)));
		if (Util.m_cPlayerControls[0].m_bDown)
		{
			if (pointer.m_rcBoundingBox.y < 225)
			pointer.m_rcBoundingBox.y++;
		}
		else if (Util.m_cPlayerControls[0].m_bUp)
		{
			if (pointer.m_rcBoundingBox.y > 90)
			pointer.m_rcBoundingBox.y--;
		}

		Text t = ((Text)(Util.m_alPrintText.get(1)));
		if (Util.m_iSetup[0] == 1)
		{
			t.m_sText = "One Player";
		}
		else if (Util.m_iSetup[0] == 2)
		{
			t.m_sText = "Two Player";
		}
						
		t = ((Text)(Util.m_alPrintText.get(3)));
		if (Util.m_iSetup[1] == 1)
		{
			t.m_sText = "Paladin";
		}
		else if (Util.m_iSetup[1] == 2)
		{
			t.m_sText = "Calumniator";
		}
		else if (Util.m_iSetup[1] == 3)
		{
			t.m_sText = "Sentinel";
		}
		else if (Util.m_iSetup[1] == 4)
		{
			t.m_sText = "Exemplar";
		}
		else if (Util.m_iSetup[1] == 5)
		{
			t.m_sText = "Pariah";
		}
		else if (Util.m_iSetup[1] == 6)
		{
			t.m_sText = "Renegade";
		}
		else if (Util.m_iSetup[1] == 7)
		{
			t.m_sText = "Hunter";
		}
		else if (Util.m_iSetup[1] == 8 && Util.m_iSetup[4] <= 7 && Util.m_iSetup[0] == 2)
		{
			t.m_sText = "Player 2 Turret";
		}
		
		t = ((Text)(Util.m_alPrintText.get(4)));
		if (Util.m_iSetup[2] == 1)
		{
			t.m_sText = "Laser";
		}
		else if (Util.m_iSetup[2] == 2)
		{
			t.m_sText = "Machine Gun";
		}
		else if (Util.m_iSetup[2] == 3)
		{
			t.m_sText = "Flame Thrower";
		}
		else if (Util.m_iSetup[2] == 4)
		{
			t.m_sText = "Pulse Laser";
		}
		else if (Util.m_iSetup[2] == 5)
		{
			t.m_sText = "Rail Gun";
		}
		else if (Util.m_iSetup[2] == 6)
		{
			t.m_sText = "Singularity Projector";
		}
		
		t = ((Text)(Util.m_alPrintText.get(5)));
		if (Util.m_iSetup[3] == 1)
		{
			t.m_sText = "Health: 50%";
		}
		else if (Util.m_iSetup[3] == 2)
		{
			t.m_sText = "Health: 100%";
		}
		else if (Util.m_iSetup[3] == 3)
		{
			t.m_sText = "Health: 150%";
		}
		else if (Util.m_iSetup[3] == 4)
		{
			t.m_sText = "Health: 200%";
		}
		else if (Util.m_iSetup[3] == 5)
		{
			t.m_sText = "Health: 300%";
		}
		else if (Util.m_iSetup[3] == 6)
		{
			t.m_sText = "Health: 500%";
		}
		
		t = ((Text)(Util.m_alPrintText.get(7)));
		if (Util.m_iSetup[4] == 1)
		{
			t.m_sText = "Paladin";
		}
		else if (Util.m_iSetup[4] == 2)
		{
			t.m_sText = "Calumniator";
		}
		else if (Util.m_iSetup[4] == 3)
		{
			t.m_sText = "Sentinel";
		}
		else if (Util.m_iSetup[4] == 4)
		{
			t.m_sText = "Exemplar";
		}
		else if (Util.m_iSetup[4] == 5)
		{
			t.m_sText = "Pariah";
		}
		else if (Util.m_iSetup[4] == 6)
		{
			t.m_sText = "Renegade";
		}
		else if (Util.m_iSetup[4] == 7)
		{
			t.m_sText = "Hunter";
		}
		else if (Util.m_iSetup[4] == 8)
		{
			t.m_sText = "Player 1 Turret";
		}
		
		t = ((Text)(Util.m_alPrintText.get(8)));
		if (Util.m_iSetup[5] == 1)
		{
			t.m_sText = "Laser";
		}
		else if (Util.m_iSetup[5] == 2)
		{
			t.m_sText = "Machine Gun";
		}
		else if (Util.m_iSetup[5] == 3)
		{
			t.m_sText = "Flame Thrower";
		}
		else if (Util.m_iSetup[5] == 4)
		{
			t.m_sText = "Pulse Laser";
		}
		else if (Util.m_iSetup[5] == 5)
		{
			t.m_sText = "Rail Gun";
		}
		else if (Util.m_iSetup[5] == 6)
		{
			t.m_sText = "Singularity Projector";
		}
		
		t = ((Text)(Util.m_alPrintText.get(9)));
		if (Util.m_iSetup[6] == 1)
		{
			t.m_sText = "Health: 50%";
		}
		else if (Util.m_iSetup[6] == 2)
		{
			t.m_sText = "Health: 100%";
		}
		else if (Util.m_iSetup[6] == 3)
		{
			t.m_sText = "Health: 150%";
		}
		else if (Util.m_iSetup[6] == 4)
		{
			t.m_sText = "Health: 200%";
		}
		else if (Util.m_iSetup[6] == 5)
		{
			t.m_sText = "Health: 300%";
		}
		else if (Util.m_iSetup[6] == 6)
		{
			t.m_sText = "Health: 500%";
		}
		
		t = ((Text)(Util.m_alPrintText.get(11)));
		if (Util.m_iSetup[7] == 1)
		{
			t.m_sText = "Very Easy";
		}
		else if (Util.m_iSetup[7] == 2)
		{
			t.m_sText = "Easy";
		}
		else if (Util.m_iSetup[7] == 3)
		{
			t.m_sText = "Normal";
		}
		else if (Util.m_iSetup[7] == 4)
		{
			t.m_sText = "Hard";
		}
		else if (Util.m_iSetup[7] == 5)
		{
			t.m_sText = "Very Hard";
		}
				
		if (pointer.m_rcBoundingBox.y < 105)
		{
			//One or Two Player
			Util.SetAllTextColor(Color.black);
			Util.SetTextColor(1,Color.yellow);	
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				if (Util.m_iSetup[0] == 1)
				{
					Util.m_iSetup[0] = 2;
				}
				else if (Util.m_iSetup[0] == 2)
				{
					Util.m_iSetup[0] = 1;
				}
				if (Util.m_iSetup[1] > 7 && Util.m_iSetup[0] == 1)
					Util.m_iSetup[1] = 1;
				Util.m_cPlayerControls[0].m_bStart = false;
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 105 && pointer.m_rcBoundingBox.y < 120)
		{
			//P1 Ship
			Util.SetAllTextColor(Color.black);
			Util.SetTextColor(3,Color.yellow);	
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_iSetup[1]++;
				if (Util.m_iSetup[1] > 8 || (Util.m_iSetup[1] >= 8 && Util.m_iSetup[0] == 1) || (Util.m_iSetup[4] >= 8 && Util.m_iSetup[1] >= 8))
					Util.m_iSetup[1] = 1;
				Util.m_cPlayerControls[0].m_bStart = false;
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 120 && pointer.m_rcBoundingBox.y < 135)
		{
			if (Util.m_iSetup[1] == 8)
			{
				pointer.m_rcBoundingBox.y = 150;
			}
			else
			{
				//P1 Weapon
				Util.SetAllTextColor(Color.black);
				Util.SetTextColor(4,Color.yellow);	
				if (Util.m_cPlayerControls[0].m_bStart)
				{
					Util.m_iSetup[2]++;
					if (Util.m_iSetup[2] > 6)
						Util.m_iSetup[2] = 1;
					Util.m_cPlayerControls[0].m_bStart = false;
				}
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 135 && pointer.m_rcBoundingBox.y < 150)
		{
			if (Util.m_iSetup[1] == 8)
			{
				pointer.m_rcBoundingBox.y = 120;
			}
			else
			{
				//P1 Health
				Util.SetAllTextColor(Color.black);
				Util.SetTextColor(5,Color.yellow);	
				if (Util.m_cPlayerControls[0].m_bStart)
				{
					Util.m_iSetup[3]++;
					if (Util.m_iSetup[3] > 6)
						Util.m_iSetup[3] = 1;
					Util.m_cPlayerControls[0].m_bStart = false;
				}
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 150 && pointer.m_rcBoundingBox.y < 165)
		{
			if (Util.m_iSetup[0] == 1)
			{
				pointer.m_rcBoundingBox.y = 195;
			}
			else
			{
				//P2 Ship
				Util.SetAllTextColor(Color.black);
				Util.SetTextColor(7,Color.yellow);	
				if (Util.m_cPlayerControls[0].m_bStart)
				{
					Util.m_iSetup[4]++;
					if (Util.m_iSetup[4] > 8 || (Util.m_iSetup[4] >= 8 && Util.m_iSetup[1] >= 8))
						Util.m_iSetup[4] = 1;
					Util.m_cPlayerControls[0].m_bStart = false;
				}
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 165 && pointer.m_rcBoundingBox.y < 180)
		{
			//P2 Weapon
			if (Util.m_iSetup[4] == 8)
			{
				pointer.m_rcBoundingBox.y = 195;
			}
			else
			{
				Util.SetAllTextColor(Color.black);
				Util.SetTextColor(8,Color.yellow);	
				if (Util.m_cPlayerControls[0].m_bStart)
				{
					Util.m_iSetup[5]++;
					if (Util.m_iSetup[5] > 6)
						Util.m_iSetup[5] = 1;
					
					Util.m_cPlayerControls[0].m_bStart = false;
				}
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 180 && pointer.m_rcBoundingBox.y < 195)
		{
			if (Util.m_iSetup[4] == 8)
			{
				pointer.m_rcBoundingBox.y = 165;
			}
			else if (Util.m_iSetup[0] == 1)
			{
				pointer.m_rcBoundingBox.y = 149;
			}
			else
			{
				//P2 Health
				Util.SetAllTextColor(Color.black);
				Util.SetTextColor(9,Color.yellow);	
				if (Util.m_cPlayerControls[0].m_bStart)
				{
					Util.m_iSetup[6]++;
					if (Util.m_iSetup[6] > 6)
						Util.m_iSetup[6] = 1;
					Util.m_cPlayerControls[0].m_bStart = false;
				}
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 195 && pointer.m_rcBoundingBox.y < 210)
		{
			//Difficulty
			Util.SetAllTextColor(Color.black);
			Util.SetTextColor(11,Color.yellow);	
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_iSetup[7]++;
				if (Util.m_iSetup[7] > 5)
					Util.m_iSetup[7] = 1;
				Util.m_cPlayerControls[0].m_bStart = false;
			}
		}
		else if (pointer.m_rcBoundingBox.y >= 210 && pointer.m_rcBoundingBox.y < 225)
		{
			//Exit
			Util.SetAllTextColor(Color.black);
			Util.SetTextColor(12,Color.yellow);	
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_alPrintText = new ArrayList();
				Util.m_alSprite = new ArrayList();
				Util.m_cPlayerControls[0].m_bStart = false;
				m_iGameStatus = STARTING;
			}
		}
		
		if (Util.m_iSetup[0] == 1)
		{
			Util.SetTextColor(7,Color.gray);
			Util.SetTextColor(8,Color.gray);
			Util.SetTextColor(9,Color.gray);
			if (Util.m_iSetup[1] == 8)
			{
				Util.m_iSetup[1] = 7;
			}
		}
		if (Util.m_iSetup[1] == 8)
		{
			Util.SetTextColor(4,Color.gray);
			Util.SetTextColor(5,Color.gray);
		}
		if (Util.m_iSetup[4] == 8)
		{
			Util.SetTextColor(8,Color.gray);
			Util.SetTextColor(9,Color.gray);
		}
	}
	public void Run(Graphics g)
	{
		int yes = Util.RandomNumber(0,_tempenemyrate);
			if (yes == 1 && _tempenemies == true)
			{
				int y = Util.RandomNumber(0,7);

				if (y == 0)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),-31),false,true);
				if (y == 1)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),-31),false,true);
				if (y == 2)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),-31),true,true);
				if (y == 3)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),-31),true,true);
				if (y == 4)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),799),false,false);
				if (y == 5)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),799),false,false);
				if (y == 6)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),799),true,false);
				if (y == 7)
					Util.AddEnemy(Util.RandomNumber(1,13),Util.RandomNumber(1,3),Util.RandomNumber(1,6),new Point(50+(200*Util.RandomNumber(0,4)),799),true,false);
			}
			yes = Util.RandomNumber(0,_temppowerrate);
			//if (yes == 1)
				//Util.AddPowerUp(new Point(50+(200*Util.RandomNumber(0,4)),50),new Point(0,8));
			yes = Util.RandomNumber(0,_tempstarrate);
			if (yes == 1)
				Level.AddStar();

		boolean yes3 = true;
		boolean lostgame = false;
		if (Util.m_alSprite.size() > 1)
		{
			Sprite s1 = (Sprite)(Util.m_alSprite.get(0));
			Sprite s2 = (Sprite)(Util.m_alSprite.get(1));
			if (!(s1.m_bIsPlayer || s2.m_bIsPlayer))
					lostgame = true;
		}
		else
		{
			Sprite s1 = (Sprite)(Util.m_alSprite.get(0));
			if (!(s1.m_bIsPlayer))
					lostgame = true;
		}
		if (lostgame)
		{
			Character s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PSentinel.gif") ,1, true, true);
			Text t = new Text("Game Status",0,0);
			Text t2 = new Text("All of your base are belong to us!",0,0);
			TextBox t3 = new TextBox(new Text(t),new Text(t2),s,new Point(300,300));
			Util.m_alPrintText.add(t3);
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				init();
				start();
				m_iGameStatus = STARTING;
			}
		}
		
		if (Util.m_cPlayerControls[0].m_bStart)
			m_iGameStatus = RUNNING;
		
		if (yes3)
		{
			/*
			Character s = new Character(new Point(100,100), new Point(32,64), getImage(getCodeBase(), "CHAR2.gif") ,1, true, true);

			Text t = new Text("Game Status",0,0);
			Text t2 = new Text("You Win!",0,0);
			TextBox t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(300,300));
			Util.m_alPrintText.add(t3);
			init();
			start();
			m_iGameStatus = STARTING;
			*/
		}

		//if ((Util.m_alSprite.get(0)) instanceof Character)
		//	if (((Character)(Util.m_alSprite.get(0))).m_bIsPlayer)
		//		Controls.HandleControls();
	}
	public void Newgame(Graphics g)
	{
		Util.m_iNumOfPlayers = Util.m_iSetup[0];
		Util.m_iDifficulty = Util.m_iSetup[7];
		if (Util.m_iDifficulty == 1)
		{
			_tempenemyrate = 60;
			_temppowerrate = 80;
			Util.m_iNumOfAllys = 5;
		}
		if (Util.m_iDifficulty == 2)
		{
			_tempenemyrate = 50;
			_temppowerrate = 90;
			Util.m_iNumOfAllys = 5;
		}
		if (Util.m_iDifficulty == 3)
		{
			_tempenemyrate = 40;
			_temppowerrate = 100;
			Util.m_iNumOfAllys = 4;
		}
		if (Util.m_iDifficulty == 4)
		{
			_tempenemyrate = 30;
			_temppowerrate = 110;	
			Util.m_iNumOfAllys = 2;
		}
		if (Util.m_iDifficulty == 5)
		{
			_tempenemyrate = 20;
			_temppowerrate = 120;	
			Util.m_iNumOfAllys = 0;
		}
		ArrayList AnimationList = new ArrayList();
		Animation a=new Animation();
		//if (Util.m_cPlayerControls[0].m_bStart)
		//{
			
			Util.m_alPrintText = new ArrayList();
			Util.m_alSprite = new ArrayList();
			//SAMPLE
			/*
			int [] map = 
			{
					 6,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 1, 1, 1, 1, 1, 1, 1, 1,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 2, 3, 2, 3, 2, 3, 2, 3,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 5, 4, 5, 4, 5, 4, 5, 4,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,17,17,17,17,17,17,17,17,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,17,17,17,17,17,17,17,17, 1, 1, 1,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,17,17,17,17,17,17,17,17, 3, 2, 3,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,17,17,17,17,17,17,17,17, 4, 5, 4,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12, 1, 1, 1, 1, 1, 1,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 1, 1, 1, 1, 1, 1, 1, 1, 7, 7, 7,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12, 3, 3, 3, 3, 3, 3,12,12,12,12,12,12,12,12,12,12, 1, 1, 1, 1, 1, 1,12,12,12, 2, 3, 2, 3, 2, 3, 2, 3, 7, 7, 7,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12,12,12, 5, 5, 5, 5, 5, 5,15,15,15,15,15,15,15,15,15,15, 3, 3, 3, 3, 3, 3,12,12,12, 5, 4, 5, 4, 5, 4, 5, 4, 7, 7, 7,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12, 1, 1, 7, 7, 7, 7, 7, 7,14,14,14,14,14,14,14,14,14,14, 5, 5, 5, 5, 5, 5,12,12,12,17,17,17,17,17,17,17,17,17,17,17,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,12,12,12,12,12,12,12, 3, 3, 7, 7, 7, 7, 7, 7,12,12,12,12,12,12,12,12,12,12,17,17,17,17,17,17,12,12,12,17,17,17,17,17,17,17,17,17,17,17,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12, 6,
					 6,10,11,10,11,10,11,10, 5, 5, 7, 7, 7, 7, 7, 7,10,11,11,10,11,10,11,10,11,10,17,17,17,17,17,17,11,10,11,17,17,17,17,17,17,17,17,17,17,17,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10,11,10, 6,
					 6, 8, 9, 8, 9, 8, 9, 8, 7, 7, 7, 7, 7, 7, 7, 7, 8, 9, 8, 9, 8, 9, 8, 9, 8, 8,17,17,17,17,17,17, 9, 8, 9,17,17,17,17,17,17,17,17,17,17,17, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 6,
					 6, 0, 1, 0, 1, 0, 1, 0, 7, 7, 7, 7, 7, 7, 7, 7, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,17,17,17,17,17,17, 1, 0, 1,17,17,17,17,17,17,17,17,17,17,17, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 6,
					 6, 2, 3, 2, 3, 2, 3, 2, 7, 7, 7, 7, 7, 7, 7, 7, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2,17,17,17,17,17,17, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 6,
					 6, 5, 4, 5, 4, 5, 4, 5, 7, 7, 7, 7, 7, 7, 7, 7, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 6,
					 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6
			};
			Sprite WAD = new Sprite(new Point(0,0), new Point(32,32), getImage(getCodeBase(), "WAD1.gif") ,1, false, false);
			Level level = new Level(map, 160, 20, WAD, 32, 32);
			int [] solids = new int[9];
			solids[0] = 20;
			solids[1] = 4;
			solids[2] = 5;
			solids[3] = 6;
			solids[4] = 7;
			solids[5] = 23;
			solids[6] = 21;
			solids[7] = 14;
			solids[8] = 13;
			level.SetSolids(solids);
			Util.WorldMap();
			Util.SetLevel(level);
			Util.m_lCurrentLevel = level;
			*/
						
			int [] map2 = 
			{
						5,5,5,5,5,5,5,5,
						5,2,2,2,2,2,2,5,
						5,2,2,2,2,2,2,5,
						5,2,2,2,2,2,2,5,
						5,2,2,2,2,2,2,5,
						5,2,2,2,2,2,2,5,
						5,2,2,2,2,2,2,5,
						5,5,5,5,2,5,5,5
			};
			
			Sprite WAD2 = new Sprite(new Point(0,0), new Point(64,64), getImage(getCodeBase(), "WAD4.gif") ,1, false, false);
			Level house = new Level(map2, 8, 8, WAD2, 64, 64);
			house.AddImageToWad(getImage(getCodeBase(), "WAD2NV.gif"));
			int [] solids2 = new int[2];
			solids2[0] = 4;
			solids2[1] = 5;
			house.SetSolids(solids2);
			
			int [] map = 
			{
				0,0,4,4,4,4,4,4, 4,4,4,4,0,0,0,0,
				0,0,4,4,4,4,4,4, 4,4,4,4,0,0,0,0,
				0,0,5,5,5,5,5,5, 5,5,5,5,0,0,0,0,
				0,0,5,3,3,5,5,5, 5,3,3,5,0,0,0,0,
				0,0,5,5,5,5,3,5, 5,5,5,5,0,0,0,0,
				0,0,5,5,5,5,3,5, 5,5,5,5,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,2,0, 0,0,0,0,0,0,0,0,
				2,2,2,2,2,2,2,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0, 0,0,0,0,0,0,1,1,
				0,0,0,0,0,0,0,0, 0,0,0,0,0,1,1,0,
				0,0,0,0,0,0,0,0, 0,0,0,0,1,1,0,0,
				0,0,0,0,0,0,0,0, 0,0,0,0,1,1,0,0,
				0,0,0,0,0,0,0,0, 0,0,0,0,1,1,0,0,
				0,0,0,0,0,0,0,0, 0,0,1,1,1,0,0,0,
				0,0,0,0,0,0,0,0, 0,1,1,0,0,0,0,0,
				0,0,0,0,0,0,0,0, 1,1,1,0,0,0,0,0,
				0,0,0,0,0,0,0,1, 1,1,0,0,0,0,0,0,
				0,0,0,0,0,0,1,1, 1,1,0,0,0,0,0,0,
				0,0,0,0,0,0,1,1, 1,1,0,0,0,0,0,0,
				0,0,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,
				0,0,0,0,1,1,0,0, 0,0,0,0,0,0,0,0,
				0,0,0,1,1,0,0,0, 0,0,0,0,0,0,0,0,
				0,0,1,1,0,0,0,0, 0,0,0,0,0,0,0,0,
				0,1,1,0,0,0,0,0, 0,0,0,0,0,0,0,0,
				1,1,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
				1,1,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
				1,0,0,0,0,0,0,0, 2,2,2,2,2,2,2,2,
				1,0,0,0,0,0,0,0, 2,0,0,0,0,0,0,0,
				1,0,0,0,0,0,0,0, 2,0,0,0,0,0,0,0,
				1,0,0,0,0,0,0,0, 2,0,0,0,0,0,0,0,
				1,1,1,0,0,0,0,0, 2,0,0,0,0,0,0,0,
				1,1,1,1,0,0,0,0, 2,0,0,0,0,0,0,0
			};
			
			Sprite WAD = new Sprite(new Point(0,0), new Point(64,64), getImage(getCodeBase(), "WAD4.gif") ,1, false, false);
			Level level = new Level(map, 16, 41, WAD, 64, 64);
			level.AddImageToWad(getImage(getCodeBase(), "WAD2NV.gif"));
			int [] solids = new int[2];
			solids[0] = 4;
			solids[1] = 5;
			level.SetSolids(solids);
			
			Entity_Teleport tp = new Entity_Teleport(-32,-32,0,0,new Point(4*64,6*64));
			Entity_Teleport tp2 = new Entity_Teleport(-32,-32,0,0,new Point(6*64,6*64));
			
			Entity_LevelChange cl2 = new Entity_LevelChange(6* 64,5*64,64,64,house);
			cl2.m_eTarget = tp;
			ArrayList e = new ArrayList();
			e.add(cl2);
			
			Entity_LevelChange cl = new Entity_LevelChange(4 * 64,7*64,64,64,level);
			cl.m_eTarget = tp2;
			ArrayList e2 = new ArrayList();
			e2 = new ArrayList();
			e2.add(cl);
			
			level.SetEntities(e);
			house.SetEntities(e2);
			
			cl2.m_lLevel = new Level(house);
			cl.m_lLevel = new Level(level);
			
			Util.SetLevel(level);
			Util.m_lCurrentLevel = new Level(level);
			
			Util.Battle();
		
			
			Character s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PSentinel.gif") ,1, true, true);

			for (int x = 0; x < Util.m_iNumOfPlayers; x++)
			{		
				s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PSentinel.gif"),  1, true, true);
				s.m_iPlayerNumber = x+1;
				if (s.m_iPlayerNumber == 1)
				{
					if (Util.m_iSetup[1] == 1)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PPaladin.gif") ,1, true, false);
						s.AddImage(getImage(getCodeBase(), "PPaladinNV.gif"));
					}
					if (Util.m_iSetup[1] == 2)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PCalumniator.gif") ,1, true, false);
						s.AddImage(getImage(getCodeBase(), "PCalumniatorNV.gif"));
					}
					if (Util.m_iSetup[1] == 3)
					{	
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PSentinel.gif") ,1, true, false);
						s.AddImage(getImage(getCodeBase(), "PSentinelNV.gif"));
					}
					if (Util.m_iSetup[1] == 4)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PExemplar.gif") ,1, true, false);
						s.AddImage(getImage(getCodeBase(), "PExemplarNV.gif"));
					}
					if (Util.m_iSetup[1] == 5)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PPariah.gif") ,1, true, false);
						s.AddImage(getImage(getCodeBase(), "PPariahNV.gif"));
					}
					if (Util.m_iSetup[1] == 6)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PRenegade.gif") ,1, true, false);
						s.AddImage(getImage(getCodeBase(), "PRenegadeNV.gif"));
					}
					if (Util.m_iSetup[1] == 7)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PHunter.gif") ,1, true, false);
						s.AddImage(getImage(getCodeBase(), "PHunterNV.gif"));
					}
				}
				if (s.m_iPlayerNumber == 2)
				{
					if (Util.m_iSetup[4] == 1)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PPaladin.gif") ,1, false, false);
						s.AddImage(getImage(getCodeBase(), "PPaladinNV.gif"));
					}
					if (Util.m_iSetup[4] == 2)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PCalumniator.gif") ,1, false, false);
						s.AddImage(getImage(getCodeBase(), "PCalumniatorNV.gif"));
					}
					if (Util.m_iSetup[4] == 3)
					{	
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PSentinel.gif") ,1, false, false);
						s.AddImage(getImage(getCodeBase(), "PSentinelNV.gif"));
					}
					if (Util.m_iSetup[4] == 4)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PExemplar.gif") ,1, false, false);
						s.AddImage(getImage(getCodeBase(), "PExemplarNV.gif"));
					}
					if (Util.m_iSetup[4] == 5)
						
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PPariah.gif") ,1, false, false);
						s.AddImage(getImage(getCodeBase(), "PPariahNV.gif"));
					}
					if (Util.m_iSetup[4] == 6)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PRenegade.gif") ,1, false, false);
						s.AddImage(getImage(getCodeBase(), "PRenegadeNV.gif"));
					}
					if (Util.m_iSetup[4] == 7)
					{
						s = new Character(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PHunter.gif") ,1, false, false);
						s.AddImage(getImage(getCodeBase(), "PHunterNV.gif"));
					}
				}
				
				s.m_iPlayerNumber = x+1;

				s.m_tWeaponRotateTime.AddMilliseconds(500);
				Weapon w;
				
				w = new Laser("Laser",15,50,s.m_iPlayerNumber);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(50);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				s.AddWeapon(w);
				
				w = new MachineGun("MachineGun",10,50,s.m_iPlayerNumber);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(10);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				s.AddWeapon(w);
				
				s.m_wTurret = new Phaser("Phaser",10,50,s.m_iPlayerNumber);
				s.m_wTurret.m_tReloadTime = new Time();
				s.m_wTurret.m_tReloadTime.AddMilliseconds(50);
				s.m_wTurret.m_tMissileReloadTime.AddMilliseconds(1000);
				
				w = new FlameThrower("FlameThrower",50,50,s.m_iPlayerNumber);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(50);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				s.AddWeapon(w);
				
				w = new PulseLaser("PulseLaser",50,50,s.m_iPlayerNumber);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(300);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				s.AddWeapon(w);
				
				w = new HellGun("HellGun",20,50,s.m_iPlayerNumber);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(1500);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				s.AddWeapon(w);
				
				w = new GravityGun("GravityGun",100,50,s.m_iPlayerNumber);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(500);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				s.AddWeapon(w);
				
				if (s.m_iPlayerNumber == 1)
				{
					if (Util.m_iSetup[2] == 1)
						s.SetWeapon("Laser");
					if (Util.m_iSetup[2] == 2)
						s.SetWeapon("MachineGun");
					if (Util.m_iSetup[2] == 3)
						s.SetWeapon("FlameThrower");
					if (Util.m_iSetup[2] == 4)
						s.SetWeapon("PulseLaser");
					if (Util.m_iSetup[2] == 5)
						s.SetWeapon("HellGun");
					if (Util.m_iSetup[2] == 6)
						s.SetWeapon("GravityGun");
				}
				if (s.m_iPlayerNumber == 2)
				{
					if (Util.m_iSetup[5] == 1)
						s.SetWeapon("Laser");
					if (Util.m_iSetup[5] == 2)
						s.SetWeapon("MachineGun");
					if (Util.m_iSetup[5] == 3)
						s.SetWeapon("FlameThrower");
					if (Util.m_iSetup[5] == 4)
						s.SetWeapon("PulseLaser");
					if (Util.m_iSetup[5] == 5)
						s.SetWeapon("HellGun");
					if (Util.m_iSetup[5] == 6)
						s.SetWeapon("GravityGun");
				}
				
				if (s.m_iPlayerNumber == 1)
				{
					if (Util.m_iSetup[3] == 1)
					{
						s.m_iHealth = 50;
						s.m_iMaxHealth = 50;
					}
					if (Util.m_iSetup[3] == 2)
					{
						s.m_iHealth = 100;
						s.m_iMaxHealth = 100;
					}
					if (Util.m_iSetup[3] == 3)
					{
						s.m_iHealth = 150;
						s.m_iMaxHealth = 150;
					}
					if (Util.m_iSetup[3] == 4)
					{
						s.m_iHealth = 200;
						s.m_iMaxHealth = 1200;
					}
					if (Util.m_iSetup[3] == 5)
					{
						s.m_iHealth = 300;
						s.m_iMaxHealth = 300;
					}
					if (Util.m_iSetup[3] == 6)
					{
						s.m_iHealth = 500;
						s.m_iMaxHealth = 500;
					}
				}
				if (s.m_iPlayerNumber == 2)
				{
					if (Util.m_iSetup[6] == 1)
					{
						s.m_iHealth = 50;
						s.m_iMaxHealth = 50;
					}
					if (Util.m_iSetup[6] == 2)
					{
						s.m_iHealth = 100;
						s.m_iMaxHealth = 100;
					}
					if (Util.m_iSetup[6] == 3)
					{
						s.m_iHealth = 150;
						s.m_iMaxHealth = 150;
					}
					if (Util.m_iSetup[6] == 4)
					{
						s.m_iHealth = 200;
						s.m_iMaxHealth = 1200;
					}
					if (Util.m_iSetup[6] == 5)
					{
						s.m_iHealth = 300;
						s.m_iMaxHealth = 300;
					}
					if (Util.m_iSetup[6] == 6)
					{
						s.m_iHealth = 500;
						s.m_iMaxHealth = 500;
					}
				}
							
					AnimationList = new ArrayList();
					a = new Animation("UP",1,1,false,3);
					AnimationList.add(a);
					a = new Animation("RIGHT",2,2,false,3);
					AnimationList.add(a);
					a = new Animation("DOWN",3,3,false,3);
					AnimationList.add(a);
					a = new Animation("LEFT",4,4,false,3);
					AnimationList.add(a);
					a = new Animation("IDLE",5,5,false,3);
					AnimationList.add(a);
					a = new Animation("UPRIGHT",6,6,false,3);
					AnimationList.add(a);
					a = new Animation("DOWNRIGHT",7,7,false,3);
					AnimationList.add(a);
					a = new Animation("UPLEFT",8,8,false,3);
					AnimationList.add(a);
					a = new Animation("DOWNLEFT",9,9,false,3);
					AnimationList.add(a);
					a = new Animation("DIE1",10,23,false,12);
					AnimationList.add(a);
					a = new Animation("DIE2",24,37,false,12);
					AnimationList.add(a);
					s.SetAnimations(AnimationList);
					s.PlayAnimation("UP");
				s.SetPosition(379 + x*64,128);
				s.m_bIsPlayer = true;
				s.m_iFaction = 0;
				
				if (s.m_iPlayerNumber == 1 && Util.m_iSetup[1] < 8)
				{ 
					Util.m_alSprite.add(s);
				}
				if (s.m_iPlayerNumber == 2 && Util.m_iSetup[4] < 8)
				{
					Util.m_alSprite.add(s);
				}
			}
			
			
			for (int x = 0; x < Util.m_iNumOfPlayers; x++)
			{	
				HUD h = new HUD();
				if ((x == 0 && Util.m_iSetup[1] != 8) || (x == 1 && Util.m_iSetup[4] != 8))
				{
				//	System.out.println();
				h.m_sWeaponSelection = new Sprite(new Point(33 + x*(800-48-33), 0), new Point(16,32), getImage(getCodeBase(), "WeaponSelection.gif"),  1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("Laser",1,1,false,3);
					AnimationList.add(a);
					a = new Animation("FlameThrower",2,2,false,3);
					AnimationList.add(a);
					a = new Animation("MachineGun",3,3,false,3);
					AnimationList.add(a);
					a = new Animation("PulseLaser",4,4,false,3);
					AnimationList.add(a);
					a = new Animation("HellGun",5,5,false,3);
					AnimationList.add(a);
					a = new Animation("GravityGun",6,6,false,3);
					AnimationList.add(a);
					h.m_sWeaponSelection.SetAnimations(AnimationList);
					h.m_sWeaponSelection.PlayAnimation("Laser");

				h.m_sHealth = new Sprite(new Point(0 + x*(800-32), 0), new Point(32,32), getImage(getCodeBase(), "Health.gif"),  1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("100",1,1,false,3);
					AnimationList.add(a);
					a = new Animation("90",2,2,false,3);
					AnimationList.add(a);
					a = new Animation("80",3,3,false,3);
					AnimationList.add(a);
					a = new Animation("70",4,4,false,3);
					AnimationList.add(a);
					a = new Animation("60",5,5,false,3);
					AnimationList.add(a);
					a = new Animation("50",6,6,false,3);
					AnimationList.add(a);
					a = new Animation("40",7,7,false,3);
					AnimationList.add(a);
					a = new Animation("30",8,8,false,3);
					AnimationList.add(a);
					a = new Animation("20",9,9,false,3);
					AnimationList.add(a);
					a = new Animation("10",10,10,false,3);
					AnimationList.add(a);
					a = new Animation("0",11,11,false,3);
					AnimationList.add(a);
					h.m_sHealth.SetAnimations(AnimationList);
					h.m_sHealth.PlayAnimation("100");
				
				h.m_sDoodad1 = new Sprite(new Point(0 + x*(800-96),0), new Point(96,32), getImage(getCodeBase(), "HUD1.gif"),  1, false, false);
				AnimationList = new ArrayList();
					a = new Animation("IDLE",x,x,true,1);
					AnimationList.add(a);
					h.m_sDoodad1.SetAnimations(AnimationList);
					h.m_sDoodad1.PlayAnimation("IDLE");
					
				h.m_tScore = new Text("0",new Point(0 + x*(800-96)+10,45));
				h.m_tScore.m_cColor = Color.red;
					
				h.m_sPointer = new Sprite(new Point(-32,0), new Point(32,16), getImage(getCodeBase(), "Players.gif"),  1, false, false);
				AnimationList = new ArrayList();
					a = new Animation("IDLE",x*4,x*4+4,true,4);
					AnimationList.add(a);
					h.m_sPointer.SetAnimations(AnimationList);
					h.m_sPointer.PlayAnimation("IDLE");
					int temp = x;
					if (x == 1 && Util.m_iSetup[1] == 8)
						temp--;
					h.m_cTarget = (Character)((Sprite)(Util.m_alSprite.get(temp)));
				}
				
				if (x == 0 && Util.m_iSetup[1] == 8)
				{
					h.m_sCrosshair = new Sprite(new Point(200,200), new Point(32,32), getImage(getCodeBase(), "Crosshairs.gif"),  1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("IDLE",1,4,true,12);
					AnimationList.add(a);
					h.m_sCrosshair.SetAnimations(AnimationList);
					h.m_sCrosshair.PlayAnimation("IDLE");
				}
				if (x == 1 && Util.m_iSetup[4] == 8)
				{
					h.m_sCrosshair = new Sprite(new Point(200,200), new Point(32,32), getImage(getCodeBase(), "Crosshairs.gif"),  1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("IDLE",5,8,true,12);
					AnimationList.add(a);
					h.m_sCrosshair.SetAnimations(AnimationList);
					h.m_sCrosshair.PlayAnimation("IDLE");
				}
				
				Util.m_alHUD.add(h);
			}

			int headunit = 0;

			for (int x = 0; x < Util.m_iNumOfAllys; x++)
			{
				AllyShip m = new AllyShip(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PSentinel.gif") ,1, false, false);
				if (x % 5 == 0)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PCalumniator.gif") ,1, false, false);
					m.AddImage(getImage(getCodeBase(), "PCalumniatorNV.gif"));
				}
				if (x % 5 == 1)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PExemplar.gif") ,1, false, false);
					m.AddImage(getImage(getCodeBase(), "PExemplarNV.gif"));
				}
				if (x % 5 == 2)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PPariah.gif") ,1, false, false);
					m.AddImage(getImage(getCodeBase(), "PPariahNV.gif"));
				}
				if (x % 5 == 3)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PPaladin.gif") ,1, false, false);
					m.AddImage(getImage(getCodeBase(), "PPaladinNV.gif"));
				}
				if (x % 5 == 4)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), getImage(getCodeBase(), "PRenegade.gif") ,1, false, false);
					m.AddImage(getImage(getCodeBase(), "PRenegadeNV.gif"));
				}

					AnimationList = new ArrayList();
					a = new Animation("UP",1,1,false,3);
					AnimationList.add(a);
					a = new Animation("RIGHT",2,2,false,3);
					AnimationList.add(a);
					a = new Animation("DOWN",3,3,false,3);
					AnimationList.add(a);
					a = new Animation("LEFT",4,4,false,3);
					AnimationList.add(a);
					a = new Animation("IDLE",5,5,false,3);
					AnimationList.add(a);
					a = new Animation("UPRIGHT",6,6,false,3);
					AnimationList.add(a);
					a = new Animation("DOWNRIGHT",7,7,false,3);
					AnimationList.add(a);
					a = new Animation("UPLEFT",8,8,false,3);
					AnimationList.add(a);
					a = new Animation("DOWNLEFT",9,9,false,3);
					AnimationList.add(a);
					m.SetAnimations(AnimationList);
					m.PlayAnimation("IDLE");
				m.SetPosition(100, 400);
				
				m.m_tWeaponRotateTime.AddSeconds(1);
				Weapon w = new GravityGun("GravityGun",100,50,0);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(500);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				m.AddWeapon(w);
				
				w = new HellGun("HellGun",10,50,0);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(1500);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				m.AddWeapon(w);
				
				w = new PulseLaser("PulseLaser",15,50,0);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(300);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				m.AddWeapon(w);
				
				w = new Laser("Laser",15,50,0);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(50);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				m.AddWeapon(w);
				
				w = new FlameThrower("FlameThrower",20,50,0);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(50);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				m.AddWeapon(w);
				
				w = new MachineGun("MachineGun",10,50,0);
				w.m_tReloadTime = new Time();
				w.m_tReloadTime.AddMilliseconds(10);
				w.m_tMissileReloadTime.AddMilliseconds(1000);
				m.AddWeapon(w);
				
				m.SetWeapon("GravityGun");
				for (int y = 0; y < x; y++)
					m.WeaponRotate();
				
				m.m_iHealth = 100;
				m.m_iMaxHealth = 100;
				
				/*
				if (x % 5 == 0)
				{
					m.m_iFormation = 5;
					m.m_iRoamFormation = 5;
					m.m_iFormationID = x/3;
					m.m_iID = x;
					m.m_iFaction = 0;
					m.m_bHeadUnit = true;
					Util.m_alSprite.add(m);
					headunit = Util.m_alSprite.size()-1;
				}
				else
				{*/
				
					//int headunit = 0;
					if (Util.m_iNumOfPlayers != 0)
					{
						headunit = x%Util.m_iNumOfPlayers;
						m.m_rcFollowBox = ((Sprite)(Util.m_alSprite.get(headunit))).m_rcBoundingBox;
					}
					m.m_rcFollowBox = ((Sprite)(Util.m_alSprite.get(headunit))).m_rcBoundingBox;
					m.m_iFormation = 5;
					m.m_iRoamFormation = 0;
					m.m_iFormationID = x;
					m.m_iID = x;
					m.m_iFaction = 0;
					Util.m_alSprite.add(m);
				//}
			}

			Text t;
			Text t2;
			TextBox t3;
			
			t = new Text("Directions",0,0);
			t2 = new Text("The panel next to the health dial contains color-coded lights displaying what weapon is selected.",0,0);
			t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
		
			t = new Text("Directions",0,0);
			t2 = new Text("The dial in the top left (Player 1) or top right (Player 2) indicates health status. If the dial points Left, your ship has little armor.",0,0);
			t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
			
			if (Util.m_iNumOfPlayers == 2)
			{
			t = new Text("Directions",0,0);
			t2 = new Text("Player Two fires with I, and changes weapon with J.",0,0);
			t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
			
			t = new Text("Directions",0,0);
			t2 = new Text("Player Two navigates using 8, 5, 4, and 6 for Up, Down, Left, and Right respectively.",0,0);
			t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
			}
			
			t = new Text("Directions",0,0);
			t2 = new Text("Player One fires with W, and changes weapon with A.",0,0);
			t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
			
			t = new Text("Directions",0,0);
			t2 = new Text("Player One navigates using T, G, F, and H for Up, Down, Left, and Right respectively.",0,0);
			t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
			
			t = new Text("Directions",0,0);
			t2 = new Text("This is an information Panel. Press the E key to close.",0,0);
			t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
			m_iGameStatus = RUNNING;
		//}
	}

	public void Demo(Graphics g)
	{		
	}
	public void End(Graphics g)
	{
	}
	
	public void update (Graphics g)
	{
		//check collision
		Collision.HandleCollision();
		for (int x = 0; x < Util.m_alHUD.size(); x++)
		{
			((HUD)(Util.m_alHUD.get(x))).Update();	
		}
		Util.m_rcCamera.HandleCamera();
		
			if (m_iGameStatus == STARTING)
				Starting(g);
			else if (m_iGameStatus == SPLASH)
				Splash(g);
			else if (m_iGameStatus == NEWGAME)
				Newgame(g);
			else if (m_iGameStatus == LOADGAME)
				Loadgame(g);
			else if (m_iGameStatus == OPTIONS)
				Options(g);
			else if (m_iGameStatus == RUNNING)
				Run(g);
			else if (m_iGameStatus == DEMO)
				Demo(g);
			else if (m_iGameStatus == END)
				End(g);
				
		//if (Util.m_tTime.m_iMilliseconds % 2 != 0) //temp frame rate
		//	return;
		
		if (dbImage == null)
		{
			dbImage = createImage (this.getSize().width, this.getSize().height);
			dbg = dbImage.getGraphics ();
		}

		dbg.setColor (getBackground ());
		dbg.fillRect (0, 0, this.getSize().width, this.getSize().height);

		dbg.setColor (getForeground());
		paint (dbg);

		g.drawImage (dbImage, 0, 0, this);
		Controls.HandleControls();
		
	}
    
	public boolean keyDown(Event e, int key)
  	{  			
		Controls.HandleKeyDownControls(e,key);
		return false;
  	}
  	
  	public boolean keyUp(Event e, int key)
  	{ 
	  	Controls.HandleKeyUpControls(e,key);
	  	return true;
  	} 
	
	public void paint (Graphics g)
	{
		//setPaintMode()

		if (Util.m_lCurrentLevel != null)
		{
			Util.m_lCurrentLevel.Paint(g);
		}

		for (int x = 0; x < Util.m_alSprite.size(); x++)
		{
				Sprite S = (Sprite)(Util.m_alSprite.get(x));
				//if (x == 0)
				//{
				//	Sprite S2 = (Sprite)(Util.m_alSprite.get(x+1));
				//}
					//	S.pos.x += 64 * x;
				if (S.m_bDelete)
				{
					//if (S.m_bIsPlayer)
						//Util.m_iNumOfPlayers--;
					Util.m_alSprite.remove(x);
					x--;
					continue;
				}
				
				if (S.CollidesWith(Util.m_rcScreen))
				{
					S.PaintAnimation(g);
			//		S.Paint(g);
			//		S.DrawBoundingBox(g);
				}
		}
		for (int x = 0; x < Util.m_alHUD.size(); x++)
		{
			HUD S = (HUD)(Util.m_alHUD.get(x));
			S.PaintAnimation(g);
		}
		for (int x = 0; x < Util.m_alPrintText.size(); x++)
		{
			if (Util.m_alPrintText.get(x) instanceof Text)
			{
				((Text)(Util.m_alPrintText.get(x))).Paint(g);
			}
			if (Util.m_alPrintText.get(x) instanceof TextBox)
			{
				((TextBox)(Util.m_alPrintText.get(x))).Paint(g);
			}
		}
		/*
		for (int x = 0; x < Util.m_alSound.size(); x++)
		{
			
	      //	URL u = MyApplet.class.getResource( "ribbet.au" );
	      //	if ( u == null )
	      //	{
	      //  	throw new IllegalArgumentException ( "ribbet.au missing from the jar" );
	      // 	}
	      //	frog = getAudioClip( u );
	      //	Util.m_alSound.add(frog);
	    	
			if (Util.m_alSound.get(x) instanceof AudioClip)
			{
				((AudioClip)(Util.m_alSound.get(x))).play();
			}
		}
		*/
		//g.setColor(Color.red);
		//g.drawRect(Util.m_rcCamera.x, Util.m_rcCamera.y, Util.m_rcCamera.width, Util.m_rcCamera.height);

	}
	
	public void mouseClicked(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e)  {} 
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e){}
}