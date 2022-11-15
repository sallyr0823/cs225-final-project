#include "edge.h"
#include <limits.h>


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