package com.spacecombat;

public abstract class Collider {
	protected RigidBody rigidBody;
	private int tags;

	public abstract boolean collidesWith(BoxCollider boxCollider);

	public boolean collidesWith(final Collider c) {

		if (c.hasIgnoreTag(this.tags)) {
			return false;
		}


		if (c instanceof BoxCollider) {
			return collidesWith((BoxCollider) c);
		}
		return false;
	}

	public int getIgnoreTags() {
		return this.tags;
	}

	public RigidBody getRigidBody() {
		return this.rigidBody;
	}

	public boolean hasIgnoreTag(final int tag) {
		return Tags.compareTagsOr(this.tags, tag);
	}

	public void setIgnoreTags(final int tags) {
		this.tags = tags;
	}

	public void setRigidBody(final RigidBody rigidBody) {
		this.rigidBody = rigidBody;
	}
}
