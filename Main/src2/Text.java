import java.awt.*;
//import java.applet.*;

public class Text
{
	public String m_sText;
	public Point m_pPos;
	public Color m_cColor;
	public Font m_fFont;
	
	public Text()
	{
		m_sText = "ERROR : NO TEXT";
		m_pPos = new Point(0,0);
		m_cColor = Color.black;
		m_fFont = null;
	}
	public Text(Text t)
	{
		m_sText = new String(t.m_sText);
		m_pPos = new Point(t.m_pPos);
		m_cColor = t.m_cColor;
		m_fFont = t.m_fFont;
	}
	public Text (String s, int x, int y)
	{
		m_sText = new String(s);
		m_pPos = new Point (x,y);
	}
	public Text (String s, Point p)
	{
		m_sText = new String(s);
		m_pPos = new Point (p);
	}
	public void SetPosition(int x, int y)
	{
		m_pPos = new Point(x,y);
	}
	public void SetPosition(Point p)
	{
		m_pPos = new Point(p);
	}
	public void Paint(Graphics g)
	{
		if (m_fFont != null)
			g.setFont(m_fFont);
		if (m_cColor != null)
			g.setColor(m_cColor);
		g.drawString(m_sText, (int)m_pPos.x, (int)m_pPos.y);
	}
}