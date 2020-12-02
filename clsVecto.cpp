#include <iostream>
using namespace std;
class Vecto {
        int n;
        int *data;
    public:
        Vecto(int m= 3);
        ~Vecto();
        Vecto(const Vecto&);
        Vecto operator + (const Vecto &x);
        int &operator [] (int i)const {return data[i];}
        const Vecto &operator = (const Vecto &x);
        friend Vecto operator - (const Vecto &x, const Vecto &y);
        friend istream &operator >>(istream &in, Vecto &x);
        friend ostream &operator <<(ostream &out, const Vecto &x);
};
Vecto::Vecto(int m):n(m){
    data = new int [m];
}
Vecto::~Vecto(){
    delete [] data;
}
Vecto::Vecto(const Vecto& x):n(x.n){
    data = new int [n];
    for(int i =0; i<n; i++)
        this->data[i] = x[i];
}
istream &operator >>(istream &in, Vecto &x){
    for(int i=0; i<x.n; i++){
        cout<<"Toa do thu "<<i<<":"; in>>x[i];
    }
    return in;
}
ostream &operator <<(ostream &out, const Vecto &x){
    out<<"(";
    for(int i=0; i<x.n-1; i++)
        out<<x[i]<<",";
    out<<x[x.n-1]<<")"<<endl;
    return out;
}
Vecto Vecto::operator + (const Vecto &x){
    Vecto t(this->n);
    for(int i=0; i<n; i++)
        t[i] = data[i] + x[i];
    return t;
}
Vecto operator - (const Vecto &x, const Vecto &y){
    Vecto t(x.n);
    for(int i=0; i<x.n; i++)
        t[i] = x[i] - y[i];
    return t;
}
const Vecto &Vecto::operator = (const Vecto &x){
    if (this != &x){
    n = x.n;
    delete [] data;
    data = new int [n];
    for (int i=0; i<n; i++) data[i] = x[i];
    }
    return *this;
}

int main(){
    Vecto a, b;
    cout<<"Nhập toạ độ của vecto a:"<<endl;
    cin>>a;
    cout<<"Nhập toạ độ của vecto b:"<<endl;
    cin>>b;
    Vecto c;
    c = a;
    c[1] = 5;
    cout<<"Vecto a:"<<a;
    cout<<"Vecto a:"<<b;
    cout<<"Vecto tong a + b:"<<a+b;
    cout<<"Vecto tong a - b:"<<a-b;
    cout<<"Vecto c:"<<c;
}