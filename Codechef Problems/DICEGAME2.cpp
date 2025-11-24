#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  vector<ll> first(3, 0), second(3, 0);
  for(auto &el : first) cin >> el;
  for(auto &el : second) cin >> el;
  sort(first.rbegin(), first.rend());
  sort(second.rbegin(), second.rend());
  if(first[0]+first[1] > second[0]+second[1]){
    cout << "Alice\n";
  }
  else if(first[0]+first[1] < second[0]+second[1]){
    cout << "Bob\n";
  }
  else{
    cout << "Tie\n";
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--) solve();
}