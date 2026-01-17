#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int rnd(int a, int b){return rand()%(b-a+1) + a;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int seed; 
	cin >> seed; 
	srand(seed);
	int n = rnd(5,10);
	int m = rnd(2,5);
	string s = "PZ";
	cout << n << ' ' << m << endl;
	for(int i = 0; i < m; i++){
		int idx = rnd(0,1);
		cout << s[idx] << ' ';
		if(idx == 0){
			cout << rnd(1,n) << ' ' << rnd(1,30) << ' ' << rnd(1,10) << endl;
		} else{
			int x1 = rnd(1, n-3);
			int x2 = rnd(x1, n);
			cout << x1 << ' ' << x2 << endl;
		}
	}
}
