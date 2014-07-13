#ifndef TRACTOR_H
#define TRACTOR_H

#include <vector>
#include "Wheel.h"

class Tractor {
public:
    Tractor(): wheels(std::vector<Wheel>(4)) {}
    Tractor(const Tractor & tractor) {*this = tractor;}
    Tractor(Tractor && Tractor) {*this = std::move(Tractor);}
    ~Tractor() {}
    Tractor & operator = (const Tractor & tractor) {return *this = tractor;}

    void Go(int);
    int Mileage();
protected:
    std::vector<Wheel> wheels;
};

int Tractor::Mileage() {
    int temp{0};
    for (std::vector<Wheel>::iterator i = wheels.begin(); i != wheels.end(); ++i)
        temp += i->getMileage();
    return static_cast<int>(temp / 4);
}

void Tractor::Go(int distance) {
    for (std::vector<Wheel>::iterator i = wheels.begin(); i != wheels.end(); ++i)
        i->Rotate(distance);
}

#endif // TRACTOR_H
