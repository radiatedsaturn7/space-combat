package com.spacecombat.ai;


import com.spacecombat.GameObject;
import com.spacecombat.RigidBody;
import com.spacecombat.Vector2;

public class AINodeFollower extends AIScript {

	private RigidBody rigidBody;
	private final Vector2 maxSpeed = new Vector2(32, 32);
	// private int count = 0;
	// private int maxCount = 120;


	private GameObject targetNode;
	private final GameObject [] nodes;
	private int currentNode = 0;

	private boolean needToMove = true;
	private boolean needToCalculate = true;

	public Vector2 temp = new Vector2();

	public AINodeFollower(final GameObject [] nodes) {
		this.nodes = nodes;
		if (nodes.length > 0)
		{
			this.targetNode = nodes[0];
		}
	}

	@Override
	public void collide(final GameObject whatIHit)
	{
		if (this.targetNode == null)
		{
			return;
		}

		if (whatIHit.equals(this.targetNode))
		{
			final Node node = (Node)this.nodes[this.currentNode].getComponent(Node.class);
			this.needToMove = false;

			if (node.isDone())
			{
				this.currentNode++;
				if (this.currentNode > this.nodes.length-1)
				{
					this.targetNode = null;
				}
				else
				{
					this.needToMove = true;
					this.needToCalculate = true;
					this.targetNode = this.nodes[this.currentNode];
				}
			}
		}
		else
		{

		}
	}

	@Override
	public void onCreate() {
		this.rigidBody = this.gameObject.getRigidBody();
	}
	public void setFollowDirection() {
		this.temp.x = this.targetNode.transform.position.x - this.gameObject.transform.position.x;
		this.temp.y = this.targetNode.transform.position.y - this.gameObject.transform.position.y;

		this.temp.normalize();

		this.rigidBody.speed.x = this.temp.x * this.maxSpeed.x; 
		this.rigidBody.speed.y = this.temp.y * this.maxSpeed.y; 
	}

	@Override
	public void update() {
		if (this.rigidBody == null) {
			this.rigidBody = this.gameObject.getRigidBody();
		}

		if (this.needToMove)
		{
			if (this.needToCalculate)
			{
				setFollowDirection();
				this.needToCalculate = false;
			}
		}
		else
		{
			this.rigidBody.speed.x = 0;
			this.rigidBody.speed.y = 0;
		}
	}
}
