//
//  NPC.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "NPC.hpp"
NPC::NPC(){
    DeciSys = new estados;
    datosPropios.inicializar();
}
NPC::~NPC(){
    
}
void NPC::update(){
    DeciSys->run(datosPropios);
}
datos NPC::getNPCinfo(){return datosPropios;}
