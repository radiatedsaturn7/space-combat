import java.awt.*;

public class TextBox 
{
	public Text m_tText;
	public Text m_tName;
	public Sprite m_sSprite;
	public Point m_pPos;
	
	public TextBox (Text t, Sprite s, Point p)
	{
		m_tText = new Text(t);
		m_sSprite = new Sprite(s);
		m_pPos = new Point(p);
		m_tName = null;
	}
	public TextBox ( Text n, Text t, Sprite s, Point p)
	{
		m_tName = new Text(n);
		m_tText = new Text(t);
		m_sSprite = new Sprite(s);
		m_pPos = new Point(p);
	}
	
	public void Paint (Graphics g)
	{
		g.setColor(Color.black);
		g.fillRoundRect(m_pPos.x, m_pPos.y, 300,100,5,5);
		g.setColor(Color.white);
		g.fillRoundRect(m_pPos.x+1, m_pPos.y+1, 298,98,5,5);
		g.setColor(Color.blue);
		g.fillRoundRect(m_pPos.x+5, m_pPos.y+5, 290,90,5,5);
		g.setColor(Color.white);
		
		//m_sSprite.SetPosition(m_pPos.x+5,m_pPos.y+5);
		//m_sSprite.Paint(g);
		/*
		//if (m_tName == null)
		//	System.out.println("NAME");
		//if (m_tText == null)
		//	System.out.println("TEXT");
		//if (m_sSprite == null)
		//	System.out.println("SPRITE");
		*/
		if (m_tName != null)
		{
			m_tName.SetPosition(m_pPos.x+10,m_pPos.y+20);
		//we need to figure out text width

			Text [] text = new Text[8];
			text[0] = new Text(m_tName);
			text[0].m_sText += " : ";
			int lastindex = 0;
			for (int i = 1; i < 8; i++)
			{
				text[i] = new Text(m_tText);
				if (lastindex == -1)
					text[i].m_sText = "";
				else if (m_tText.m_sText.length() > lastindex+40)
				{
					text[i].m_sText = new String(m_tText.m_sText.substring(lastindex,lastindex+40));
					text[i].m_sText = text[i].m_sText.substring(0,text[i].m_sText.lastIndexOf(' ')+1);
					lastindex += text[i].m_sText.length();
				}
				else if (m_tText.m_sText.length() < lastindex+40)
				{
					text[i].m_sText = new String(m_tText.m_sText.substring(lastindex));
					lastindex = -1;
				}
				text[i].SetPosition(m_pPos.x+10,m_pPos.y+20+(12*i));
			}/*
				Text txt1 = new Text(m_tText);
				Text txt2 = new Text(m_tText);
				Text txt2 = new Text(m_tText);
				Text txt2 = new Text(m_tText);
				txt1.m_sText = new String(m_tText.m_sText.substring(27));
				txt2 .m_sText = new String(m_tText.m_sText.substring(0,27));
				txt2 .SetPosition(m_pPos.x+10,m_pPos.y+32);//m_pPos.x+m_sSprite.pos.x+10,m_pPos.y+5+m_tName.m_fFont.getSize()+5);
				txt1.SetPosition(m_pPos.x+10,m_pPos.y+44);//m_pPos.x+m_sSprite.pos.x+10,m_pPos.y+5+m_tName.m_fFont.getSize()+5);
*/
			for (int i = 0; i < 8; i++)
			{
				text[i].Paint(g);
			}
		}
		else
		{
			m_tText.SetPosition(m_pPos.x+m_sSprite.m_rcBoundingBox.x+10,m_pPos.y+5);
			m_tText.Paint(g);
		}
	}
}
