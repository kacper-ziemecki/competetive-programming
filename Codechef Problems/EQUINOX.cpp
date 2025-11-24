#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
	ll n,a,b;
  cin >> n >> a >> b;
  ll one = 0, two = 0;
  string text;
  string wzor = "EQUINOX";
  for(ll i = 0; i < n; i++){
    cin >> text;
    bool flag = false;
    for(auto el : wzor){
      if(el == text[0]) flag = true;
    }
    if(flag){
      one += a;
    }
    else two += b;
  }
  if(one > two){
    cout << "SARTHAK\n";
  }
  else if(one < two){
    cout << "ANURADHA\n";
  }
  else{
    cout << "DRAW\n";
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
  while(t--)
  solve();
}