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

int n;
string s;

bool good(string s){
  if(s.size() <= 2) return true;
  if(s == "RRR" || s == "LLL") return false;
  return true;
}

string shorten(string s){
  if(s.size() <= 2) return s;
  return s.substr(1,2);
}
void solve(){
  cin >> n >> s;

  vector<map<string, int>> dp1(n), dp2(n), dp3(n), dp4(n); // minimalna liczba operacji
  dp1[0]["LR"] = (s[n-1] != 'L') + (s[0] != 'R');
  dp2[0]["RL"] = (s[n-1] != 'R') + (s[0] != 'L');
  dp3[0]["LL"] = (s[n-1] != 'L') + (s[0] != 'L');
  dp4[0]["RR"] = (s[n-1] != 'R') + (s[0] != 'R');

  for(int id = 1; id < n-1; id++){
    for(auto ch : {'L', 'R'}){
      for(auto state : dp1[id-1]){
        if(!good(shorten(state.first)+ch)) continue;
        if(dp1[id].count(shorten(state.first)+ch) == 0) dp1[id][shorten(state.first)+ch] = state.second + (s[id] == ch ? 0 : 1);
        else dp1[id][shorten(state.first)+ch] = min(dp1[id][shorten(state.first)+ch], state.second + (s[id] == ch ? 0 : 1));
      }
    }
  }
  for(int id = 1; id < n-1; id++){
    for(auto ch : {'L', 'R'}){
      for(auto state : dp2[id-1]){
        if(!good(shorten(state.first)+ch)) continue;
        if(dp2[id].count(shorten(state.first)+ch) == 0) dp2[id][shorten(state.first)+ch] = state.second + (s[id] == ch ? 0 : 1);
        else dp2[id][shorten(state.first)+ch] = min(dp2[id][shorten(state.first)+ch], state.second + (s[id] == ch ? 0 : 1));
      }
    }
  }
  for(int id = 1; id < n-1; id++){
    for(auto ch : {'L', 'R'}){
      for(auto state : dp3[id-1]){
        if(!good(shorten(state.first)+ch)) continue;
        if(dp3[id].count(shorten(state.first)+ch) == 0) dp3[id][shorten(state.first)+ch] = state.second + (s[id] == ch ? 0 : 1);
        else dp3[id][shorten(state.first)+ch] = min(dp3[id][shorten(state.first)+ch], state.second + (s[id] == ch ? 0 : 1));
      }
    }
  }
  for(int id = 1; id < n-1; id++){
    for(auto ch : {'L', 'R'}){
      for(auto state : dp4[id-1]){
        if(!good(shorten(state.first)+ch)) continue;
        if(dp4[id].count(shorten(state.first)+ch) == 0) dp4[id][shorten(state.first)+ch] = state.second + (s[id] == ch ? 0 : 1);
        else dp4[id][shorten(state.first)+ch] = min(dp4[id][shorten(state.first)+ch], state.second + (s[id] == ch ? 0 : 1));
      }
    }
  }
  int res1 = INT_MAX, res2 = INT_MAX, res3 = INT_MAX, res4 = INT_MAX;
  for(auto state : dp1[n-2]){
    string tmp1(1, state.first.back());
    tmp1 += 'L';
    tmp1 += 'R';
    string tmp2 = shorten(state.first) + 'L';
    if(good(tmp1) && good(tmp2)) res1 = min(res1, state.second);
  }
  for(auto state : dp2[n-2]){
    string tmp1(1, state.first.back());
    tmp1 += 'R';
    tmp1 += 'L';
    string tmp2 = shorten(state.first) + 'R';
    if(good(tmp1) && good(tmp2)) res2 = min(res2, state.second);
  }
  for(auto state : dp3[n-2]){
    string tmp1(1, state.first.back());
    tmp1 += 'L';
    tmp1 += 'L';
    string tmp2 = shorten(state.first) + 'L';
    if(good(tmp1) && good(tmp2)) res3 = min(res3, state.second);
  }
  for(auto state : dp4[n-2]){
    string tmp1(1, state.first.back());
    tmp1 += 'R';
    tmp1 += 'R';
    string tmp2 = shorten(state.first) + 'R';
    if(good(tmp1) && good(tmp2)) res4 = min(res4, state.second);
  }
  // dbg(res1,res2,res3,res4);
  cout << min({res1,res2,res3,res4}) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  int t;
  cin >> t;
  while(t--)
  solve();
}