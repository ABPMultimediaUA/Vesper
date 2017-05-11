//
//  Nodo_ARuido.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_ARuido_hpp
#define Nodo_ARuido_hpp

#include "../Nodo_base.hpp"

class Nodo_ARudio : public Nodo_base{
    tiempo t;
    bool init;
public:
    short run(const int&);
    void reset(){t.reset();init=false;}
    Nodo_ARudio(){init=false;}
    ~Nodo_ARudio(){}
};

#endif /* Nodo_ARuido_hpp */
