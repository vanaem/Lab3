#ifndef CSCI2421_MAP_H
#define CSCI2421_MAP_H

#include "City.h"
#include "ConnectedCity.h"
#include "LinkedStack.h"
#include "LinkedBag.h"

using namespace std;

/**
 * This class represents a map, that contains cities and the connections between them.
 * E.g. Denver, Boulder, Colorado Springs and Durango are cities.
 * Denver and Boulder are connected and are 28 miles apart.
 * Denver and Colorado Springs are connected and are 71 miles apart.
 * However, Denver and Durango are not directly connected as you need to stop by another city to get there, like
 * for instance Colorado Springs.
 */
class Map {
private:
    LinkedBag<City*> cities;
    LinkedBag<ConnectedCity*> connections;

    City* getCityByName(string cityName) const noexcept(false);
    /**
     * returns true if there is a path from the source to the target, even if it means stopping in other cities.
     * This is a RECURSIVE IMPLEMENTATION.
     * @param source
     * @param target
     * @return
     */
    bool isPathR(City* source, City* target);

    /**
     * returns true if there is a path from the source to the target, even if it means stopping in other cities.
     * THIS IS A ITERATIVE STACK-BASED IMPLEMENTATION
     * @param source
     * @param target
     * @return
     */
    bool isPathS(City* source, City* target);
public:
    explicit Map();
    ~Map();

    /**
     * Reads flight information into the flight map.
     * @param cityFileName
     */
    void readMapFile(string cityFileName, string connectionsFileName);

    /**
     * Adds a city to the map's cities.
     * @param aCity
     */
    void addCity(string cityName);

    /**
     * Marks a city as visited.
     * @param aCity
     */
    void markVisited(City* aCity);

    /**
     * Clears marks on all cities.
     */
    void unvisitAll();

    /**
     * Inserts a city adjacent to another city in a flight map.
     * @param source
     * @param target
     * @param miles
     */
    void insertConnectedCities(City* source, City* target, int miles);

    /**
     *
     * @param fromCity
     * @return Returns the next unvisited city, if any, that is connected to a given city.
     * @throws std::logic_error is there are no more unvisited cities for that given city.
     */
    City* getNextCity(City* fromCity) noexcept(false);

    /**
     *
     * @param originCity
     * @param destinationCity
     * @return
     * @throws std::logic_error if the cities are not connected.
     */
    int distance(City* originCity, City* destinationCity) noexcept(false);


    /**
     * prints the current map.
     * @param os
     * @param aMap
     * @return
     */
    friend ostream& operator<<(ostream& os, const Map& aMap);



    /**
    * Tests whether a sequence of flights exists between two cities.
    * @param originCity name
    * @param destinationCity name
    * @return
    * @throws logic_error if any city is not in the system.
    */
    bool isPathAndPrint(string originCity, string destinationCity, bool useRecursive) noexcept(false);

    /**
     * Prints to std output all the possible routes from origin to destination including the total distance.
     *
     * EXTRA CREDIT 30 marks Due by 3PM.
     * @param originCity
     * @param destinationCity
     * @throws logic_error if any city is not in the system.
     */
    void printAllRoutesWithDistance(string originCity, string destinationCity) noexcept(false);

};

#include "Map.cpp"

#endif //CSCI2421_MAP_H
