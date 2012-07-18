package com.spacecombat.game;

import com.spacecombat.Camera;
import com.spacecombat.Component;

public class DestroyOnOutOfBounds extends Component {
	@Override
	public void update() {
		if (this.gameObject.transform.position.y  > Camera.mainCamera.gameObject.transform.position.y + 800 + 128) {
			this.gameObject.destroy();
		}

		if (this.gameObject.transform.position.y  < Camera.mainCamera.gameObject.transform.position.y + 0 - 128) {
			this.gameObject.destroy();
		}

		if (this.gameObject.transform.position.x  > Camera.mainCamera.gameObject.transform.position.x + 0 + 528) {
			this.gameObject.destroy();
		}

		if (this.gameObject.transform.position.x < Camera.mainCamera.gameObject.transform.position.x + 0 - 128) {
			this.gameObject.destroy();
		}
	}
}
