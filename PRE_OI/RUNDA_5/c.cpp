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
vector<pair<int,int>> skrzynki;
vector<bool> vis;
bool flag1 = true;
bool flag2 = true;
int dp[2001];
int res;

int helper(int h=0, int mx_ciezar=INT_MAX, int ciezar=0){
  int mx_h = h;
  for(int i = 0; i < n; i++){
    if(!vis[i] && mx_ciezar >= ciezar+skrzynki[i].second){
      vis[i] = true;
      mx_h = max(mx_h, helper(h+1, min(mx_ciezar,ciezar+skrzynki[i].second+skrzynki[i].first), ciezar+skrzynki[i].second));
      vis[i] = false;
    }
  }
  return mx_h;
}

void solve(){
  cin >> n;
  if(n > 1000) flag2 = false;
  vis.assign(n,false);
  skrzynki.resize(n);
  for(int i = 0; i < n; i++){
    cin >> skrzynki[i].first >> skrzynki[i].second;
    if(skrzynki[i].second != 1) flag1 = false; 
    if(skrzynki[i].second > 1000 || skrzynki[i].first > 1000) flag2 = false;
  }
  if(flag1){
    sort(skrzynki.begin(), skrzynki.end(), greater<>());
    int mx_w = INT_MAX;
    for(int i = 0; i < n; i++){
      if(mx_w < i+1) break;
      mx_w = min(mx_w, i+1+skrzynki[i].first);
      res++;
    }
    cout << res << endl;
  } else if(flag2){
    for(int i = 0; i < n; i++){
      for(int waga = skrzynki[i].first; waga >= 0; waga--){
        if(dp[waga] == 0 && waga != 0) continue;
        dp[waga+skrzynki[i].second] = max(dp[waga+skrzynki[i].second], dp[waga]+1);
        res = max(res, dp[waga+skrzynki[i].second]);
      }
    }
    cout << res << endl;
  } else{
    cout << helper() << endl;
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