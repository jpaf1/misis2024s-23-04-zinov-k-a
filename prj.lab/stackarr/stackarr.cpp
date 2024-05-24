#include <stackarr/stackarr.hpp>

#if 1
StackArr::StackArr(StackArr&& st) noexcept {
  std::swap(st.size_, size_);
  std::swap(st.i_top_, i_top_);
  std::swap(st.data_, data_);
}
#else
StackArr::StackArr(StackArr&& st) noexcept
  : StackArr(st) {
}
#endif

StackArr::StackArr(const StackArr& src)
: i_top_(src.i_top_) {
    if (src.i_top_ > 0) {
        size_ = src.size_;
        data_ = new Complex[size_];
        std::copy(src.data_, src.data_ + i_top_ + 1, data_);
    }
}

StackArr::~StackArr() {
  delete[] data_;
}

StackArr& StackArr::operator=(const StackArr& src) {
    if (this != &src) {
        if (src.i_top_ < 0) { Clear();}
        if (size_ < src.i_top_) {
            size_ = src.size_;
            Complex* buf = new Complex[size_];
            std::swap(data_, buf);
            delete[] buf;
        }
        i_top_ = src.i_top_;
        std::copy(src.data_, src.data_ + i_top_ + 1, data_);
    }
    return *this;
}

StackArr& StackArr::operator=(StackArr&& src) noexcept {
  if (this != &src) {
      if (!src.IsEmpty()) {
    std::swap(size_, src.size_);
    std::swap(i_top_, src.i_top_);
    std::swap(data_, src.data_);
      } else {
        Clear();
      }
  }
  return *this;
}

bool StackArr::IsEmpty() const noexcept {
  return i_top_ < 0;
}

void StackArr::Clear() noexcept {
  i_top_ = -1;
}

void StackArr::Push(const Complex& val) {
    if (data_ == nullptr) {
        size_ = 1;
        data_ = new Complex[size_];
    }
    if (size_ == i_top_ + 1) {
        size_ = size_ * 2;
        Complex* buf = new Complex[size_];
        std::copy(data_, data_ + size_, buf);
        std::swap(data_, buf);
        delete[] buf;
    }
    i_top_ = i_top_ + 1;
    data_[i_top_] = val;
}


Complex& StackArr::Top() & {
  if (i_top_ < 0) {
    throw std::logic_error("StackArr - try get top form empty stack.");
  }
  return data_[i_top_];
}

const Complex& StackArr::Top() const & {
  if (i_top_ < 0) {
    throw std::logic_error("StackArr - try get top form empty stack.");
  }
  return data_[i_top_];
}

void StackArr::Pop() noexcept {
  if (!IsEmpty()) {
    i_top_ -= 1;
  }
}
