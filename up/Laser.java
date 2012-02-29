import java.util.*;
import java.awt.*;

public class Laser extends Weapon{
	public Laser(String name, int damage, int damage2, int owner)
	{
		super(name, damage, damage2, owner);
	}
	public void Shoot(Point Position, Point Speed, int Faction, Time Life)
	{

		ArrayList AnimationList = new ArrayList();
			Animation a = new Animation();
		Shot sh = new Shot(new Point(Position),new Point(32,32),Util.m_imLaserImage, Util.m_iLaserDamage, m_iOwner, false, false);
		sh.AddImage(Util.m_imLaserImageNV);
		sh.m_iDamage = m_iBaseDamage+m_iPowerLevel;
		if (Life != null)
				sh.m_tLife = new Time(Life);
		AnimationList = new ArrayList();
			a = new Animation("IDLE",m_iPowerLevel,m_iPowerLevel,true,12);
		AnimationList.add(a);

		sh.SetAnimations(AnimationList);
		sh.PlayAnimation("IDLE");
		
		sh.m_pSpeed.x = Speed.x;
		sh.m_pSpeed.y = Speed.y;

		sh.m_iFaction = Faction;
		
		sh.SetImage(Util.m_iVision);
		Util.m_alSprite.add(sh);
		
		m_tLastShotTime = new Time(Util.m_tTime);
	}
	public void ShootMissile(Point Position, Point Speed, int Faction, Time Life)
	{
		Shot sh;
		ArrayList AnimationList = new ArrayList();
		Animation a = new Animation();
		if (m_iPowerLevel2 > 0)
		{
			sh = new Shot(new Point(Position),new Point(32,32),Util.m_imMissileImage, 1, m_iOwner, false, false);
			sh.AddImage(Util.m_imMissileImageNV);
			sh.m_iDamage = m_iMissileBaseDamage+m_iPowerLevel2;
			
			sh.m_tLife = null;
			
			AnimationList = new ArrayList();
				a = new Animation("IDLE",1,3,true,6);
			AnimationList.add(a);
	
			sh.SetAnimations(AnimationList);
			sh.PlayAnimation("IDLE");
			
			sh.m_pSpeed.x = -7;
			sh.m_pSpeed.y = -8;
	
			sh.m_iFaction = Faction;
			sh.SetImage(Util.m_iVision);
			Util.m_alSprite.add(sh);
			//---------------------------
			sh = new Shot(new Point(Position),new Point(32,32),Util.m_imMissileImage, 1, m_iOwner, false, false);
			sh.AddImage(Util.m_imMissileImageNV);
			sh.m_iDamage = m_iMissileBaseDamage+m_iPowerLevel2;
			
			sh.m_tLife = null;
			
			AnimationList = new ArrayList();
				a = new Animation("IDLE",1,3,true,6);
			AnimationList.add(a);
	
			sh.SetAnimations(AnimationList);
			sh.PlayAnimation("IDLE");
	
			
			sh.m_pSpeed.x = 7;
			sh.m_pSpeed.y = -8;
	
			sh.m_iFaction = Faction;
			sh.SetImage(Util.m_iVision);
			Util.m_alSprite.add(sh);	
		}
		m_tMissileLastShotTime = new Time(Util.m_tTime);
	}
}
