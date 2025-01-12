//
// Created by grisha shustov on 12.01.2025.
//

#include "deleteArrayElem.h"

#include "indexesArrayFuncs.h"

void deleteArrayElem(StationReport *&reports, LastNamePair *&indexesArrayLastName,
                     ThreatsEliminatedPair *&indexesArrayThreatsElim, int reportID, int &size) {
    auto *newReports = new StationReport[size - 1];

    for (int i = 0; i < reportID - 1; i++) {
        newReports[i] = reports[i];
    }
    for (int i = reportID; i < size; i++) {
        newReports[i - 1] = reports[i];
        newReports[i - 1].reportIndex -= 1;
    }

    delete[] reports;
    reports = newReports;
    --size;

    indexesArrayLastName = createLastNameIndexesArray(reports, size);
    indexesArrayThreatsElim = createThreatesElimIndexesArray(reports, size);
}
