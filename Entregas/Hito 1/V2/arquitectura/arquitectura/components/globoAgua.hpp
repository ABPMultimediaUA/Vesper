//
//  globoAgua.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 16/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef globoAgua_hpp
#define globoAgua_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class globoAgua : public armaInterface{
public:
	globoAgua(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~globoAgua();
	void atacar();
	unsigned int getMunicion();
	void setMunicion(unsigned int n);
	void destructor();
	void update();
	
private:
	unsigned int cadencia, municion, cargador;
	float tiempo_recarga, tiempo_vida, alcance;
	time_t tiempo;
};

#endif /* globoAgua_hpp */
