#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<pair<ll, ll>> list(n, {0, 0});
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    list[i].first = temp;
    list[i].second = i;
  }
  sort(list.begin(), list.end());
  if(list[0].first == list[1].first){
    cout << "Still Rozdil\n";
  }
  else{
    cout << list[0].second+1 << endl;
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