public class Direction 
{
	public int dir;
	
	public Direction()
	{
		dir = -1;	
	}
	public Direction(Direction d)
	{
		dir = d.dir;	
	}
	public void Up()
	{
		dir = 1;
	}
	public void Down()
	{
		dir = 2;
	}
	public void Left()
	{
		dir = 3;
	}
	public void Right()
	{
		dir = 4;
	}
	
	public void Reverse()
	{
		if (IsUp())
			Down();
		else if (IsDown())
			Up();
		if (IsLeft())
			Right();
		else if (IsRight())
			Left();
	}
	
	public boolean IsUp()
	{
		return dir == 1;
	}
	public boolean IsDown()
	{
		return dir == 2;
	}
	public boolean IsLeft()
	{
		return dir == 3;
	}
	public boolean IsRight()
	{
		return dir == 4;
	}
}
