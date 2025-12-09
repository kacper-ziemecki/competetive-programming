#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  cin >> t;
  while(t > 0){
    t -= 1;
    int n;
    cin >> n;
    vector<int> lista(n);
    for(int i = 0; i < n; i+=1){
      cin >> lista[i];
    }
    for(int i = 0; i < n; i+=1){
      cout << lista[i] << ' ';
    }
    cout << endl;
  }
}