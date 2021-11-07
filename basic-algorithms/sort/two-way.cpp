#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
const int N = 1e6 + 10;
int arr[N];

void quickSort(int arr[], int l, int r) {
  if (l >= r) return;
  int x = arr[l + r >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    do i++; while (arr[i] < x);
    do j--; while (arr[j] > x);
    if (i < j) swap(arr[i], arr[j]);
  }
  quickSort(arr, l, j);
  quickSort(arr, j + 1, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
