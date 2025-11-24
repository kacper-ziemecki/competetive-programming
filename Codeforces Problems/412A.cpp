#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double

void solve()
{
  ll n,k;
  cin >> n >> k;
  string text;
  cin >> text;
  if(k > n/2){
    for(ll i = k; i < n; i++){
      cout << "RIGHT\n";
    }
    for(ll i = n-1; i >= 0; i--){
      cout << "PRINT " << text[i] << endl;
      if(i!=0) cout << "LEFT\n";
    }
  }
  else{
    for(ll i = 0; i < k-1; i++){
      cout << "LEFT\n";
    }
    for(ll i = 0; i < n; i++){
      cout << "PRINT " << text[i] << endl;
      if(i!= n-1) cout << "RIGHT\n";
    }
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