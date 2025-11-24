#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

vector<int> lista = {1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,111,222,333,444,555,666,777,888,999,1111,2222,3333,4444,5555,6666,7777,8888,9999,11111,22222,33333,44444,55555,66666,77777,88888,99999,111111,222222,333333,444444,555555,666666,777777,888888,999999,1111111,2222222,3333333,4444444,5555555,6666666,7777777,8888888,9999999,11111111,22222222,33333333,44444444,55555555,66666666,77777777,88888888,99999999};

void solve(){
	 int n,res=0;
	 cin >> n;
	 for(auto el : lista){
	 	if(el > n) break;
	 	res++;
	 }
	 cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 
