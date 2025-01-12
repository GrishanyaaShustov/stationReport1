#include <iostream>
#include <iomanip>
#include "stationReport.h"

void StationReport::print() const {
    std::cout << "Report index: " << reportIndex << "\n"
            << "Station: " << stationNumber << "\n"
            << "First name: " << firstName << "\n"
            << "Last name: " << lastName << "\n"
            << "Rank: " << rank << "\n"
            << "Air temperature: " << airTemperature << "\n"
            << "Wind speed: " << windSpeed << "\n"
            << "Threats eliminated: " << threatsEliminated << "\n"
            << "Date: " << std::put_time(&reportDate, "%Y-%m-%d") << "\n"
            << "Report time in seconds: " << reportTimeSeconds << "s\n";
}
