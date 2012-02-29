/* COPYRIGHT 2005 ROB PISKULE
 *ALL RIGHTS RESERVED
 *
 *OPEN SOURCE< LEAVE ALL CREDITS AT TOP!*/

//FIX POWER UP SPRITE
//FIX ENEMY SHOT SO IT WILL SHOOT AT ANYONE

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.awt.geom.Line2D;
import java.net.*;


public class Main extends Applet implements Runnable, MouseListener
{
	static final long serialVersionUID = 1;
	
	//OTHER
	boolean m_bUseButtonToggle = false;
	boolean m_bStartNewThread = true;
	
	static int m_iPointerSelection = 0;
	
	private Image dbImage;
	private Graphics dbg;
	
	Sprite s;
	
	Line2D.Float G_l;
	ArrayList m_alAllEntities = new ArrayList();
	
	/*
	public static Image GetImage(URL u, String s)
	{
		return Applet.getImage(u,s);
	}
	*/
	
	public void init()
	{
		Util.m_mMain = this;
		Util.m_cPlayerControls[0] = new Controls();
		Util.m_cPlayerControls[1] = new Controls();
		Time t = new Time(); //time = 0
		Util.SetTime(t); //set global time to 0
		int camsizex = 150;
		int camsizey = 100;
		Util.m_rcCamera = new Camera();
		Util.m_rcScreen = new Rectangle();
		Util.m_pGlobalOffset = new Point();
		Util.m_pScrollSpeed = new Point();
		Util.m_rcScreen.x = 0;
		Util.m_rcScreen.y = 0;
		
		Util.m_rcScreen.width = 800;
		Util.m_rcScreen.height = 600;
		
		Util.m_rcCamera.width = camsizex;
		Util.m_rcCamera.height = camsizey;
		Util.m_rcCamera.x = (int)((Util.m_rcScreen.width/2)-(Util.m_rcCamera.width/2));
		Util.m_rcCamera.y = (int)((Util.m_rcScreen.height/2)-(Util.m_rcCamera.height/2));
		Util.m_pGlobalOffset.x = 0;//-124;
		Util.m_pGlobalOffset.y = 0;//-2024;
		Util.m_pWorldGlobalOffset = new Point(0,0);
		Util.m_pTownGlobalOffset = new Point(0,0);
		Util.m_pBattleGlobalOffset = new Point(0,0);
		Util.m_pScrollSpeed.x = 0;
		Util.m_pScrollSpeed.y = 0;
		this.resize(Util.m_rcScreen.width,Util.m_rcScreen.height);
		
		GameRules.OnRestart();
		
		Util.m_imEnemyImage = GetImage("Enemy.gif");
	
		if (!m_bStartNewThread)
		{
			return;
		}
		GameRules.OnStart();
		m_bStartNewThread = false;
		Thread th = new Thread (this);
		th.start ();
	}

	public void start ()
	{
		//when the window is re opened, do this
	}

	public void stop()
	{
		//when the window is minimized, do this
	}

	public void destroy()
	{

	}

	public void run ()
	{
		Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
		while (true)
		{
			repaint();
			try
			{
				Thread.sleep (35);
				Util.m_tTime.AddMilliseconds(35);
			}
			catch (InterruptedException ex)
			{
			}
			//Thread.currentThread().setPriority(Thread.NORM_PRIORITY);
		}
	}
	
	public Image GetImage(String s)
	{
		      return getImage(getCodeBase(), s);
	}
	
	
	public void Restart()
	{
			init();
			start();
			
			Util.Starting();
	}
	
