#include "City.h"

#include <utility>

City::City(): City("", false) {}
City::City(string name, bool visited): name(name), visited(visited) {}

const string &City::getName() const {
    return name;
}

void City::setName(const string &cityName) {
    City::name = cityName;
}

bool City::isVisited() const {
    return visited;
}

void City::setVisited(bool isVisited) {
    City::visited = isVisited;
}

ostream& operator<<(ostream& os, const City& aCity){
    os << aCity.getName() ;
    return os;
}

