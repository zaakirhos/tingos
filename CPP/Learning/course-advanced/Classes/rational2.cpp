// rational2.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-03 for CppAdv
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
    Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
    ~Rational ();
    int numerator() const { return _n; };
    int denominator() const { return _d; };
    Rational & operator = ( const Rational & );
    operator std::string () const;
};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational::operator std::string() const {
    if(_d == 1) return std::to_string(_n);
    else return std::to_string(_n) + "/" +  std::to_string(_d);
}

Rational operator + ( const Rational & lhs, const Rational & rhs ) {
    return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator - ( const Rational & lhs, const Rational & rhs ) {
    return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator * ( const Rational & lhs, const Rational & rhs ) {
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Rational operator / ( const Rational & lhs, const Rational & rhs ) {
    return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

Rational::~Rational() {
    _n = 0; _d = 1;
}

// for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {
    return o << std::string(r);
}

int main() {
    
    Rational a = 7;        // 7/1
    cout << "a is: " << a << endl;
    Rational b(5, 3);    // 5/3
    cout << "b is: " << b << endl;
    Rational c = b;        // copy constructor
    cout << "c is: " << c << endl;
    Rational d;            // default constructor
    cout << "d is: " << d << endl;
    d = c;                // assignment operator
    cout << "d is: " << d << endl;
    Rational & e = d;    // reference
    d = e;                // assignment to self!
    cout << "e is: " << e << endl;
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    string s = "Rational value is: "; 
    s +=b;
    std::cout << s << std::endl;
    return 0;
}
