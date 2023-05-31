#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int momPartition(int A[], int l, int r, int M);
int partition(int A[], int l, int r);
int quickSelection(int A[], int l, int r, int i);

int momSelect(int A[], int l, int r, int i) {
	int n = r - 1 + 1;
	int mid = 0;
	if (n <= 5) {
		return quickSelection(A, l, r, i);
	}
	
	int G = ceil(n / 5.0);
	int* B = new int[G + 1];

	for (int j = 1; j < G; j++) {
		mid = quickSelection(A, l + (j - 1) * 5, 4 + l + (j - 1) * 5, 3);
		B[j] = mid;
	}

	if ((n - (G - 1) * 5) % 2 == 1) {
		mid = quickSelection(A, l + (G - 1) * 5, r, ceil((r - (G - 1) * 5) / 2.0));
		B[G] = mid;
	}
	else if ((n - (G - 1) * 5) == 4) {
		mid = quickSelection(A, l + (G - 1) * 5, r, 2);
		B[G] = mid;
	}
	else if ((n - (G - 1) * 5) == 2) {
		mid = quickSelection(A, l + (G - 1) * 5, r, 1);
		B[G] = mid;
	}

	int M = momSelect(B, 1, G, ceil(G / 2.0));

	int p = momPartition(A, l, r, M);

	int k = p - l + 1;

	cout << fixed << setprecision(2) << M << " " << k << " " << n << " " << (double)k / n;
	cout <<"\n";
	delete[] B;
	if (i < k) {
		return momSelect(A, l, p - 1, i);
	}
	else if (i == k) {
		return A[p];
	}
	else {
		return momSelect(A, p + 1, r, i - k);
	}
}

int momPartition(int A[], int l, int r, int M) {
	int idx = 0;
	for (int i = l; i <= r; i++) {
		if (A[i] == M) {
			idx = i;
		}
	}
	swap(A[idx], A[r]);
	return partition(A, l, r);
}






int partition(int A[], int l, int r) {
	int i = l - 1;
	int pivot = A[r];

	for (int j = l; j < r; j++) {
		if (pivot >= A[j]) {
			swap(A[++i], A[j]);
		}
		
	}
	swap(A[i + 1], A[r]);

	return i + 1;
}


int quickSelection(int A[], int l, int r, int i) { 
	if (l == r) {
		return A[l]; //원소가 1개일 때는 그 수를 return
	}

	int p = partition(A, l, r);

	int k = p - l + 1;
	
	if (i < k) {
		return quickSelection(A, l, p - 1, i);
	}
	else if (k == i) {
		return A[p];
	}
	else {
		return quickSelection(A, p + 1, r, i - k);
	}

}

int main(void) {
	int n;
	int a;
	cin >> n;
	cin >> a;
	int* arr = new int[n + 1];
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	momSelect(arr, 1, n, a);
	delete[] arr;
	return 0;
}
