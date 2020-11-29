#include "bds.h"

Dat::Dat(string msd="", double dongia=0)
{
    this->msd = msd;
    this->dongia = dongia;
}
DatHCN::DatHCN(string msd="", double dongia=0, double dai=0, double rong=0) : Dat(msd, dongia)
{
    this->msd = msd;
    this->dongia = dongia;
    this->dai = dai;
    this->rong = rong;
}
void DatHCN::inputInfo()
{
    cin.ignore();
    cout << "Nhap vao MaSoDat: ";
    getline(cin, this->msd);
    cout << "Nhap vao Don gia moi m2: ";
    cin >> this->dongia;
    cout << "Nhap vao chieu dai: ";
    cin >> this->dai;
    cout << "Nhap vao chieu rong: ";
    cin >> this->rong;
}
double DatHCN::DienTich()
{
    return this->dai * this->rong;
}
double DatHCN::GiaTien()
{
    return this->dongia * this->DienTich();
}
void DatHCN::outInfo()
{
    cout << "MSD: " << this->msd <<"\t";
    cout << "Don Gia: " << this->dongia <<"\t";
    cout << "Chieu Dai: " << this->dai <<"\t";
    cout << "Chieu Rong: " << this->rong <<"\t";
    cout << "Dien tich: " << this->DienTich() <<"\t";
    cout << "Gia tien: " << this->GiaTien()<<endl;
}

DatTamGiac::DatTamGiac(string msd="", double dongia=0, double day=0, double cao=0) : Dat(msd, dongia)
{
    this->msd = msd;
    this->dongia = dongia;
    this->day = day;
    this->cao = cao;
}
void DatTamGiac::inputInfo()
{
    cin.ignore();
    cout << "Nhap vao MaSoDat: ";
    getline(cin, this->msd);
    cout << "Nhap vao Don gia moi m2: ";
    cin >> this->dongia;
    cout << "Nhap vao day: ";
    cin >> this->day;
    cout << "Nhap vao chieu cao: ";
    cin >> this->cao;
}
double DatTamGiac::DienTich()
{
    return (this->day * this->cao) / 2.0;
}
double DatTamGiac::GiaTien()
{
    return (this->dongia * this->DienTich()) - (this->dongia * this->DienTich() * 0.1);
}
void DatTamGiac::outInfo()
{
    cout << "MSD: " << this->msd <<"\t";
    cout << "Don Gia: " << this->dongia <<"\t";
    cout << "Day: " << this->day <<"\t";
    cout << "Chieu Cao: " << this->cao <<"\t";
    cout << "Dien tich: " << this->DienTich() <<"\t";
    cout << "Gia tien: " << this->GiaTien()<<endl;
}

DatHinhThang::DatHinhThang(string msd="", double dongia=0, double cao=0, double lon=0, double nho=0) : Dat(msd, dongia)
{
    this->msd = msd;
    this->dongia = dongia;
    this->cao = cao;
    this->lon = lon;
    this->nho = nho;
}
void DatHinhThang::inputInfo()
{
    cin.ignore();
    cout << "Nhap vao MaSoDat: ";
    getline(cin, this->msd);
    cout << "Nhap vao Don gia moi m2: ";
    cin >> this->dongia;
    cout << "Nhap vao chieu cao: ";
    cin >> this->cao;
    cout << "Nhap vao cao lon: ";
    cin >> this->lon;
    cout << "Nhap vao cao nho: ";
    cin >> this->nho;
}
double DatHinhThang::DienTich()
{
    return ((this->lon + this->nho) * this->cao) / 2.0;
}
double DatHinhThang::GiaTien()
{
    return (this->dongia * this->DienTich()) - (this->dongia * this->DienTich() * 0.1);
}
void DatHinhThang::outInfo()
{
    cout << "MSD: " << this->msd <<"\t";
    cout << "Don Gia: " << this->dongia <<"\t";
    cout << "Chieu cao: " << this->cao <<"\t";
    cout << "Day lon: " << this->lon <<"\t";
    cout << "Day nho: " << this->nho <<"\t";
    cout << "Dien tich: " << this->DienTich() <<"\t";
    cout << "Gia tien: " << this->GiaTien()<<endl;
}