package com.spacecombat;

public class DestroyOnOutOfBounds extends Component {
	@Override
	public void update() {
		if (this.gameObject.transform.position.y > 128) {
			this.gameObject.destroy();
		}

		if (this.gameObject.transform.position.y < 128) {
			this.gameObject.destroy();
		}

		if (this.gameObject.transform.position.x > 528) {
			this.gameObject.destroy();
		}

		if (this.gameObject.transform.position.x < -128) {
			this.gameObject.destroy();
		}
	}
}
