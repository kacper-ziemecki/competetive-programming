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

int n,a,b,vis=0;
char c;
const int maxn = 11;
vector<int> lista[maxn];
vector<vector<int>> combinations;
vector<int> cur;

string print(int x){
  string s;
  while(x){
    s += (x&1 ? '1' : '0');
    x >>= 1;
  }
  reverse(s.begin(), s.end());
  return s;
}

void helper(int id){
  if(id == n){
    combinations.pb(cur);
    return;
  }
  if(!(vis&(1<<(lista[id][0])))){
    vis = vis ^ (1<<(lista[id][0]));
    cur.pb(lista[id][0]);
    helper(id+1);
    vis = vis ^ (1<<(lista[id][0]));
    cur.pop_back();
  }
  if((lista[id].size() == 2) && !(vis&(1<<(lista[id][1])))){
    vis = vis ^ (1<<(lista[id][1]));
    cur.pb(lista[id][1]);
    helper(id+1);
    vis = vis ^ (1<<(lista[id][1]));
    cur.pop_back();
  }
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> c;
    if(c == 'N'){
      cin >> a >> b;
      lista[i].pb(a-1); lista[i].pb(b-1);
    } else{
      cin >> a;
      lista[i].pb(a-1);
    }
  }
  // for(int i = 0; i < n; i++){
  //   dbg(lista[i][0]);
  //   if(lista[i].size() == 2) dbg(lista[i][1]);
  // }
  helper(0);
  if(combinations.size() == 1){
    cout << "TAK\n";
    for(int i = 0; i < n; i++){
      cout << combinations[0][i]+1 << endl;
    }
  } else{
    cout << "NIE\n";
    cout << combinations.size() << endl;
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