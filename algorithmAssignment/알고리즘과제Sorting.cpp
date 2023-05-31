//#include<iostream>
//using namespace std;
//
//int comp = 0;
//int swap = 0;
//int comp2 = 0;
//int swap2 = 0;
//int comp3 = 0;
//int swap3 = 0;
//
//
//void merge(int A[], int left, int middle, int right)
//{
//	int i = left;
//	int j = middle + 1;
//	int t = 0;
//	int* temp = new int[right - left + 1];
//
//	while (i <= middle && j <= right)
//	{
//		::comp++;
//		if (A[i] <= A[j])
//		{
//			::swap++;
//			temp[t++] = A[i++];
//		}
//		else
//		{
//			::swap++;
//			temp[t++] = A[j++];
//		}
//	}
//	if (i <= middle)
//	{
//		while (i <= middle)
//		{
//			::swap++;
//			temp[t++] = A[i++];
//		}
//	}
//	else
//	{
//		while (j <= right)
//		{
//			::swap++;
//			temp[t++] = A[j++];
//		}
//	}
//	i = left, t = 0;
//	while (i <= right)
//	{
//		::swap++;
//		A[i++] = temp[t++];
//	}
//	delete[] temp;
//}
//
//void merge_sort(int A[], int left, int right)
//{
//	int middle;
//	if (left < right)
//	{
//		middle = (left + right) / 2;
//		merge_sort(A, left, middle);
//		merge_sort(A, middle + 1, right);
//		merge(A, left, middle, right);
//	}
//}
//
//int partition(int A[], int left, int right)
//{
//	int pivot = A[right];
//	int i = left - 1;
//
//	for (int j = left; j <= right - 1; j++)
//	{
//		::comp2++;
//		if (A[j] <= pivot)
//		{
//			::swap2++;
//			i += 1;
//			int temp = A[i];
//			A[i] = A[j];
//			A[j] = temp;
//		}
//	}
//	::swap2++;
//	int temp = A[i + 1];
//	A[i + 1] = A[right];
//	A[right] = temp;
//
//	return i + 1;
//}
//
//void quick_sort(int A[], int left, int right)
//{
//	if (left < right)
//	{
//		int p = partition(A, left, right);
//		quick_sort(A, left, p - 1);
//		quick_sort(A, p + 1, right);
//	}
//}
//
//void down_heap(int A[], int i, int n)
//{
//	int left = 2 * i;
//	int right = 2 * i + 1;
//	int largest = i;
//	if (left <= n)
//	{
//		::comp3++;
//		if (A[left] > A[largest])
//		{
//			largest = left;
//		}
//	}
//
//	if (right <= n)
//	{
//		::comp3++;
//		if (A[right] > A[largest])
//		{
//			largest = right;
//		}
//	}
//	if (largest != i)
//	{
//		::swap3++;
//		int temp = A[i];
//		A[i] = A[largest];
//		A[largest] = temp;
//
//		down_heap(A, largest, n);
//	}
//
//}
//
//void heap_sort(int A[], int n)
//{
//	for (int i = n / 2; i > 0; i--)
//	{
//		down_heap(A, i, n);
//	}
//
//	for (int i = n; i > 1; i--)
//	{
//		::swap3++;
//		int temp = A[i];
//		A[i] = A[1];
//		A[1] = temp;
//		down_heap(A, 1, i - 1);
//	}
//}
//
//int main(void)
//{
//	int num;
//	cin >> num;
//	int arr1[num];
//	int arr2[num];
//	int arr3[num + 1];
//
//	for (int i = 0; i < num; i++)
//	{
//		int a;
//		cin >> a;
//		arr1[i] = a;
//		arr2[i] = a;
//		arr3[i + 1] = a;
//	}
//	
//	merge_sort(arr1, 0, num - 1);
//	quick_sort(arr2, 0, num - 1);
//	heap_sort(arr3, num);
//	cout << "comp: " << ::comp << ", swap: " << ::swap << endl;
//	cout << "comp: " << ::comp2 << ", swap: " << ::swap2 << endl;
//	cout << "comp: " << ::comp3 << ", swap: " << ::swap3 << endl;
//
//	return 0;
//}