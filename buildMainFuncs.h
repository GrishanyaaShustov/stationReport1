#ifndef BUILDMAINFUNCS_H
#define BUILDMAINFUNCS_H

#include "stationReport.h"

void printSortedData(StationReport* sourceReports, LastNamePair* indexesArrayFamilies, ThreatsEliminatedPair* indexesArrayThreats, int size);
StationReport* searchData(StationReport* sourceReports, LastNamePair* indexesArrayFamilies, ThreatsEliminatedPair* indexesArrayThreats, int size);
void updateStationReportRecord(StationReport* report, bool& isIndexesChanged);
void deleteStationReport(StationReport*& reports, int reportID, int& size);
void cleanMemmory(StationReport* sourceReports, LastNamePair* indexesArrayFamilies, ThreatsEliminatedPair* indexesArrayThreats);
void printAllRecords(StationReport* sourceReports, int size);

#endif //BUILDMAINFUNCS_H
