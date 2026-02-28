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

ll n,q;
vector<ll> lista;
ll t,k,a,x,b;

struct Node{
  Node *right, *left;
  ll sum;
  Node(ll s = 0,Node *l=nullptr, Node *r=nullptr){
    right = r;
    left = l;
    sum = s;
  }
};

struct SegTree{
  vector<Node*> roots;
  ll ss;
  SegTree(vector<ll> vals){
    ss = 1;
    while(ss < vals.size()) ss<<=1;
    roots.pb(build(vals,0,ss-1));
  }
  Node *build(vector<ll>& vals, ll lx, ll rx){
    // dbg(lx,rx);
    if(lx==rx){
      // dbg(lx,vals.size());
      return new Node((lx < vals.size() ? vals[lx] : 0));
    }
    ll mid = (lx+rx)/2;
    Node *l = build(vals,lx,mid);
    Node *r = build(vals,mid+1,rx);
    // dbg(lx,rx, l->sum+r->sum);
    return new Node(l->sum+r->sum,l,r);
  }

  Node* set(Node *prev, ll i, ll val, ll lx, ll rx){
    if(lx == rx){
      return new Node(val, nullptr, nullptr);
    }
    ll mid = (lx+rx)/2;
    if(i <= mid){
      Node *new_left = set(prev->left,i,val,lx,mid);
      return new Node(prev->right->sum+new_left->sum, new_left, prev->right);
    }
    else{
      Node *new_right = set(prev->right,i,val,mid+1,rx);
      return new Node(new_right->sum+prev->left->sum, prev->left, new_right);
    }
  }
  void set(ll root, ll i, ll val){
    roots.pb(set(roots[root],i,val,0,ss-1));
  }
  ll get(Node *node, ll l, ll r, ll lx, ll rx){
    // dbg(lx,rx,node->sum);
    if(l <= lx && rx <= r){
      // dbg(node->sum,lx,rx);
      return node->sum;
    }
    if(lx > r || rx < l) return 0;
    ll mid = (lx+rx)/2;
    return get(node->left,l,r,lx,mid)+get(node->right,l,r,mid+1,rx);
  }
  ll get(ll root, ll l, ll r){
    return get(roots[root],l,r,0,ss-1);
  }
  void create_copy(ll k){
    roots.pb(roots[k]);
  }
};

void solve(){
  cin >> n >> q;
  lista.resize(n);
  for(auto &el : lista) cin >> el;
  SegTree segtree(lista);
  // dbg(segtree.roots[0]->right->sum);
  // segtree.get(0,0,lista.size()-1);
  // dbg(segtree.roots[0]->sum);
  // return;
  map<ll,ll> mp;
  mp[1]=0;
  ll cnt = 1;
  for(ll i = 0; i < q; i++){
    cin >> t;
    if(t == 1){
      cin >> k >> a >> x;
      segtree.set(mp[k],a-1,x);
      mp[k]=segtree.roots.size()-1;
    } else if(t == 2){
      cin >> k >> a >> b;
      cout << segtree.get(mp[k],a-1,b-1) << endl;
    } else{
      cin >> k;
      segtree.create_copy(mp[k]);
      mp[++cnt] = segtree.roots.size()-1;
    }
  }
}

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../in.in", "r", stdin);
//   freopen("../out.out", "w", stdout);
// #endif

  
  solve();
}