import java.util.Random;
import java.awt.*;
import java.util.*;
import java.net.*;

public class Util
{
	public static boolean OnWorldMap;
	public static boolean OnTownMap;
	public static boolean InBattle;
	public static Time m_tTime;
	public static Level m_lCurrentLevel;
	public static int m_iGravity;
	public static Rectangle m_rcScreen;
	public static Camera m_rcCamera;
	public static Point m_pGlobalOffset;
	public static Point m_pScrollSpeed;
	public static URL CodeBase;
	public static int m_iNumOfPlayers;
	public static int m_iNumOfAllys;
	public static int m_iLaserDamage;
	public static int m_iBulletDamage;
	public static int m_iFlameDamage;
	public static int m_iPulseDamage;
	public static int m_iPhaserDamage;
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
	
	public static ArrayList m_alPrintText = new ArrayList();
	public static ArrayList m_alSprite = new ArrayList();
	public static ArrayList m_alSound = new ArrayList();
	public static ArrayList m_alHUD = new ArrayList();
	public static Controls [] m_cPlayerControls = new Controls[2];
	
	public Util(){}
	
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
		OnWorldMap = true;
		OnTownMap = false;
		InBattle = false;
	}
	public static void TownMap()
	{
		OnWorldMap = false;
		OnTownMap = true;
		InBattle = false;
	}
	public static void Battle()
	{
		OnWorldMap = false;
		OnTownMap = false;
		InBattle = true;
	}
	public static void SetLevel(Level L)
	{
		m_lCurrentLevel = new Level(L);
	}
	public static void AddEnemy(int kind, int script, int scriptshot, Point pos, boolean Reverse, boolean TravelDown)
	{
		ScriptedShip m2 = new ScriptedShip(new Point(pos), new Point(32,32), Util.m_imEnemyImage ,1, true, true);
		m2.m_wWeapon = new Phaser("Phaser", 1);
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
		m2.m_bTravelDown = false;
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
		m2.m_tDeathTime = new Time(Util.m_tTime);
		m2.m_tDeathTime.AddMilliseconds(750);
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", 1,9,true,12);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		m2.PlayAnimation("DIE");
		m2.m_pSpeed.x = speed.x;
		m2.m_pSpeed.y = speed.y;
		Util.m_alSprite.add(m2);
	}
	public static void AddPowerUp(Point pos, Point speed)
	{
		PowerUp m2 = new PowerUp(new Point(pos), new Point(32,32), Util.m_imPowerUpImage ,1, false, false);
			ArrayList AnimationList = new ArrayList();
			Animation a = new Animation("DIE", 1,9,true,12);
			AnimationList.add(a);
			m2.SetAnimations(AnimationList);
		m2.PlayAnimation("DIE");
		m2.m_iType = Util.RandomNumber(0,1);
		m2.m_pSpeed.x = speed.x;
		m2.m_pSpeed.y = speed.y;
		Util.m_alSprite.add(m2);
	}
}