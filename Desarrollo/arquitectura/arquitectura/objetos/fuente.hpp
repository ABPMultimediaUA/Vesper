//
//  fuente.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef fuente_hpp
#define fuente_hpp

#include "GameObject.hpp"
#include "Dvector.hpp"

class fuente : public GameObject{
public:
    fuente(int &ID);
    ~fuente();
    void update();
private:
    int ID;
    bool rota, NPCKnows;
    dvector3D * posi;
};

#endif /* fuente_hpp */
