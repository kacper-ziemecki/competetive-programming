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

int n,x;
const int N = 2e5+1;
const int MOD = 998244353;
ull lista[N];
vector<ull> cur;
ull res;
int mx_length=0;
int counter = 0;

void helper(int idx){
  if(idx == n) return;

  bool can_add = true;
  for(auto el : cur){
    if((el^lista[idx]) < x){
      can_add = false;
      break;
    } 
  }
  // dbg(lista[idx], can_add);
  if(can_add){
    cur.pb(lista[idx]);
    mx_length = max(mx_length,(int)cur.size());
    if(cur.size() == 7){
      dbg(x);
      for(auto el : cur) cout << el << ' ';
      cout << endl;
    }
    // if((counter++) % 10000000000000) dbg(mx_length);
    // for(auto el : cur) cout << el << ' ';
    // cout << endl;
    res++;
    helper(idx+1);
    cur.pop_back();
    helper(idx+1);
  } else{
    helper(idx+1);
  }
}

void solve(){
  cin >> n >> x; 
  res=0;
  for(int i = 0; i < n; i++) cin >> lista[i];
  helper(0);
  // cout << "----------\n";
  cout << res << endl;
  dbg(mx_length);
  // cout << "----------\n";
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