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

int n,cur,prev;
string s;
const int maxn = (1<<26);
pair<int,int> dp[maxn];

void solve(){
  cin >> n >> s;
  for(int i = 0; i < maxn; i++){
    dp[i] = {INT_MAX, -1};
  }
  for(int i = 0; i < n; i++){
    cur = cur ^ (1<<(s[i]-'a'));
    for(int j = 0; j < 26; j++){
      
    }
  }
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

  solve();
}