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
StationReport report1 = {1, 1, "Grigoriy", "Shustov", "Senior inspector", 32.5, 12.1, 4, getDate(2024, 12, 24), 80000};
StationReport report2 = {2, 3, "Ivan", "Ivanov", "Junior inspector", 31.2, 9.1, 2, getDate(2024, 12, 21), 72000};
StationReport report3 = {3, 2, "Petr", "Petrovich", "Firefighter", 21, 4, 3, getDate(2024, 12, 12), 77777};
StationReport report4 = {4, 32, "Magnus", "Carlsen", "Senior inspector", 12, 1.8, 9, getDate(2025, 1, 1), 69321};
StationReport *sourceReports = {new StationReport[size]{report1, report2, report3, report4}};
// TEST DATA

int main() {
    LastNamePair *indexesArrayFamilies = createLastNameIndexesArray(sourceReports, size);
    ThreatsEliminatedPair *indexesArrayThreats = createThreatesElimIndexesArray(sourceReports, size);

    while (true) {
        bool isIndexesChanged = false;

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
                searchData(sourceReports, indexesArrayFamilies, indexesArrayThreats, size);
                break;

            case 3:
                updateStationReportRecord(sourceReports, indexesArrayFamilies, indexesArrayThreats, size);
                break;

            case 4:
                deleteStationReport(sourceReports, indexesArrayFamilies, indexesArrayThreats, size);
                break;

            case 5:
                printAllRecords(sourceReports, size);
                break;

            case 6:
                cleanMemmory(sourceReports, indexesArrayFamilies, indexesArrayThreats);
                return 0;

            default:
                std::cout << "Incorrect choice, try again.\n";
                break;
        }
    }
}
