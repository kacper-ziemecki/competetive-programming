#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n,m,k,zeros=0,idx,idxZero;
const int maxM = 1e6+1;
vector<int> lista[maxM], vals[maxM];
vector<pair<int,int>> res;

bool check(){
	for(int i = 0; i < m; i++){
		if(lista[i].empty()) continue;
		if(lista[i][0] == 1){
			idx = i;
			break;
		}
	}
	for(int i = 1; i < lista[idx].size(); i++){
		if(lista[idx][i] != lista[idx][i-1]+1) return false;
	}
	return true;
}

void calc_zeros(){
	for(int i = 0; i < m; i++){
		if(lista[i].empty()) zeros++;
	}
}

void print_lista(){
	cout << "lista:\n";
	for(int i = 0; i < m; i++){
		cout << '|';
		for(int j = 0; j < lista[i].size(); j++) cout << lista[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> k;
		lista[i].resize(k);
		for(int j = 0; j < k; j++) cin >> lista[i][j];
	}
	calc_zeros();
	// print_lista();
	// dbg(check(), zeros);
	if(!check() && zeros == 0){
		vector<int> mn1 = {INT_MAX,INT_MAX,INT_MAX,INT_MAX}, mn2 = {INT_MAX,INT_MAX,INT_MAX,INT_MAX};
		for(int i = 0; i < m; i++){
			vals[i] = {lista[i][0], lista[i][lista[i].size()-1], (int)lista[i].size(), i};
			if(vals[i][1] < mn1[1]) mn1 = vals[i];
		}
		for(int i = 0; i < m; i++){
			if(vals[i][0] > mn1[1] && vals[i][2] < mn2[2]) mn2 = vals[i];
		}
		if(mn2[0] != INT_MAX){ // jezeli udalo sie znalezc taki stos ktory mozna przeniesc
			dbg(mn1[0], mn1[1], mn1[2], mn1[3]);
			dbg(mn2[0], mn2[1], mn2[2], mn2[3]);
			for(int i = 0; i < lista[mn2[3]].size(); i++) res.pb({mn2[3]+1, mn1[3]+1}); // zapisywanie wyniku
			lista[mn1[3]].insert(lista[mn1[3]].begin(), lista[mn2[3]].begin(), lista[mn2[3]].end());

			lista[mn2[3]].clear();
		}
	}
	// print_lista();
	if(!check() && zeros > 0){
		for(int i = 0; i < m; i++){
			if(lista[i].empty()){
				idxZero = i;
				break;
			}
		}
		lista[idxZero].pb(1);
		lista[idx].erase(lista[idx].begin());
		res.pb({idx+1, idxZero+1}); // zapisywanie wyniku
	}
	// print_lista();
	if(check()){
		vector<pair<int,int>> sortowanie;
		for(int i = 0; i < m; i++){
			if(i == idx) continue;
			for(int j = 0; j < lista[i].size(); j++){
				sortowanie.pb({lista[i][j], i});
			}
		}
		sort(sortowanie.begin(), sortowanie.end());
		for(auto el : sortowanie){
			res.pb({el.second+1, idx+1});
		}
		// for(auto el : sortowanie) cout << el.first << ' ' << el.second << " | ";
		// cout << endl;

		cout << res.size() << endl;
		for(auto el : res){
			cout << el.first << ' ' << el.second << endl;
		}
	} else{
		cout << -1 << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}