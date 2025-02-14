//
//  Bala.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//
#include "../../Arquitectura IA/gestor_eventos.hpp"
#include "Bala.hpp"

Bala::Bala(dvector3D &pos, dvector3D &dir, float vel, float tVida){
    velocidad = vel;
    
    damage = 0;
    
    createPhysicsBody(DYNAMIC_BODY,dvector3D(0.1,0.1,0));
    
    velocidad = vel;
    
    m_pos = pos + dir*0.6f;
    //pos.y += dir.y*1.5f;
    m_pos.z = 0;
    
    setPosition(m_pos);
    
    direccion.x = dir.x * velocidad;
    direccion.y = dir.y * velocidad;
    //direccion.z = 0;
    
    temp.start();
    tiempo_vida = tVida;
    
    gestor_eventos::instance()->addEvento(m_ID, P_RUIDO, *getPosition());
    
}

void Bala::setDamage(int u){damage = u;}

Bala::~Bala(){
    class render * r = static_cast<class render*>(componentes.find(RENDER)->second);
    if(r)
        r->deleteNode();
}

void Bala::update(){
    
	
	
    if(temp.tTranscurrido(tiempo_vida) && eliminar == false)
        eliminar = true;
    else
        mover(direccion);
	GameObject::update();
}

void Bala::contacto(PhysicObject *g){
    eliminar = true;
}
