#include <chrono>
#include <iostream>
#include <limits>
#include "createReport.h"
#include "buildMainFuncs.h"
#include "stationReport.h"
#include "indexesArrayFuncs.h"
#include "searchFuncs.h"

// TEST DATA Раскоментировать при использовании тестовых данных
int size = 4;
StationReport report1 = {1, 1, "Grigoriy", "Shustov", "Senior inspector", 32.5, 12.1, 4, getDate(2024,12,24),80000};
StationReport report2 = {2, 3, "Ivan", "Ivanov", "Junior inspector", 31.2, 9.1, 2, getDate(2024,12,21),72000};
StationReport report3 = {3, 2, "Petr", "Petrovich", "Firefighter", 21, 4, 3, getDate(2024,12,12),77777};
StationReport report4 = {4, 32, "Magnus", "Carlsen", "Senior inspector", 12, 1.8, 9, getDate(2025,1,1),69321};
StationReport* sourceReports = {new StationReport[size]{report1, report2, report3, report4}};
// TEST DATA

int main() {

    LastNamePair* indexesArrayFamilies = createLastNameIndexesArray(sourceReports, size);
    ThreatsEliminatedPair* indexesArrayThreats = createThreatesElimIndexesArray(sourceReports, size);

    while (true) {
        StationReport* searchResult = nullptr;
        bool isIndexesChanged = false;

        std::string deletedLastName;
        int deletedThreats;

        std::cout << "\nChose task: " << std::endl;
        std::cout << "1. Print sorted data" << std::endl;
        std::cout << "2. Search data by keys values" << std::endl;
        std::cout << "3. Changing array records" << std::endl;
        std::cout << "4. Delete an record by the value of one of the key attributes" << std::endl;
        std::cout << "5. Print all records from array" << std::endl;
        std::cout << "6. Exit program" << std::endl;

        std::cout << "Enter task number: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {

            case 1:
                printSortedData(sourceReports, indexesArrayFamilies, indexesArrayThreats, size);
                break;

            case 2:
                searchResult = searchData(sourceReports, indexesArrayFamilies, indexesArrayThreats, size);
                if (searchResult) {
                    std::cout << "Found record:\n" << std::endl;
                    searchResult->print();
                }
                else std::cout << "\nNo record found." << std::endl;
                break;

            case 3:
                int idChoice;
                std::cout << "To change one of the array records, \nenter its ID (the value of the Report id field, i.e. the sequence number in the array)" << std::endl;
                std::cout << "Enter report ID: ";
                std::cin >> idChoice;

                searchResult = binarySearchByReportId(sourceReports, idChoice, size);
                if (searchResult) {
                    std::cout << "\nRecord is founded!" << std::endl;
                    updateStationReportRecord(searchResult, isIndexesChanged);
                    if (isIndexesChanged) {
                        indexesArrayFamilies = createLastNameIndexesArray(sourceReports, size);
                        indexesArrayThreats = createThreatesElimIndexesArray(sourceReports, size);
                    }
                }
                else std::cout << "\nRecord is not found =(" << std::endl;
                break;

            case 4:
                int deleteChoice;
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
                        searchResult = binarySearchByFamilieRecursive(indexesArrayFamilies, sourceReports, deletedLastName, 0, size);
                        if (searchResult) {
                            std::cout << "Deleted record by last name was found!\n" << std::endl;
                            searchResult->print();
                            deleteStationReport(sourceReports, searchResult->reportIndex, size);
                            indexesArrayFamilies = createLastNameIndexesArray(sourceReports, size);
                            indexesArrayThreats = createThreatesElimIndexesArray(sourceReports, size);
                            std::cout << "\nThe record was deleted successfully" << std::endl;
                        }
                        else std::cout << "\nDeleted record by last name was not found." << std::endl;
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
                        searchResult = binarySearchByElimThreads(indexesArrayThreats, sourceReports, deletedThreats, size);
                        if (searchResult) {
                            std::cout << "Deleted record by eliminated threats quantity was found!\n" << std::endl;
                            searchResult->print();
                            deleteStationReport(sourceReports, searchResult->reportIndex, size);
                            indexesArrayFamilies = createLastNameIndexesArray(sourceReports, size);
                            indexesArrayThreats = createThreatesElimIndexesArray(sourceReports, size);
                            std::cout << "\nThe record was deleted successfully" << std::endl;
                        }
                        else std::cout << "\nDeleted record by eliminated threats quantity was not found." << std::endl;
                        break;
                }
                break;


            case 5:
                printAllRecords(sourceReports, size);
                break;

            case 6:
                std::cout << "Exiting program..." << std::endl;
                cleanMemmory(sourceReports, indexesArrayFamilies, indexesArrayThreats);
                return 0;

            default:
                std::cout << "Incorrect choice, try again.\n";
                break;
        }
    }
}