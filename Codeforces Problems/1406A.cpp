#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  unordered_map<ll, ll> list;
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    list[temp]++;
  }
  ll first = 0, second = 0;
  bool flag1 = true, flag2 = true;
  for(ll i = 0; i <= n; i++){
    if(list[i] < 2 && flag1){
      flag1 = false;
      first = i;
    }
    if(list[i] < 1 && flag2){
      flag2 = false;
      second = i;
    }
  }
  cout << first+second << endl;
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

  ll t;
  cin >> t;
  while(t--) solve();
}