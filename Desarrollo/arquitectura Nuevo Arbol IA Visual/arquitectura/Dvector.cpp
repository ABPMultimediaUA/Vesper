
#include "Dvector.hpp"


dvector3D::dvector3D(const dvector3D &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}
dvector3D::dvector3D(const dvector3D *p) {
    this->x = p->x;
    this->y = p->y;
    this->z = p->z;
}

dvector3D::dvector3D(float _x, float _y, float _z){
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

dvector3D::~dvector3D() {
}

dvector3D& dvector3D::operator=(const dvector3D &p){
    if(&p!=this){
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
    }
    return *this;
}
dvector3D& dvector3D::operator=(const dvector2D &p){
    if(p.x!=this->x && p.y!=this->y){
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}
dvector3D& dvector3D::operator+(const dvector3D &p){
    this->x+=p.x;
    this->y+=p.y;
    this->z+=p.z;
    return *this;
}
dvector3D& dvector3D::operator-(const dvector3D &p){
    this->x-=p.x;
    this->y-=p.y;
    this->z-=p.z;
    return *this;
}
dvector3D& dvector3D::operator*(const dvector3D &p){
    this->x*=p.x;
    this->y*=p.y;
    this->z*=p.z;
    return *this;
}
dvector3D& dvector3D::operator/(const dvector3D &p){
    if(p.x != 0)this->x/=p.x;
    if(p.y != 0)this->y/=p.y;
    if(p.z != 0)this->z/=p.z;
    return *this;
}

dvector2D::dvector2D(const dvector2D &p) {
	this->x = p.x;
	this->y = p.y;
}

dvector2D::dvector2D(float _x, float _y){
    this->x = _x;
    this->y = _y;
}

dvector2D::~dvector2D() {
}

dvector2D& dvector2D::operator=(const dvector2D &p){
	if(&p!=this){
		this->x = p.x;
		this->y = p.y;
		
	}
	return *this;
}

dvector2D& dvector2D::operator=(const dvector3D &p){
    if(p.x!=this->x && p.y!=this->y){
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}

dvector3D& dvector3D::operator*=(const float &p){
    this->x*=p;
    this->y*=p;
    this->z*=p;
    return *this;
}

dvector2D& dvector2D::operator+(const dvector2D &p){
	this->x+=p.x;
	this->y+=p.y;
	return *this;
}
dvector2D& dvector2D::operator-(const dvector2D &p){
	this->x-=p.x;
	this->y-=p.y;
	return *this;
}
dvector2D& dvector2D::operator*(const dvector2D &p){
	this->x*=p.x;
	this->y*=p.y;
	return *this;
}
dvector2D& dvector2D::operator/(const dvector2D &p){
	if(p.x != 0)this->x/=p.x;
	if(p.y != 0)this->y/=p.y;
	return *this;
}
