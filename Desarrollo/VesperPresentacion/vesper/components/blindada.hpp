
#ifndef blindada_hpp
#define blindada_hpp

#include <stdio.h>
#include "component.hpp"

class blindada : public component{
public:
	blindada();
	~blindada();
	void update() override;
	
};

#endif /* blindada_hpp */
