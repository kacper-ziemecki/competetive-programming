
// q - ilosc zapytan
// 1 a pytanie o dodanie wartosci a
// 2 i i-ta liczba najmniejsza

5
1 2
1 8
1 5
2 1 
2 3


// --------OPIS----------
5
1 2

{2}

1 8

{2 8}

1 5

{2 5 8}

2 1 -> 2
2 3 -> 8










vector<int> lista = {3,5,9,0,7,4};
sort(lista.begin(), lista.end(), less<int>());
sort(lista.begin(), lista.end(), greater<int>());

for(int i = 0; i < lista.size(); i++){
	cout << lista[i] << ' ';
}
cout << endl;

sort -> O(n * log n)

O(q * (n * log n))

max operacji => 10^8

q = 3*10^5
n = 3*10^5
log n = 20

O(q * log n)
O(q * log^2 n)
10^5 * (10^5 * 20) = 10^10 *20 = 2*10^11


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// ordered_set => uporządkowany zbiór
// zbiór -> nie ma żadnych powtórzeń, np. {1,6,3,9}
// w zbiorze nie mozemy mieć, np. {1,1}

ordered_set A;

//insert -> O(log n)
//normalnie push_back -> O(1)
A.insert(6);
A.insert(5);
A.insert(1);

//erase -> O(log n)
//erase w vector -> O(n)
A.erase(1);
A.erase(2);

// jezeli A = {1,4,7,8,10}
// zwraca ilosc elementow mniejszych niz 5
cout << A.order_of_key(5) << endl; // O(log n)
// to wtedy wyswietli 2

// zwraca element pod indeksem 2
cout << *A.find_by_order(2) << endl; // O(log n)
// to jest to samo, tylko uzywamy takiej metody, poniewaz nie mozemy indeksowac
cout << A[2] << endl;