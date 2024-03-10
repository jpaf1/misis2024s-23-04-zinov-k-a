#include <iostream>
#include <string>
#include <array>

int main()
{
  int n = 1;
  int k = 0;
  std::cin >> n >> k;
  std::array <int, 50> b;
  int y = 0;
  int c = 0;
  for (int i=0;i<n;i++)
  {
      int a = 0;
      std::cin >> a;
      b[i] = a;
      if (i == k-1) {
          y=a;
      }

  }
  for (int i=0;i<n;i++)
  {
     if (b[i]>=y and b[i]>0){
        c++;
     }
  }
  std::cout << c;
}
