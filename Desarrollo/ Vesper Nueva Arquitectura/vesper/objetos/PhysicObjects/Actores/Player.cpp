//
//  Player.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Player.hpp"
#include "../PlayerObjects.hpp"
#include <iostream>

#define VELOCIDADN 2.f




Player::Player(){
    
    arma = new armas;
    componentes.insert(std::pair<ComponentType, component*>(ARMAS,arma));
    arma->setFather(this);
    component * componente = new habilidadEspecial();
	((habilidadEspecial*)componente)->setTipo(tHabINVISIBLE);
    componentes.insert(std::pair<ComponentType, component*>(HABESPECIAL,componente));
    componente->setFather(this);
    addNodo("3d/sphere.3ds");
    setTexture("3d/texture.png");
}

Player::~Player(){
    if(llaves)
        delete[] llaves;
}

void Player::update(){
	dvector3D vel;
    /*
    Keys aux;
    for(aux=SKY_MOUSE_BUTTON_1;aux<SKY_KEY_RIGHT_CONTROL;aux++){
        
    }
     */
	if(MyEventReceiver::Instance()->IsKeyDown(SKY_KEY_UP))
		vel.y += VELOCIDADN;
	if(MyEventReceiver::Instance()->IsKeyDown(SKY_KEY_DOWN))
		vel.y += -VELOCIDADN;
	if(MyEventReceiver::Instance()->IsKeyDown(SKY_KEY_LEFT))
		vel.x += -VELOCIDADN;
	if(MyEventReceiver::Instance()->IsKeyDown(SKY_KEY_RIGHT))
		vel.x += VELOCIDADN;
    if(MyEventReceiver::Instance()->IsKeyDown(SKY_KEY_N))
        atacar();
    if(MyEventReceiver::Instance()->IsKeyDown(SKY_KEY_TAB))
       cambiarArma();
    if(MyEventReceiver::Instance()->IsKeyDown(SKY_KEY_E))
        changeActiveKey();
	mover(vel);
    
    
    m_rot = ventana::Instance()->posicionRaton(m_pos);
    rotarConRaton(m_rot);
    GameObject::update();
    arma->update();

}

void Player::render(){
    PhysicObject::render();
    arma->render();
}

void Player::atacar(){
    
    if(*(arma->getArmaActual()->getType()) == tPALAc)
        cuerpoacuerpo();
    else
        arma->shoot();
}

void Player::cambiarArma(){
    arma->changeGun();
    std::cout << *arma->getArmaActual()->getType() << std::endl;
}

void Player::inicializar(int ID, int numL){
    numLlaves = numL;
    llaves = new int[numLlaves];
    m_ID = ID; activa = 0;
    for(size_t a=0;a<numLlaves;a++)
        llaves[a]=-1;
    
}

void Player::changeActiveKey(){
    activa++;
    if(activa==numLlaves) activa = 0;
    std::cout << "LLAVE :" << activa << "| VALOR:"<< llaves[activa] << std::endl;
}

void Player::setVelocidad(unsigned int vel){
    velocidad = vel;
}

void Player::activarHab(){
    if(habActiva()){
        habilidadEspecial * hab = static_cast<habilidadEspecial*>(componentes.find(HABESPECIAL)->second);
        hab->activar();
    }
    
}

bool Player::habActiva(){
    habilidadEspecial * hab = static_cast<habilidadEspecial*>(componentes.find(HABESPECIAL)->second);
    return hab->puedoUsar();
}



void Player::contacto(PhysicObject * g){
    if(g != NULL){
        if(g->getObjectType() == PALA){
            arma->insertarArma(9);
        }
        if(g->getObjectType() == MONEDAS){
            habilidadEspecial * h = static_cast<habilidadEspecial*>(componentes.find(HABESPECIAL)->second);
            h->aumentarMoneda();
        }
        if(g->getObjectType() == ALARMA){
            
        }
        if(g->getObjectType() == ESCOPETA){
            arma->insertarArma(2);
        }
        if(g->getObjectType() == SWEET_SHOOTER){
            arma->insertarArma(3);
        }
        if(g->getObjectType() == GLOBO_AGUA){
            arma->insertarArma(5);
        }
        if(g->getObjectType() == BUMMER_BOOM){
            arma->insertarArma(6);
        }
        if(g->getObjectType() == BOMBA_HUMO){
            arma->insertarArma(7);
        }
        if(g->getObjectType() == LLAVE){
            for (size_t a=0; a<numLlaves; a++) {
                if(llaves[a]==-1) {
                    llaves[a]=static_cast<PlayerObjects*>(g)->Llave();
                    break;
                }
            }
            
        }
    }
    obj_colisionado = g;
}

void Player::addArma(){
    
    
    class render* go = static_cast<class render*>(componentes.find(RENDER)->second);
    if(go != NULL)
        go->anyadirArma();
}



void Player::accionar(){
    /*
    if(obj_colisionado != NULL){
        if(*obj_colisionado->getObjectType() == ALARMA){
            if(!(static_cast<alarma*>(obj_colisionado)->estaActivado())){
                static_cast<alarma*>(obj_colisionado)->activar();
            }
        }else if(*obj_colisionado->getObjectType() == PUERTA){
            if(!(static_cast<puerta*>(obj_colisionado))->estasAbierta()){
                static_cast<puerta*>(obj_colisionado)->abre();
            }else
                static_cast<puerta*>(obj_colisionado)->cierra();
        }
    }
     */
}

void Player::cuerpoacuerpo(){
    //TO DO: revisar
    /*
    if(obj_colisionado != NULL){
        if(*obj_colisionado->getObjectType() == tALARMA){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<alarma*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }else if(*obj_colisionado->getObjectType() == tFUENTE){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<fuente*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }
    }
    */
}
