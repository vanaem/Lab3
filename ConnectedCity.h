#ifndef CSCI2421_CONNECTEDCITY_H
#define CSCI2421_CONNECTEDCITY_H

#include <iostream>
#include "City.h"

using namespace std;

/**
 * This class records two directly connected cities and the distance between them.
 * Connection is considered directional. i.e. source is connected to target, does not mean that target is connected to
 * source.
 */
class ConnectedCity {
private:
    City* source;
    City* target;
    int miles;  /** Distance between source and target */
public:
    explicit ConnectedCity();
    ConnectedCity(City* source, City* target, int miles);
    ~ConnectedCity();

    City *getSource() const;
    void setSource(City *aSource);

    City *getTarget() const;
    void setTarget(City *aTarget);

    int getMiles() const;
    void setMiles(int inMiles);

    friend ostream& operator<<(ostream& os, const ConnectedCity& aConnection);


};

#include "ConnectedCity.cpp"

#endif //CSCI2421_CONNECTEDCITY_H
