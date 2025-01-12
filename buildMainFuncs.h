#ifndef BUILDMAINFUNCS_H
#define BUILDMAINFUNCS_H

#include "stationReport.h"

void printSortedData(StationReport *sourceReports, LastNamePair *indexesArrayFamilies,
                     ThreatsEliminatedPair *indexesArrayThreats, int size);

void searchData(StationReport *sourceReports, LastNamePair *indexesArrayFamilies,
                ThreatsEliminatedPair *indexesArrayThreats, int size);

void updateStationReportRecord(StationReport *&reports, LastNamePair *&indexesArrayFamilies, ThreatsEliminatedPair *&indexesArrayThreats, int size);

void deleteStationReport(StationReport *&reports, LastNamePair *&indexesArrayFamilies,
                         ThreatsEliminatedPair *&indexesArrayThreats, int &size);

void cleanMemmory(StationReport *sourceReports, LastNamePair *indexesArrayFamilies,
                  ThreatsEliminatedPair *indexesArrayThreats);

void printAllRecords(StationReport *sourceReports, int size);

#endif //BUILDMAINFUNCS_H
