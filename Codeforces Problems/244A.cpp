#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n*k+1, 0);
  ll temp;
  for(ll i = 1; i <= k; i++){
    cin >> temp;
    list[temp] = i;
  }
  for(ll i = 1; i <= k; i++){

    for(ll j = 1; j <= n*k; j++){
      if(list[j] == i){
        cout << j << " ";
      }
    }

    ll cnt = n;
    for(ll j = 1; j <= n*k; j++){
      if(list[j] == 0 && (--cnt > 0)){
        list[j] = i;
        cout << j << " ";
      }
    }
    cout << endl;
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