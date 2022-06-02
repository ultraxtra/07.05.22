
#include <iostream>
using namespace std;

template <class T1, class T2>
class Base
{

protected:
    T1 VALUE1;
    T2 VALUE2;

public:

    Base() : VALUE1(0), VALUE2(0) { }
    Base(T1 value1, T2 value2) : VALUE1(value1), VALUE2(value2) { }

    void Print() {
        cout << "VALUE1 = " << VALUE1 << endl
            << "VALUE2 = " << VALUE2 << endl;
    }

    ~Base() { }
};

template <class T1, class T2, class T3, class T4>
class Child : public Base<T1, T2> {

protected:
    T3 VALUE3;
    T4 VALUE4;

public:
    Child() : VALUE3(0), VALUE4(0) {}

    Child(T1 value1, T2 value2, T3 value3, T4 value4) : Base(value3, value4), VALUE3(value3), VALUE4(value4) {}

    void Print() {
        Base::Print();
        cout << "VALUE3 = " << VALUE3 << endl << "VALUE4 = " << VALUE4 << endl;
    }

    ~Child() { }
};

template <class T1, class T2, class T3, class T4, class T5, class T6>
class Child2 :public Base<T1, T2>, public Child <T1, T2, T3, T4> {

protected:
    T5 VALUE5;
    T6 VALUE6;

public:
    Child2() : VALUE5(0), VALUE6(0) {}

    Child2(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6) : Child(value3, value4), VALUE5(value5), VALUE6(value6) {}

    void Print() {
        Base::Print();
        Child::Print();
        cout << "VALUE5 = " << VALUE5 << endl << "VALUE6 = " << VALUE6 << endl;
    }

    ~Child2() { }
};

int main() {

    cout << "Class Base : " << endl;
    Base <int, int> A(1, 2);
    A.Print();
    Base <double, double> B(1.1, 2.2);
    B.Print();
    Base <char, char> C("qwerty", "qwerty2");
    C.Print();
    cout << "Class Child : " << endl;
    Child <int, int, int, int> D(1, 2, 3, 4);
    C.Print();
    Child <double, double, double, double> E(1.1, 2.2, 3.3, 4.4);
    E.Print();
    Child <char, char, char, char> F("qwerty", "qwerty2", "qwerty3", "qwerty4");
    F.Print();
    cout << "Class Child2 : " << endl;
    Child2 <int, int, int, int, int, int> G(1, 2, 3, 4, 5, 6);
    G.Print();
    Child2 <double, double, double, double, double, double> H(1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
    H.Print();
    Child2 <char, char, char, char, char, char> I("qwerty", "qwerty2", "qwerty3", "qwerty4", "qwerty5", "qwerty6");
    I.Print();

    return 0;
}