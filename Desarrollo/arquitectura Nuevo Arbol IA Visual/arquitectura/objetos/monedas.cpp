
#include "monedas.hpp"

monedas::monedas(){
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
    
    physics* fisica = (physics*)findComponent("physics");
    
    dvector3D dim(1,1,1);
    dvector3D pos(0,0,0);
    
    fisica->crearBodyEstatico(dim, pos, 90.f);
	
    muero = false;
	aux = NULL;
	setType(tMONEDAS);
}

monedas::~monedas(){
    
}

void monedas::update(){
   GameObject::update();
}

void monedas::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){ //compruebo que choco con el player
        muero = true;
    }
}

bool const* monedas::getmuero(){
    return &muero;
}

void monedas::contactoEnd(GameObject *g){
    
}
