#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)



int main(){
  
  vector<int> lista(5);

  for(int i = 0; i < 5; i++) cin >> lista[i];

  for(int &el: lista) cin >> el;
  
}
