#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

// (a+b)/c - zaokroglenie na dul | floor(64.3) -> 64
// (a+b+c-1)/c - zaokroglenie do gory | ceil(64.3) -> 65

int main(){
  
  vector<int> lista = {5,6,9,10,14,20,51,110};
  int n = lista.size();
  int a = 110;
  double lewo = 0, prawo = n-1;
  while(lewo < prawo){
    int srodek = (lewo+prawo+1)/2; 
    if(lista[srodek] <= a) lewo = srodek;
    else prawo = srodek-1;
  }
  cout << lewo << endl;
}
