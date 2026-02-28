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


struct Question{
  int l,r,k;
};

int n,q,v;
vector<int> lista,sorted;
vector<Question> zapytania;

struct Node{
  Node *right;
  Node *left;
  int val;
  Node(Node* l=nullptr, Node* r=nullptr, int v=0){
    left = l;
    right = r;
    val = v;
  }
};


struct SegTree{
  vector<Node*> roots;
  int ss;
  Node* build(int lx, int rx){
    if(lx == rx) return new Node();
    int mid = (lx+rx)/2;
    Node *l = build(lx,mid);
    Node *r = build(mid+1,rx);
    return new Node(l, r, l->val+r->val);
  }
  SegTree(int n){
    ss = 1;
    while(ss < n) ss <<= 1;
    roots.pb(build(0,ss-1));
  }
  Node* set(Node* node, int i, int val, int lx, int rx){
    if(lx == rx) return new Node(nullptr,nullptr,node->val+val);
    int mid = (lx+rx)/2;
    if(i <= mid){
      Node* l = set(node->left,i,val,lx,mid);
      return new Node(l,node->right,node->right->val+l->val);
    } else{
      Node* r = set(node->right,i,val,mid+1,rx);
      return new Node(node->left,r,r->val+node->left->val);
    }
  }
  void set(int i, int val){
    roots.pb(set(roots.back(),i,val,0,ss-1));
  }
  int get(Node *node, int k, int lx, int rx){
    if(lx > k) return node->val;
    if(rx <= k) return 0;
    int mid = (lx+rx)/2;
    return get(node->left,k,lx,mid) + get(node->right,k,mid+1,rx);
  }

  int get(int l, int r, int k){
    return get(roots[r-1],k,0,ss-1) - (l-2 < 0 ? 0 : get(roots[l-2],k,0,ss-1));
  }
};

void solve(){
  cin >> n;
  lista.resize(n);
  sorted.resize(n);
  zapytania.resize(q);
  for(int i = 0; i < n; i++){
    cin >> lista[i];
    sorted[i] = lista[i];
  }
  cin >> q;
  for(int i = 0; i < q; i++){
    Question cur;
    cin >> cur.l >> cur.r >> cur.k;
    zapytania[i] = cur;
    sorted.pb(cur.k);
  }
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  SegTree segtree(sorted.size()+1);
  for(int i = 0; i < n; i++){
    int val = lower_bound(sorted.begin(), sorted.end(), lista[i]) - sorted.begin();
    segtree.set(val,1);
  }
  for(int i = 0; i < q; i++){
    Question cur = zapytania[i];
    int k = lower_bound(sorted.begin(), sorted.end(), cur.k) - sorted.begin();
    cout << segtree.get(cur.l,cur.r,cur.k) << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}