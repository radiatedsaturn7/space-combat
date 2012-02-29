import java.awt.*;
//import java.util.*;

public class Character extends Sprite
{
	public boolean m_bIsPlayer;
	public String m_sName;
	public Weapon m_wWeapon;
	public Armor m_aArmor;
	public HeadGear m_hgHeadgear;
	public Relic m_rRelic;
	
	public int m_iHealth;
	public int m_iMagic;
	
	public int m_iStrength;
	public int m_iDefense;
	
	public int m_iMagicStrength;
	public int m_iMagicDefense;
	
	public int m_iSpeed;
	public int m_iEndurance;
	
	public int m_iLuck;
	public int m_iDetermination;
	
	public int m_iEXP;
	public int m_iMEXP;
	public int m_iWEXP;
	
	public Character(Character c)
	{
		super(((Sprite)(c)));
		m_dDirection = new Direction(c.m_dDirection);
		m_iHealth = c.m_iHealth;
		m_iMagic = c.m_iMagic;
		m_iStrength = c.m_iStrength;
		m_iDefense = c.m_iDefense;
		m_iMagicStrength = c.m_iMagicStrength;
		m_iMagicDefense = c.m_iMagicDefense;
		m_iSpeed = c.m_iSpeed;
		m_iEndurance = c.m_iEndurance;
		m_iLuck = c.m_iLuck;
		m_iDetermination = c.m_iDetermination;
		m_bIsPlayer = c.m_bIsPlayer;
		m_iEXP = c.m_iEXP;
		m_iMEXP = c.m_iMEXP;
		m_iWEXP = c.m_iWEXP;
		
	}
	public Character(Point Pos, Point Size, Image image, int frame, boolean solid, boolean applygravity)
	{
		super (Pos, Size, image, frame, solid, applygravity);
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
	}
	public Character(){

	}
	
	
	public int GetAttackDmg()
	{
		return m_wWeapon.m_iBaseDamage + m_iStrength + Util.RandomNumber(-2,5);
	}
	
	public int TakeDamage(int amt, char type)
	{
		if (type == 'P')
		{
			if (amt - m_iDefense > 0)
			{
				m_iHealth -= (amt - m_iDefense);
				return (amt-m_iDefense);
			}
		}
		else if (type == 'M')
		{
			if (amt - m_iMagicDefense > 0)
			{
				m_iHealth -= (amt - m_iMagicDefense);
				return (amt-m_iMagicDefense);
			}
		}
		return 0;
	}
	
	public boolean IsLucky()
	{
		int luck = Util.RandomNumber(0,100);
		if (luck < m_iLuck)
			return true;
		return false;
	}
	public boolean IsDetermined()
	{
		int determination = Util.RandomNumber(0,100);
		if (determination < m_iDetermination)
			return true;
		return false;
	}
	public void Update()
	{
		if (m_iHealth <= 0)
			m_bDelete = true;
		super.Update();
	}
	public void CollideWith (Sprite S)
	{
		if (S.m_iFaction == m_iFaction)
		{
					return;
		}
		if (S instanceof Shot)
		{
			TakeDamage(((Shot)(S)).m_iDamage, 'P');
			S.m_bDelete = true;
		}
		else if (S instanceof Character)
		{
			S.m_dDirection.Reverse();
			TakeDamage(10, 'P');
			if (S.m_rcBoundingBox.x > m_rcBoundingBox.x)
			{
				m_pSpeed.x = -8;
				m_pSpeed.y = -20;
			}
			else
			{
				m_pSpeed.x = 8;
				m_pSpeed.y = -20;
			}
		}
		else if (S.m_bIsSolid)
		{
			m_pSpeed.x = (int)(1/2)*(-m_pSpeed.x);
			m_pSpeed.y = (int)(1/2)*(-m_pSpeed.y);
			S.m_pSpeed.x = (int)(1/2)*(-S.m_pSpeed.x);
			S.m_pSpeed.y = (int)(1/2)*(-S.m_pSpeed.y);
		}
		//System.out.println("Collision Character");
	}
}