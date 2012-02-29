import java.util.*;
import java.awt.*;

public class HellGun extends Weapon{
	public HellGun(String name, int damage)
	{
		super(name, damage);
	}
	public void Shoot(Point Position, Point Speed, int Faction, Time Life)
	{
		int max = (int)(Util.m_rcScreen.height / 32)+1;
		Shot sh;
		ArrayList AnimationList = new ArrayList();
		Animation a = new Animation();
		for (int loop = 0; loop < 2; loop++)
		{
			for (int x = 0; x < max; x++)
			{
				AnimationList = new ArrayList();
				a = new Animation();
				sh = new Shot(new Point(Position.x,Position.y - (32 * x)),new Point(32,32),Util.m_imHellImage, 1, false, false);
				sh.m_iDamage += m_iPowerLevel;
				int z = 5-(int)((m_iPowerLevel-1)/1.8);

				AnimationList = new ArrayList();
					a = new Animation("IDLE",z,5,false,6);
				AnimationList.add(a);
		
				sh.SetAnimations(AnimationList);
				sh.PlayAnimation("IDLE");
				
				sh.m_pSpeed.x = Speed.x + Util.RandomNumber(-3,3);
				sh.m_pSpeed.y = Speed.y + Util.RandomNumber(0,6);
		
				sh.m_iFaction = Faction;
				Util.m_alSprite.add(sh);
				
				m_tLastShotTime = new Time(Util.m_tTime);
			}
		}
		if (m_iPowerLevel2 > 0)
		{
			sh = new Shot(new Point(Position),new Point(32,32),Util.m_imMissileImage, 1, false, false);
			sh.m_iDamage += m_iPowerLevel;
			sh.m_tLife = null;
			AnimationList = new ArrayList();
				a = new Animation("IDLE",1,3,true,6);
			AnimationList.add(a);
	
			sh.SetAnimations(AnimationList);
			sh.PlayAnimation("IDLE");
			
			sh.m_pSpeed.x = -1;
			sh.m_pSpeed.y = -15;
	
			sh.m_iFaction = Faction;
			Util.m_alSprite.add(sh);
			
			sh = new Shot(new Point(Position),new Point(32,32),Util.m_imMissileImage, 1, false, false);
			sh.m_iDamage += m_iPowerLevel;
			sh.m_tLife = null;
			AnimationList = new ArrayList();
				a = new Animation("IDLE",1,3,true,6);
			AnimationList.add(a);
	
			sh.SetAnimations(AnimationList);
			sh.PlayAnimation("IDLE");
			sh.m_pSpeed.x = 1;
			sh.m_pSpeed.y = -15;
	
			sh.m_iFaction = Faction;
			Util.m_alSprite.add(sh);	
		}
	}
}
