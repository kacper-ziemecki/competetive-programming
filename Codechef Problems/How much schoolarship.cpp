#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  if(n < = 50){
    cout << 100 << endl;
  }
  else if(n <= 100){
    cout << 50 << endl;
  }
  else{
    cout << 0 << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  solve();
}