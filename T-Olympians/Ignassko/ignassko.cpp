#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string napis = "programowanie";

	for(int i = 0; i < napis.size(); i++){
		cout << napis[i] << ' ';
	}
	cout << endl;

	for(char el : napis){
		cout << el << ' ';
	}
	cout << endl;

}