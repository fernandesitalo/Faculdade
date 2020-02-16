#include <bits/stdc++.h>
using namespace std;

template < class T >
void quickSort (T* arr, int left, int right)
{
  if (left >= right)
    return;

  register int l = left, r = right;
  T& pivot = arr[(left + right) / 2];

  /* partition */
  while (l <= r)
  {
    while (arr[l] < pivot) ++l;
    while (arr[r] > pivot) --r;
    if (l <= r) swap(arr[l++], arr[r--]);
  }

  /* recursion */
  quickSort(arr, left, r);
  quickSort(arr, l, right);
}

int main()
{
  srand(0);

  int n = 1e6, a[n];

  for (int i = 0; i < n; ++i) a[i] = i;

  quickSort(a, 0, n - 1);
  //sort(a, a + n);

  if (!is_sorted(a, a + n))
    cerr << "Erro" << endl;

  return 0;
}
