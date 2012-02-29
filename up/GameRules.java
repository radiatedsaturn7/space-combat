import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.awt.geom.Line2D;
import java.net.URL;


public class GameRules extends Applet {
	
	public static int _tempstarrate;
	public static int _tempenemyrate;
	public static int _temppowerrate;
	public static boolean _tempenemies;
	public static Main main = new Main();
	public static boolean _usegravity;
		
	public GameRules ()
	{
		main = new Main();
	}
	public static void OnRestart()
	{
		_tempstarrate = 0;
		_tempenemyrate = 10000;
		_temppowerrate = 0;
		_tempenemies = false;
		_usegravity = true;
		
		Util.m_iVision = 0;
		
		Util.m_iKills = new int[2];
		Util.m_iKills[0] = 0;
		Util.m_iKills[1] = 0;
		
		Util.m_iNumOfPlayers= 1;
		Util.m_iNumOfAllys = 5;
		Util.m_iGravity = 1;
		Util.m_imEnemyImage = Util.m_mMain.GetImage("Enemy.gif");
		Util.m_imShotImage = Util.m_mMain.GetImage("Helaser.gif");
		Util.m_imLaserImage = Util.m_mMain.GetImage("Hlaser.gif");
		Util.m_imBulletImage = Util.m_mMain.GetImage("Hmgun.gif");
		Util.m_imFlameImage = Util.m_mMain.GetImage("Hflame.gif");
		Util.m_imPulseImage = Util.m_mMain.GetImage("Hpulse.gif");
		Util.m_imHellImage = Util.m_mMain.GetImage("Hhell.gif");
		Util.m_imGravImage = Util.m_mMain.GetImage("Hgrav.gif");
		Util.m_imExplosionImage = Util.m_mMain.GetImage("Exp1.gif");
		Util.m_imParticleImage = Util.m_mMain.GetImage("Particle.gif");
		Util.m_imPowerUpImage = Util.m_mMain.GetImage("PowerUp.gif");
		Util.m_imMissileImage = Util.m_mMain.GetImage("Hmissile.gif");
		
		Util.m_imEnemyImageNV = Util.m_mMain.GetImage("EnemyNV.gif");
		Util.m_imShotImageNV = Util.m_mMain.GetImage("HelaserNV.gif");
		Util.m_imLaserImageNV = Util.m_mMain.GetImage("HlaserNV.gif");
		Util.m_imBulletImageNV = Util.m_mMain.GetImage("HmgunNV.gif");
		Util.m_imFlameImageNV = Util.m_mMain.GetImage("HflameNV.gif");
		Util.m_imPulseImageNV = Util.m_mMain.GetImage("HpulseNV.gif");
		Util.m_imHellImageNV = Util.m_mMain.GetImage("HhellNV.gif");
		Util.m_imGravImageNV = Util.m_mMain.GetImage("HgravNV.gif");
		Util.m_imExplosionImageNV = Util.m_mMain.GetImage("Exp1NV.gif");
		Util.m_imParticleImageNV = Util.m_mMain.GetImage("ParticleNV.gif");
		Util.m_imPowerUpImageNV = Util.m_mMain.GetImage("PowerUpNV.gif");
		Util.m_imMissileImageNV = Util.m_mMain.GetImage("HmissileNV.gif");
		Util.m_lCurrentLevel = null;
		Util.m_alHUD = new ArrayList();
		Util.WorldMap();
		Util.Starting();
		Util.m_iGravity = 9;
	}
	public static void OnStart()
	{
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
	}
	public static void Starting(Graphics g)
	{
		Animation a = new Animation();
		ArrayList  AnimationList = new ArrayList();
		Sprite s = new Sprite();
		Util.m_alPrintText  = new ArrayList();
		
		/*
		s = new Sprite(new Point(0,0), new Point(64,48), Util.m_mMain.GetImage( "Loading.jpg") ,1, false, false);
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
			
			s = new Sprite(new Point(0,0), new Point(800,600), Util.m_mMain.GetImage("Splash.gif") ,1, false, false);
				AnimationList = new ArrayList();
				a = new Animation("PRINT",0,0,true,1);
				AnimationList.add(a);
				s.SetAnimations(AnimationList);
				s.PlayAnimation("PRINT");
			Util.m_alSprite.add(s);
			s = new Sprite(new Point(0,100),new Point(135,480),Util.m_mMain.GetImage("Cursor.jpg"), 1, false, false);
				AnimationList = new ArrayList();
				a = new Animation("PRINT",0,0,true,17);
				AnimationList.add(a);
				s.SetAnimations(AnimationList);
				s.PlayAnimation("PRINT");
			Util.m_alSprite.add(s);
			Util.Splash();
	}
	public static void Splash(Graphics g)
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
				Util.NewGame();
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
				Util.LoadGame();
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
				
				Sprite s = new Sprite(new Point(0,0), new Point(800,600), Util.m_mMain.GetImage("Options.gif") ,1, false, false);
					ArrayList AnimationList = new ArrayList();
					Animation a = new Animation("PRINT",0,0,true,1);
					AnimationList.add(a);
					s.SetAnimations(AnimationList);
					s.PlayAnimation("PRINT");
				Util.m_alSprite.add(s);
				s = new Sprite(new Point(0,100),new Point(135,480),Util.m_mMain.GetImage("Cursor.jpg"), 1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("PRINT",0,0,true,17);
					AnimationList.add(a);
					s.SetAnimations(AnimationList);
					s.PlayAnimation("PRINT");
				Util.m_alSprite.add(s);
				Util.m_cPlayerControls[0].m_bStart = false;
				Util.Options();
			}
		}
	}
	public static void Run(Graphics g)
	{
			int yes = Util.RandomNumber(0,_tempenemyrate);
			if (yes == 1 && _tempenemies == true)
			{
				Util.Battle();
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
				
		if ((!Util.m_bOnWorldMap) && Util.NumOfEnemies() == 0)
		{
			Util.WorldMap();
		}
		if (Util.m_bInBattle)
		{
			Sprite s = ((Sprite)(Util.m_alSprite.get(0)));
			s.m_pBattlePos = new Point (600,500);
			s.m_rcBoundingBox.x = s.m_pBattlePos.x;
			s.m_rcBoundingBox.y = s.m_pBattlePos.y;
		}
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
			Character s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage("PSentinel.gif") ,1, true, true);
			Text t = new Text("Game Status",0,0);
			Text t2 = new Text("All of your base are belong to us!",0,0);
			TextBox t3 = new TextBox(new Text(t),new Text(t2),s,new Point(300,300));
			Util.m_alPrintText.add(t3);
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.Restart();
			}
		}
		
		if (Util.m_cPlayerControls[0].m_bStart)
			Util.Running();
		
		if (yes3)
		{
			/*
			Character s = new Character(new Point(100,100), new Point(32,64), Util.m_mMain.GetImage( "CHAR2.gif") ,1, true, true);

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
	public static void Options(Graphics g)
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
				Util.Starting();
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
	public static void Demo(Graphics g)
	{
	}
	public static void End(Graphics g)
	{
	}
	public static void LoadGame(Graphics g)
	{
	}
	public static void NewGame(Graphics g)
	{
		Util.m_iNumOfPlayers = Util.m_iSetup[0];
		Util.m_iDifficulty = Util.m_iSetup[7];
		if (Util.m_iDifficulty == 1)
		{
			_tempenemyrate = 160;
			_temppowerrate = 80;
			Util.m_iNumOfAllys = 5;
		}
		if (Util.m_iDifficulty == 2)
		{
			_tempenemyrate = 150;
			_temppowerrate = 90;
			Util.m_iNumOfAllys = 5;
		}
		if (Util.m_iDifficulty == 3)
		{
			_tempenemyrate = 140;
			_temppowerrate = 100;
			Util.m_iNumOfAllys = 4;
		}
		if (Util.m_iDifficulty == 4)
		{
			_tempenemyrate = 130;
			_temppowerrate = 110;	
			Util.m_iNumOfAllys = 2;
		}
		if (Util.m_iDifficulty == 5)
		{
			_tempenemyrate = 120;
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
			Sprite WAD = new Sprite(new Point(0,0), new Point(32,32), Util.m_mMain.GetImage( "WAD1.gif") ,1, false, false);
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
			
			Util.m_lWorld = new Level(level);
			Util.SetLevel(level);
			
			Util.WorldMap();
			Util.SetLevel(level);
			Util.m_lCurrentLevel = level;
			
			/*
			int [] world = 
			{
						6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
						6,6,1,1,1,6,6,6,6,6,6,6,1,6,1,6,6,6,6,1,1,1,6,6,
						6,6,6,1,1,1,6,6,1,1,1,1,1,1,6,6,1,1,1,1,1,1,6,6,
						6,6,6,6,1,1,6,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,6,6,
						6,6,1,6,6,6,6,6,1,1,1,1,1,6,6,6,1,1,1,1,1,1,1,6,
						6,6,1,1,1,1,6,6,6,1,1,1,1,6,6,6,6,6,1,1,1,1,1,6,
						6,1,1,1,1,1,6,6,3,3,3,3,3,3,6,6,6,6,1,1,1,6,1,6,
						6,6,7,7,7,6,6,6,3,3,3,3,3,3,6,6,6,6,1,1,1,1,1,6,
						6,6,6,7,6,6,6,6,3,3,3,3,3,3,6,6,6,6,6,6,1,6,1,6,
						6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
						6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
						6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,6,6,
						6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,3,1,1,1,1,6,
						6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,3,1,1,1,1,6,
						6,6,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,3,1,1,7,1,6,
						6,1,1,1,1,1,6,6,3,3,3,3,3,3,3,3,6,6,3,6,1,7,1,6,
						6,6,1,1,1,1,6,6,3,3,3,3,3,3,3,3,6,6,3,6,1,7,1,6,
						6,6,1,1,6,6,6,6,3,3,3,3,3,3,3,3,6,6,3,6,1,7,1,6,
						6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,6,6,3,6,6,6,1,6,
						6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,6,6,3,6,6,6,6,6,
						6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,6,6,3,6,6,6,6,6,
						6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,6,6,3,1,1,6,6,6,
						6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,6,6,1,1,1,6,6,6,
						6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6
			};
			
			Sprite WAD2 = new Sprite(new Point(0,0), new Point(64,64), Util.m_mMain.GetImage("WAD4.gif") ,1, false, false);
			Level lworld= new Level(world, 24, 24, WAD2, 64, 64);
			lworld.AddImageToWad(Util.m_mMain.GetImage("WAD2NV.gif"));
			int [] solids4 = new int[2];
			solids4[0] = -1;
			solids4[1] = -1;
			lworld.SetSolids(solids4); 
			Util.m_lWorld = new Level(lworld);
			
			int [] battle = 
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
			
			Sprite WAD3 = new Sprite(new Point(0,0), new Point(64,64), Util.m_mMain.GetImage("WAD4.gif") ,1, false, false);
			Level lbattle = new Level(battle, 8, 8, WAD3, 64, 64);
			lbattle.AddImageToWad(Util.m_mMain.GetImage("WAD2NV.gif"));
			int [] solids5 = new int[2];
			solids5[0] = 4;
			solids5[1] = 5;
			lbattle.SetSolids(solids5); 
			Util.m_lBattle = new Level(lbattle);
			
						
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
			
			Sprite WAD4 = new Sprite(new Point(0,0), new Point(64,64), Util.m_mMain.GetImage("WAD4.gif") ,1, false, false);
			Level house = new Level(map2, 8, 8, WAD4, 64, 64);
			house.AddImageToWad(Util.m_mMain.GetImage("WAD2NV.gif"));
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
				0,0,1,1,0,0,0,0, 0,0,0,3,0,0,0,0,
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
			
			Sprite WAD = new Sprite(new Point(0,0), new Point(64,64), Util.m_mMain.GetImage("WAD4.gif") ,1, false, false);
			Level level = new Level(map, 16, 41, WAD, 64, 64);
			level.AddImageToWad(Util.m_mMain.GetImage("WAD2NV.gif"));
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
			
			Util.m_lTown = new Level(level);
			Util.SetLevel(level);
			Util.m_lCurrentLevel = new Level(level);
			
			Util.TownMap();
			*/
		
			
			Character s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage("PSentinel.gif") ,1, true, _usegravity);

