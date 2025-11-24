#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  int res = 1;
  int i = 2;
  while(b){
    if(a % i == 0 && b % i == 0){
      a /= i;
      b /= i;
    }
    else if(a % i != 0 && b % i == 0){
      res *= i;
      b /= i;
    }
    else{
      i++;
    }
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}