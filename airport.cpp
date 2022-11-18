#include "airport.h"
using namespace std;

Airport::Airport() {}

Airport::~Airport() {
    airport_name = "";
    airport_ID = 0;
    airport_IATA = "";
    airport_location = std::make_pair(0, 0);
    airport_city = std::make_pair("", "");
}

Airport::Airport(unsigned ID, std::string name, std::string IATA, double latitude, double longitude, std::string city, std::string country) {
    airport_name = name;
    airport_ID = ID;
    airport_IATA = IATA;


    //airport_position = std::make_pair(latitude, longitude);
    airport_location = std::make_pair(city, country);
}

Airport::Airport(const Airport& other) {
    airport_name = other.AirportName();
    airport_ID = other.AirportID();
    airport_IATA = other.AirportIATA();
    airport_location = other.AirportLocation();
    airport_city = other.AirportCity();
}

std::string Airport::AirportName() const {
    return airport_name;
}

string Airport::AirportID() const {
    return airport_ID;
}

string Airport::AirportIATA() const {
    return airport_IATA;
}
    
pair<double, double> Airport::AirportLocation() const {
    return airport_location;
}
    
pair<std::string, std::string> Airport::AirportCity() const {
    return airport_city;
}

bool operator==(const Airport& other) const {
    if (airport_name != other.airport_name || airport_ID != other.airport_ID || airport_IATA != other.airport_IATA ||
    airport_location != other.airport_location || airport_city != other.airport_city) {
        return false;
    }
    return true;
}
