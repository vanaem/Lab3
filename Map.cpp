#include "iostream"
#include "fstream"
#include "string"
#include "sstream"

#include "Map.h"

Map::Map(): cities(LinkedBag<City*>()), connections(LinkedBag<ConnectedCity*>()) {}

Map::~Map() {
    for (ConnectedCity* aConnection : this->connections.toVector()) {
        this->connections.remove(aConnection); //removes the connection from the bag.
        aConnection->setSource(nullptr);
        aConnection->setTarget(nullptr);
        delete aConnection; //deletes the connection
    }

    for (City* aCity: this->cities.toVector()){
        this->cities.remove(aCity); //removes the city from the bag
        delete aCity; //deletes the city object
    }
}

City* Map::getCityByName(string cityName) const  {
    for (City* aCity : this->cities.toVector())
        if (aCity->getName() == cityName)
            return aCity;
    throw logic_error("City Not Found:"+cityName);
}

void Map::readMapFile(string cityFileName, string connectionsFileName) {

    const string delimiter = ",";
    string line;

    ifstream cityFile(cityFileName);
    while (std::getline(cityFile, line)) {
        this->addCity(line);
    }
    cityFile.close();

    ifstream connectionFile(connectionsFileName);
    while (std::getline(connectionFile, line)) {
        vector<string> tokens;    // Vector of string to save tokens
        stringstream stringstream1(line);
        string token;

        while(getline(stringstream1, token, ','))
            tokens.push_back(token);

        try {
            City *source = this->getCityByName(tokens[0]);
            City *target = this->getCityByName(tokens[1]);
            int miles = stoi(tokens[2]);
            this->insertConnectedCities(source, target, miles);
        }
        catch (logic_error& error) {
            cout<< "Error on Line:" << line <<":::" << error.what() << endl;
        }
    }
    connectionFile.close();


}

void Map::addCity(string cityName){
    for (City* aCity : this->cities.toVector())
        if (aCity->getName() == cityName)
            return; // city already in the bag.

    auto* aCity = new City(cityName, false);
    this->cities.add(aCity);
}


void Map::markVisited(City *aCity) {
    aCity->setVisited(true);
}

void Map::unvisitAll() {
    for(City* aCity: this->cities.toVector())
        aCity->setVisited(false);
}

void Map::insertConnectedCities(City *source, City *target, int miles) {
    for (ConnectedCity* aConnection : this->connections.toVector())
        if (aConnection->getSource()->getName() == source->getName() &&
            aConnection->getTarget()->getName() == target->getName())
            return; // Connection already there.

    auto* aConnection = new ConnectedCity(source, target, miles);
    this->connections.add(aConnection);
}

City *Map::getNextCity(City *fromCity) noexcept(false) {
    for (ConnectedCity* aConnection : this->connections.toVector())
        if (aConnection->getSource()->getName() == fromCity->getName() && !aConnection->getTarget()->isVisited())
            return aConnection->getTarget();

    throw logic_error("No more unvisited cities.");
}

int Map::distance(City *originCity, City *destinationCity) noexcept(false) {
    for (ConnectedCity* aConnection : this->connections.toVector())
        if (aConnection->getSource()->getName() == originCity->getName() &&
            aConnection->getTarget()->getName() == destinationCity->getName())
            return aConnection->getMiles();

    throw logic_error("There's no connection among those cities.");
}

ostream& operator<<(ostream& os, const Map& aMap){
    os<< "THIS IS THE CURRENT MAP:"<<endl;
    os << string(80, '*')<<endl;
    os<< "Cities: | ";
    for (City* aCity: aMap.cities.toVector())
        os<< aCity->getName() << " | ";
    os<<endl << endl;
    os<< "SOURCE CITY    -->   TARGET CITY   ==> Distance" <<endl;
    os << string(80, '-')<<endl;
    for (ConnectedCity* aConnection: aMap.connections.toVector())
        os<<*aConnection<<endl;
    os << string(80, '-');
    return os;
}


bool Map::isPathAndPrint(string originCity, string destinationCity, bool useRecursive) {

    unvisitAll();

    City* source = this->getCityByName(originCity);
    City* target = this->getCityByName(destinationCity);

    if (useRecursive)
        return this->isPathR(source, target);
    else
        return this->isPathS(source, target);
}


////// PRIVATE
/* RECURSIVE IMPLEMENTATION*/
bool Map::isPathR(City *source, City *target) {
    /**
     * TODO #3 Recursive implementation
     *
     * Similar to the Airline problem on chapter 5.3
     *
     * Addition: if found destination, print the source.
     * Major difference: getNextCity throws and exception.
     */

}

/*ITERATIVE IMPLEMENTATION*/
bool Map::isPathS(City *source, City *target) {
    /**
     * TODO #4 Implementation using a Stack
     *
     * Similar to the Airline problem on chapter 6.4
     *
     * Addition: if found destination, print the source.
     * Major difference: getNextCity throws and exception. *
     *
     */

}


/**
 * EXTRA CREDIT 30 marks Due 3pm
 * This is an advanced problem and it is optional.
 * You can implement it recursively or using stack.
 * If done recursively add the recursion function as private below.
 **/
void Map::printAllRoutesWithDistance(string originCity, string destinationCity) noexcept(false) {
    cout<< "Not implemented..."<<endl;

    /**
     * TODO #5: EXTRA CREDIT
     * Not looking for a perfect solution for the Extra Credit but yor solution should print 3 routes for the given data.
     * Hints:
     *      - Have a linked bag to store strings representing the routes.
     *      - keep looking for routes until your stack is empty.
     *      - if the top of the stack is the target:
     *          - use a temporary stack to reverse the main stack. (stack -> temp stack)
     *          - as you pop from temp stack, write the route, compute distance, and push back to the main stack.
     *          - add the route (string) to the bag (include the distance!).
     *      - otherwise
     *          - get the next available city
     *          - when no more available cities, set the target as not visited, just in case you found it
     *            you want to be able to reach that one again.
*            - at the end if you routes is not empty, print the routes or a msg saying no route found.
     */
}


