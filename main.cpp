
#include "iostream"
#include "LinkedStack.h"
#include "Map.h"

using namespace std;

void getRoute(Map &aMap, const string& source, const string& target, bool recursive ){
    cout<< ">>>Looking for a route from "<< source<< " TO "<<target<<"<<<"<<endl;
    if (aMap.isPathAndPrint(source, target, recursive))
        cout<<endl<<"Yes that's the route from Denver to LA"<<endl;
    else
        cout<<"It does not exist a current route from "<< source << " To "<< target<<endl;
}

int main(){
    Map myMap;
    myMap.readMapFile("cities.txt", "connections.csv");
    cout<<myMap<<endl;

    cout << "TESTING RECURSIVE IMPLEMENTATION" << endl;
    getRoute(myMap,"Denver", "Los Angeles", true); cout<<endl;
    getRoute(myMap,"Denver", "Durango", true);cout<<endl;
    getRoute(myMap,"Durango", "Denver", true);cout<<endl;

    cout << "TESTING STACK IMPLEMENTATION" << endl;
    getRoute(myMap,"Denver", "Los Angeles", false); cout<<endl;
    getRoute(myMap,"Denver", "Durango", false);cout<<endl;
    getRoute(myMap,"Durango", "Denver", false);cout<<endl;

    cout << "TESTING ALL ROUTES IMPLEMENTATION - EXTRA CREDIT" << endl;
    myMap.printAllRoutesWithDistance("Denver", "Los Angeles");

}