#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct node{
  vector<node*> children;
  node(){
    children.assign(10, NULL);
  }
};

class Trie{
private:
  node* root;
public:
  Trie(){
    root = new node();
  }
  void insert(string number){
    node* cur = root;
    for(auto character : number){
      int alphaNum = character-'0';
      if(cur->children[alphaNum] == NULL){
        cur->children[alphaNum] = new node();
      } 
      cur = cur->children[alphaNum];
    }
  }
  bool search(string number){
    node* cur = root;
    for(auto character : number){
      int alphaNum = character-'0';
      if(cur->children[alphaNum] == NULL){
        return false;
      } 
      cur = cur->children[alphaNum];
    }
    return true;
  }
};


void solve()
{
  ll n;
  cin >> n;
  vector<string> lista(n);
  for(auto &el : lista) cin >> el;
  sort(lista.begin(), lista.end(), [](string& a, string& b){ return a.size() > b.size();});
  Trie tr;
  for(auto el : lista){
    if(tr.search(el)){
      cout << "NO\n";
      return;
    }
    tr.insert(el);
  }
  cout << "YES\n";
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

  ll t;
  cin >> t;
  while(t--) solve();
}