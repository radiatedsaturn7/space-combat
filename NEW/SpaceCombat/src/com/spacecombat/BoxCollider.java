package com.spacecombat;

public class BoxCollider extends Collider {

	public Vector2 size = new Vector2();

	public BoxCollider(final Vector2 size) {
		this.size = size;
	}

	@Override
	public boolean collidesWith(final BoxCollider boxCollider) {

		if (this.rigidBody.gameObject == null) {
			throw new RuntimeException(
					"gameObject is null -- can't perform collision");
		}

		if (boxCollider.getRigidBody().gameObject == null) {
			throw new RuntimeException(
					"boxCollider.gameObject is null -- can't perform collision");
		}

		if (this.rigidBody.gameObject.transform.position.x + this.size.x >= boxCollider
				.getRigidBody().gameObject.transform.position.x
				&& this.rigidBody.gameObject.transform.position.y + this.size.y >= boxCollider
				.getRigidBody().gameObject.transform.position.y
				&& this.rigidBody.gameObject.transform.position.x <= boxCollider
				.getRigidBody().gameObject.transform.position.x
				+ boxCollider.size.x
				&& this.rigidBody.gameObject.transform.position.y <= boxCollider
				.getRigidBody().gameObject.transform.position.y
				+ boxCollider.size.y) {
			return true;
		}

		return false;
	}
}
