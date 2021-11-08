#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0;
const int N = 1e6  + 10;
int arr[N], tmp[N];

long long mergeSort(int arr[], int l, int r) {
  if (l >= r) return 0;
  int mid = l + r >> 1;
  long long result = mergeSort(arr, l, mid) + mergeSort(arr, mid + 1, r);
  
  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
    else {
      tmp[k++] = arr[j++];
      result += mid - i + 1;
    }
  }
  
  while (i <= mid) tmp[k++] = arr[i++];
  while (j <= r) tmp[k++] = arr[j++];

  for (i = l, j = 0; i <= r; i++, j++) arr[i] = tmp[j];
  return result;
}



int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << mergeSort(arr, 0, n - 1);
  return 0;
}
