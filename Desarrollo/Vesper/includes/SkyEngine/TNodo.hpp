//
//  TNodo.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TNodo_hpp
#define TNodo_hpp

#include <vector>
#include "TEntidad.hpp"
#include "Pila.h"

class TNodo{
public:
	TNodo();
	~TNodo();
	
	int addHijo(TNodo* n);
	int remHijo(TNodo* n);
	bool setEntidad(TEntidad* en);
	TEntidad* getEntidad(){ return entidad; }
	void setPadre(TNodo* p);
	TNodo* getPadre(){ return padre; }
	void Draw(bool pass);
	
private:
	TEntidad* entidad;
	std::vector<TNodo*> hijos;
	TNodo* padre;
	
};

#endif /* TNodo_hpp */
