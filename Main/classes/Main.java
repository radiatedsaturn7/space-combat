/* COPYRIGHT 2005 ROB PISKULE
 *ALL RIGHTS RESERVED
 *
 *OPEN SOURCE< LEAVE ALL CREDITS AT TOP!*/



import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.awt.geom.Line2D;


public class Main extends Applet implements Runnable, MouseListener
{
	//DEFINES
	int STARTING = 0;
	int SPLASH = 1;
	int NEWGAME = 2;
	int LOADGAME = 3;
	int OPTIONS = 4;
	int RUNNING = 5;
	int DEMO = 6;
	int END = 7;
	
	//OTHER
	boolean m_bUseButtonToggle = false;
	
	static int m_iPointerSelection = 0;
	
	private Image dbImage;
	private Graphics dbg;
	
	Sprite s;
	
	Line2D.Float G_l;
	ArrayList m_alAllEntities = new ArrayList();
	
	public int m_iGameStatus;
	
	
	public void init()
	{
		Util.m_iGravity = 1;
		m_iGameStatus = STARTING;
		Util.m_cPlayerControls[0] = new Controls();
		Util.m_cPlayerControls[1] = new Controls();
		Time t = new Time(); //time = 0
		Util.SetTime(t); //set global time to 0
	}

	public void start ()
	{
		Util.m_rcCamera = new Camera();
		Util.m_rcScreen = new Rectangle();
		Util.m_pGlobalOffset = new Point();
		Util.m_rcCamera.x = 150;
		Util.m_rcCamera.y = 150;
		Util.m_rcCamera.width = 500;
		Util.m_rcCamera.height = 300;
		Util.m_rcScreen.x = 0;
		Util.m_rcScreen.y = 0;
		Util.m_rcScreen.width = 800;
		Util.m_rcScreen.height = 600;
		Util.m_pGlobalOffset.x = 0;
		Util.m_pGlobalOffset.y = 0;
		this.resize(Util.m_rcScreen.width,Util.m_rcScreen.height);
		Thread th = new Thread (this);
		th.start ();
	}

	public void stop()
	{

	}

	public void destroy()
	{

	}

