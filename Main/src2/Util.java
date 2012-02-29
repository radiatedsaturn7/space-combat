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
	public static Image m_imEnemyImage;
	public static Image m_imShotImage;
	
	public static ArrayList m_alPrintText = new ArrayList();
	public static ArrayList m_alSprite = new ArrayList();
	public static ArrayList m_alSound = new ArrayList();
	public static Controls [] m_cPlayerControls = new Controls[2];
	
	public Util(){}
	
	public static int RandomNumber (int num1, int num2)
	{
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
}