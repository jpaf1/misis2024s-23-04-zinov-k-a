#ifndef stackarr_hpp
#define stackarr_hpp

#include <iostream>
#include <sstream>
#include <complex/complex.hpp>
#include <cstddef>

class StackArr {
public:
  StackArr() = default;

  StackArr(const StackArr& src);

  StackArr(StackArr&& st) noexcept;
  
  ~StackArr();
  
  StackArr& operator=(const StackArr& src);

  StackArr& operator=(StackArr&& src) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  Complex& Top() &;

  const Complex& Top() const &;

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
  std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
  Complex* data_ = nullptr;   //!< элементы стека
};

#endif /* stackarr_hpp */
