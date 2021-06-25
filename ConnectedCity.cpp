#include "ConnectedCity.h"

ConnectedCity::ConnectedCity() : ConnectedCity(nullptr, nullptr, 0) {}
ConnectedCity::ConnectedCity(City *source, City *target, int miles): source(source), target(target), miles(miles){}

ConnectedCity::~ConnectedCity() {
    this->source = nullptr;
    this->target = nullptr;
    this-> miles = 0;
}

City *ConnectedCity::getSource() const {    return source;}
void ConnectedCity::setSource(City *aSource) { ConnectedCity::source = aSource;}

City *ConnectedCity::getTarget() const {    return target;}
void ConnectedCity::setTarget(City *aTarget) { ConnectedCity::target = aTarget;}

int ConnectedCity::getMiles() const {    return miles;}
void ConnectedCity::setMiles(int inMiles) { ConnectedCity::miles = inMiles;}

ostream &operator<<(ostream &os, const ConnectedCity &aConnection) {
    os << *aConnection.getSource() << " ---> " << *aConnection.getTarget() << " ==> " << aConnection.getMiles()<< " miles";
    return os;
}

