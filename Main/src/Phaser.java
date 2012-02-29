import java.util.*;
import java.awt.*;

public class Phaser extends Weapon{
	public Phaser(String name, int damage)
	{
		super(name, damage);
	}
	public void Shoot(Point Position, Point Speed, int Faction, Time Life)
	{
		ArrayList AnimationList = new ArrayList();
		Animation a = new Animation();
		Shot sh = new Shot(new Point(Position),new Point(32,32),Util.m_imShotImage, 1, false, false);

		AnimationList = new ArrayList();
			a = new Animation("IDLE",1,7,true,12);
		AnimationList.add(a);

		sh.SetAnimations(AnimationList);
		sh.PlayAnimation("IDLE");
		
		sh.m_pSpeed.x = Speed.x;
		sh.m_pSpeed.y = Speed.y;

		sh.m_iFaction = Faction;
		Util.m_alSprite.add(sh);
		
		m_tLastShotTime = new Time(Util.m_tTime);
	}
}
