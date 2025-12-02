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

stack<int> res;
vector<int> cur;
map<int, vector<int>> mp;
int n,x,dlugosc,poczotek;

bool helper(int l){
  if(l == 0){
    cur.clear();
    while(!res.empty()){
      cur.pb(res.top());
      res.pop();
    }
    reverse(cur.begin(), cur.end());
    for(int i = 0; i < cur.size(); i++) res.push(cur[i]);
    cout << "? " << poczotek << ' ' << cur.size() << ' ';
    for(auto el : cur) cout << el << ' ';
    cout << endl;
    cin >> x;
    return (x == cur.size());
  }
  for(auto el : mp[l]){
    res.push(el);
    if(helper(l-1)) return true;
    res.pop();  
  }
  dbg(l,false);
  return false;
}

void solve(){
  dlugosc=0;
  cin >> n;
  mp.clear();
  while(!res.empty()) res.pop();
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
  poczotek = mp[dlugosc][0];
  res.push(poczotek);
  helper(dlugosc-1);

  cur.clear();
  while(!res.empty()){
    cur.pb(res.top());
    res.pop();
  }
  reverse(cur.begin(), cur.end());
  cout << "! " << cur.size() << ' ';
  for(auto el : cur) cout << el << ' ';
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