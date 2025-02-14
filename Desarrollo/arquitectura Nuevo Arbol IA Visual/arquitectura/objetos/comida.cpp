//
//  comida.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 11/1/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "comida.hpp"

#define TIEMPO_COMESTIBLE 10

comida::comida(int & ID){
    this->ID = ID;
    this->consumido = false;
    component* aux = new class render();
    this->insertComponent((char*)"render", aux);
    aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
    aux = new physics();
    this->insertComponent((char*)"physics", aux);
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
    
    physics* fisica = (physics*)findComponent("physics");
    
    dvector3D dim(1,1,1);
    dvector3D pos(0,0,0);
    
    fisica->crearBodyEstatico(dim, pos, 90.0f);
    
    muero = false;
    aux = NULL;
	setType(tCOMIDA);
}
comida::~comida(){

}
void comida::gestorTiempo(){
    if(time(NULL)>_time){
        consumido = false;
    }
}
void comida::update(){
	gestorTiempo();
    if (LevelBlackBoard::instance()->exist_record(ID, P_HAMBRE) && !consumido) {
        LevelBlackBoard::instance()->RemoveRecord(ID, P_HAMBRE);
		consumido = true;
		_time = time(NULL) + TIEMPO_COMESTIBLE;
		return;
	}
    if(!consumido)
        LevelBlackBoard::instance()->AnswerRecord(P_HAMBRE, ID, getPosicion());
}

void comida::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
//        muero = true;
    }
}

bool const* comida::getmuero(){
    return &muero;
}

void comida::contactoEnd(GameObject *g){
    
}
