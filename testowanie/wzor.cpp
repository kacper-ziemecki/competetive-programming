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

int n,res=1;
const int N = 1e6+1;
int lista[N];
set<int> st,nie_dziala;

bool okej(int idx){
  set<int>::iterator it = nie_dziala.upper_bound(lista[idx]);
  return it == nie_dziala.end();
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < n; i++){
    if(!okej(i)){
      res++;
      st.clear();
      nie_dziala.clear();
      st.emplace(-lista[i]);
    } else{
      int a = lista[i];
      st.emplace(-a);
      set<int>::iterator it = st.upper_bound(-a);
      if(it != st.end()) nie_dziala.emplace(-(*it));
    }
    // dbg(i,res);
  }
  cout << res << endl;
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