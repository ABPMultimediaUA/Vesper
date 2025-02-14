
#ifndef TEscena_hpp
#define TEscena_hpp

#include "TNodo.hpp"
#include "SkyEngine.hpp"
#include "ShaderManager.hpp"

// dimensiones de la ventana
const GLuint WIDTH = 800, HEIGHT = 600;

class TEscena {
public:
	TEscena();
	~TEscena();
	void Draw();
	void update();
	void imprime();
		
//	TNodo* getActiveCamera();
private:
	SkyEngine* motor;
	SkyCamara* cam;
	std::vector<SkyMalla*> mallas;
	SkyMalla *cubo, *plano;
    SkyLuz* luz;
	SkyMallaAnimada* animacion;
};

#endif /* TEscena_hpp */
