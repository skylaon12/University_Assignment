//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main(void)
//{
//	int arr[100000] = { 0 };
//	int num;
//	int selection;
//	int count = 0;
//	cin >> num;
//	cin >> selection;
//
//	for (int i = 0; i < num; i++)
//	{
//		cin >> arr[i];
//	}
//	sort(arr, arr + num);
//	int start = 0;
//	int end = num - 1;
//
//	while (1)
//	{
//		if (start >= end)
//		{
//			break;
//		}
//		
//		int sum = arr[start] + arr[end];
//		if (sum == selection)
//		{
//			count++;
//			start++;
//			end--;
//		}
//		else if (sum < selection)
//		{
//			start++;
//		}
//		else
//		{
//			end--;
//		}
//	}
//	
//
//	cout << count;
//
//	return 0;
//}
