//
//  TMalla.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 14/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TMalla.hpp"

TMalla::TMalla(){
	
}

TMalla::~TMalla(){
	
}

void TMalla::cargarMalla(std::string fichero){
	malla.cargarMalla(fichero);
}

void TMalla::beginDraw(){
	malla.Draw(*sh);
}

void TMalla::endDraw(){
	
}