			for (int x = 0; x < Util.m_iNumOfPlayers; x++)
			{		
				s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage("CHAR2.gif"),  1, true, _usegravity);
				s.m_iPlayerNumber = x+1;
				if (s.m_iPlayerNumber == 1)
				{
					if (Util.m_iSetup[1] == 1)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PPaladin.gif") ,1, true, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PPaladinNV.gif"));
					}
					if (Util.m_iSetup[1] == 2)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PCalumniator.gif") ,1, true, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PCalumniatorNV.gif"));
					}
					if (Util.m_iSetup[1] == 3)
					{	
						s = new Character(new Point(100,100), new Point(32,64), Util.m_mMain.GetImage( "CHAR2.gif") ,1, true, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PSentinelNV.gif"));
					}
					if (Util.m_iSetup[1] == 4)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PExemplar.gif") ,1, true, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PExemplarNV.gif"));
					}
					if (Util.m_iSetup[1] == 5)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PPariah.gif") ,1, true, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PPariahNV.gif"));
					}
					if (Util.m_iSetup[1] == 6)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PRenegade.gif") ,1, true, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PRenegadeNV.gif"));
					}
					if (Util.m_iSetup[1] == 7)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PHunter.gif") ,1, true, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PHunterNV.gif"));
					}
				}
				if (s.m_iPlayerNumber == 2)
				{
					if (Util.m_iSetup[4] == 1)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PPaladin.gif") ,1, false, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PPaladinNV.gif"));
					}
					if (Util.m_iSetup[4] == 2)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PCalumniator.gif") ,1, false, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PCalumniatorNV.gif"));
					}
					if (Util.m_iSetup[4] == 3)
					{	
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PSentinel.gif") ,1, false, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PSentinelNV.gif"));
					}
					if (Util.m_iSetup[4] == 4)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PExemplar.gif") ,1, false, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PExemplarNV.gif"));
					}
					if (Util.m_iSetup[4] == 5)
						
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PPariah.gif") ,1, false, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PPariahNV.gif"));
					}
					if (Util.m_iSetup[4] == 6)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PRenegade.gif") ,1, false, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PRenegadeNV.gif"));
					}
					if (Util.m_iSetup[4] == 7)
					{
						s = new Character(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PHunter.gif") ,1, false, _usegravity);
						s.AddImage(Util.m_mMain.GetImage( "PHunterNV.gif"));
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
					a = new Animation("IDLE",1,3,false,3);
					AnimationList.add(a);
					a = new Animation("WALK",3,6,false,3);
					AnimationList.add(a);
					a = new Animation("JUMP",1,1,false,3);
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
				s.m_pMaxSpeed = new Point(72,72);
				
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
				h.m_sWeaponSelection = new Sprite(new Point(33 + x*(800-48-33), 0), new Point(16,32), Util.m_mMain.GetImage( "WeaponSelection.gif"),  1, false, false);
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

				h.m_sHealth = new Sprite(new Point(0 + x*(800-32), 0), new Point(32,32), Util.m_mMain.GetImage( "Health.gif"),  1, false, false);
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
				
				h.m_sDoodad1 = new Sprite(new Point(0 + x*(800-96),0), new Point(96,32), Util.m_mMain.GetImage( "HUD1.gif"),  1, false, false);
				AnimationList = new ArrayList();
					a = new Animation("IDLE",x,x,true,1);
					AnimationList.add(a);
					h.m_sDoodad1.SetAnimations(AnimationList);
					h.m_sDoodad1.PlayAnimation("IDLE");
					
				h.m_tScore = new Text("0",new Point(0 + x*(800-96)+10,45));
				h.m_tScore.m_cColor = Color.red;
					
				h.m_sPointer = new Sprite(new Point(-32,0), new Point(32,16), Util.m_mMain.GetImage( "Players.gif"),  1, false, false);
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
					h.m_sCrosshair = new Sprite(new Point(200,200), new Point(32,32), Util.m_mMain.GetImage( "Crosshairs.gif"),  1, false, false);
					AnimationList = new ArrayList();
					a = new Animation("IDLE",1,4,true,12);
					AnimationList.add(a);
					h.m_sCrosshair.SetAnimations(AnimationList);
					h.m_sCrosshair.PlayAnimation("IDLE");
				}
				if (x == 1 && Util.m_iSetup[4] == 8)
				{
					h.m_sCrosshair = new Sprite(new Point(200,200), new Point(32,32), Util.m_mMain.GetImage( "Crosshairs.gif"),  1, false, false);
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
				AllyShip m = new AllyShip(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage("PSentinel.gif") ,1, false, false);
				if (x % 5 == 0)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PCalumniator.gif") ,1, false, false);
					m.AddImage(Util.m_mMain.GetImage( "PCalumniatorNV.gif"));
				}
				if (x % 5 == 1)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PExemplar.gif") ,1, false, false);
					m.AddImage(Util.m_mMain.GetImage( "PExemplarNV.gif"));
				}
				if (x % 5 == 2)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PPariah.gif") ,1, false, false);
					m.AddImage(Util.m_mMain.GetImage( "PPariahNV.gif"));
				}
				if (x % 5 == 3)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PPaladin.gif") ,1, false, false);
					m.AddImage(Util.m_mMain.GetImage( "PPaladinNV.gif"));
				}
				if (x % 5 == 4)
				{
					m = new AllyShip(new Point(100,100), new Point(32,32), Util.m_mMain.GetImage( "PRenegade.gif") ,1, false, false);
					m.AddImage(Util.m_mMain.GetImage( "PRenegadeNV.gif"));
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
			Util.Running();
		//}
	}
}
