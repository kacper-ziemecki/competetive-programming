#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  ll a = 0, b = 0;
  bool flag = true;
  for(ll i = 0; i < n; i++){
    if(flag && text[i] == 'A'){
      a++;
      continue;
    }
    if(flag && text[i] == 'B'){
      flag = false;
      continue;
    }
    if(!flag && text[i] == 'B'){
      b++;
      continue;
    }
    if(!flag && text[i] == 'A'){
      flag = true;
      continue;
    }
  }
  cout << a << " " << b << endl;
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