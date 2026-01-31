#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
string ans;
vector<int> order = {1},res;

void solve(){
  cin >> n;
  res.resize(n);
  for(int i = 2; i <= n; i++){
    int l = 0, r = order.size();
    while(l < r){
      int mid = (l+r)/2;
      cout << "? " << i << ' ' << order[mid] << endl;
      cin >> ans;
      if(ans == "YES"){
        l = mid+1;
      } else{
        r = mid;
      }
    }
    if(l == order.size()) order.pb(i);
    else order.insert(order.begin()+r, i);
  }
  for(int i = 0; i < n; i++) res[order[i]-1] = n-i;
  cout << "! ";
  for(auto el : res) cout << el << ' ';
  cout << endl;
}

int main()
  {

  // ios_base::sync_with_stdio(0);
  // cin.tie(0); 
  // cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../in.in", "r", stdin);
//   freopen("../out.out", "w", stdout);
// #endif

  solve();
}