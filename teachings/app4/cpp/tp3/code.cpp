#include <iostream>
#include <sstream>
#include <complex>
#include <vector>
#include <memory>
#include <cassert>

//------------------------------------------------------------------------------------------
// Implement a number class with the following abstract functions:
//
//  - a print function that takes a std::ostream& as a parameter and returns std::ostream&
//  - A square function that takes no parameters and returns a unique_ptr of number
//------------------------------------------------------------------------------------------
class number
{
};

//------------------------------------------------------------------------------------------
// Complete and correct the following classes so that the tests in the tests() function
// compile and pass successfully.
//------------------------------------------------------------------------------------------
class integer
{
  public:
  integer(std::ptrdiff_t n) : value_(n) {}

  private:
  std::ptrdiff_t value_;
};

class real : public number
{
  public:
  real(double n) : value_(n) {}

  private:
  double value_;
};

class complex : public number
{
  public:
  complex(double r, double i)     : value_(r,i) {}
  complex(std::complex<double> n) : value_(n) {}

  private:
  std::complex<double> value_;
};

void test()
{
  // Test integer::print
  {
    integer i(4);
    i.print(std::cout) << std::endl;

    std::ostringstream str;
    i.print(str);
    assert( str.str() == "Integer(4)");
  }

  // Test real::print
  {
    real    r(3.5);
    r.print(std::cout) << std::endl;

    std::ostringstream str;
    r.print(str);
    assert( str.str() == "Real(3.5)");
  }

  // Test complex::print
  {
    complex z(3.5,-0.25);
    z.print(std::cout) << std::endl;

    std::ostringstream str;
    z.print(str);
    assert( str.str() == "Complex(3.5,-0.25)");
  }

  // Test integer::square
  {
    integer i(4);
    auto p = i.square();
    p->print(std::cout) << std::endl;

    std::ostringstream str;
    p->print(str);
    assert( str.str() == "Integer(16)");
  }

  // Test real::square
  {
    real    r(3.5);
    auto p = r.square();
    p->print(std::cout) << std::endl;

    std::ostringstream str;
    p->print(str);
    assert( str.str() == "Real(12.25)");
  }

  // Test complex::square
  {
    complex z(3,-5);
    auto p = z.square();
    p->print(std::cout) << std::endl;

    std::ostringstream str;
    p->print(str);
    assert( str.str() == "Complex(-16,-30)");
  }
}

double roll(double min, double max)
{
  return (max - min) * (rand() / (1.*RAND_MAX)) + min;
}

//------------------------------------------------------------------------------------------
// Correct the lotsanumbers function so that it compiles and runs without errors.
//------------------------------------------------------------------------------------------
void lotsanumbers(int n)
{
  std::vector<std::unique_ptr<number>> values(n);

  for(auto& p : values)
  {
    auto i = static_cast<int>( roll(0,3) );

    switch(i)
    {
      case 0 : p = roll(1,100); break;
      case 1 : p = std::make_unique<real>(roll(-10,10)); break;
      case 2 : p = std::make_unique<complex>(roll(-5,5),roll(-5,5)); break;
    };
  }

  for(auto const p : values)
    p.print(std::cout) << std::endl;

  for(auto p : values)
    delete p;
}

int main()
{
  test();
  lotsanumbers(10);

  return 0;
}
