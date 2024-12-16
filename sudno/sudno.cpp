#include <iostream>
#include <string>
using namespace std;

// ������� ����� "������������ ��������"
class Transport {
protected:
    string name;       // �������� ����������
    double weight;     // ��� ����������
    double fuelUsage;  // ������ �������

public:
    Transport(string n, double w, double fuel) : name(n), weight(w), fuelUsage(fuel) {}

    // ����������� ����� ��� ������� ��������� ��������
    virtual double deliveryCost() = 0;

    // ����������� ����� ��� ����������� ����������
    virtual void showDetails() {
        cout << "Transport: " << name << endl;
        cout << "Weight: " << weight << " kg\n";
        cout << "Fuel consumption: " << fuelUsage << " l/100 km\n";
    }
};

// ����������� ����� "����������"
class Car : public Transport {
private:
    int passengers; // ���������� ����������

public:
    Car(string n, double w, double fuel, int p)
        : Transport(n, w, fuel), passengers(p) {
    }

    // ��������������� ������ ������� ��������� ��������
    double deliveryCost() override {
        // ��������� ������� ��� ��������� �������� ��� ����������
        return (weight / 1000) * fuelUsage * 10;  // ��������� ������� �� ���� � ������� �������
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Number of passengers: " << passengers << "\n";
    }
};

// ����������� ����� "�������"
class Plane : public Transport {
private:
    int passengers; // ���������� ����������

public:
    Plane(string n, double w, double fuel, int p)
        : Transport(n, w, fuel), passengers(p) {
    }

    // ��������������� ������ ������� ��������� ��������
    double deliveryCost() override {
        // ��������� ������� ��� ��������� �������� ��� ��������
        return (weight / 10000) * fuelUsage * 100;  // ��������� ������� �� ���� � ������� �������
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Number of passengers: " << passengers << "\n";
    }
};

// ����������� ����� "�����"
class Ship : public Transport {
private:
    int passengers; // ���������� ����������

public:
    Ship(string n, double w, double fuel, int p)
        : Transport(n, w, fuel), passengers(p) {
    }

    // ��������������� ������ ������� ��������� ��������
    double deliveryCost() override {
        // ��������� ������� ��� ��������� �������� ��� �����
        return (weight / 5000) * fuelUsage * 50;  // ��������� ������� �� ���� � ������� �������
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Number of passengers: " << passengers << "\n";
    }
};

// ����������� ����� "��������"
class Truck : public Transport {
private:
    double cargoWeight; // ����������������

public:
    Truck(string n, double w, double fuel, double c)
        : Transport(n, w, fuel), cargoWeight(c) {
    }

    // ��������������� ������ ������� ��������� ��������
    double deliveryCost() override {
        // ��������� ������� ��� ��������� �������� ��� ���������
        return (cargoWeight / 1000) * fuelUsage * 5;  // ��������� ������� �� ����� � ������� �������
    }

    void showDetails() override {
        Transport::showDetails();
        cout << "Cargo capacity: " << cargoWeight << " kg\n";
    }
};

// ������� �������
int main() {
    // �������� �������� ��������� ������������ ������� ����� ��������� �� ������� �����
    Transport* car = new Car("Passenger car", 1500, 8, 4);
    Transport* plane = new Plane("Passenger plane", 50000, 3000, 200);
    Transport* ship = new Ship("Passenger ship", 200000, 500, 1000);
    Transport* truck = new Truck("Truck", 8000, 20, 12000);

    // ����� ���������� � ������ ��������� ��������
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

    // ������������ ������
    delete car;
    delete plane;
    delete ship;
    delete truck;

    return 0;
}
