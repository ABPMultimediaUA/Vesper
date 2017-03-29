//
//  Game.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 1/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <stdio.h>
#include "components/render.hpp"
#include "components/input.hpp"
#include "Level.hpp"
#include "Fps.hpp"
#include "mundoBox2D.hpp"
#include "Dvector.hpp"
#include "GUI/LayoutGUI.hpp"
#include "tiempo.h"

class Game {
public:
	static Game* Instance();
	
	void start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver);
	void stop();
	
	virtual ~Game();
	void update();
	void render();
	bool isRunning();
    void setPausa(bool p){
        pausa = p;
    }
protected:
	Game();
	
private:
	class render *renderizador;
	class input* entrada;
	bool running, pausa;
	Level* nivelazo;
	
	void processEvents();
	
	LayoutGUI* layoutPrueba;
};

#endif /* Game_hpp */
