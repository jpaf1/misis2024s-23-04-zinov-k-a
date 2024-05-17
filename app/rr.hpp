#ifndef rr_hpp
#define rr_hpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class RoboRun {
public:
    RoboRun() = default;
    RoboRun(const RoboRun& rhs);
    
    void GoRun(double x);
    void GoN(double y);
    void GoS(double y);
    void GoE(double x);
    void GoW(double x);
    void Rev(int n);
    void printCoord() const;
    
private:
    double cx{0.0};
    double cy{0.0};
    std::vector<std::string> direction;
    std::vector<double> values;
};

class Comands : RoboRun
{
    //todo команды обработки потока
};


#endif /* rr_hpp */
