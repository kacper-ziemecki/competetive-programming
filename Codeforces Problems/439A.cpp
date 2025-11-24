#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n,d;
  cin >> n >> d;
  ll suma = 0;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    suma += temp;
  }
  if(d < suma + (n-1) * 10){
    cout << -1 << endl;
  }
  else{
    cout << (d-suma)/5 << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}