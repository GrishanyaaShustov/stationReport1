#ifndef STATIONREPORT_H
#define STATIONREPORT_H

 #include <string>
#include <ctime>
#include <iomanip>

struct StationReport {

    int reportIndex {};
    unsigned int stationNumber {}; // Номер станции
    std::string firstName {}; // Имя сотрудника
    std::string lastName {}; // Фамилия сотрудника
    std::string rank {}; // Ранг сотрудника
    float airTemperature {}; // Температура воздуха (цельсии)
    float windSpeed {}; // Скорость ветра (метры в сек)
    unsigned int threatsEliminated {}; // Количество устраненных угроз
    std::tm reportDate {}; // Дата отчета
    unsigned int reportTimeSeconds {}; // Время отправки отчета в секундах от начала суток

    void print() const;

};

// Индекс-массив для ключевого атрибута "Фамилия"
struct LastNamePair {
    int index;
    std::string lastName;
};

// Индекс-массив для ключевого атрибута "Количество устраненных угроз"
struct ThreatsEliminatedPair {
    int index;
    unsigned threatsEliminated;
};

std::tm getDate(int year, int month, int day);
bool isValidDate(int year, int month, int day);


#endif //STATIONREPORT_H
