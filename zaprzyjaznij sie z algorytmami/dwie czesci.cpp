#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

int wyszukiwanie(vector<int> lista){
	stack<int> stos;
	int jeden,dwa;
	for(auto el : lista){
		stos.push(el);

		if(stos.size() >= 2){
			jeden = stos.top();
			stos.pop();
			dwa = stos.top();
			stos.pop();
			if(jeden == dwa){
				stos.push(dwa);
				stos.push(jeden);
			}
		}
	} 
	return (stos.size() > 0 ? stos.top() : -1);
}

void solve(){
	int n,res=0;
	cin >> n;
	vector<int> lista(n, 0);
	for(auto &el : lista) cin >> el;
	int lider = wyszukiwanie(lista);
	vector<int> suma_prefix(n, 0);
	suma_prefix[0] = (lista[0] == lider);
	for(int i = 1; i < n; i++){
		if(lista[i] == lider){
			suma_prefix[i] = suma_prefix[i-1] + 1;
		}
		else suma_prefix[i] = suma_prefix[i-1];
	}
	for(int i = 0; i < n; i++){
		if(suma_prefix[i] * 2 > i+1 && (suma_prefix[n-1]-suma_prefix[i])*2 > n-i-1){
			res++;
		}
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 