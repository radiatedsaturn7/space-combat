import java.util.Random;
import java.awt.*;
import java.util.*;
import java.net.*;

public class Util
{
	public static Main m_mMain;
	
	public static boolean m_bOnWorldMap;
	public static boolean m_bOnTownMap;
	public static boolean m_bInBattle;
	public static Point m_pWorldGlobalOffset;
	public static Point m_pTownGlobalOffset;
	public static Point m_pBattleGlobalOffset;
	
	public static Time m_tTime;
	public static Level m_lCurrentLevel;
	public static Level m_lWorld;
	public static Level m_lTown;
	public static Level m_lBattle;
	public static int m_iGravity;
	public static Rectangle m_rcScreen;
	public static Camera m_rcCamera;
	public static Point m_pGlobalOffset;
	public static Point m_pScrollSpeed;
	public static URL CodeBase;
	public static int [] m_iSetup;
	public static int m_iNumOfPlayers;
	public static int m_iNumOfAllys;
	public static int m_iDifficulty;
	public static int m_iLaserDamage;
	public static int m_iBulletDamage;
	public static int m_iFlameDamage;
	public static int m_iPulseDamage;
	public static int m_iPhaserDamage;
	
	public static int [] m_iKills;
	
	public static int m_iVision;
	
	public static Image m_imEnemyImage;
	public static Image m_imShotImage;
	public static Image m_imLaserImage;
	public static Image m_imBulletImage;
	public static Image m_imFlameImage;
	public static Image m_imPulseImage;
	public static Image m_imHellImage;
	public static Image m_imGravImage;
	public static Image m_imExplosionImage;
	public static Image m_imParticleImage;
	public static Image m_imPowerUpImage;
	public static Image m_imMissileImage;
	
	public static Image m_imEnemyImageNV;
	public static Image m_imShotImageNV;
	public static Image m_imLaserImageNV;
	public static Image m_imBulletImageNV;
	public static Image m_imFlameImageNV;
	public static Image m_imPulseImageNV;
	public static Image m_imHellImageNV;
	public static Image m_imGravImageNV;
	public static Image m_imExplosionImageNV;
	public static Image m_imParticleImageNV;
	public static Image m_imPowerUpImageNV;
	public static Image m_imMissileImageNV;
	
	public static ArrayList m_alPrintText = new ArrayList();
	public static ArrayList m_alSprite = new ArrayList();
	public static ArrayList m_alSound = new ArrayList();
	public static ArrayList m_alHUD = new ArrayList();
	public static Controls [] m_cPlayerControls = new Controls[2];
	public static int m_iGameStatus;
	
	public static int STARTING = 0;
	public static int SPLASH = 1;
	public static int NEWGAME = 2;
	public static int LOADGAME = 3;
	public static int OPTIONS = 4;
	public static int RUNNING = 5;
	public static int DEMO = 6;
	public static int END = 7;
	public static int RESTART= 8;
	
	public Util(){}
	
	public static void Starting()
	{
		m_iGameStatus = STARTING;
	}
	public static void Splash()
	{	
		m_iGameStatus = SPLASH;
	}
	public static void LoadGame()
	{	
		m_iGameStatus = LOADGAME;
	}
	public static void NewGame()
	{	
		m_iGameStatus = NEWGAME;
	}
	public static void Running()
	{	
		m_iGameStatus = RUNNING;
	}
	public static void Options()
	{	
		m_iGameStatus = OPTIONS;
	}
	public static void Demo()
	{			
		m_iGameStatus = DEMO;
	}
	public static void End()
	{	
		m_iGameStatus = END;
	}
	public static void Restart()
	{
		m_iGameStatus = RESTART;
	}
	
	public static int RandomNumber (int num1, int num2)
	{
		num2 = num2+1;
		Random r = new Random();
		return (Math.abs(r.nextInt()) % (num2-num1)) + num1;
	}
	
	public static void SetTime(Time t)
	{
		m_tTime = new Time(t);	
	}
	
	public static void WorldMap()
	{
		m_bOnWorldMap = true;
		m_bOnTownMap = false;
		m_bInBattle = false;
		m_lCurrentLevel = m_lWorld;
		m_pGlobalOffset = m_pWorldGlobalOffset;
	}
	public static void TownMap()
	{
		m_bOnWorldMap = false;
		m_bOnTownMap = true;
		m_bInBattle = false;
		m_lCurrentLevel = m_lTown;
		if (m_pTownGlobalOffset != null)
		{
			m_pGlobalOffset = m_pTownGlobalOffset;
		}
	}
	public static void Battle()
	{
		m_bOnWorldMap = false;
		m_bOnTownMap = false;
		m_bInBattle = true;
		m_lCurrentLevel = m_lBattle;
		if (m_pBattleGlobalOffset != null)
		{
			m_pGlobalOffset = m_pBattleGlobalOffset;
		}
	}
	public static void SetLevel(Level L)
	{
		m_lCurrentLevel = new Level(L);
	}
	public static void AddEnemy(int kind, int script, int scriptshot, Point pos, boolean Reverse, boolean TravelDown)
	{
		ScriptedShip m2 = new ScriptedShip(new Point(pos), new Point(32,32), Util.m_imEnemyImage ,1, true, true);
		m2.m_pBattlePos = new Point(pos);
		m2.AddImage(Util.m_imEnemyImageNV);
		if (Util.m_iVision == 1)
			m2.SetImage(1);
		m2.m_wWeapon = new Phaser("Phaser", 10,10,99);
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("IDLE", (kind*8-2),(kind*8),true,20);
			AnimationList.add(a);
			a = new Animation("DIE1",((kind-1)*8)+1,(kind*8-2),false,48);
			AnimationList.add(a);
			a = new Animation("DIE2",((kind-1)*8)+1,(kind*8-2),false,48);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
			m2.PlayAnimation("IDLE");
		m2.m_iScript = script;
		m2.m_iScriptShot = scriptshot;
		m2.m_iFaction = 99;
		m2.m_bTravelDown = TravelDown;
		m2.m_bReverse = Reverse;
		if (TravelDown)
		{
			m2.m_pMaxSpeed.y = 2;
			m2.m_pMaxSpeed.x = 2;
			m2.m_pSpeed.y = 0;
			m2.m_pSpeed.y = 2;
		}
		else
		{
			m2.m_pMaxSpeed.y = -2;
			m2.m_pMaxSpeed.x = 2;
			m2.m_pSpeed.y = 0;
			m2.m_pSpeed.y = -2;
		}
		Util.m_alSprite.add(m2);
	}
	
