#include <iostream>

int main() {
int n = 0;
std::cin >> n;
int x = 0;
for (int i = 0;i<n;i++){
    char s;
    std::cin >> s;
    if (s =='+'){
        x++;
    }
    if (s == '-'){
        x--;
    }
    std::cin >> s;
    std::cin >> s;
    if (s == '+'){
        x++;
    }
    if (s == '-'){
        x--;
    }
}
std::cout << x << std::endl;

return 0;
}
