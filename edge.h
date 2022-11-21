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
        Edge(Airport s, Airport d);
        //constructor with everything
        Edge(Airport s, Airport d, double w);

        //get 

        unsigned getSourceId();       
        unsigned getDestId();    

        string getSourceName();
        string getDestName();
        string getSourceIATA();
        string getDestIATA();
        double getWeight();

        double calculateWeight(Airport source, Airport destination);

        //set
        void setWeight(double w);
        void setSource(Airport s);
        void setDestination(Airport d); 

        //operator overloading
        bool operator<(const Edge& other) const;
        bool operator==(Edge& other) const;
    
        //std::pair<double, double> AirportLocation() const;
        
        
    private:
        //source airport IATA
        Airport source;
        //destination airport IATA
        Airport destination;
        //distances in KM between two airports
        double weight;
};


