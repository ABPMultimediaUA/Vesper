//
//  InputManager.h
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 21/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef InputManager_h
#define InputManager_h

#include <GLFW/glfw3.h>
#include "SkyKeysDef.h"
#include "Dvector.hpp"

class InputManager {
public:
	static InputManager* Instance() { static InputManager inst; return &inst; }
	bool isPressed(int key) { return keys[key]; }
	bool keys[SKY_KEY_LAST];
	dvector2D mousePos;
private:
	InputManager(){}
};

#endif /* InputManager_h */
