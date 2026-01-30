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
	int n = rnd(2,30);
	int m = rnd(2,30);
	vector<string> lista(n, string(m, '.'));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 && j == 0) continue;
			if(i == n-1 && j == m-1) continue;
			int prob = rnd(1,100);
			if(prob < 30) lista[i][j] = 'X';
		}
	}
	cout << n << ' ' << m << endl;
	for(auto el : lista) cout << el << endl;
}
