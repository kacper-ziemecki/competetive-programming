#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll q;
  cin >> q;
  ll maks = -1, last = -1, minimum = -1;

  ll temp;
  for(ll i = 0; i < q; i++){
    cin >> temp;
    // cout << endl;
    // cout << ":" << maks << " " << last << endl;
    if(i == 0){
      maks = temp;
      minimum = temp;
      cout << 1;
      continue;
    }

    if(temp >= maks && last == -1){
      cout << 1;
      maks = temp;
      continue;
    }
    if(temp <= minimum && temp >= last){
      last = temp;
      cout << 1;
      continue;
    }


    cout << 0;
  }
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}