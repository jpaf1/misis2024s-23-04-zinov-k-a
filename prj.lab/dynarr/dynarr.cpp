#include <dynarr/dynarr.hpp>

DynArr::DynArr (const DynArr& rhs)
  : data_(nullptr)
, size_ (rhs.size_)
  , capacity_(rhs.capacity_)
{
    data_ = new float[capacity_];
    for (float* i = rhs.data_;i < rhs.data_ + rhs.size_; i++){
        *(data_ + (i - rhs.data_)) = *i;
    }
}

DynArr::DynArr(const std::ptrdiff_t size)
  : data_(nullptr)
  , size_(size)
  , capacity_(2*size)
{
    if (size <= 0) {
        throw std::invalid_argument("Size should be a positive number");
    }
    else {
        data_ = new float[capacity_];
        for (float* i = data_; i < data_ + size_; i++) {
            *i = 0;
        }
    }
}

DynArr::DynArr(std::initializer_list<float> il) {
    size_=il.size();
    capacity_=2 * il.size();
    data_ = new float[capacity_];
    for (auto i = il.begin(); i < il.end(); i++) {
        *(data_ + (i - il.begin())) = *(i);
    }
}


DynArr::~DynArr() {
    delete[] data_;
    data_ = nullptr;
}

void DynArr::Resize(const std::ptrdiff_t size){
    if (size <= 0) {
        throw std::invalid_argument("Size should be a positive number");
    }
    if (size > capacity_) {
        float* d = new float[size*2];
        for (float* i = d; i < d + size*2; i++) {
            if (i < d+size_) {
                *i = *(data_ + (i-d));
            }
            else {
                *i = 0;
            }
        }
        delete[] data_;
        data_ = d;
        capacity_ = size*2;
    }
    if (size < size_) {
        for (float* i = data_; i < data_ + size_; i++) {
            if (i >= data_ + size) {
                *i = 0;
            }
        }
    }
    size_ = size;
}
    
DynArr& DynArr::operator=(const DynArr& rhs){
    if (this == &rhs) return *this;
    (*this).Resize(rhs.size_);
    for (float* i = rhs.data_;i < rhs.data_ + rhs.size_; i++){
        *(data_ + (i - rhs.data_)) = *i;
    }
    return *this;
}

float& DynArr::operator[](const std::ptrdiff_t idx) {
    if (idx < 0) throw std::invalid_argument("Index should be a non-negative number");
    if (idx >= size_) throw std::out_of_range("Index out of range");
    return *(data_ + idx);
}

const float& DynArr::operator[](const std::ptrdiff_t idx) const {
    if (idx < 0) throw std::invalid_argument("Index should be a non-negative number");
    if (idx > size_) throw std::out_of_range("Index out of range");
    return *(data_ + idx);
}


std::ostream& operator<<(std::ostream& ostrm, const DynArr& rhs) {
    return rhs.Print(ostrm);
}

std::ostream& DynArr::Print(std::ostream& ostrm) const {
    for (float* i = data_; i < data_ + size_; i++) ostrm << (*i) << ' ';
    ostrm << std::endl;
    return ostrm;
}
