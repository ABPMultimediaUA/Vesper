//
//  TEntidad.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TEntidad_hpp
#define TEntidad_hpp

#include <stack>

class TEntidad{
public:
	TEntidad(){}
	~TEntidad(){}
	virtual void beginDraw()=0;
	virtual void endDraw()=0;
};

#endif /* TEntidad_hpp */
