#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n, 0), b(n, 0);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  vector<ll> list(n+n, 0), dp(n+n, 0), res(n+n, 0);
  for(ll i = 0; i < n; i++){
    if((a[i] >= 0 && b[i] >= 0) || (a[i] <= 0 && b[i] <= 0)){
      list[i*2] = a[i];
      list[i*2+1] = b[i];
      dp[i*2] = max(max((i > 0 ? dp[i*2-1] : 0)+list[i*2], list[i*2]), 0ll);
      dp[i*2+1] = max(max(dp[i*2]+list[i*2+1], list[i*2+1]), 0ll);
    }
    else{
      if(i > 0){
        if(dp[i*2-1] + a[i] + b[i] > 0){
          list[i*2] = min(a[i], b[i]);
          list[i*2+1] = max(a[i], b[i]);
          dp[i*2] = max(max(dp[i*2-1] + min(a[i], b[i]), min(a[i], b[i])), 0ll);
          dp[i*2+1] = max(max(dp[i*2] + max(a[i], b[i]), max(a[i], b[i])), 0ll);
        }
        else{
          list[i*2] = max(a[i], b[i]);
          list[i*2+1] = max(a[i], b[i]);
          dp[i*2] = max(max(dp[i*2-1] + max(a[i], b[i]), max(a[i], b[i])), 0ll);
          dp[i*2+1] = max(a[i], b[i]);
        }
      }
      else{
        list[i*2] = min(a[i], b[i]);
        list[i*2+1] = max(a[i], b[i]);
        dp[i*2] = 0;
        dp[i*2+1] = max(a[i], b[i]);
      }
    }
  }

  ll ms = 0;
  for(auto el : dp) ms = max(ms, el);
  ll cnt = 0;
  for(auto el : dp) if(el == ms) cnt++;
  if(cnt >= 2){
    cout << ms << endl;
    return;
  }

  ll maks = 0;
  for(ll i = n+n-1; i >= 0; i--){
    if(dp[i] == 0){
      maks = 0;
    }
    else if(dp[i] > maks){
      maks = dp[i];
    }
    dp[i] = maks;
  }

  ll prawo = n,lewo = -1;
  for(ll i = 0; i < n+n; i++){
    if(dp[i] == ms){
      lewo = i;
      break;
    }
  }
  for(ll i = n+n-1; i >= 0; i--){
    if(dp[i] == ms){
      prawo = i;
      break;
    }
  }
  ll answer = ms;
  if(prawo != n+n-1){
    ll temp1 = dp[prawo];
    temp1 -= max(a[prawo/2], b[prawo/2]);
    temp1 += min(a[prawo/2], b[prawo/2]);
    ll temp2 = dp[prawo+1];
    temp1 += max(a[prawo/2], b[prawo/2]);
    temp1 -= min(a[prawo/2], b[prawo/2]);
    answer = max(temp1, temp2);
  }
  if(lewo != 0){
    ll temp1 = dp[lewo];
    temp1 -= max(a[lewo/2], b[lewo/2]);
    temp1 += min(a[lewo/2], b[lewo/2]);
    ll temp2 = dp[lewo-1];
    temp1 += max(a[lewo/2], b[lewo/2]);
    temp1 -= min(a[lewo/2], b[lewo/2]);
    answer = min(answer, max(temp1, temp2));
  }
  cout << lewo << " " << prawo << endl;
  cout << "dp:\n";
  for(auto el : dp) cout << el << " ";
  cout << endl;
  cout << "list:\n";
  for(auto el : list) cout << el << " ";
  cout << endl;
  cout << answer << endl;
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
  while(t--)
  solve();
}