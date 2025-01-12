#include <iostream>
#include <limits>

#include "deleteArrayElem.h"
#include "stationReport.h"
#include "indexesArrayFuncs.h"
#include "searchFuncs.h"

void printSortedData(StationReport *sourceReports, LastNamePair *indexesArrayFamilies,
                     ThreatsEliminatedPair *indexesArrayThreats, int size) {
    std::cout << "\nChoose sorting key: " << std::endl;
    std::cout << "1. Last name (increasing order)" << std::endl;
    std::cout << "2. Quantity eliminated threats (decreasing order)" << std::endl;
    std::cout << "Your choice: ";

    int choice;

    if (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Invalid Input. Returning to main menu." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    printSourceArrayData(sourceReports, size);
    if (choice == 1) {
        printIndexesArayByLastName(indexesArrayFamilies, size);
        printSortedArrayByLastName(indexesArrayFamilies, sourceReports, size);
    } else {
        printIndexesArrayByThreatsElim(indexesArrayThreats, size);
        printSortedArrayByThreatsElim(indexesArrayThreats, sourceReports, size);
    }
}

void searchData(StationReport *sourceReports, LastNamePair *indexesArrayFamilies,
                ThreatsEliminatedPair *indexesArrayThreats, int size) {
    int choice;
    StationReport *searchResult;
    while (true) {
        std::cout << "\nChoose search key: " << std::endl;
        std::cout << "1. Last name" << std::endl;
        std::cout << "2. Quantity eliminated threats" << std::endl;
        std::cout << "Your choice: ";

        if (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
            std::cout << "Invalid input. Please enter 1 or 2.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    if (choice == 1) {
        std::string lastName;
        while (true) {
            std::cout << "Enter the last name: ";
            if (!(std::cin >> lastName) || lastName.empty()) {
                std::cout << "Invalid input. Please enter a valid last name.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        searchResult = binarySearchByFamilieRecursive(indexesArrayFamilies, sourceReports, lastName, 0, size - 1);
    } else {
        int threats;
        while (true) {
            std::cout << "Enter the number of eliminated threats: ";
            if (!(std::cin >> threats) || threats < 0) {
                std::cout << "Invalid input. Please enter a non-negative integer.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        searchResult = binarySearchByElimThreads(indexesArrayThreats, sourceReports, threats, size);
    }

    if (searchResult) {
        std::cout << "Record is founded!\n" << std::endl;
        searchResult->print();
    } else {
        std::cout << "Record is not founded! =(\n" << std::endl;
    }
}

void updateStationReportRecord(StationReport *&reports, LastNamePair *&indexesArrayFamilies, ThreatsEliminatedPair *&indexesArrayThreats, int size) {
    int idChoice;
    std::cout <<"To change one of the array records, \nenter its ID (the value of the Report id field, i.e. the sequence number in the array)"<< std::endl;
    std::cout << "Enter report ID: ";

    if (!(std::cin >> idChoice) || idChoice <= 0) {
        std::cout << "Invalid input. Please enter a positive integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    StationReport *searchResult = binarySearchByReportId(reports, idChoice, size);

    if (searchResult) {
        std::string newFirstName;
        std::string newLastName;
        std::tm newDate = {};
        unsigned int newStationNumber;
        float newAirTemperature;
        float newWindSpeed;
        unsigned int newEliminatedThreats;
        unsigned int newReportTime;

        while (true) {
            std::cout << "\nChoose field to rewrite: " << std::endl;
            // report id не изменяем т.к оно автоматически добавляется при созаднии массива записей
            std::cout << "1. Station number" << std::endl;
            std::cout << "2. First name" << std::endl;
            std::cout << "3. Last name" << std::endl;
            std::cout << "4. Rank" << std::endl;
            std::cout << "5. Air temperature(Celsius)" << std::endl;
            std::cout << "6. Wind speed(m/s)" << std::endl;
            std::cout << "7. Threats eliminated quantity" << std::endl;
            std::cout << "8. Date" << std::endl;
            std::cout << "9. Report time in seconds" << std::endl;
            std::cout << "Enter '10' to exit" << std::endl;

            int choice;
            std::cout << "Your choice: ";
            if (!(std::cin >> choice) || choice < 0) {
                std::cout << "Invalid input. Please enter a non-negative integer.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    std::cout << "\nOld station number: " << searchResult->stationNumber << std::endl;
                while (true) {
                    std::cout << "Enter new station number: ";
                    if (!(std::cin >> newStationNumber) || newStationNumber < 0) {
                        std::cout << "Invalid input. Please enter a non-negative integer.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                searchResult->stationNumber = newStationNumber;
                std::cout << "\nStation number was changed successfully" << std::endl;
                break;

                case 2:
                    std::cout << "\nOld first name: " << searchResult->firstName << std::endl;
                while (true) {
                    std::cout << "Enter the new first name: ";
                    if (!(std::cin >> newFirstName) || newFirstName.empty()) {
                        std::cout << "Invalid input. Please enter a valid first name.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                searchResult->firstName = newFirstName;
                std::cout << "\nFirst name was changed successfully" << std::endl;
                break;

                case 3:
                    std::cout << "\nOld last name: " << searchResult->lastName << std::endl;
                while (true) {
                    std::cout << "Enter the new last name: ";
                    if (!(std::cin >> newLastName) || newLastName.empty()) {
                        std::cout << "Invalid input. Please enter a valid first name.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                searchResult->lastName = newLastName;
                std::cout << "\nLast name was changed successfully" << std::endl;
                indexesArrayFamilies = createLastNameIndexesArray(reports, size);
                break;

                case 4:
                    std::cout << "\nOld rank: " << searchResult->rank << std::endl;
                std::cout << "New Rank (select one): " << std::endl;
                std::cout << "1. Senior inspector" << std::endl;
                std::cout << "2. Junior inspector" << std::endl;
                std::cout << "3. Firefighter" << std::endl;

                int choiceNewRank;
                while (true) {
                    std::cout << "Enter the number corresponding to the rank: ";
                    if (std::cin >> choiceNewRank && (choiceNewRank >= 1 && choiceNewRank <= 3)) {
                        break;
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                        std::cout << "Invalid choice. Please select 1, 2, or 3." << std::endl;
                    }
                }

                switch (choiceNewRank) {
                    case 1:
                        searchResult->rank = "Senior inspector";
                    break;
                    case 2:
                        searchResult->rank = "Junior inspector";
                    break;
                    case 3:
                        searchResult->rank = "Firefighter";
                    break;
                }
                std::cout << "\nRank was changed successfully" << std::endl;
                break;

                case 5:
                    std::cout << "\nOld air temperature: " << searchResult->airTemperature << std::endl;
                while (true) {
                    std::cout << "Enter the new air temperature: ";
                    if (!(std::cin >> newAirTemperature) || newAirTemperature < -40 || newAirTemperature > 60) {
                        std::cout << "Invalid input. Please enter a valid air temperature.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                searchResult->airTemperature = newAirTemperature;
                std::cout << "\nAir temperature was changed successfully" << std::endl;
                break;

                case 6:
                    std::cout << "\nOld wind speed: " << searchResult->windSpeed << std::endl;
                while (true) {
                    std::cout << "Enter new wind speed: ";
                    if (!(std::cin >> newWindSpeed) || newWindSpeed < 0 || newWindSpeed > 130) {
                        std::cout << "Invalid input. Please enter a valid air temperature.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                searchResult->windSpeed = newWindSpeed;
                std::cout << "\nWind speed was changed successfully" << std::endl;
                break;

                case 7:
                    std::cout << "\nOld eliminated threats quantity: " << searchResult->threatsEliminated << std::endl;
                while (true) {
                    std::cout << "Enter eliminated threats quantity: ";
                    if (!(std::cin >> newEliminatedThreats) || newEliminatedThreats < 0) {
                        std::cout << "Invalid input. Please enter a valid eliminated threats quantity.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                searchResult->threatsEliminated = newEliminatedThreats;
                std::cout << "\nEliminated threats quantity was changed successfully" << std::endl;
                indexesArrayThreats = createThreatesElimIndexesArray(reports, size);
                break;

                case 8:
                    std::cout << "\nOld date: " << searchResult->reportDate.tm_year + 1900 << "-" << searchResult->reportDate.tm_mon + 1
                            << "-" << searchResult->reportDate.tm_mday << std::endl;
                int newYear, newMonth, newDay;

                std::cout << "\nEnter new year: ";
                while (!(std::cin >> newYear) || newYear < 2000 || newYear > 2025) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid year. Please enter a year between 1900 and 2100: ";
                }

                std::cout << "Enter new month: ";
                while (!(std::cin >> newMonth) || newMonth < 1 || newMonth > 12) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid month. Please enter a value between 1 and 12: ";
                }

                std::cout << "Enter day: ";
                while (!(std::cin >> newDay) || newDay < 1 || newDay > 31 || !isValidDate(newDay, newDay, newDay)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid day. Please enter a valid day for the given month and year: ";
                }

                searchResult->reportDate = getDate(newYear, newMonth, newDay);
                std::cout << "\nDate was changed successfully" << std::endl;
                break;

                case 9:
                    std::cout << "\nOld report time in seconds: " << std::endl;
                while (true) {
                    std::cout << "Enter new report time in seconds: ";
                    if (!(std::cin >> newReportTime) || newReportTime < 64800 || newReportTime > 86400) {
                        std::cout <<
                                "Invalid report time. Please enter a non-negative number (you can receive a response only after 18:00 that is, after 64800 seconds)";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                searchResult->reportTimeSeconds = newReportTime;
                std::cout << "\nReport time in seconds was changed successfully" << std::endl;
                break;

                case 10:
                    std::cout << "\nEditing of record is completed.\n" << std::endl;
                return;

                default:
                    std::cout << "\nIncorrect choice. Try again.\n";
                break;
            }
        }
    }
    else {
        std::cout << "\nRecord is not found =(" << std::endl;
    }
}

void deleteStationReport(StationReport *&reports, LastNamePair *&indexesArrayFamilies,
                         ThreatsEliminatedPair *&indexesArrayThreats, int &size) {
    int deleteChoice;
    StationReport *searchResult = nullptr;
    int deletedThreats;
    std::string deletedLastName;

    while (true) {
        std::cout << "\nChoose delete key: " << std::endl;
        std::cout << "1. Last name" << std::endl;
        std::cout << "2. Quantity eliminated threats" << std::endl;
        std::cout << "Your choice: ";

        if (!(std::cin >> deleteChoice) || (deleteChoice != 1 && deleteChoice != 2)) {
            std::cout << "Invalid input. Please enter 1 or 2.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    switch (deleteChoice) {
        case 1:
            while (true) {
                std::cout << "Enter the last name: ";
                if (!(std::cin >> deletedLastName) || deletedLastName.empty()) {
                    std::cout << "Invalid input. Please enter a valid last name.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }
            searchResult = binarySearchByFamilieRecursive(indexesArrayFamilies, reports, deletedLastName, 0, size);
            if (searchResult) {
                std::cout << "Deleted record by last name was found!\n" << std::endl;
                searchResult->print();
                deleteArrayElem(reports, indexesArrayFamilies, indexesArrayThreats, searchResult->reportIndex, size);
                std::cout << "\nThe record was deleted successfully" << std::endl;
            } else std::cout << "\nDeleted record by last name was not found." << std::endl;
            break;

        case 2:
            while (true) {
                std::cout << "Enter the number of eliminated threats: ";
                if (!(std::cin >> deletedThreats) || deletedThreats < 0) {
                    std::cout << "Invalid input. Please enter a non-negative integer.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }
            searchResult = binarySearchByElimThreads(indexesArrayThreats, reports, deletedThreats, size);
            if (searchResult) {
                std::cout << "Deleted record by eliminated threats quantity was found!\n" << std::endl;
                searchResult->print();
                deleteArrayElem(reports, indexesArrayFamilies, indexesArrayThreats, searchResult->reportIndex, size);
                std::cout << "\nThe record was deleted successfully" << std::endl;
            } else std::cout << "\nDeleted record by eliminated threats quantity was not found." << std::endl;
            break;
    }
}

void cleanMemmory(StationReport *sourceReports, LastNamePair *indexesArrayFamilies,
                  ThreatsEliminatedPair *indexesArrayThreats) {
    std::cout << "Exiting program..." << std::endl;
    delete[] sourceReports;
    delete[] indexesArrayFamilies;
    delete[] indexesArrayThreats;
}

void printAllRecords(StationReport *sourceReports, int size) {
    std::cout << std::string(80, '-') << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "\nRecord #" << i + 1 << ": " << std::endl;
        sourceReports[i].print();
        std::cout << std::string(80, '-') << std::endl;
    }
}
