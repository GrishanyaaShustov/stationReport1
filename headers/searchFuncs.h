#ifndef SEARCHFUNCS_H
#define SEARCHFUNCS_H
#include "stationReport.h"

StationReport* binarySearchByFamilieRecursive(LastNamePair* familieIndexArray, StationReport* sourceReports, std::string key, int left, int right);
StationReport* binarySearchByElimThreads(ThreatsEliminatedPair* threatsElimPair, StationReport* sourceReports, int key, int size);
StationReport* binarySearchByReportId(StationReport* sourceReports, int keyId, int size);

#endif //SEARCHFUNCS_H
