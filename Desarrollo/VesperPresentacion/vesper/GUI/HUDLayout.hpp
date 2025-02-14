//
//  HUDLayout.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef HUDLayout_hpp
#define HUDLayout_hpp

#include <stdio.h>
#include "GUI.h"
#include "../components/typeArma.hpp"

class states;

class HUDLayout : public GUI {
public:
    HUDLayout();
    ~HUDLayout();
    //    void update() override;
    void init();
    void getVida(int v);
    void getMonedas(int v);
    void getllaves(int v);
    void getMunicion(unsigned int municion);
    void getCarga(unsigned int carga);
    void ocultarArmas();
    void mostrarArma(typeArma tipo);
    void update();
    
private:
   	CEGUI::DefaultWindow *moneda1;
    CEGUI::DefaultWindow *moneda2;
    CEGUI::DefaultWindow *moneda3;
    CEGUI::DefaultWindow *llave1;
    CEGUI::ProgressBar *vida;
    CEGUI::DefaultWindow* actual;
    CEGUI::DefaultWindow* label;
    std::string carga_muni, aux;
    
    std::map<typeArma,CEGUI::DefaultWindow*> armas;
    states* estado;
};

#endif /* HUDLayout_hpp */
