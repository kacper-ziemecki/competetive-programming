#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n, 0), b(n, 0);
  int c=0,d=0,res=-1;
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  for(int i = 0; i < n; i++){
  	if(c < a[i]){
  		c = a[i];
  		d = b[i];
  		res = i;
  	}
  	else if(c == a[i] && d < b[i]){
  		d = b[i];
  		res=i;
  	}
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}