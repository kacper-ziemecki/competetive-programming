#include <bits/stdc++.h>
using namespace std;


void solve()
{
  int a,b,n,res=0;
  cin >> a >> b >> n;
  while(a <= n && b <= n){
  	if(a >= b){
  		b+= a;
	  }
	else{
		a+=b;
	}
	res++;
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
}
