#include <rational/rational.hpp>

int main()
{
    Rational x, y;

    // Test Case 1
    x = Rational{ 1, 2 };
    y = Rational{ 3, 4 };
    std::cout << x << " + " << y << " == " << x + y << " Expected: {5, 4}\n";

    // Test Case 2
    x = Rational{ 3, 5 };
    y = Rational{ 1, 4 };
    std::cout << x << " - " << y << " == " << x - y << " Expected: {7, 20}\n";

    // Test Case 3
    x = Rational{ 2, 3 };
    y = Rational{ 5, 7 };
    std::cout << x << " * " << y << " == " << x * y << " Expected: {10, 21}\n";

    // Test Case 4
    x = Rational{ 3, 5 };
    y = Rational{ 2, 3 };
    std::cout << x << " / " << y << " == " << x / y << " Expected: {9, 10}\n";

    // Test Case 5
    x = Rational{ 1, 2 };
    y = Rational{ 1, 3 };
    std::cout << x << " + " << y << " == " << x + y << " Expected: {5, 6}\n";

    // Test Case 6
    x = Rational{ 5, 8 };
    y = Rational{ 1, 4 };
    std::cout << x << " - " << y << " == " << x - y << " Expected: {3, 8}\n";

    // Test Case 7
    x = Rational{ 2, 3 };
    y = Rational{ 5, 7 };
    std::cout << x << " == " << y << " : " << (x == y) << " Expected: 0\n";

    // Test Case 8
    x = Rational{ 3, 5 };
    y = Rational{ 3, 5 };
    std::cout << x << " == " << y << " : " << (x == y) << " Expected: 1\n";

    // Test Case 9
    x = Rational{ 1, 2 };
    y = Rational{ 3, 4 };
    std::cout << x << " != " << y << " : " << (x != y) << " Expected: 1\n";

    // Test Case 10
    x = Rational{ 3, 5 };
    y = Rational{ 3, 5 };
    std::cout << x << " != " << y << " : " << (x != y) << " Expected: 0\n";

    // Test Case 11
    x = Rational{ 2, 3 };
    y = Rational{ 5, 7 };
    std::cout << x << " < " << y << " : " << (x < y) << " Expected: 1\n";

    // Test Case 12
    x = Rational{ 5, 8 };
    y = Rational{ 1, 4 };
    std::cout << x << " > " << y << " : " << (x > y) << " Expected: 1\n";

    // Test Case 13
    x = Rational{ 3, 5 };
    y = Rational{ 2, 3 };
    std::cout << x << " <= " << y << " : " << (x <= y) << " Expected: 1\n";

    // Test Case 14
    x = Rational{ 5, 8 };
    y = Rational{ 1, 4 };
    std::cout << x << " >= " << y << " : " << (x >= y) << " Expected: 1\n";

    // Test Case 15
    x = Rational{ 2, 3 };
    std::cout << "-(" << x << ") == " << -x << " Expected: {-2, 3}\n";

    // Test Case 16
    x = Rational{ 1, 2 };
    y = Rational{ 3, 4 };
    x += y;
    std::cout <<  x << " += " << y << " => " << x << " Expected: {5, 4}\n";

    // Test Case 17
    x = Rational{ 3, 5 };
    y = Rational{ 1, 4 };
    x -= y;
    std::cout <<  x << " -= " << y << " => " << x << " Expected: {7, 20}\n";

    // Test Case 18
    x = Rational{ 2, 3 };
    y = Rational{ 5, 7 };
    x *= y;
    std::cout <<  x << " *= " << y << " => " << x << " Expected: {10, 21}\n";

    // Test Case 19
    x = Rational{ 3, 5 };
    y = Rational{ 2, 3 };
    x /= y;
    std::cout << x << " /= " << y << " => " << x << " Expected: {9, 10}\n";

    // Test Case 20
    x = Rational{ 1, 2 };
    y = Rational{ 1, 3 };
    std::cout << x << " + " << y << " == " << x + y << " Expected: {5, 6}\n";

    // Test Case 21
    x = Rational{ 5, 8 };
    y = Rational{ 1, 4 };
    std::cout << x << " - " << y << " == " << x - y << " Expected: {3, 8}\n";

    // Test Case 22
    x = Rational{ 2, 3 };
    y = Rational{ 5, 7 };
    std::cout << x << " > " << y << " : " << (x > y) << " Expected: 0\n";

    // Test Case 23
    x = Rational{ 5, 8 };
    y = Rational{ 1, 4 };
    std::cout << x << " < " << y << " : " << (x < y) << " Expected: 0\n";

    // Test Case 24
    x = Rational{ 3, 5 };
    y = Rational{ 2, 3 };
    std::cout << x << " <= " << y << " : " << (x <= y) << " Expected: 1\n";

    // Test Case 25
    x = Rational{ 5, 8 };
    y = Rational{ 1, 4 };
    std::cout << x << " >= " << y << " : " << (x >= y) << " Expected: 1\n";

    // Test Case 26
    x = Rational{ 2, 3 };
    y = Rational{ 2, 3 };
    std::cout << x << " == " << y << " : " << (x == y) << " Expected: 1\n";

    // Test Case 27
    x = Rational{ 2, 3 };
    y = Rational{ 5, 7 };
    std::cout << x << " != " << y << " : " << (x != y) << " Expected: 1\n";

    // Test Case 28
    x = Rational{ 2, 3 };
    std::cout << "-" << x << " : " << (-x) << " Expected: -{2, 3}\n";

    // Test Case 28
    
    try {
        std::cout << "{2, 0}" << " Expected: Divide by zero exception\n";
        x = Rational{ 2, 0 };
    }
    catch (std::overflow_error& e) {
      std::cout << e.what() << '\n';
    }
}
