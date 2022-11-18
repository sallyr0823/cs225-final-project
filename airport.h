#pragma once

#include <iostream>
#include <string>

class Airport {
public:
    Airport();
    Airport(const Airport& other);
    Airport(unsigned ID, std::string name, std::string IATA, double latitude, double longitude, std::string city, std::string country);
    ~Airport();
    std::string AirportName() const;
    std::string AirportID() const;
    std::string AirportIATA() const;
    std::pair<double, double> AirportLocation() const;
    std::pair<std::string, std::string> AirportCity() const;
    bool operator==(const Airport& other) const;
private:
    std::string airport_name;
    std::string airport_ID;
    std::string airport_IATA;
    // <latitude, longitude> of airport
    std::pair<double, double> airport_location;
    // <city, country> of airport
    std::pair<std::string, std::string> airport_city;
};