#pragma once

#include <string>
#include <limits.h>
#include "airport.h"

using std::string;
class Edge {
    public:
        //default constructor
        Edge();
        //constructor without given weight
        Edge(string s, string d);
        //constructor with everything
        Edge(string s, string d, double w);

        //get 
        string getSourceId();       
        string getDestId();     
        double getWeight();
        double calculateWeight(Airport source, Airport destination);
       
        //set
        void setWeight(double w);
        void setSource(double s);
        void setDestination(double d); 

        //operator overloading
        bool operator<(const Flight& other) const;
        bool operator==(Flight& other) const;
    
        //std::pair<double, double> AirportLocation() const;
        
        
    private:
        //source airport IATA
        string source;
        //destination airport IATA
        string destination;
        //distances in KM between two airports
        double weight;
};


