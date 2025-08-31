#include <iostream>
#include <vector>
#include <cassert>

struct base_matrix
{
  base_matrix ( int sz, int total_size)
              : storage(total_size), size(sz)
  {}

  [[nodiscard]] int height() const { return size;     }
  [[nodiscard]] int width()  const { return height(); }

  [[nodiscard]] virtual double get(int, int) const = 0;
  virtual void   set(int, int, double) = 0;

  protected:
  std::vector<double> storage;
  int size;
};

struct dense_matrix : public base_matrix
{
  explicit dense_matrix(int n) : base_matrix(n, n*n) {}

  [[nodiscard]] double get(int l, int c) const override
  {
    return storage[c + l * width()];
  }

  void set(int l, int c, double v)  override
  {
    storage[c + l * width()] = v;
  }
};

struct diagonal_matrix : public base_matrix
{
  explicit diagonal_matrix(int n) : base_matrix(n,n) {}

  [[nodiscard]] double get(int l, int c) const override
  {
    if(l == c)  return storage[c];
    else        return 0.;
  }

  void set(int l, int c, double v) override
  {
    assert(   l == c
          &&  "access to diagonal matrix requires similar row and col"
          );
    if(l == c) storage[c] = v;
  }
};

int main()
{
  dense_matrix d(3);

  for(int l = 0;l<d.height();++l)
    for(int c = 0;c<d.width();c++)
      d.set(l,c, (1+c) + 100.*(l+1));

  for(int l = 0;l<d.height();++l)
  {
    for(int c = 0;c<d.width();c++)
      std::cout << d.get(l,c) << " ";
    std::cout << "\n";
  }

  diagonal_matrix dg(3);

  for(int l = 0;l<dg.height();++l)
    dg.set(l,l, (1+l) + 100.*(l+1));

  for(int l = 0;l<dg.height();++l)
  {
    for(int c = 0;c<dg.width();c++)
      std::cout << dg.get(l,c) << " ";
    std::cout << "\n";
  }
}
