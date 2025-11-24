#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void solve(){
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	printf(a+b==c ? "YES\n" : "NO\n");
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
}
