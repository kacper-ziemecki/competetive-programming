#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> list1(n, 0), list2(m, 0);
  for(auto &el : list1) cin >> el;
  for(auto &el : list2) cin >> el;
  ll suma1 = 0, suma2 = 0;
  for(auto el : list1) suma1 += el;
  for(auto el : list2) suma2 += el;

  if(suma1 > suma2){
    cout << "Tsondu\n";
  }	 
  else if(suma1 < suma2){
    cout << "Tenzing\n";
  }
  else{
    cout <<"Draw\n";
  }
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