package com.spacecombat.game;

import com.spacecombat.Component;

public class DestroyOnOutOfBounds extends Component {
	@Override
	public void update() {
		if (this.gameObject.transform.position.y > 800 + 128) {
			this.gameObject.destroy();
		}

		if (this.gameObject.transform.position.y < 0 - 128) {
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
