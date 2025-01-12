#ifndef INDEXARRAYFUNCS_H
#define INDEXARRAYFUNCS_H

#include "stationReport.h"

void printStationReportsTable(); // Выводит табличку с названиями элементов структуры StationReport
LastNamePair* createLastNameIndexesArray(StationReport array[], int size); // Вовзращает динамический индекс-массив с фамилиями
ThreatsEliminatedPair* createThreatesElimIndexesArray(StationReport array[], int size); // Вовзращает динамический индекс-массив с количеством устраненных угроз
void printSourceArrayData(StationReport r[], int size); // Вывоводит массив исходных данных
void printIndexesArayByLastName(LastNamePair array[], int size); //Выводит индекс-массив по фамилии
void printSortedArrayByLastName(LastNamePair indexArray[], StationReport r[], int size); // Выводит отсортированный по возрастанию по ключу фамилия массив структур StationReport
void printIndexesArrayByThreatsElim(ThreatsEliminatedPair array[], int size); // Выводит индекс-массив по количеству устраненных угроз
void printSortedArrayByThreatsElim(ThreatsEliminatedPair indexArray[], StationReport r[], int size); // Выводит отсортированный по уменьшению по ключу количество устраненных угроз массив стурктур StationReport

#endif //INDEXARRAYFUNCS_H
