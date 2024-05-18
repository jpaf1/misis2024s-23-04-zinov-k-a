#include "rr.hpp"

void RoboRun::GoRun(double x) {
    cx = x;
    cy = 0.0;
    direction.push_back("R");
    values.push_back(x);
}

void RoboRun::GoE(double x) {
    cx = cx + x;
    direction.push_back("E");
    values.push_back(x);
}

void RoboRun::GoW(double x) {
    cx = cx - x;
    direction.push_back("W");
    values.push_back(x);
}

void RoboRun::GoN(double y) {
    cy = cy + y;
    direction.push_back("N");
    values.push_back(y);
}

void RoboRun::GoS(double y) {
    cy = cy - y;
    direction.push_back("S");
    values.push_back(y);
}

void RoboRun::Rev(int n) {
    //if (n > commands.size()) //todo проверка n
    for (int i=0; i<n; i++) {
        std::string c = direction.back();
        if (c == "E") cx = cx - values.back();
        if (c == "W") cx = cx + values.back();
        if (c == "N") cy = cy - values.back();
        if (c == "S") cy = cy + values.back();
        direction.pop_back();
        values.pop_back();
    }
}

void RoboRun::printCoord() const {
    std::cout << "(" << cx << ", " << cy << ")\n";
}
