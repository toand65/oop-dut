#include <bits/stdc++.h>
#ifndef cinema_h
#define cinema_h
using namespace std;

class Cinema
{
protected:
    int x, y;
    string **name;
    bool **active;
    int **price;
public:
    Cinema(int, int);
    ~Cinema();

    void Booking();
    bool isActive(int, int);
    int Available();
    int getPrice(int, int);
    int getX() { return x; }
    int getY() { return y; }

    virtual void returnInfo() = 0;
    virtual void Price(int) = 0;
};
class CinemaNormal : public Cinema
{
public:
    // CinemaNormal(int, int);
    using Cinema::Cinema;
    ~CinemaNormal(){    }

    virtual void returnInfo();
    virtual void Price(int);
};
class CinemaVip : public Cinema
{
public:
    // CinemaVip(int, int);
    using Cinema::Cinema;
    ~CinemaVip(){   }

    virtual void returnInfo();
    virtual void Price(int);
};

#endif