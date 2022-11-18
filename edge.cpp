#include "edge.h"
#include <limits.h>
#include <cmath>
#include <math.h>



Edge::edge(){
    source = "";
    destination = ""; 
    weight = 0;
};
Edge::Edge(string s, string d){
    source = s;
    destination = d; 
    weight = 0;
};

Edge::Edge(string s, string d, double w){
    source = s;
    destination = d; 
    weight = w;
};
string Edge::getSourceId() {
    return source;
}
string Edge::getDestId() {
    return destination;
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

void Edge::setSource(double s) {
    source = s;
}
void Edge::setDestination(double d) {
    destination = d; 
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