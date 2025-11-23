#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n;
vector<int> lista;

bool comp(int a, int b){
	return b >= a;
}

namespace jeden{
	void print(int a){
		cout << "(" << a << ")\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	n = 7;
	lista = {6,5,2,0,1,-1};
	sort(lista.begin(), lista.end(), comp);

	for(auto el : lista) cout << el << ' ';
	cout << endl;
	
	while(true){
		cout << 1 << endl;
	}
	jeden::print(6);
}

