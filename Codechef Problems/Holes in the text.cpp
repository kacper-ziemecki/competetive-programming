#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  int cnt = 0;
  for(auto el : text){
    if(el == 'A' || el == 'D' || el == 'O' || el == 'P' || el == 'R' || el =='Q' ){
      cnt++;
    }
    if(el == 'B'){
      cnt+=2;
    }
  }
  cout << cnt << endl;
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