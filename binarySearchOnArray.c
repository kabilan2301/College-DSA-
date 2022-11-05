#include<stdio.h>

void main() {
  int a[10], mid, f = 0, l, n, i, key;
  printf("Enter the Size of the Array(MAX_10): ");
  scanf("%d", & n);
  printf("Enter the Values of the Sorted Array:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", & a[i]);
  }
  l = n - 1;
  mid = (f + l) / 2;
  printf("Enter the value to Search: ");
  scanf("%d", & key);
  while (f <= l) {
    if (key > a[mid]) {
      f = mid + 1;
      mid = (f + l) / 2;
    } else if (key < a[mid]) {
      l = mid - 1;
      mid = (f + l) / 2;
    } else if (key == a[mid]) {
      printf("Element present %d at the position %d", key, mid + 1);
      return;
    }
  }
  if (f > l) {
    printf("Element %d is Not present in the Array :(", key);
  }

}