	public static void AddExplosion(Point pos, Point speed)
	{
		Sprite m2 = new Sprite();
		int r = Util.RandomNumber(1,3);
		if (r == 1)
			m2 = new Sprite(new Point(pos), new Point(42,42), Util.m_imExplosionImage ,1, false, false);
		if (r == 2)
			m2 = new Sprite(new Point(pos), new Point(42,42), Util.m_imExplosionImage ,1, false, false);
		if (r == 3)
			m2 = new Sprite(new Point(pos), new Point(42,42), Util.m_imExplosionImage ,1, false, false);
		m2.AddImage(Util.m_imExplosionImageNV);
		if (Util.m_iVision == 1)
			m2.SetImage(1);
		m2.m_tDeathTime = new Time(Util.m_tTime);
		m2.m_tDeathTime.AddMilliseconds(500);
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", 1,9,true,12);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		m2.PlayAnimation("DIE");
		m2.m_pSpeed.x = speed.x;
		m2.m_pSpeed.y = speed.y;
		Util.m_alSprite.add(m2);
	}
	public static void AddParticle(Point pos, Point speed)
	{
		Sprite m2 = new Sprite(new Point(pos), new Point(3,3), Util.m_imParticleImage ,1, false, false);
		m2.AddImage(Util.m_imParticleImageNV);
		m2.m_tDeathTime = new Time(Util.m_tTime);
		m2.m_tDeathTime.AddMilliseconds(750);
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", 1,9,true,12);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		m2.PlayAnimation("DIE");
		m2.m_pSpeed.x = speed.x;
		m2.m_pSpeed.y = speed.y;
		m2.SetImage(Util.m_iVision);
		Util.m_alSprite.add(m2);
	}
	public static void AddPowerUp(Point pos, Point speed)
	{
		PowerUp m2 = new PowerUp(new Point(pos), new Point(32,32), Util.m_imPowerUpImage ,1, false, false);
		m2.m_iType = Util.RandomNumber(0,2);
		m2.AddImage(Util.m_imPowerUpImageNV);
		if (Util.m_iVision == 1)
			m2.SetImage(1);
		if (m2.m_iType == 0)
		{
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", 1,3,true,3);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		}
		if (m2.m_iType == 1)
		{
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", 4,6,true,3);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		}
		if (m2.m_iType == 2)
		{
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", 7,9,true,3);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		}
		m2.PlayAnimation("DIE");
		m2.m_pSpeed.x = speed.x;
		m2.m_pSpeed.y = speed.y;
		Util.m_alSprite.add(m2);
	}
	
	public static void SetAllTextColor(Color c)
	{
		for (int x = 0; x < Util.m_alPrintText.size(); x++)
		{
			if (Util.m_alPrintText.get(x) instanceof Text)
			{
				Text t = ((Text)(Util.m_alPrintText.get(x)));
				t.m_cColor = c;
			}
			if (Util.m_alPrintText.get(x) instanceof TextBox)
			{
				Text t = ((TextBox)(Util.m_alPrintText.get(x))).m_tText;
				t.m_cColor = c;
				t = ((TextBox)(Util.m_alPrintText.get(x))).m_tName;
				t.m_cColor = c;
			}
		}
	}
	public static void SetTextColor(int x, Color c)
	{
		if (x >= Util.m_alPrintText.size())
			return;
		
		if (Util.m_alPrintText.get(x) instanceof Text)
			{
				Text t = ((Text)(Util.m_alPrintText.get(x)));
				t.m_cColor = c;
			}
			if (Util.m_alPrintText.get(x) instanceof TextBox)
			{
				Text t = ((TextBox)(Util.m_alPrintText.get(x))).m_tText;
				t.m_cColor = c;
				t = ((TextBox)(Util.m_alPrintText.get(x))).m_tName;
				t.m_cColor = c;
			}
	}
	public static int NumOfEnemies()
	{
		int ret = 0;
		for (int x = 0; x < Util.m_alSprite.size(); x++)
		{
			if (((Sprite)(m_alSprite.get(x))).m_iFaction == 99)
			{
				ret++;
			}
		}
		return ret;
			
	}
	public static void SetVision(int i)
	{
		for (int x = 0; x < Util.m_alSprite.size(); x++)
		{
			((Sprite)(m_alSprite.get(x))).SetImage(i);
		}
	}
}