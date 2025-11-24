#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll a,b;
  cin >> a >> b;
  // -1+1 b++; a--;
  // +3-1 b--; a+=3;
  bool flag = true;
  while(flag){
    flag = false;
    if(a >= b+2){
      a--;
      b++;
      flag = true;
    }
    else if(b >= a+4){
      b--;
      a+=3;
      flag = true;
    }
  }
  if(a==b){
    cout <<"YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--) solve();
}