	public void run ()
	{
		Thread.currentThread().setPriority(Thread.MIN_PRIORITY);
		while (true)
		{
			repaint();
			try
			{
				Thread.sleep (20);
				Util.m_tTime.AddMilliseconds(20);
			}
			catch (InterruptedException ex)
			{
			}
			Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	public void Starting(Graphics g)
	{
		Animation a = new Animation();
		ArrayList  AnimationList = new ArrayList();
		Sprite s = new Sprite();
		
		
		s = new Sprite(new Point(0,0), new Point(64,48), getImage(getCodeBase(), "Loading.jpg") ,1, false, false);
			AnimationList = new ArrayList();
			a = new Animation("PRINT",0,1,true,17);
			AnimationList.add(a);
			s.SetAnimations(AnimationList);
			s.PlayAnimation("PRINT");
		Util.m_alSprite.add(s);
	//	if (Util.m_cPlayerControls[0].m_bStart)
	//	{
			Util.m_alSprite.remove(0);
			Util.m_alPrintText.add(new Text("Start", 140,100));
			Util.m_alPrintText.add(new Text("Load", 140,120));
			Util.m_alPrintText.add(new Text("Options", 140,140));
			Util.m_alSprite = new ArrayList();
			
			s = new Sprite(new Point(0,0), new Point(640,480), getImage(getCodeBase(), "Splash.jpg") ,1, false, false);
				AnimationList = new ArrayList();
				a = new Animation("PRINT",0,0,true,17);
				AnimationList.add(a);
				s.SetAnimations(AnimationList);
				s.PlayAnimation("PRINT");
			Util.m_alSprite.add(s);
			s = new Sprite(new Point(0,100),new Point(135,480),getImage(getCodeBase(), "Cursor.jpg"), 1, false, false);
				AnimationList = new ArrayList();
				a = new Animation("PRINT",0,0,true,17);
				AnimationList.add(a);
				s.SetAnimations(AnimationList);
				s.PlayAnimation("PRINT");
			Util.m_alSprite.add(s);
			
			m_iGameStatus = SPLASH;
	//	}
	}
	public void Splash(Graphics g)
	{
		Sprite pointer = ((Sprite)(Util.m_alSprite.get(1)));
		if (Util.m_cPlayerControls[0].m_bDown)
		{
			if (pointer.m_rcBoundingBox.y < 130)
			pointer.m_rcBoundingBox.y++;
		}
		else if (Util.m_cPlayerControls[0].m_bUp)
		{
			if (pointer.m_rcBoundingBox.y > 90)
			pointer.m_rcBoundingBox.y--;
		}
			
	//	if (pointer.pos.y < 105)
	//	{
			Text temp1; 
			Text temp2; 
			Text temp3;
			temp1 = new Text((Text)Util.m_alPrintText.get(0));
			temp2 = new Text((Text)Util.m_alPrintText.get(1));
			temp3 = new Text((Text)Util.m_alPrintText.get(2));
			Util.m_alPrintText = null;
			Util.m_alPrintText = new ArrayList();
			temp1.m_cColor = Color.yellow;
			temp2.m_cColor = Color.black;
			temp3.m_cColor = Color.black;
			Util.m_alPrintText.add(temp1);
			Util.m_alPrintText.add(temp2);
			Util.m_alPrintText.add(temp3);
		//	if (Util.m_cPlayerControls[0].m_bStart)
		//	{
				Util.m_alPrintText = new ArrayList();
				Util.m_alSprite = new ArrayList();
				m_iGameStatus = NEWGAME;
		//	}
		//}
				/*
		if (pointer.pos.y >= 105 && pointer.pos.y < 120)
		{
			Text temp1, temp2, temp3;
			temp1 = new Text(((Text)(Util.m_alPrintText.get(0))));
			temp2 = new Text(((Text)(Util.m_alPrintText.get(1))));
			temp3 = new Text(((Text)(Util.m_alPrintText.get(2))));
			Util.m_alPrintText = null;
			Util.m_alPrintText = new ArrayList();
			temp1.m_cColor = Color.black;
			temp2.m_cColor = Color.yellow;
			temp3.m_cColor = Color.black;
			Util.m_alPrintText.add(temp1);
			Util.m_alPrintText.add(temp2);
			Util.m_alPrintText.add(temp3);
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_alPrintText = new ArrayList();
				Util.m_alSprite = new ArrayList();
				m_iGameStatus = LOADGAME;
			}
		}
		else if (pointer.pos.y >= 120)
		{
			Text temp1, temp2, temp3;
			temp1 = new Text(((Text)(Util.m_alPrintText.get(0))));
			temp2 = new Text(((Text)(Util.m_alPrintText.get(1))));
			temp3 = new Text(((Text)(Util.m_alPrintText.get(2))));
			Util.m_alPrintText = null;
			Util.m_alPrintText = new ArrayList();
			temp1.m_cColor = Color.black;
			temp2.m_cColor = Color.black;
			temp3.m_cColor = Color.yellow;
			Util.m_alPrintText.add(temp1);
			Util.m_alPrintText.add(temp2);
			Util.m_alPrintText.add(temp3);	
			if (Util.m_cPlayerControls[0].m_bStart)
			{
				Util.m_alPrintText = new ArrayList();
				Util.m_alSprite = new ArrayList();
				m_iGameStatus = OPTIONS;
			}
		}
		*/
	}
	public void Newgame(Graphics g)
	{
		ArrayList AnimationList = new ArrayList();
		Animation a=new Animation();
		//if (Util.m_cPlayerControls[0].m_bStart)
		//{
			
			Util.m_alPrintText = new ArrayList();
			Util.m_alSprite = new ArrayList();
			
			int [] map = 
			{
					 6,13,12,13,12,12,12,13,12,12,13,12,13,13,12,13,13,13,13,13,13,14,12,13,12,12,13,12,13,12,12,13,13,12,12,13,21,21,21,21,
					 6,13,12,13,12,12,12,13,12,12,13,12,13,13,12,13,13,13,13,12,13,14,12,13,12,12,13,12,13,12,12,13,13,12,13,12,19,18,19,23,
					 6,13,12,13,12,12,12,13,12,12,13,12,13,13,12,13,13,13,13,12,13,14,12,13,12,12,13,12,13,12,12,13,13,12,13,12,19,18,19,23,
					 6,13,12,13,12,12,12,13,12,12,13,12,13,13,12,13,13,13,13,13,12,14,15,15,15,15,15,15,15,15,15,15,15,15,22,22,22,18,19,23,
					 6,13,12,13,12,12,12,13,12,12,13,12,13,13,12,13,13,13,13,13,13,14,14,14,14,14,14,14,14,14,14,14,14,14,20,20,20,18,19,23,
					 6,13,12,13,12,12,12,13,12,12, 0, 1, 0,13,12,13,13,13,13,12,13,13,12,13,12,12,13,12,13,12,12,13,13,12,23,23,19,18,19,23,
					 6,13,12,13,12,12,12,13,12,12, 3, 2, 3,13,12,13,13,13,13,12,13,13,12,13,12,12,13,12,13,12,12,13,13,12,23,23,19,18,22,23,
					 6, 0, 1, 0, 0, 1, 0, 1, 1, 0, 5, 5, 4, 0, 1, 1,13,13,13,12,13,13,12,13,12,12,13,12,13,12,12,13,13,12,23,23,19,18,20,23,
					 6, 2, 3, 2, 2, 3, 3, 2, 2, 3, 7, 7, 6, 3, 2, 2, 0, 0,13,13, 1, 1, 0,13,12,12,13,12,13,12,12,13,13,12,23,23,19,18,19,23,
					 6, 4, 4, 5, 4, 5, 5, 5, 4, 4, 7, 7, 6, 4, 4, 5, 2, 2,12,12, 3, 2, 2,13,12,12,13,12,13,12,12,13,13,12,23,23,19,18,19,23,
					 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 6, 7, 7, 7, 7, 7, 5, 4,10,11, 4, 5, 5,10,10,10,11,11,10,11,11,10,11,10,21,21,19,22,19,23,
					 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 8, 9, 7, 6, 7, 8, 9, 8, 9, 9, 8, 9, 9, 9, 8, 8,19,19,19,20,19,23,
					 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7,18,19, 7, 6, 7, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0,22,22,19,18,19,23,
					 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7,19,18, 7, 6, 7, 3, 2, 2, 3, 2, 3, 2, 3, 2, 2, 2,22,22,19,18,19,23,
					 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7,18,19, 7, 6, 7, 5, 4, 5, 5, 5, 5, 5, 4, 5, 5, 4,20,20,22,18,19,23,
					 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7,19,18, 6, 7, 7, 7, 6, 7, 7, 7, 6, 7, 7, 7, 6, 7,23,23,20,18,19,23,
					 6, 6, 7, 7, 7, 6, 7, 6, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7,19,18, 6, 7, 7, 7, 6, 7, 7, 7, 6, 7, 7, 7, 6, 7,23,23,19,18,19,23,
					21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,19,18,21,21,21,21,21,21,21,21,21,21,21,21,21,21,23,21,19,18,22,23,
					23,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,18,19,19,18,19,19,18,19,19,18,19,19,18,19,19,23,19,19,18,20,23,
					23,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,19,19,18,19,19,18,19,19,18,19,19,18,19,19,18,19,23,18,19,19,18,23,
					23,19,19,19,18,18,18,18,18,18,18,18,18,18,18,18,18,18,19,19,18,19,19,18,19,19,18,19,19,18,19,19,18,19,23,18,19,19,18,23,
					23,18,18,19,22,22,22,22,22,22,18,18,22,22,22,22,22,22,22,22,19,19,18,22,22,22,19,19,18,19,19,18,19,19,23,22,22,18,19,23,
					23,19,19,18,20,20,20,20,20,20,18,18,20,20,20,20,20,20,20,20,19,19,18,20,20,20,19,19,18,19,19,18,22,22,23,20,20,18,19,23,
					23,18,18,19,23,23,23,23,23,23,18,18,23,23,23,23,23,23,23,23,22,22,22,23,23,23,19,19,18,19,19,18,20,20,23,19,19,18,19,23,
					23,19,19,18,23,23,23,23,23,23,18,18,23,23,23,23,23,23,23,23,20,20,20,23,23,23,22,22,22,22,22,22,23,23,23,19,19,18,19,23,
					23,22,22,22,23,23,23,23,23,23,18,18,23,23,23,23,23,23,23,23,23,23,23,23,23,23,20,20,20,20,20,20,23,23,23,19,19,18,19,23,
					23,20,20,20,23,23,23,23,23,23,18,18,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,19,19,22,22,23,
					23,23,23,23,23,23,23,23,23,23,18,18,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,19,19,20,20,23,
					23,21,21,21,21,21,21,21,21,21,18,18,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,19,19,18,19,23,
					23,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,22,18,18,18,23,
					23,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,20,18,18,18,23,
					23,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,22,23,
					23,18,18,18,18,18,18,22,22,22,22,22,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,20,23,
					23,18,18,18,18,18,18,20,20,20,20,20,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,23,
					23,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,22,22,22,22,22,22,18,18,18,18,18,18,22,22,22,22,18,18,23,
					23,22,22,22,22,22,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,20,20,20,20,20,20,18,18,18,18,18,18,20,20,20,20,18,18,23,
					23,20,20,20,20,20,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,23,23,23,23,23,23,22,22,22,22,22,22,23,23,23,18,18,18,23,
					23,23,23,23,23,23,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,23,23,23,23,23,23,20,20,20,20,20,20,23,23,23,18,18,18,23,
					23,23,23,23,23,23,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,22,22,22,23,
					23,23,23,23,23,23,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,20,20,20,23
			};
			Sprite WAD = new Sprite(new Point(0,0), new Point(32,32), getImage(getCodeBase(), "WAD1.gif") ,1, false, false);
			Level level = new Level(map, 40, 40, WAD, 32, 32);
			int [] solids = new int[8];
			solids[0] = 20;
			solids[1] = 4;
			solids[2] = 5;
			solids[3] = 6;
			solids[4] = 7;
			solids[5] = 23;
			solids[6] = 21;
			solids[7] = 14;
			level.SetSolids(solids);
			Util.WorldMap();
			Util.SetLevel(level);
			Util.m_lCurrentLevel = level;
			
			Sprite s = new Sprite(new Point(100,100), new Point(32,64), getImage(getCodeBase(), "CHAR2.gif") ,1, true, true);
						
				AnimationList = new ArrayList();
				a = new Animation("IDLE",1,2,false,2);
				AnimationList.add(a);
				a = new Animation("WALK",3,6,false,3);
				AnimationList.add(a);
				s.SetAnimations(AnimationList);
				s.PlayAnimation("IDLE");
			s.SetPosition(200,0);
			Util.m_alSprite.add(s);
			
			Monster m = new Monster(new Point(100,100), new Point(32,64), getImage(getCodeBase(), "CHAR2.gif") ,1, true, true);
						
				AnimationList = new ArrayList();
				a = new Animation("IDLE",1,2,false,2);
				AnimationList.add(a);
				a = new Animation("WALK",3,6,false,3);
				AnimationList.add(a);
				m.SetAnimations(AnimationList);
				m.PlayAnimation("IDLE");
			m.SetPosition(100, 0);
			Util.m_alSprite.add(m);
			
			Text t = new Text("Directions",0,0);
			Text t2 = new Text("Click on this text box to gain focus of the screen. Use the left and right arrow keys to move, and the up arrow key to jump. Press enter when ready to play.",0,0);
			TextBox t3 = new TextBox(new Text(t),new Text(t2),new Sprite(s),new Point(10,10));
			Util.m_alPrintText.add(t3);
			m_iGameStatus = RUNNING;
		//}
	}
	public void Loadgame(Graphics g)
	{
		System.out.println("LOAD");
		Util.m_alPrintText = new ArrayList();
		Util.m_alSprite = new ArrayList();
		m_iGameStatus = RUNNING;
	}
	public void Options(Graphics g)
	{
		System.out.println("OPTIONS");
	}
	public void Run(Graphics g)
	{
		if (Util.m_cPlayerControls[0].m_bStart)
			m_iGameStatus = RUNNING;
		Controls.HandleControls();
	}
	public void Demo(Graphics g)
	{		
	}
	public void End(Graphics g)
	{
	}
	
	public void update (Graphics g)
	{
		//check collision
		Util.m_rcCamera.HandleCamera();
		Collision.HandleCollision();
		
			if (m_iGameStatus == STARTING)
				Starting(g);
			else if (m_iGameStatus == SPLASH)
				Splash(g);
			else if (m_iGameStatus == NEWGAME)
				Newgame(g);
			else if (m_iGameStatus == LOADGAME)
				Loadgame(g);
			else if (m_iGameStatus == OPTIONS)
				Options(g);
			else if (m_iGameStatus == RUNNING)
				Run(g);
			else if (m_iGameStatus == DEMO)
				Demo(g);
			else if (m_iGameStatus == END)
				End(g);
				
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
				//	System.out.println(S.pos.x + " " + S.pos.y + "|" + S2.pos.x + " " + S2.pos.y);
				//}
					//	S.pos.x += 64 * x;
				if (S.CollidesWith(Util.m_rcScreen))
				{
					S.PaintAnimation(g);
					S.Paint(g);
					S.DrawBoundingBox(g);
				}
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
	}
	
	public void mouseClicked(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e)  {} 
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e){}
}