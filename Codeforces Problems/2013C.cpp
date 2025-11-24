#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n,x,cnt=0;
  cin >> n;
  string res;
  set<string> vis;
  bool right = true;
  for(ll i = 0; res.size() < n; i++){
    if(right){
      if(i&1){
        if(vis.count(res+'1')) continue;
        cout << "? " << res+'1' << endl;
        vis.emplace(res+'1');
        cin >> x;
        if(x){ res+='1'; cnt=0; }
        else cnt++;
      } else{
        if(vis.count(res+'0')) continue;
        cout << "? " << res+'0' << endl;
        vis.emplace(res+'0');
        cin >> x;
        if(x){ res+='0'; cnt=0; }
        else cnt++;
      }
    } else{
      if(i&1){
        if(vis.count('1'+res)) continue;
        cout << "? " << '1'+ res << endl;
        vis.emplace('1'+res);
        cin >> x;
        if(x){ res='1'+res; cnt=0; }
        else cnt++;
      } else{
        if(vis.count('0'+res)) continue;
        cout << "? " << '0'+res << endl;
        vis.emplace('0'+res);
        cin >> x;
        if(x){ res='0'+res; cnt=0; }
        else cnt++;
      }
    }
    if(cnt==2) right=false;
  }
  cout << "! " << res << endl;
} 
  

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  ll t;
  cin >> t;
  while(t--)
  solve();
}