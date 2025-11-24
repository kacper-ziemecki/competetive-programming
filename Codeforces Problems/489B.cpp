#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> one(n, 0);
  for(auto &el : one) cin >> el;
  ll m;
  cin >> m;
  vector<ll> two(m, 0);
  for(auto &el : two) cin >> el;
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  ll res = 0;
  ll i = 0, j = 0;
  while(i < n || j < m){
    if((one[i] + 1 == two[j]) || (one[i] == two[j]) || (one[i] - 1 == two[j])){
      i++;
      j++;
      res++;
    }
    else if(one[i] > two[j]){
      j++;
    }
    else if(one[i] < two[j]){
      i++;
    }
  }
  cout << res << endl;
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