	public void update (Graphics g)
	{
		//check collision
		Collision.HandleCollision();
		for (int x = 0; x < Util.m_alHUD.size(); x++)
		{
			((HUD)(Util.m_alHUD.get(x))).Update();	
		}
		Util.m_rcCamera.HandleCamera();
		
			if (Util.m_iGameStatus == Util.STARTING)
				GameRules.Starting(g);
			else if (Util.m_iGameStatus == Util.SPLASH)
				GameRules.Splash(g);
			else if (Util.m_iGameStatus == Util.NEWGAME)
				GameRules.NewGame(g);
			else if (Util.m_iGameStatus == Util.LOADGAME)
				GameRules.LoadGame(g);
			else if (Util.m_iGameStatus == Util.OPTIONS)
				GameRules.Options(g);
			else if (Util.m_iGameStatus == Util.RUNNING)
				GameRules.Run(g);
			else if (Util.m_iGameStatus == Util.DEMO)
				GameRules.Demo(g);
			else if (Util.m_iGameStatus == Util.END)
				GameRules.End(g);
			else if (Util.m_iGameStatus == Util.RESTART)
				Restart();
				
		//if (Util.m_tTime.m_iMilliseconds % 2 != 0) //temp frame rate
		//	return;
		
		if (dbImage == null)
		{
			dbImage = createImage (this.getSize().width, this.getSize().height);
			dbg = dbImage.getGraphics ();
		}

		dbg.setColor (getBackground ());
		dbg.fillRect (0, 0, this.getSize().width, this.getSize().height);

		dbg.setColor (getForeground());
		paint (dbg);

		g.drawImage (dbImage, 0, 0, this);
		Controls.HandleControls();
		
	}
    
	public boolean keyDown(Event e, int key)
  	{  			
		Controls.HandleKeyDownControls(e,key);
		return false;
  	}
  	
  	public boolean keyUp(Event e, int key)
  	{ 
	  	Controls.HandleKeyUpControls(e,key);
	  	return true;
  	} 
	
	public void paint (Graphics g)
	{
		//setPaintMode()

		if (Util.m_lCurrentLevel != null)
		{
			Util.m_lCurrentLevel.Paint(g);
		}

		for (int x = 0; x < Util.m_alSprite.size(); x++)
		{
				Sprite S = (Sprite)(Util.m_alSprite.get(x));
				//if (x == 0)
				//{
				//	Sprite S2 = (Sprite)(Util.m_alSprite.get(x+1));
				//}
					//	S.pos.x += 64 * x;
				if (S.m_bDelete)
				{
					//if (S.m_bIsPlayer)
						//Util.m_iNumOfPlayers--;
					Util.m_alSprite.remove(x);
					x--;
					continue;
				}
				
				if (S.CollidesWith(Util.m_rcScreen))
				{
					if ((Util.m_bInBattle && S.m_pBattlePos != null) ||
					(Util.m_bOnTownMap && S.m_pTownPos != null)||
					(Util.m_bOnWorldMap && S.m_pWorldPos != null))
					S.PaintAnimation(g);
			//		S.Paint(g);
			//		S.DrawBoundingBox(g);
				}
		}
		for (int x = 0; x < Util.m_alHUD.size(); x++)
		{
			HUD S = (HUD)(Util.m_alHUD.get(x));
			S.PaintAnimation(g);
		}
		for (int x = 0; x < Util.m_alPrintText.size(); x++)
		{
			if (Util.m_alPrintText.get(x) instanceof Text)
			{
				((Text)(Util.m_alPrintText.get(x))).Paint(g);
			}
			if (Util.m_alPrintText.get(x) instanceof TextBox)
			{
				((TextBox)(Util.m_alPrintText.get(x))).Paint(g);
			}
		}
		/*
		for (int x = 0; x < Util.m_alSound.size(); x++)
		{
			
	      //	URL u = MyApplet.class.getResource( "ribbet.au" );
	      //	if ( u == null )
	      //	{
	      //  	throw new IllegalArgumentException ( "ribbet.au missing from the jar" );
	      // 	}
	      //	frog = getAudioClip( u );
	      //	Util.m_alSound.add(frog);
	    	
			if (Util.m_alSound.get(x) instanceof AudioClip)
			{
				((AudioClip)(Util.m_alSound.get(x))).play();
			}
		}
		*/
		//g.setColor(Color.red);
		//g.drawRect(Util.m_rcCamera.x, Util.m_rcCamera.y, Util.m_rcCamera.width, Util.m_rcCamera.height);

	}
	
	public void mouseClicked(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e)  {} 
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e){}
}