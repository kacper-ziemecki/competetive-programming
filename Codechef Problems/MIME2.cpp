#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(string a, string b){
  if(a.size() >= b.size()+1 && a.substr(a.size()-b.size()) == b && a[a.size()-b.size()-1] == '.'){
    return true;    
  }
  return false;
}

void solve(){
  ll n,m;
  cin >> n >> m;
  string a,b;
  map<string, string> mp;
  for(ll i = 0; i < n; i++){
    cin >> a >> b;
    mp[a] = b;
  }
  for(ll i = 0; i < m; i++){
    cin >> a;
    bool flag = false;
    for(auto el : mp){
      if(check(a, el.first)){
        cout << el.second << endl;
        flag = true;
        break;
      }
    }
    if(!flag){
      cout << "unknown\n";
    }
  }
} 
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
  
  
}