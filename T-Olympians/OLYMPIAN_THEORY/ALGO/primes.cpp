// 1 2 3 4 5 ... 100
// 1 ... n 
// n / ln n <= tyle jest liczb pierwszych
// ln n <= srednia odleglosc pomiedzy dwoma liczbami pierwszymi

// 2*3 = 6
// wszystkie liczby pierwsze w tym zakresie 

// log2 100 = 7 
// 100/7 = 15 <= 20
// 2 3 4 5
#include<bits/stdc++.h>
using namespace std;


bool pierwsza(int n){ //O(sqrt(n))
	for(int i = 2; i*i <= n; i++) if(n % i == 0) return false;
	return true;
}

vector<int> dzielniki(int n){
	vector<int> dzil;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			dzil.push_back(i);
			if(i != n/i) dzil.push_back(n/i);
		}
	}
	return dzil;
}









n







n
int wynik;
cout << wynik % (10^9+7);

modulo 10^9+7







// n = 10^16
0...n 
n/ln n   

n = 100
log n = 7 
n = 1000
log n = 10


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << sqrt(1000) << endl;

	for(int i = 2; i*i <= n; i++){

	}

	vector<int> liczby_pierwsze;
	for(int i = 1; liczby_pierwsze.size() < 15; i++){
		if(pierwsza(i)){
			liczby_pierwsze.push_back(i);
		}
	}
}


int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}