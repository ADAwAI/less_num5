#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
//using namespace std;

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    // Конструктор с параметрами
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    // Метод для формирования строки адреса
    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    // Добавляем метод для получения названия города и дальнейшей сортировки
    std::string getCity() const {
        return city;
    }
};

// Функция сравнения для сортировки адресов по городу
bool compareByCity(const Address& a, const Address& b) {
    return a.getCity() < b.getCity();
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream inFile("in.txt");
    std::ofstream outFile("out.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return 1;
    }

    int N;
    inFile >> N;
    inFile.ignore(); // Пропускаем перевод строки после числа N

    std::vector<Address> addresses;

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        std::getline(inFile, city);
        std::getline(inFile, street);
        inFile >> houseNumber >> apartmentNumber;
        inFile.ignore(); // Пропускаем перевод строки после номера квартиры

        addresses.emplace_back(city, street, houseNumber, apartmentNumber);
    }

    // Сортируем адреса по названию города
    std::sort(addresses.begin(), addresses.end(), compareByCity);

    outFile << N << std::endl;

    for (int i = 0; i < N; ++i) {
        outFile << addresses[i].getOutputAddress() << std::endl;
    }

    return 0;
}
