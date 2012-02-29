import java.awt.*;

public class Collision
{
	public static void HandleCollision()
	{
		int tempx;
		int tempy;
//GRAVITY
		for (int x = 0; x < Util.m_alSprite.size(); x++)
		{
			Sprite temp = new Sprite((Sprite)(Util.m_alSprite.get(x)));
			if (!(temp.m_bApplyGravity))
				continue;
			tempx = temp.m_pSpeed.x;
			tempy = temp.m_pSpeed.y;
			
			temp.m_pSpeed.x = 0;
			
			System.out.println(temp.m_pSpeed.y + "+=" + .5 + "*" + Util.m_iGravity + "*"+temp.m_iCompoundedGravity);
			
			temp.m_pSpeed.y = (int)(.5 * Util.m_iGravity * temp.m_iCompoundedGravity);
			
			temp.Update();
			
			boolean update = true;
			

			//camera
				if (x < 2)
				{
					if (!Util.m_rcScreen.contains(temp.m_rcBoundingBox) && (temp).m_bIsPlayer)
						update = false;
				}
				
				for (int y = x+1; y < Util.m_alSprite.size(); y++)
				{
					
					//Sprite temp2 = new Sprite((Sprite)(Util.m_alSprite.get(y)));
					//if (temp.m_iFaction >=0 && temp2.m_iFaction>=0 && temp.m_iFaction != temp2.m_iFaction && temp.IsColliding(temp2.m_rcBoundingBox) && temp.m_bIsSolid && temp2.m_bIsSolid)
					//	update = false;
				}
				if (Util.m_lCurrentLevel != null)
				{
					if (Util.m_lCurrentLevel.IsColliding(temp.m_rcBoundingBox))
					{
						if (temp.m_bIsSolid)
							update = false;
					}
					if (Util.m_lCurrentLevel.m_alEntities != null)
					{
						for (int t = 0; t < Util.m_lCurrentLevel.m_alEntities.size(); t++)
						{
							Entity E = (Entity)(Util.m_lCurrentLevel.m_alEntities.get(t));
	
					
							if (temp.IsColliding(new Rectangle(E.m_rcBoundingBox.x + Util.m_pGlobalOffset.x,
															   E.m_rcBoundingBox.y + Util.m_pGlobalOffset.y,
															   E.m_rcBoundingBox.width,
															   E.m_rcBoundingBox.height)))
							{
								E.Update((Sprite)(Util.m_alSprite.get(x)));
							}
						}
					}
					else
					{
				//		System.out.println("Null");
					}
				}
				if (temp.m_tDeathTime != null)
					update = true;
				if (update)
				{
					Sprite temp2 = (Sprite)(Util.m_alSprite.get(x));
					temp2.m_bDidCompoundGravity = true;
					temp2.m_pSpeed.x = 0;
					temp2.m_pSpeed.y = (int)(.5 * Util.m_iGravity * temp2.m_iCompoundedGravity);
					temp2.Update();
					temp2.m_pSpeed.x = tempx;
					temp2.m_pSpeed.y = tempy + (int)(.5 * Util.m_iGravity * temp2.m_iCompoundedGravity);
					temp2.m_bOnGround = false;
				}
				else
				{
					Sprite temp2 = (Sprite)(Util.m_alSprite.get(x));
					temp2.m_bDidCompoundGravity = false;
					temp2.m_bOnGround = true;
				}
		}

//MOVEMENT
		for (int x = 0; x < Util.m_alSprite.size(); x++)
		{
			Sprite temp = new Sprite((Sprite)(Util.m_alSprite.get(x)));
			temp.Update();

				boolean update = true;
				
				//camera
				if (x < 2)
				{
					if (!Util.m_rcScreen.contains(temp.m_rcBoundingBox) && (temp).m_bIsPlayer)
						update = false;
				}
				for (int y = x+1; y < Util.m_alSprite.size(); y++)
				{
					
					Sprite temp2 = new Sprite((Sprite)(Util.m_alSprite.get(y)));
					
					if (temp.IsColliding(temp2.m_rcBoundingBox))
					{
						Sprite real = (Sprite)(Util.m_alSprite.get(x));
						Sprite real2 = (Sprite)(Util.m_alSprite.get(y));
						real.CollideWith(real2);
						
						//if (temp.m_iFaction >=0 && temp2.m_iFaction>=0 && temp.m_iFaction != temp2.m_iFaction && temp.IsColliding(temp2.m_rcBoundingBox) && temp.m_bIsSolid && temp2.m_bIsSolid)
						//	update = false;
					}
					
				}
				if (Util.m_lCurrentLevel != null)
				{
					if (Util.m_lCurrentLevel.IsColliding(temp.m_rcBoundingBox))
					{
						Sprite real = (Sprite)(Util.m_alSprite.get(x));
						Util.m_lCurrentLevel.CollideWith(real);
						if (temp.m_bIsSolid)
							update = false;
					}
					if (Util.m_lCurrentLevel.m_alEntities != null)
					{
						for (int t = 0; t < Util.m_lCurrentLevel.m_alEntities.size(); t++)
						{
							Entity E = (Entity)(Util.m_lCurrentLevel.m_alEntities.get(t));
							if (temp.IsColliding(new Rectangle(E.m_rcBoundingBox.x + Util.m_pGlobalOffset.x,
								   E.m_rcBoundingBox.y + Util.m_pGlobalOffset.y,
								   E.m_rcBoundingBox.width,
								   E.m_rcBoundingBox.height)))
							{
								E.Update((Sprite)(Util.m_alSprite.get(x)));
							}
						}
					}
					else
					{
					//	System.out.println("Null");
					}
				}
				if (temp.m_tDeathTime != null)
					update = true;
				if (update)
				{
					Sprite temp2 = (Sprite)(Util.m_alSprite.get(x));
					temp2.Update();
				}
		}
	}
}