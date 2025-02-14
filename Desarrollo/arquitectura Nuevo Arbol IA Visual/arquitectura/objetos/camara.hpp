
#ifndef camara_hpp
#define camara_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Fps.hpp"
#include "../Dvector.hpp"

class camara : public GameObject {
public:
    camara();
    ~camara();
	void addCamara(dvector3D &p, dvector3D &l);
	void movimientoInteligente(dvector3D &posPlayer);
    void setCamSpeed(float vel);
    float* getCamSpeed();
    void setZoom(bool z);
    bool getZoom();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
    void setRapido(bool r);
    bool getRapido();
    
private:
	class render* renderiza;
	float incrX, incrY, incrZ, offsetX, offsetY, offsetZ, camSpeed;
    bool cerca, muero, rapido;
};
#endif /* camara_hpp */
