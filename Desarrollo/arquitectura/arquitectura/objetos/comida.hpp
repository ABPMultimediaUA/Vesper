
//
//  comida.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef comida_hpp
#define comida_hpp
#include "GameObject.hpp"
#include "Dvector.hpp"
#include <time.h>

class comida : public GameObject {
public:
    comida();
    ~comida();
    void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const getmuero();
private:
    void gestorTiempo();
    bool consumido, muero;
    time_t _time;
};

#endif /* comida_hpp */
