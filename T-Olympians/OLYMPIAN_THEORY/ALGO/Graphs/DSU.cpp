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

struct DSU{
  vector<int> parents, sajz;
  DSU(int n){
    sajz.assign(n+1, 1);
    parents.resize(n+1);
    for(int i = 0; i <= n; i++){
      parents[i] = i;
    }
  }
  int find(int a){
    if(parents[a] == a) return a;
    else{
      parents[a] = find(parents[a]);
      return parents[a];
    }
  }
};

int main()
  {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);

  // rozne konstruktory vectora

  vector<int> lista;
  
  vector<int> lista(5, 0);

  vector<int> lista(5);

  vector<int> lista = {95,3,25,3,5,3,5};
}