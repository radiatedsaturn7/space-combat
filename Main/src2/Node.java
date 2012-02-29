import java.awt.*;

public class Node 
{
	Node [] m_nNode = new Node[4];
	Rectangle m_rcNode;
	
	public Node (int x, int y, int width, int height)
	{
		m_rcNode = new Rectangle();
		m_rcNode.x = x;
		m_rcNode.y = y;
		m_rcNode.width = width;
		m_rcNode.height = height;
	}
}
