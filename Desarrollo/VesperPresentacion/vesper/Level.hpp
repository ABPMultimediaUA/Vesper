//
//  Level.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 18/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

#include <string>
#include "loadLevel.hpp"
#include "estados/estados.h"
#include "estados/state.hpp"


class Level  : public state{
    bool exportar_objetos(loadLevel& nivel);
    Player * p;
    Camera * c;
    vector<GameObject*> w;
    size_t it,end;
    bool iniciado;
    void clear();
    InputManager* input;
public:
    Level();
    ~Level();
    bool lvlActivo() const {return iniciado;}
    bool inicializar();
    void render(float &interpolation);
    void update(const long &timePerFrame);
    void destroy();
};


#endif /* Level_hpp */
