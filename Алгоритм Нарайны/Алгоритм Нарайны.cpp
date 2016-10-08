// Алгоритм Нарайны.cpp: определяет точку входа для консольного приложения.
//

#include "iostream"
#include "cstdlib"
using namespace std;
//проврка является ли перестанока последней.
bool is_last_perm(int *perm, int n) {
	for(int i = 0; i<n - 1; i++)
		if(perm[i] < perm[i + 1])
		return false;
	return true;
}
//определение начала подперестановки
int get_first_numb_subperm(int *perm, int n) {
	int first_elem = n - 1;
		while ((perm[first_elem - 1] > perm[first_elem]) && (first_elem >= 1)) {
			first_elem--;
		}
	return first_elem;
}
//поиск индекса наименьшего элемента подперестановки.
int find_index_subperm(int *perm, int n, int first_elem) {
	for(int i = first_elem; i<n; i++)
		if(perm[first_elem - 1] < perm[n - 1 + first_elem - i])
		return(n - 1 + first_elem - i);
}
//обмен значений
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
//обмен местами элементов подстановки
void reverse_subperm(int *perm, int n, int first_elem) {
	int med = (first_elem + (n - 1)) / 2;
	for (int i = 0; i <= med - first_elem; i++)
		swap(perm[first_elem + i], perm[n - 1 - i]);
}
//Функция
int* next_perm(int *perm, int n) {
	if (!is_last_perm(perm, n)) {
		int first_numb_subperm =
			get_first_numb_subperm(perm, n);
		int index_elem_subperm =
			find_index_subperm(perm, n, first_numb_subperm);
		swap(perm[first_numb_subperm - 1],
			perm[index_elem_subperm]);
		reverse_subperm(perm, n, first_numb_subperm);
	}
	return(perm);
}

void perm_gen(int n) {
	int *perm = new int[n];
	for (int i = 0; i < n; i++) {
		perm[i] = i + 1;
		cout << perm[i] << " ";
	}
	cout << endl;
	while (!is_last_perm(perm, n)) {
		perm = next_perm(perm, n);
		for (int i = 0; i < n; i++)
			cout << perm[i] << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	printf("n:\n>");
	int a = 0;
	cin >> a;
	perm_gen(a);
	system("pause");
    return 0;
}

