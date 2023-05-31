#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int mom_select(int A[], int l, int r, int j);
int mom_partition(int A[], int l, int r, int j);
int partition(int A[], int l, int r);
int quick_select(int A[], int l, int r, int j);


int mom_select(int A[], int l , int r, int i){
   int n = r - l+1; // size to be considered
   if(n<=5){
      return quick_select(A,l,r,i);
   }
   else{
      int G = ceil((double)n/5.0); // group size is 5 and G is the number of groups
      int *B = new int[G+1];
      
      int r_j, l_j;
      r_j = l+4;
      l_j = l;
      
      for(int j = 1; j <= G-1; j++){
         int m_j = quick_select(A,l_j,r_j,3);
         B[j] = m_j;
         r_j+=5;
         l_j+=5;
      }
      if(n%5==4){
          B[G] = quick_select(A, l_j, r, 2);
      }
      else if(n%5 == 2)
      {
         B[G] = quick_select(A, l_j, r, 1);
      }
      else if(n%5 == 3){
         B[G] = quick_select(A, l_j, r, 2);
      }
      else if(n%5 == 1){
         B[G] = quick_select(A, l_j, r, 1);
      }
      else{
         B[G] = quick_select(A, l_j, r,3);   
      }
      int M = mom_select(B, 1, G, ceil(G/2.0));
      
      int p = mom_partition(A,l,r,M);
      
      int k = p - l + 1;
      
      cout << M <<" " << k <<" "<< n << " ";
      cout << fixed << setprecision(2) << (double)k/n << endl;
      
      delete[] B;
      
      if(i<k){
         return mom_select(A,l,p-1,i);
      }
      else if(i==k){
         return A[p];
      }
      else{
         return mom_select(A,p+1,r,i-k);
      }
   }
}
int mom_partition(int A[], int l , int r, int M){
   int idx = 0;
   for(int i = l; i <= r; i++){
      if(A[i] == M){
         idx = i;
         break;
      }
   }
   swap(A[idx],A[r]);
   return partition(A,l,r);
}

int partition(int A[], int l, int r){
   int pivot = A[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
        if (A[j] <= pivot) {
            swap(A[++i], A[j]); 
        }
    }
    swap(A[i + 1], A[r]); 
    return i+1;
}


int quick_select(int A[], int l, int r, int i){
   if(l == r){
      return A[l];
   }
   int p = partition(A,l,r);
   int k = p-l+1;
   
   if(i<k)
      return quick_select(A,l,p-1,i);
   else if (i==k){
      return A[p];
   }
   else
      return quick_select(A,p+1, r, i-k);
}


int main(void){
   int input;
   int input2;
   
   cin >> input; 
   cin >> input2;
   int *arr = new int[input+1];
   for(int i = 1 ; i < input+1; i++){
      cin >> arr[i];
   }

   mom_select(arr,1,input, input2);
   
   delete[] arr;
   
   return 0;   
}
