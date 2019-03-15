/*
CH08-320142
Problem 3.1 cpp
Digdarshan Kunwar
d.kunwar@jacobs-university.de
*/

#include<iostream>
#include<string>

class City {
private:
    std::string name;
    int numOfCitizen; //number of citizens
    std::string location;
    std::string poi;

public:
    //setter methods
    City(std::string newName) : name(newName){};
    void setLocation(std::string newLocation);
    void setPoi(std::string newPoi);
    void setNumOfCitizens(int newNumOfCitizens);

    //getter methods
    std::string getName();
    std::string getLocation();
    std::string getPoi();
    int getNumOfCitizens();

    //usage methods
    void print();
};