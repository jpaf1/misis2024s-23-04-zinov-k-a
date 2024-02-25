#include <iostream>
#include <string>
int main(){

int n = 0;
int c=0;
std::cin >> n;
for (int i=0; i<n;i++){ 
    std::string s;
    std::cin >> s;
    if (s[0]=='1' and s[2] == '1'){
        c++;
    }
    else {
        if(s[0]=='1' and s[4] == '1'){
        c++;
    }
    else {
        if (s[2]=='1' and s[4] == '1'){
        c++;
    }}
}

}
std::cout << c;

return 0;
}
