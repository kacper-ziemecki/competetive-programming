#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> one(n, 0), two(n, 0), prefix(n, 0), three(n, 0);
  ll a,b;
  for(ll i = 0; i < n; i++){
    cin >> a >> b; 
    one[i] = a;
    two[i] = b;
    three[i] = b;
    prefix[i] = (i-1 >= 0 ? prefix[i-1] + one[i] : one[i]);
  }
  sort(two.rbegin(), two.rend());
  for(ll i = 0; i < n; i++){
    ll res = prefix[n-1] - one[i];
    if(two[0] == three[i]){
      res *= two[1];
    }
    else{
      res *= two[0];
    }
    cout << res << " ";
  }
  cout << endl;
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