#ifndef DELETEARRAYELEM_H
#define DELETEARRAYELEM_H

#include "stationReport.h"

void deleteArrayElem(StationReport *&reports, LastNamePair *&indexesArrayLastName,
                     ThreatsEliminatedPair *&indexesArrayThreatsElim, int reportID, int &size);

#endif //DELETEARRAYELEM_H
