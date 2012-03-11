package com.spacecombat;

public abstract class Collider {
	protected RigidBody rigidBody;
	private String[] tags;

	public abstract boolean collidesWith(BoxCollider boxCollider);

	public boolean collidesWith(final Collider c) {

		if (c.hasTag(this.tags)) {
			return false;
		}


		if (c instanceof BoxCollider) {
			return collidesWith((BoxCollider) c);
		}
		return false;
	}

	public String getPrintableTags() {
		String s = "";
		if (this.tags != null) {
			int x = 0;
			for (x = 0; x < this.tags.length; x++) {
				s += this.tags[x] + ",";
			}
		}
		return s;
	}

	public RigidBody getRigidBody() {
		return this.rigidBody;
	}

	public String[] getTags() {
		return this.tags;
	}

	public boolean hasTag(final String tag) {
		if (this.tags == null) {
			return false;
		}

		if (tag == null) {
			return false;
		}

		int x = 0;
		for (x = 0; x < this.tags.length; x++) {
			if (this.tags[x].equalsIgnoreCase(tag)) {
				return true;
			}
		}

		return false;
	}

	public boolean hasTag(final String[] otherTags) {
		if (this.tags == null) {
			return false;
		}
		if (otherTags == null) {
			return false;
		}

		int x = 0;
		for (x = 0; x < this.tags.length; x++) {
			int y = 0;
			for (y = 0; y < otherTags.length; y++) {
				if (this.tags[x].equalsIgnoreCase(otherTags[y])
						&& otherTags[y] != null) {
					return true;
				}
			}
		}

		return false;
	}

	public void setRigidBody(final RigidBody rigidBody) {
		this.rigidBody = rigidBody;
	}

	public void setTags(final String[] tags) {
		this.tags = tags;
	}
}
