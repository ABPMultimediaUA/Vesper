
#ifndef escopeta_hpp
#define escopeta_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class escopeta : public armaInterface{
public:
	escopeta(unsigned int pMunicion, float pAlcance, float pTiempo_recarga);
	~escopeta();
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

#endif /* escopeta_hpp */
