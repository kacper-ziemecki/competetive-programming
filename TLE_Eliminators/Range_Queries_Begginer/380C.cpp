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

string s;
int m,n;
int l,r;

struct SegTree{
  vector<int> mx,lewo,prawo;
  int ss;
  SegTree(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    mx.assign(ss<<1,0);
    lewo.assign(ss<<1,0);
    prawo.assign(ss<<1,0);
  }
  vector<int> combine(vector<int> left, vector<int> right){
    vector<int> cur = {0,0,0};
    cur[0] = left[0] + right[0] + 2*min(left[2], right[1]);
    cur[1] = left[1] + right[1] - min(left[2], right[1]);
    cur[2] = left[2] + right[2] - min(left[2], right[1]);
    return cur;
  }
  void set(int idx, char c, int x, int lx, int rx){
    if(lx > idx || rx < idx) return;
    if(lx==rx){
      mx[x] = 0;
      lewo[x] = (c == ')');
      prawo[x] = (c == '(');
      return;
    }
    int mid = (lx+rx)/2;
    set(idx,c,2*x+1,lx,mid);
    set(idx,c,2*x+2,mid+1,rx);
    mx[x] = mx[2*x+1] + mx[2*x+2] + 2*min(prawo[2*x+1], lewo[2*x+2]);
    lewo[x] = lewo[2*x+1] + lewo[2*x+2] - min(prawo[2*x+1], lewo[2*x+2]);
    prawo[x] = prawo[2*x+1] + prawo[2*x+2] - min(prawo[2*x+1], lewo[2*x+2]);
  }
  void set(int idx, char c){
    set(idx,c,0,1,ss);
  }
  vector<int> get(int l, int r, int x, int lx, int rx){
    // dbg(l,r,lx,rx);
    if(l <= lx && rx <= r){
      // dbg("koniec", lx,rx);
      return {mx[x], lewo[x], prawo[x]};
    }
    if(r < lx || rx < l){
      // dbg("aof", lx,rx);
      return {0, 0, 0};
    }
    int mid = (lx+rx)/2;
    return combine(get(l,r,2*x+1,lx,mid), get(l,r,2*x+2,mid+1,rx));
  }
  int get(int l, int r){
    return get(l,r,0,1,ss)[0];
  }
};

void solve(){
  cin >> s >> m;
  // dbg(s,m);
  n = s.size();
  SegTree segtree(n+1);
  for(int i = 0; i < n; i++) segtree.set(i+1,s[i]);
  for(int i = 0; i < m; i++){
    cin >> l >> r;
    cout << segtree.get(l,r) << endl;
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

  solve();
}