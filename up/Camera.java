import java.awt.*;

public class Camera extends Rectangle
{
	static final long serialVersionUID = 1;
	 public void HandleCamera()
	 {
		
		 Direction LR = new Direction();
		 Direction UD = new Direction();
		 int sx = 0;
		 int sy = 0;
		 
		 //System.out.println("LR"+(-(Util.m_pGlobalOffset.x + Util.m_pScrollSpeed.x - Util.m_rcScreen.width)) + "<"+ (Util.m_lCurrentLevel.m_iSizeX) + "::" + (0 - Util.m_pGlobalOffset.x + Util.m_pScrollSpeed.x) + ">" + "0");
		//System.out.println("UD"+(-(Util.m_pGlobalOffset.y + Util.m_pScrollSpeed.y - Util.m_rcScreen.height))+ "<"+ (Util.m_lCurrentLevel.m_iSizeY) + "::" + (0 - Util.m_pGlobalOffset.y + Util.m_pScrollSpeed.y) + ">" + "0");

		//SCROLLING
		if ((Util.m_lCurrentLevel != null && (-(Util.m_pGlobalOffset.x + Util.m_pScrollSpeed.x - Util.m_rcScreen.width)) < Util.m_lCurrentLevel.m_iSizeX) && (0 - Util.m_pGlobalOffset.x + Util.m_pScrollSpeed.x > 0))
		{
				Util.m_pGlobalOffset.x +=Util.m_pScrollSpeed.x;
		}
		if ((Util.m_lCurrentLevel != null && (-(Util.m_pGlobalOffset.y + Util.m_pScrollSpeed.y - Util.m_rcScreen.height)) < Util.m_lCurrentLevel.m_iSizeY) && (0 - Util.m_pGlobalOffset.y + Util.m_pScrollSpeed.y > 0))
		{
				Util.m_pGlobalOffset.y +=Util.m_pScrollSpeed.y;
		}
		
		 for (int x = 0; x < Util.m_alSprite.size(); x++)
		 {
			Sprite S1 = null;
			if (Util.m_alSprite.size() >= 2)
				S1 = (Sprite)Util.m_alSprite.get(1);
			//player 2 is not a player
			if ((x == 0 && S1 instanceof Character && !((Character)(S1)).m_bIsPlayer) || S1 == null)
			{
				Sprite S = (Sprite)Util.m_alSprite.get(x);
				sx = Math.abs(S.m_pSpeed.x);
				sy = Math.abs(S.m_pSpeed.y);
					//RIGHT
				if (S.m_rcBoundingBox.x > this.x + this.width)
				{
					if (Util.m_lCurrentLevel != null && (-(Util.m_pGlobalOffset.x - sx - Util.m_rcScreen.width)) < Util.m_lCurrentLevel.m_iSizeX)
					{
						LR.Left();
						S.m_rcBoundingBox.x -= sx;
						Util.m_pGlobalOffset.x -= sx;
					}
				}
				//LEFT
				if (S.m_rcBoundingBox.x < this.x)
				{
					if (0 - Util.m_pGlobalOffset.x - sx > 0)
					{
						LR.Right();
						S.m_rcBoundingBox.x += sx;
						Util.m_pGlobalOffset.x += sx;
					}
				}
				//DOWN
				if (S.m_rcBoundingBox.y > this.y + this.height)
				{
					if (Util.m_lCurrentLevel != null && (-(Util.m_pGlobalOffset.y - sy + Util.m_pScrollSpeed.y - Util.m_rcScreen.height)) < Util.m_lCurrentLevel.m_iSizeY)
					{
						UD.Down();
						S.m_rcBoundingBox.y -= sy;
						Util.m_pGlobalOffset.y -= sy;
						Util.m_pGlobalOffset.y -= (int)(.5 * Util.m_iGravity * S.m_iCompoundedGravity);
					}
				}
				//UP
				if (S.m_rcBoundingBox.y < this.y)
				{
					if (0 - Util.m_pGlobalOffset.y - sy + Util.m_pScrollSpeed.y > 0)
					{
						//System.out.println("TRUE");
						UD.Up();
						S.m_rcBoundingBox.y += sy;
						Util.m_pGlobalOffset.y +=sy;
						Util.m_pGlobalOffset.y -= (int)(.5 * Util.m_iGravity * S.m_iCompoundedGravity);
					}
				}	
			}
			else if (x == 0 && S1 instanceof Character && ((Character)(S1)).m_bIsPlayer)
			{
				Sprite S = (Sprite)Util.m_alSprite.get(x);
				Sprite S2 = (Sprite)Util.m_alSprite.get(x+1);
				
				Point p = new Point ((int)((S.m_rcBoundingBox.x + S2.m_rcBoundingBox.x)/2),(int)((S.m_rcBoundingBox.y + S2.m_rcBoundingBox.y)/2));
				
				//System.out.println("R"+S.m_rcBoundingBox.x+ ">"+ (this.x + this.width));
				//System.out.println("L"+S.m_rcBoundingBox.x+ "<"+ (this.x));
				//System.out.println("D"+S.m_rcBoundingBox.y+ ">"+ (this.y + this.height));
				//System.out.println("U"+S.m_rcBoundingBox.y+ "<"+ (this.y) + " " + sx + " " +sy);

				//RIGHT
				if (p.x > this.x + this.width)
				{
					if (Util.m_lCurrentLevel != null && (-(Util.m_pGlobalOffset.x - sx - Util.m_rcScreen.width)) < Util.m_lCurrentLevel.m_iSizeX)
					{
						if (S.m_rcBoundingBox.x > S2.m_rcBoundingBox.x)
							sx = Math.abs(S.m_pSpeed.x);
						else
							sx = Math.abs(S2.m_pSpeed.x);
						LR.Left();
						S.m_rcBoundingBox.x -= sx;
						Util.m_pGlobalOffset.x -= sx;
					}
				}
				//LEFT
				if (p.x < this.x)
				{
					if (0 - Util.m_pGlobalOffset.x - sx > 0)
					{
						if (S.m_rcBoundingBox.x < S2.m_rcBoundingBox.x)
							sx = Math.abs(S.m_pSpeed.x);
						else
							sx = Math.abs(S2.m_pSpeed.x);
						LR.Right();
						S.m_rcBoundingBox.x += sx;
						Util.m_pGlobalOffset.x += sx;
					}
				}
				//DOWN
				if (p.y > this.y + this.height)
				{
					if (Util.m_lCurrentLevel != null && (-(Util.m_pGlobalOffset.y - sy - Util.m_rcScreen.height)) < Util.m_lCurrentLevel.m_iSizeY)
					{
						if (S.m_rcBoundingBox.y > S2.m_rcBoundingBox.y)
							sy = Math.abs(S.m_pSpeed.y);
						else
							sy = Math.abs(S2.m_pSpeed.y);
						UD.Down();
						S.m_rcBoundingBox.y -= sy;
						Util.m_pGlobalOffset.y -= sy;
						Util.m_pGlobalOffset.y -= (int)(.5 * Util.m_iGravity * S.m_iCompoundedGravity);
					}
				}
				//UP
				if (p.y < this.y)
				{
						if (S.m_rcBoundingBox.y < S2.m_rcBoundingBox.y)
							sy = Math.abs(S.m_pSpeed.y);
						else
							sy = Math.abs(S2.m_pSpeed.y);
					if (0 - Util.m_pGlobalOffset.y - sy > 0)
					{
					//	System.out.println("TRUE");
						UD.Up();
						S.m_rcBoundingBox.y += sy;
						Util.m_pGlobalOffset.y +=sy;
						Util.m_pGlobalOffset.y -= (int)(.5 * Util.m_iGravity * S.m_iCompoundedGravity);
					}
				}		
			}
			else
			{
				Sprite S = (Sprite)Util.m_alSprite.get(x);
				if (LR.IsLeft())
				{
					S.m_rcBoundingBox.x -= sx;
				}
				if (LR.IsRight())
				{
					S.m_rcBoundingBox.x += sx;
				}
				
				if (UD.IsDown())
				{
					S.m_rcBoundingBox.y -= sy;
				}
				if (UD.IsUp())
				{
					S.m_rcBoundingBox.y += sy;
				}	
			}
		 }
	 }
}
