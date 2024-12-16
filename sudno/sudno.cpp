#include <iostream>
#include <string>
using namespace std;

// Базовый класс "Транспортное средство"
class Transport {
protected:
    string name;       // Название транспорта
    double weight;     // Вес транспорта
    double fuelUsage;  // Расход топлива

public:
    Transport(string n, double w, double fuel) : name(n), weight(w), fuelUsage(fuel) {}

    // Виртуальный метод для расчета стоимости доставки
    virtual double deliveryCost() = 0;

    // Виртуальный метод для отображения информации
    virtual void showDetails() {
        cout << "Transport: " << name << endl;
        cout << "Weight: " << weight << " kg\n";
        cout << "Fuel consumption: " << fuelUsage << " l/100 km\n";
    }
};

// Производный класс "Автомобиль"
class Car : public Transport {
private:
    int passengers; // Количество пассажиров

public:
    Car(string n, double w, double fuel, int p)
        : Transport(n, w, fuel), passengers(p) {
    }

    // Переопределение метода расчета стоимости доставки
    double deliveryCost() override {
        // Примерная формула для стоимости доставки для автомобиля
        return (weight / 1000) * fuelUsage * 10;  // Стоимость зависит от веса и расхода топлива
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Number of passengers: " << passengers << "\n";
    }
};

// Производный класс "Самолет"
class Plane : public Transport {
private:
    int passengers; // Количество пассажиров

public:
    Plane(string n, double w, double fuel, int p)
        : Transport(n, w, fuel), passengers(p) {
    }

    // Переопределение метода расчета стоимости доставки
    double deliveryCost() override {
        // Примерная формула для стоимости доставки для самолета
        return (weight / 10000) * fuelUsage * 100;  // Стоимость зависит от веса и расхода топлива
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Number of passengers: " << passengers << "\n";
    }
};

// Производный класс "Судно"
class Ship : public Transport {
private:
    int passengers; // Количество пассажиров

public:
    Ship(string n, double w, double fuel, int p)
        : Transport(n, w, fuel), passengers(p) {
    }

    // Переопределение метода расчета стоимости доставки
    double deliveryCost() override {
        // Примерная формула для стоимости доставки для судна
        return (weight / 5000) * fuelUsage * 50;  // Стоимость зависит от веса и расхода топлива
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Number of passengers: " << passengers << "\n";
    }
};

// Производный класс "Грузовик"
class Truck : public Transport {
private:
    double cargoWeight; // Грузоподъемность

public:
    Truck(string n, double w, double fuel, double c)
        : Transport(n, w, fuel), cargoWeight(c) {
    }

    // Переопределение метода расчета стоимости доставки
    double deliveryCost() override {
        // Примерная формула для стоимости доставки для грузовика
        return (cargoWeight / 1000) * fuelUsage * 5;  // Стоимость зависит от груза и расхода топлива
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Cargo capacity: " << cargoWeight << " kg\n";
    }
};

// Главная функция
int main() {
    // Создание объектов различных транспортных средств через указатели на базовый класс
    Transport* car = new Car("Passenger car", 1500, 8, 4);
    Transport* plane = new Plane("Passenger plane", 50000, 3000, 200);
    Transport* ship = new Ship("Passenger ship", 200000, 500, 1000);
    Transport* truck = new Truck("Truck", 8000, 20, 12000);

    // Вывод информации и расчет стоимости доставки
    cout << "\nCar information:\n";
    car->showDetails();
    cout << "Delivery cost: " << car->deliveryCost() << " units\n";

    cout << "\nPlane information:\n";
    plane->showDetails();
    cout << "Delivery cost: " << plane->deliveryCost() << " units\n";

    cout << "\nShip information:\n";
    ship->showDetails();
    cout << "Delivery cost: " << ship->deliveryCost() << " units\n";

    cout << "\nTruck information:\n";
    truck->showDetails();
    cout << "Delivery cost: " << truck->deliveryCost() << " units\n";

    // Освобождение памяти
    delete car;
    delete plane;
    delete ship;
    delete truck;

    return 0;
}
