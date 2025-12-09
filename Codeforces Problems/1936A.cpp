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

int n,mx,sr;
char a;
void solve(){
  cin >> n;
  mx=0;
  vector<int> lista = {0};
  for(int i = 1; i < n; i++){
    cout << "? " << mx << ' ' << mx << ' ' << i << ' ' << i << endl;
    cin >> a;
    if(a == '<') mx = i;
  }
  for(int i = 1; i < n; i++){
    int j = lista.back();
    cout << "? " << mx << ' ' << j << ' ' << mx << ' ' << i << endl;
    cin >> a;
    if(a == '<'){
      lista.clear();
      lista.pb(i);
    } else if(a == '=') lista.pb(i);
  }
  for(auto el : lista) dbg(el);

  int cur=0;
  for(int i = 1; i < lista.size(); i++){
    cout << "? " << lista[cur] << ' ' << lista[cur] << ' ' << lista[i] << ' ' << lista[i] << endl;
    cin >> a;
    if(a == '>') cur = i;
  }
  cout << "! " << mx << ' ' << lista[cur] << endl;
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