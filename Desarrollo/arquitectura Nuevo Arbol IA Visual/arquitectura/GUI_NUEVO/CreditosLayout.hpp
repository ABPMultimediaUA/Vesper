//
//  CreditosLayout.hpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef CreditosLayout_hpp
#define CreditosLayout_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

class CreditosLayout : public Motor::GUI {
public:
    CreditosLayout();
    ~CreditosLayout();
    //    void update() override;
    tLayout getLayout() override;
    void onClickVolver(const CEGUI::EventArgs &e);
    
private:
    CEGUI::DefaultWindow *label_creditos;
    CEGUI::PushButton *button_partida1;
    CEGUI::PushButton *button_partida2;
    CEGUI::PushButton *button_partida3;
    CEGUI::PushButton *button_volver;
};

#endif /* CreditosLayout_hpp */
