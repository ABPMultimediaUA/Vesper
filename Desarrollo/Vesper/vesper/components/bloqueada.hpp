
#ifndef bloqueada_hpp
#define bloqueada_hpp

#include <stdio.h>
#include "component.hpp"

class bloqueada : public component{
public:
	bloqueada();
	~bloqueada();
	void update() override;
	
};

#endif /* bloqueada_hpp */
