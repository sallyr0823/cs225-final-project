#pragma once

#include <iostream>
#include <string>

class Airport {
public:
    Airport();
    Airport(const Airport& other);
    Airport(unsigned ID, std::string name, std::string city,std::string country, std::string IATA, std::string ICAO,double latitude, double longitude);
    ~Airport();
    std::string AirportName() const;
    unsigned AirportID() const;
    std::string AirportIATA() const;
    std::pair<double, double> AirportLocation() const;
    std::pair<std::string, std::string> AirportCity() const;
    bool operator==(const Airport& other) ;
private:
    std::string airport_name;
    unsigned airport_ID;

    std::string airport_IATA;
    std::string airport_ICAO;
    // <latitude, longitude> of airport
    std::pair<double ,double> airport_location;
    // <city, country> of airport
    std::pair<std::string, std::string> airport_city;
};