#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());

  vector<pair<ll,ll>> sieve(list[n-1]+1, {1,0});
  for(ll i = 2; i < list[n-1]+1; i++){
    if(sieve[i].first == 1){
      sieve[i].first = i;
      for(ll j = i * i; j < list[n-1]+1; j+=i){
        sieve[j].first = i;
      }
    }
  }

  for(auto el : list){
    sieve[el].second++;
  }

  for(ll i = 0; i < n; i++){
    ll temp1 = 0, temp2 = list[i];

    vector<ll> temp3;
    while(temp2 > 1){
      temp3.push_back(sieve[temp2].first);
      temp2 /= sieve[temp2].first;
    }
    temp3.push_back(temp2);
    if(temp3.size() > 2) temp3.push_back(list[i]);
    for(auto el : temp3){
      temp1 += sieve[el].second;
    }
    cout << n-temp1 << " ";
  }
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
//   freopen("../../output.txt", "w", stdout);
// #endif

  solve();
}