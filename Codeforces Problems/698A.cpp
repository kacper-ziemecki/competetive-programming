#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n;
  cin >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  vector<ll> dp0(n),dp1(n),dp2(n),dp3(n);
  for(ll i = 0; i < n; i++){
    ll zero=(i-1 >= 0 ? dp0[i-1] : 0);
    ll one=(i-1 >= 0 ? dp1[i-1] : 0);
    ll two=(i-1 >= 0 ? dp2[i-1] : 0);
    ll three=(i-1 >= 0 ? dp3[i-1] : 0);
    if(list[i]==0){
      dp0[i] = max({zero,one,two,three});
    }else if(list[i]==1 || list[i]==3){
      dp1[i] = 1+max({(i-2 >= 0 ? dp1[i-2]:0),zero,two});
    }else if(list[i]==2 || list[i]==3){
      dp2[i] = 1+max({(i-2 >= 0 ? dp2[i-2]:0),zero,one});
    }else if(list[i]==3){
      dp3[i] = 1+max({(i-2 >= 0 ? dp3[i-2]:0),zero});
    }
    dp0[i] = max(zero,dp0[i]);
    dp1[i] = max(one,dp1[i]);
    dp2[i] = max(two,dp2[i]);
    dp3[i] = max(three,dp3[i]);
  }
  for(auto el : dp0) cout << el << " ";
  cout << endl;
  for(auto el : dp1) cout << el << " ";
  cout << endl;
  for(auto el : dp2) cout << el << " ";
  cout << endl;
  for(auto el : dp3) cout << el << " ";
  cout << endl;
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