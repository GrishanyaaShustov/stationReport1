#ifndef INDEXARRAYFUNCS_H
#define INDEXARRAYFUNCS_H

#include "stationReport.h"

void printStationReportsTable();

LastNamePair *createLastNameIndexesArray(StationReport array[], int size);

ThreatsEliminatedPair *createThreatesElimIndexesArray(StationReport array[], int size);

void printSourceArrayData(StationReport r[], int size);

void printIndexesArayByLastName(LastNamePair array[], int size);

void printSortedArrayByLastName(LastNamePair indexArray[], StationReport r[], int size);

void printIndexesArrayByThreatsElim(ThreatsEliminatedPair array[], int size);

void printSortedArrayByThreatsElim(ThreatsEliminatedPair indexArray[], StationReport r[], int size);


#endif //INDEXARRAYFUNCS_H
