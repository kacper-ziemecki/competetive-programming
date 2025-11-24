#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);

  ll n;
  cin >> n;

  vector<bool> jest_pierwsze(n+1, true);
  jest_pierwsze[0] = jest_pierwsze[1] = false;
  for (ll i = 2; i <= n; i++) {
    if (jest_pierwsze[i] && (ll)i * i <= n) {
        for (ll j = i * i; j <= n; j += i)
            jest_pierwsze[j] = false;
    }
  }

  vector<ll> pierwsze;
  for(ll i = 3; i <= n; i++){
    if(jest_pierwsze[i]) pierwsze.push_back(i);
  }


  for(auto el : pierwsze) cout << el << endl;
} 