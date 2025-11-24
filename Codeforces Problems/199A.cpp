#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  if(n == 2){
    cout << "0 1 1\n"; 
    return;
  }
  if(n == 1){
    cout << "0 0 1\n";
    return;
  }
  if(n == 0){
    cout << "0 0 0\n";
    return;
  }
  vector<ll> list = {0, 1, 1};
  while(list[list.size() - 1] + list[list.size()-2] + list[list.size()-3] < n){
    list.push_back(list[list.size() - 1] + list[list.size()-2]);
  }
  cout << list[list.size()-1] << " " << list[list.size()-3] << " " << list[list.size()-4] << endl;
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