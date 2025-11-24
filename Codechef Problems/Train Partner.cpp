#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,temp;
  cin >> n;
  temp = n;
  n %= 8;
  if(n == 1){
    cout << temp + 3 << "LB\n";
  }
  if(n == 2){
    cout << temp + 3 << "MB\n";
  }
  if(n == 3){
    cout << temp + 3 << "UB\n";
  }
  if(n == 4){
    cout << temp - 3 << "LB\n";
  }
  if(n == 5){
    cout << temp - 3 << "MB\n";
  }
  if(n == 6){
    cout << temp - 3 << "UB\n";
  }
  if(n == 7){
    cout <<  temp + 1 << "SU\n";
  }
  if(n == 0){
    cout <<  temp - 1 << "SL\n";
  }
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