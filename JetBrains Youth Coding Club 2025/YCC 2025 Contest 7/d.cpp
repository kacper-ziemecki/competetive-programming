#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

void solve(){
  int d, sumTime, minSum=0, maxSum=0;
  cin >> d >> sumTime;
  vector<pair<int,int>> lista(d);
  for(auto &el : lista){
    cin >> el.first >> el.second;
    minSum += el.first;
    maxSum += el.second;
  }

  if(!(minSum <= sumTime && sumTime <= maxSum)){
    cout << "NO\n"; return;
  }
  cout << "YES\n";
  sumTime -= minSum;
  for(auto el : lista){
    int tmp = min(sumTime, el.second-el.first);
    sumTime -= tmp;
    cout << el.first + tmp << ' ';
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("../../in.in", "r", stdin);
  // freopen("../../out.out", "w", stdout);

  solve();
}