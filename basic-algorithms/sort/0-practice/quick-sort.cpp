#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int arr[N];
int n;
int k;

int quickSort(int arr[], int l, int r, int k) {
  if (l == r) return arr[l];
  int x = arr[l + r >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    while (arr[++i] < x);
    while (arr[--j] > x);
    if (i < j) swap(arr[i], arr[j]);
  }
  int sl = j - l + 1;
  if (k <= sl) return quickSort(arr, l, j, k);

  return quickSort(arr, j + 1, r, k - sl);
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << quickSort(arr, 0, n - 1, k) << endl;
  return 0;
}
