//
//  OpcionesLayout.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 8/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef OpcionesLayout_hpp
#define OpcionesLayout_hpp

#include <stdio.h>
#include "GUI.h"

class OpcionesLayout : public GUI {
public:
    OpcionesLayout();
	~OpcionesLayout(){}
//    void update() override;
    void init(CEGUI::RenderTarget* target);
    void onClickControles(const CEGUI::EventArgs &e);
    void onClickSonido(const CEGUI::EventArgs &e);
    void onClickVolver(const CEGUI::EventArgs &e);
    void onClickGuardar(const CEGUI::EventArgs &e);
    void setControles();
    
private:
    CEGUI::DefaultWindow *label_ajustes;
    CEGUI::PushButton *button_controles;
    CEGUI::PushButton *button_sonido;
    CEGUI::PushButton *button_volver;
    CEGUI::PushButton *button_guardar;
    CEGUI::ToggleButton *check_sonido;
    CEGUI::Slider *slider_volumen;
    
    CEGUI::DefaultWindow *contenedor_sonido;
    CEGUI::DefaultWindow *contenedor_controles;

    int volumen;
	const char* controlesFile = "controles.json";
};

#endif /* OpcionesLayout_hpp */
