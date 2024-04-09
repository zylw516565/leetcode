#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class MyComplex
{
private:
  double real;
  double image;
public:
  double getReal() {return real;}
  double getImage() {return image;}

  void setReal(const double r) {real = r;}
  void setImage(const double i) {image = i;}
public:
  MyComplex(double r = 0, double i = 0):real(r), image(i) {}

  MyComplex& operator=(const MyComplex& rhs) {
    real  = rhs.real;
    image = rhs.image;
    return *this;
  }

  MyComplex& operator-(const MyComplex& rhs) {
    real  -= rhs.real;
    image -= rhs.image;
    return *this;
  }

  MyComplex& operator*(const MyComplex& rhs) {
    real  *= rhs.real;
    image *= rhs.image;
    return *this;
  }
};

std::ostream& operator<<(std::ostream& os, MyComplex& rhs) {
  os << rhs.getReal() << rhs.getImage() << endl;
  return os;
}

std::istream& operator>>(std::istream& is, MyComplex& rhs) {
  double real, image;
  is >> real >> image;
  rhs.setReal(real);
  rhs.setImage(image);
  return is;
}

int main()
{
  MyComplex a,b;
  cin >> a >> b;
  MyComplex c = a - b, d = a * b;
  cout << c << endl;
  cout << d << endl;
}