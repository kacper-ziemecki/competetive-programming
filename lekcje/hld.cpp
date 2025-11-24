#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



struct SegTree{
  struct Node {
    int max_subtree;
    int push_add;
    Node() : max_subtree{0}, push_add{0} {}
  };

  vector<Node> nodes;
  int base;

  SegTree(){}
  SegTree(int  n) : base{1} {
    while(base <= n) base <<= 1; 
    nodes.resize(base * 2);
  }
  void Touch(int v){
    if(v < base){
      for(int s : {v*2, v*2+1}){
        nodes[s].max_subtree += nodes[v].push_add;
        nodes[s].push_add += nodes[v].push_add;
      }
    }
    nodes[v].push_add = 0;
  }

  void AddIntv(int lq, int rq, int val, int lb, int rb, int v){
    if(lq >= rb || rq <= lb) return;
    Touch(v);
    if(lq <= lb && rb <= rq){
      nodes[v].max_subtree += val;
      nodes[v].push_add += val;
      return;
    }
    const int mid = (lb+rb)/2;
    AddIntv(lq,rq,val,lb,mid, v*2);
    AddIntv(lq,rq,val,mid,rb, v*2+1);
    nodes[v].max_subtree = max(nodes[v*2].max_subtree, nodes[v*2+1].max_subtree);
  }

  void AddIntv(int L, int R, int val){
    AddIntv(L, R, val, 0, base, 1);
  }

  int GetMax(int lq, int rq, int lb, int rb, int v){
    if(lq >= rb || rq <= lb) return INT_MIN;
    Touch(v);
    if(lq <= lb && rb <= rq){
      return nodes[v].max_subtree;
    }
    const int mid = (lb+rb)/2;
    return max(GetMax(lq,rq,lb,mid, v*2), GetMax(lq,rq,mid,rb, v*2+1));
  }

  int GetMax(int L, int R){
    return GetMax(L,R,0,base,1);
  }
};

const int MaxN = 2e5;
int n,q;
vector<int> graph[MaxN];
int tree_size[MaxN];
int depth[MaxN];
int parent[MaxN];
SegTree hld_seg_tree;

void DfsPrepoc(int v, int p){
  tree_size[v] = 1;
  parent[v] = p;
  for(int s : graph[v]){
    if(s != p){
      depth[s] = depth[v]+1;
      DfsPrepoc(s, v);
      tree_size[v] += tree_size[s];
    }
  }
}
int path_index[MaxN];
int preorder[MaxN], postorder[MaxN];
int pre_tm;

void DfsHeavyLight(int v, int p){
  preorder[v] = pre_tm++;
  int max_size = -1;
  int who_max_size = -1;
  for(int s : graph[v]){
    if(s == p) continue;
    if(tree_size[s] > max_size){
      max_size = tree_size[s];
      who_max_size = s;
    }
  }
  if(who_max_size != -1){
    path_index[who_max_size] = path_index[v];
    DfsHeavyLight(who_max_size, v);
    for(int s : graph[v]){
      if(s == p || s == who_max_size) continue;
      path_index[s] = s;
      DfsHeavyLight(s, v);
    }
  }
  postorder[v] = pre_tm;
}

int GetAnswer(int x, int y){
  int ans = INT_MIN;
  while(path_index[x] != path_index[y]){
    if(depth[path_index[x]] > depth[path_index[y]]) swap(x,y);
    const int root_y = path_index[y];
    const int max_on_y_path = hld_seg_tree.GetMax(preorder[root_y], preorder[y]+1);
    ans = max(ans, max_on_y_path);
    y = parent[root_y];
  }
  const int pre_x = preorder[x];
  const int pre_y = preorder[y];
  const int max_on_xy_path = hld_seg_tree.GetMax(min(pre_x, pre_y), max(pre_x, pre_y));
  return max(ans, max_on_xy_path);
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    int u,v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  DfsPrepoc(1, -1);
  path_index[1] = 1;
  DfsHeavyLight(1, -1);

  hld_seg_tree = SegTree(n + 10);

  cin >> q;
  for(int qidx = 1; qidx < q; ++qidx){
    string type;
    cin >> type;
    if(type == "add"){
      int v, val;
      cin >> v >> val;
      hld_seg_tree.AddIntv(preorder[v], postorder[v], val);
    } else{
      assert(type == "max");
      int x,y;
      cin >> x >> y;
      cout << GetAnswer(x,y) << endl;
    }
  } 
}