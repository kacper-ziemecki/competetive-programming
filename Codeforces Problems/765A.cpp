#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  string home;
  cin >> home;
  string temp;
  ll cnt = 0;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(temp[0] == home[0] && temp[1] == home[1] && temp[2] == home[2]){
      cnt++;
    }
    else if(temp[5] == home[0] && temp[6] == home[1] && temp[7] == home[2]){
      cnt++;
    }
  }
  if(cnt&1){
    cout << "contest\n";
  }
  else{
    cout << "home\n";
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