#include "stationReport.h"

StationReport *binarySearchByFamilieRecursive(LastNamePair *familieIndexArray, StationReport *sourceReports,
                                              std::string key, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    int mid = left + (right - left) / 2;

    if (familieIndexArray[mid].lastName == key) {
        return &sourceReports[familieIndexArray[mid].index];
    } else if (familieIndexArray[mid].lastName < key) {
        return binarySearchByFamilieRecursive(familieIndexArray, sourceReports, key, mid + 1, right);
    } else {
        return binarySearchByFamilieRecursive(familieIndexArray, sourceReports, key, left, mid - 1);
    }
}

StationReport *binarySearchByElimThreads(ThreatsEliminatedPair *threatsElimPair, StationReport *sourceReports, int key,
                                         int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (threatsElimPair[mid].threatsEliminated == key) {
            return &sourceReports[threatsElimPair[mid].index];
        } else if (threatsElimPair[mid].threatsEliminated > key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nullptr;
}

StationReport *binarySearchByReportId(StationReport *sourceReports, int keyId, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sourceReports[mid].reportIndex == keyId) {
            return &sourceReports[mid];
        } else if (sourceReports[mid].reportIndex < keyId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nullptr;
}
