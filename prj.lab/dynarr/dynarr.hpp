#ifndef dynarr_hpp
#define dynarr_hpp

#include <iostream>
#include <cstdint>
#include <sstream>


class DynArr {
private:
    float* data_{nullptr};
    std::ptrdiff_t size_{0};
    std::ptrdiff_t capacity_{0};
    
public:
    DynArr() = default;
    DynArr(const DynArr& rhs);
    DynArr(const std::ptrdiff_t size);
    DynArr(std::initializer_list<float> il);
    ~DynArr();
    
    DynArr& operator=(const DynArr&);
    std::ptrdiff_t Size() const noexcept { return size_; }
    std::ptrdiff_t Capacity() const noexcept { return capacity_; }
    void Resize(const std::ptrdiff_t size);
    
    float& operator[](const std::ptrdiff_t idx);
    const float& operator[](const std::ptrdiff_t idx) const;
    
    std::ostream& Print(std::ostream& ostrm) const;
};

std::ostream& operator<<(std::ostream& ostrm, const DynArr& rhs);

#endif /* dynarr_hpp */
