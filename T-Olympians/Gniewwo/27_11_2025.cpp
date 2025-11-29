#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

bool comparator(int &a, int &b){
	return a >= b;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> lista(n);
	for(auto &el : lista) cin >> el;
	sort(lista.begin(), lista.end(), comparator);
	for(auto el : lista) cout << el << ' ';
	cout << endl;
}

