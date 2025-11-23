#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n;
vector<int> lista;

void sortowanie(int lewo, int prawo){
	if(lewo == prawo) return;
	int srodek = (lewo+prawo)/2;
	sortowanie(lewo, srodek);
	sortowanie(srodek+1, prawo);

	int jeden = 0, dwa = 0;
	vector<int> tmp;
	for(int i = lewo; i <= prawo; i++){
		if(jeden < srodek+1 && lista[lewo+jeden] < lista[srodek+1+dwa]){
			tmp.push_back(lista[lewo+jeden]);
			jeden++;
		} else{
			tmp.push_back(lista[srodek+1+dwa]);
			dwa++;
		}
	}
	for(int i = lewo; i <= prawo; i++) lista[i] = tmp[i-lewo];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	lista.resize(n);
	for(int i = 0; i < n; i++) cin >> lista[i];

	sort(lista.begin(), lista.begin()+2);
	sortowanie(0,n-1);
	
}

