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
	
	int n = rnd(1,10), m = rnd(1,3);
	cout << n << ' ' << m << endl;
	for(int i = 0; i < m; i++){
		int t = rnd(1,2);
		cout << t << ' ';
		if(t == 1){
			int l = rnd(0, n-1);
			int r = rnd(l+1, n);
			int v = rnd(1, 10);
			cout << l << ' ' << r << ' ' << v << endl;
		} else{
			int l = rnd(0, n-1);
			int r = rnd(l+1, n);
			cout << l << ' ' << r << endl;
		}
	}
}
