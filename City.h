#ifndef CSCI2421_CITY_H
#define CSCI2421_CITY_H

#include <iostream>
#include "string"

using namespace std;

class City {
private:
    string name;
    bool visited;

public:
    explicit City();
    explicit City(string name, bool visited);

    const string &getName() const;
    void setName(const string &cityName);

    bool isVisited() const;
    void setVisited(bool aVisited);

    friend ostream& operator<<(ostream& os, const City& aCity);


};

#include "City.cpp"

#endif //CSCI2421_CITY_H
