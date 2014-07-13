#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
public:
    Wheel(): mileage(0) {}
    Wheel(const Wheel & wheel) {*this = wheel;}
    Wheel(Wheel && wheel) {*this = std::move(wheel);}
    ~Wheel() {}
    Wheel & operator = (const Wheel & wheel) {return *this = wheel;}

    int getMileage() {return mileage;}
    void Rotate(int count = 1) {mileage += count;}
protected:
    int mileage;
};

#endif // WHEEL_H
