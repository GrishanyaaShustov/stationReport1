#include <iostream>
#include <iomanip>
#include "indexesArrayFuncs.h"


void printStationReportsTable() {
    std::cout << std::left
            << std::setw(2) << "ID"
            << std::setw(5) << " StationNumber"
            << std::setw(5) << " FirstName"
            << std::setw(5) << " LastName"
            << std::setw(5) << " Rank"
            << std::setw(5) << " AirTemp"
            << std::setw(5) << " WindSpeed"
            << std::setw(5) << " ThreatsElim"
            << std::setw(5) << " Date"
            << std::setw(5) << " ReportTime(s)"
            << std::endl;

    std::cout << std::string(110, '-') << std::endl;
}

LastNamePair *createLastNameIndexesArray(StationReport array[], int size) {
    auto *indexesArray = new LastNamePair[size];

    for (int i = 0; i < size; i++) {
        indexesArray[i].index = i;
        indexesArray[i].lastName = array[i].lastName;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (indexesArray[i].lastName > indexesArray[j].lastName) {
                std::ranges::swap(indexesArray[i], indexesArray[j]);
            }
        }
    }

    return indexesArray;
}

ThreatsEliminatedPair *createThreatesElimIndexesArray(StationReport array[], int size) {
    auto *indexesArray = new ThreatsEliminatedPair[size];

    for (int i = 0; i < size; i++) {
        indexesArray[i].index = i;
        indexesArray[i].threatsEliminated = array[i].threatsEliminated;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (indexesArray[i].threatsEliminated < indexesArray[j].threatsEliminated) {
                std::ranges::swap(indexesArray[i], indexesArray[j]);
            }
        }
    }
    return indexesArray;
}

void printSourceArrayData(StationReport r[], int size) {
    std::cout << "\n" << std::endl;
    std::cout << "_____Source Data______" << std::endl;
    printStationReportsTable();
    for (int idx = 0; idx < size; idx++) {
        std::cout << r[idx].reportIndex << " " << r[idx].stationNumber << " " << r[idx].firstName << " " << r[idx].
                lastName << " " << r[idx].rank << " " << r[idx].airTemperature << " " << r[idx].windSpeed << " " << r[
                    idx].threatsEliminated << " " << r[idx].reportDate.tm_year + 1900 << "-" << r[idx].reportDate.tm_mon
                + 1 << "-" << r[idx].reportDate.tm_mday << " " << r[idx].reportTimeSeconds << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void printIndexesArayByLastName(LastNamePair array[], int size) {
    std::cout << "_____Indexes Array By Last Name______" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << array[i].lastName << "(Index: " << array[i].index << ")" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void printSortedArrayByLastName(LastNamePair indexArray[], StationReport r[], int size) {
    std::cout << "_____Sorted By Last Name Data Array______" << std::endl;
    printStationReportsTable();
    for (int i = 0; i < size; i++) {
        int idx = indexArray[i].index;
        std::cout << r[idx].reportIndex << " " << r[idx].stationNumber << " " << r[idx].firstName << " " << r[idx].
                lastName << " " << r[idx].rank << " " << r[idx].airTemperature << " " << r[idx].windSpeed << " " << r[
                    idx].threatsEliminated << " " << r[idx].reportDate.tm_year + 1900 << "-" << r[idx].reportDate.tm_mon
                + 1 << "-" << r[idx].reportDate.tm_mday << " " << r[idx].reportTimeSeconds << std::endl;
    }
}

void printIndexesArrayByThreatsElim(ThreatsEliminatedPair array[], int size) {
    std::cout << "_____Indexes Array By Eliminated Threads Count______" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << array[i].threatsEliminated << "(Index: " << array[i].index << ")" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void printSortedArrayByThreatsElim(ThreatsEliminatedPair indexArray[], StationReport r[], int size) {
    std::cout << "_____Sorted By Threats Eliminated Count Array______" << std::endl;
    printStationReportsTable();
    for (int i = 0; i < size; i++) {
        int idx = indexArray[i].index;
        std::cout << r[idx].reportIndex << " " << r[idx].stationNumber << " " << r[idx].firstName << " " << r[idx].
                lastName << " " << r[idx].rank << " " << r[idx].airTemperature << " " << r[idx].windSpeed << " " << r[
                    idx].threatsEliminated << " " << r[idx].reportDate.tm_year + 1900 << "-" << r[idx].reportDate.tm_mon
                + 1 << "-" << r[idx].reportDate.tm_mday << " " << r[idx].reportTimeSeconds << std::endl;
    }
}
