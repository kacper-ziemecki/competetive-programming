#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,cur,prv;
string s;
const int maxn = 2e5+1;
map<int,vector<pair<int,int>>> dp;
int previous[maxn];

string print(int x){
  string tmp;
  while(x){
    tmp += (x&1 ? '1' : '0');
    x >>= 1;
  }
  if(tmp.empty()) tmp += '0';
  reverse(tmp.begin(), tmp.end());
  return tmp;
}

int findIdx(int prv, int i){
  int l = 0, r = dp[prv].size()-1;
  while(l < r){
    int mid = (l+r+1)/2;
    if(i-dp[prv][mid].first-dp[prv][mid].second >= 0) l = mid;
    else r = mid-1;
  }
  return r;
}

void solve(){
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    cur = cur ^ (1<<(s[i]-'a'));
    if(__builtin_popcount(cur) <= 1){
      dp[cur].pb(make_pair(i+1, i));
      previous[i] = 0;
      continue;
    }
    int mn=-1,lastIdx=-1;
    if(dp.count(cur) && i != n-1){
      mn = dp[cur].back().first;
      lastIdx = dp[cur].back().second;
      previous[i] = lastIdx;
    } 
    for(int j = 0; j < 26; j++){
      prv = cur ^ (1<<j);
      if(dp.count(prv) == 0) continue;
      int idx = findIdx(prv,i);
      for(int k = max(0, idx-2); k < min(int(dp[prv].size()), idx+2); k++){
        if(min(dp[prv][k].first, i-dp[prv][k].second) > mn){
          mn = min(dp[prv][k].first, i-dp[prv][k].second);
          previous[i] = dp[prv][k].second;
          lastIdx = i;
        }
      }
    }
    if(mn != -1){
      dp[cur].pb(make_pair(mn,lastIdx));
    }
  }
  vector<int> res;
  cur = n-1;
  while(cur){
    res.pb(cur);
    cur = previous[cur];
  }
  res.pb(0);
  reverse(res.begin(), res.end());
  int mx = INT_MAX;
  for(int i = 0; i < res.size()-1; i++){
    mx = min(mx, (res[i+1]+1)-(res[i]+1+(i ? 1 : 0))+1);
  }
  cout << mx << endl;
  cout << res.size()-1 << endl;
  for(int i = 0; i < res.size()-1; i++){
    cout << res[i]+1+(i ? 1 : 0) << ' ' << res[i+1]+1 << endl;
  }
  
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}