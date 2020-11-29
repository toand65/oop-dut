#include <bits/stdc++.h>
using namespace std;
#ifndef bds_h
#define bds_h
class Dat
{
protected:
    string msd;
    double dongia;
    
public:
    Dat(string, double);
    virtual void inputInfo()=0;
    virtual void outInfo()=0;
    virtual double DienTich()=0;
    virtual double GiaTien()=0;
};
class DatHCN : public Dat
{
private:
    double dai, rong;

public:
    DatHCN(string, double, double, double);
    virtual void inputInfo();
    virtual void outInfo();
    virtual double DienTich();
    virtual double GiaTien();
};
class DatTamGiac : public Dat
{
private:
    double day, cao;

public:
    DatTamGiac(string, double, double, double);
    virtual void inputInfo();
    virtual void outInfo();
    virtual double DienTich();
    virtual double GiaTien();
};
class DatHinhThang : public Dat
{
private:
    double lon, nho, cao;

public:
    DatHinhThang(string, double, double, double, double);
    virtual void inputInfo();
    virtual void outInfo();
    virtual double DienTich();
    virtual double GiaTien();
};
#endif
