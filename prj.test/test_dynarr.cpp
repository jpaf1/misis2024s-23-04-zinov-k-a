#include <dynarr/dynarr.hpp>

int main() {
    std::cout << "Test for DynArr(const std::ptrdiff_t size): ";
    //test 1
    try {
        DynArr da = DynArr(0);
    } catch (std::invalid_argument) {
        std::cout << "test 1 is ok\n";
    }
    
    std::cout << "Test for DynArr(const std::ptrdiff_t size) and Size(): ";
    //test 2
    DynArr da = DynArr(5);
    if (da.Size() == 5) std::cout << "test 2 is ok\n";
    else std::cout << "test 2 is error\n";
    
    std::cout << "Test for DynArr(const std::ptrdiff_t size) and operator[]: ";
    //test 3
    if (da[3] == 0) std::cout << "test 3 is ok\n";
    else std::cout << "test 3 is error\n";
    
    std::cout << "Test for DynArr(const std::ptrdiff_t size) and Capacity(): ";
    //test 4
    if (da.Capacity() == 10) std::cout << "test 4 is ok\n";
    else std::cout << "test 4 is error\n";
    
    std::cout << "Test for operator[]: ";
    //test 5
    da[3] = 1;
    if (da[3] == 1) std::cout << "test 5 is ok\n";
    else std::cout << "test 5 is error\n";
    
    std::cout << "Test for DynArr(const DynArr& rhs): ";
    //test 6
    DynArr da1 = DynArr(da);
    if (da1.Capacity() == 10 and da1.Size() == 5 and da1[3] == 1) std::cout << "test 6 is ok\n";
    else std::cout << "test 6 is error\n";
    
    std::cout << "Tests for Resize(): ";
    //test 7
    int ok = 0;
    da[4] = 1;
    
    da.Resize(4);
    try {
        da[4] = 1;
    } catch (std::out_of_range) {
        ok++;
    }
    
    da.Resize(5);
    try {
        if (da[4] == 0) ok++;
    } catch (std::out_of_range) {}
    
    da.Resize(15);
    try {
        if (da[14] == 0) ok++;
    } catch (std::out_of_range) {}
    
    if (ok == 3) std::cout << "test 7 is ok\n";
    else std::cout << "test 7 is error\n";
    
    std::cout << "Test for operator=: ";
    //test 8
    DynArr da2 = DynArr();
    da1[0] = 5;
    da2 = da1;
    if (da2.Capacity() == 10 and da2.Size() == 5 and da2[3] == 1) std::cout << "test 8 is ok\n";
    else std::cout << "test 8 is error\n";
    
    std::cout << "Test for operator<<: ";
    //test 8
    std::cout <<"da1: " << da1 << "da2: " << da2 << "\n";
}

