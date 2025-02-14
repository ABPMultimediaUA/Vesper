//
//  NpcLibrary.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 10/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NpcLibrary.hpp"
#include "../PathFinding/PathPlanning.hpp"

/*
 NPC_LIBRARY
 */

#define CADUCIDAD 4.0f


NpcLibrary * NpcLibrary::instancia(){
    static NpcLibrary library;
    return &library;
}

NpcLibrary::NpcLibrary(){}
NpcLibrary::~NpcLibrary(){
    it = libros.begin();
    while (it!=libros.end()) {
        if(it->second)
            delete it->second;
        it++;
    }
    libros.clear();
}

NpcBook * NpcLibrary::add_book(const int &ID, dvector3D *posicion){
    it=libros.find(ID);
    if (it!=libros.end()) return nullptr;
    
    NpcBook * book = new NpcBook(ID,posicion);
    libros.insert(std::pair<int, NpcBook*>(ID,book));
    
    return book;
}

bool NpcLibrary::remove_book(const int &ID){
    it=libros.find(ID);
    if (it==libros.end()) return false;
    
    delete it->second;
    libros.erase(it);
    return true;
}

NpcBook * NpcLibrary::recover_book(const int &ID){
    it=libros.find(ID);
    if (it==libros.end()) return nullptr;
    return it->second;
}
/*
 EVENTOS
 */

Eventos::Eventos(int& ID, const Prioridades& tipo, dvector3D * posicion){
    m_ID = ID;
    m_posiciones.push_back(posicion);
    m_time.start();
}
Eventos::Eventos(int& ID,const Prioridades& tipo, std::vector<dvector3D*> posiciones){
    m_ID = ID;
    m_posiciones = posiciones;
}
Eventos::~Eventos(){
    size_t it;
    for (it=0; it<m_posiciones.size(); it++) {
        delete m_posiciones[it];
    }
}

/*
 NPC_BOOK
 */

NpcBook::NpcBook(const int& ID,dvector3D* posicion) : posPlayer(nullptr){
    m_ID = ID;
    salud = 100;
    estado = 0;
    tiempo t;
    srand(t.getActual());
    sed = rand()%60 + 10;
    hambre = rand()%40 + 10;
    PosicionPropia = posicion;
    VectorMovimiento = new dvector3D(0,0,0);
    Enemigo = Aviso = Ruido = Alarma = Evento = Alerta = false;
    Patrullar = ACTalarma = false;
    pila.clear();
}

NpcBook::~NpcBook(){
    it = pila.begin();
    while (it!=pila.end()) {
        delete it->second;
        it++;
    }
}

bool NpcBook::TengoEsteEvento(const Prioridades p, int ID){
    it = pila.find(p);
    if(it!=pila.end() && it->second->m_ID==ID)
        return true;
    return false;
}

void NpcBook::notify(int ID,const Prioridades tipo, dvector3D * posicion){
    
    it = pila.find(tipo);
    if(it!=pila.end()) remove_EventsByType(it->first);
    Evento = true;
    
    dvector3D * pos = new dvector3D(posicion);
    
    if(tipo==P_ENEMIGO)
        posPlayer = posicion;
    
    pila.insert(std::pair<Prioridades, Eventos*>(tipo,new Eventos(ID,tipo,pos)));
    
    if(tipo<P_VIDA)
        valueObjective(tipo);
}

void NpcBook::notify(int ID,const Prioridades tipo, std::vector<dvector3D*> posiciones){
    Evento = true;
    it = pila.find(tipo);
    if(it!=pila.end()) remove_EventsByType(it->first);
    
    pila.insert(std::pair<Prioridades, Eventos*>(tipo,new Eventos(ID,tipo,posiciones)));
}



void NpcBook::valueObjective(const Prioridades &tipo){
    it = pila.find(tipo);
    if(it==pila.end()) return;
    switch (it->first) {
        case P_ENEMIGO:
            Enemigo = true;
            changeObjective();
            Ruido = false;
            remove_EventsByType(P_RUIDO);
            break;
        case P_ALERTA:
            Alerta = true;
            break;
        case P_ALARMA:
            if(Enemigo && getMoral()>40) return;
            Alarma = true;
            changeObjective();
        case P_AVISO:
            Aviso = true;
            if(Ruido) return;
            changeObjective();
            break;
        case P_RUIDO:
            if (Enemigo) return;
            Ruido = true;
            changeObjective();
            break;
        case P_VOID: break;
        case P_PATRULLAR:
            Patrullar = true;
            changeObjective();
            break;
        default:changeObjective();break;
    }
}
void NpcBook::changeObjective(){
    PosicionesDestino.clear();
    PosicionesDestino = PathPlanning::instance()->obtenerCamino(PosicionPropia, it->second->m_posiciones[0]);
}

int NpcBook::getMoral(){
    int calculo = (salud * 50)+(hambre * 30)+(sed * 20);
    return calculo/100;
}



bool NpcBook::ExistEventByType(const Prioridades& tipo){
    it = pila.find(tipo);
    if(it==pila.end()) return false;
    valueObjective(tipo);
    return true;
}

bool NpcBook::updateObjetivo(){
    if(PosicionesDestino.empty()) return false;
    PosicionesDestino.erase(PosicionesDestino.begin());
    return true;
}

dvector3D NpcBook::lastPosition() const{
    if(PosicionesDestino.empty()) return dvector3D(-1,-1,-1);
    return PosicionesDestino[0];
}

void NpcBook::resetVectorMovimiento(){
    VectorMovimiento->x = 0;
    VectorMovimiento->y = 0;
    VectorMovimiento->z = 0;
}
void NpcBook::updateBook(){
    it = pila.begin();
    while(it!=pila.end()){
        if(it->second->m_time.tTranscurrido(CADUCIDAD)
           && it->first!=P_PATRULLAR
           && it->first!=P_VIGILAR
           && it->first!=P_ENEMIGO
           ){
            delete it->second;
            pila.erase(it);
            it = pila.begin();
            continue;
        }
        it++;
    }
}

void NpcBook::remove_EventsByType(const Prioridades &tipo){
    it = pila.find(tipo);
    if(it==pila.end()) return;
    
    delete it->second;
    pila.erase(it);
}
