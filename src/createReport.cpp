#include "stationReport.h"
#include <iostream>
#include <iomanip>
#include <limits>

std::tm getDate(int year, int month, int day);
bool isValidDate(int year, int month, int day);

StationReport* createReport(int reportsCount) {

    auto* reports = new StationReport[reportsCount];

    for (int i = 0; i < reportsCount; i++) {
        StationReport reportInstance;
        std::cout << "Enter report" << " #" << i+1 << " data: " << std::endl;
        reportInstance.reportIndex = i + 1;
// ---------------------------------------------------------------------------------------
    std::cout << "Station: ";
    while (!(std::cin >> reportInstance.stationNumber) || reportInstance.stationNumber < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid station number. Please enter a non-negative integer: ";
    }
// ---------------------------------------------------------------------------------------
    std::cout << "First name: ";
    std::getline(std::cin >> std::ws, reportInstance.firstName);
    while (reportInstance.firstName.empty()) {
        std::cout << "First name cannot be empty. Please try again: ";
        std::getline(std::cin, reportInstance.firstName);
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Last name: ";
    std::getline(std::cin >> std::ws, reportInstance.lastName);
    while (reportInstance.lastName.empty()) {
        std::cout << "Last name cannot be empty. Please try again: ";
        std::getline(std::cin, reportInstance.lastName);
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Rank (select one): " << std::endl;
    std::cout << "1. Senior inspector" << std::endl;
    std::cout << "2. Junior inspector" << std::endl;
    std::cout << "3. Firefighter" << std::endl;

    int choice = 0;
    while (true) {
        std::cout << "Enter the number corresponding to the rank: ";
        if (std::cin >> choice && (choice >= 1 && choice <= 3)) {
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid choice. Please select 1, 2, or 3." << std::endl;
        }
    }

    switch (choice) {
        case 1:
            reportInstance.rank = "Senior inspector";
            break;
        case 2:
            reportInstance.rank = "Junior inspector";
            break;
        case 3:
            reportInstance.rank = "Firefighter";
            break;
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Air temperature (Celsius): ";
    while (!(std::cin >> reportInstance.airTemperature) || reportInstance.airTemperature < -40 || reportInstance.airTemperature > 60) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid temperature. Please enter a value between -40 and 60: ";
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Wind speed (m/s): ";
    while (!(std::cin >> reportInstance.windSpeed) || reportInstance.windSpeed < 0 || reportInstance.windSpeed > 130) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid wind speed. Please enter a non-negative number between 1 and 130: ";
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Threats eliminated: ";
    while (!(std::cin >> reportInstance.threatsEliminated) || reportInstance.threatsEliminated < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid number of threats eliminated. Please enter a non-negative integer: ";
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Enter date (year, month, day): " << std::endl;
    std::tm date = {};
    int year, month, day;
// ---------------------------------------------------------------------------------------
    std::cout << "Enter year: ";
    while (!(std::cin >> year) || year < 2000 || year > 2025) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid year. Please enter a year between 1900 and 2100: ";
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Enter month: ";
    while (!(std::cin >> month) || month < 1 || month > 12) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid month. Please enter a value between 1 and 12: ";
    }
// ---------------------------------------------------------------------------------------
    std::cout << "Enter day: ";
    while (!(std::cin >> day) || day < 1 || day > 31 || !isValidDate(year, month, day)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid day. Please enter a valid day for the given month and year: ";
    }
// ---------------------------------------------------------------------------------------

    reportInstance.reportDate = getDate(year,month,day);

    std::cout << "Report time in seconds: ";
    while (!(std::cin >> reportInstance.reportTimeSeconds) || reportInstance.reportTimeSeconds < 64800 || reportInstance.reportTimeSeconds > 86400) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid report time. Please enter a non-negative number (you can receive a response only after 18:00 that is, after 64800 seconds): ";
    }

    std::cout << " " << std::endl;
    reports[i] = reportInstance;
    }
    return reports;
}



std::tm getDate(int year, int month, int day) {
    std::tm date = {};
    date.tm_year = year - 1900;
    date.tm_mon = month-1;
    date.tm_mday = day;

    return date;
}

bool isValidDate(int year, int month, int day) {
    std::tm tmDate = {};
    tmDate.tm_year = year - 1900;
    tmDate.tm_mon = month - 1;
    tmDate.tm_mday = day;
    std::mktime(&tmDate);
    return tmDate.tm_year == year - 1900 && tmDate.tm_mon == month - 1 && tmDate.tm_mday == day;
}
