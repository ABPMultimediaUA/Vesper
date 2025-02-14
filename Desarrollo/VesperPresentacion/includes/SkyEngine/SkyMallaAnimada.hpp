//
//  SkyMallaAnimada.hpp
//  motor
//
//  Created by Gaspar Rodriguez Valero on 14/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyMallaAnimada_hpp
#define SkyMallaAnimada_hpp

#include "TGestorRecursos.hpp"
#include "TMallaAnimada.hpp"
#include "SkyNodo.hpp"
#include "tiempo.h"
#include <map>
#include <vector>
#include <stdio.h>


class SkyMallaAnimada : public SkyNodo {
	friend class SkyEngine;
    TMallaAnimada * m_mallas;
public:
    SkyMallaAnimada(TNodo * padre);
    ~SkyMallaAnimada();
    bool AnyadirAnimacion(std::string ruta,std::string nombre,float time,unsigned int NumberFrames = 0);
    bool CambiarAnimacion(std::string cambio);
	void setTextura(char* fichero) { m_mallas->setTextura(fichero); }
	void setVisibleAlways(){m_mallas->setVisible();}
    
};

#endif /* SkyMallaAnimada_hpp */
