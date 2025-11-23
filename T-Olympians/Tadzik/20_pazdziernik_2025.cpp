#include <bits/stdc++.h>
using namespace std;

 
int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    if((i%5 == 0) && (i%2 != 0)){ // (chcemy liczby podzielne przez 5) i (niepodzielne przez 2)
      cout << i << ' ';
    }
  }
  cout << endl;
} 
i -> && 
lub -> ||
nie -> !
