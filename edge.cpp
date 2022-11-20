#include "edge.h"
#include <limits.h>
#include <cmath>
#include <math.h>



Edge::edge(){
    
};
Edge::Edge(Airport s, Airport d){
    source = Airport(s);
    destination = Airport(d); 
    weight = calculateWeight(s,d);
};

Edge::Edge(Airport s, Airport d, double w){
    source = Airport(s);
    destination = Airport(d); 
    weight = w;
};
string Edge::getSourceId() {
    return source.AirportID();
}
string Edge::getDestId() {
    return destination.AirportID();
}
double Edge::calculateWeight(Airport source, Airport destination) {
    // consider source to be class object
    std::pair<double,double> loc1 = source.AirportLocation();
    std::pair<double,double> loc2 = destination.AirportLocation();
    //https://www.movable-type.co.uk/scripts/latlong.html
    const double R = 6371;
    const double pi = atan(1.0)*4;
    double phi1 = loc1.first * pi / 180;
    double phi2 = loc2.first * pi /180;
    double delta_phi = (loc2.first-loc1.first) * pi / 180;
    double delta_lam = (loc2.second - loc1.second) * pi / 180;
    double a =  sin(delta_phi / 2) * sin(delta_phi / 2) + cos(phi1)*cos(phi2)*sin(delta_lam/2)*sin(delta_lam/2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    double d = R*c;
    return d;
}

double Edge::getWeight() {
    return weight;
}
void Edge::setWeight(double w) {
    weight = w;
}
string Edge::getSourceName() {
    return source.AirportName();
}
string Edge::getDestName() {
    return destination.AirportName();
}
string Edge::getSourceIATA() {
    return source.AirportIATA();
}
string Edge::getDestIATA() {
    return destination.AirportIATA();
}
void Edge::setSource(Airport s) {
    source = Airport(s);
}
void Edge::setDestination(Airport d) {
    destination = Airport(d); 
}


bool Edge::operator<(const Edge& other) const {
    return weight < other.weight;
}

bool Edge::operator==(Edge& other) const {
    if (source != other.source) {
        return false;
    }
    if (destination != other.destination) {
        return false;
    }
    return true;
}