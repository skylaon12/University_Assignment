//#include <iostream>
//#include <algorithm>
//#define inf 1000000;
//using namespace std;
//
//
//int C[2001][2001] = { 0 };
//int M[2001][2001] = { 0 };
//int matrixPath(int n) {
//
//	for (int j = 1; j <= n; j++) {
//		::C[0][j] = inf;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		::C[i][n + 1] = inf;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = n; j >= 1; j--) {
//			::C[i][j] = ::M[i][j] + min({::C[i][j + 1], ::C[i - 1][j], ::C[i - 1][j + 1]});
//		}
//	}
//
//
//	return C[n][1];
//}
//
//int main(void) {
//
//	int num = 0;
//	cin >> num;
//
//	for (int i = 1; i <= num; i++) {
//		for (int j = 1; j <= num; j++) {
//			cin >> ::M[i][j];
//		}
//	}
//
//	int a = matrixPath(num);
//	cout << a;
//
//	return 0;
//}
