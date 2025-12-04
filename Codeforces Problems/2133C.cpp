#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<int> res;
map<int, vector<int>> mp;
int n,x,dlugosc;

void solve(){
  dlugosc=0;
  cin >> n;
  mp.clear();
  res.clear();
  for(int i = 1; i <= n; i++){
    cout << "? " << i << ' ';
    cout << n << ' ';
    for(int j = 1; j <= n; j++){
      cout << j << ' ';
    }
    cout << endl;
    cin >> x;
    mp[x].pb(i);
    dlugosc = max(dlugosc, x);
  }
  res.pb(mp[dlugosc][0]);

  for(int dl = dlugosc-1; dl > 0; dl--){
    for(auto el : mp[dl]){
      cout << "? " << res.back() << " 2 " << res.back() << ' ' << el << endl;
      cin >> x;
      if(x == 2){
        res.pb(el);
        break;
      }
    }
  }
  cout << "! " << dlugosc;
  for(auto el : res) cout << ' ' << el;
  cout << endl;
}

int main()
{

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  int t;
  cin >> t;
  while(t--)
  solve();
}