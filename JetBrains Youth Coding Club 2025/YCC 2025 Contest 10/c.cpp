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


void solve(){
  ll n;
  cin >> n;
  set<ll> zeros = {1,2,3,5,7,11};
  if(zeros.count(n)){
    cout << -1 << endl;
    return;
  }
  if((n % 4) == 0){
    cout << n/4 << endl;
  } else if(((n-6) % 4) == 0){
    cout << 1+(n-6)/4 << endl;
  } else if(((n-9) % 4) == 0){
    cout << 1+(n-9)/4 << endl;
  } else{
    cout << 2+(n-9-6)/4 << endl;
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

  int t;
  cin >> t;
  while(t--)
  solve();
}