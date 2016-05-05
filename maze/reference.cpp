/*#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define N 92
int L[92], R[92];

int main()
{
  char pat[3] = {};
  int m, n;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) {
    cout<<"._";
    L[i] = R[i] = i;
  }
  L[n] = n - 1;

  printf(".\n|");
  while (m--) {
    for (int i = 0; i < n; i++) {
      int j = L[i + 1];
      if (i != j && rand() % 3) {
        L[R[j] = R[i]] = j;
        L[R[i] = i + 1] = i;
        pat[1] = '.';
      } else
        pat[1] = '|';
      if (i != L[i] && rand() % 3) {
        L[R[i]] = L[i];
        R[L[i]] = R[i];
        L[i] = R[i] = i;
        pat[0] = '_';
      } else
        pat[0] = ' ';
      printf(pat);
    }
    printf("\n|");
  }

  pat[0] = '_';
  for (int i = 0; i < n; i++) {
    int j = L[i + 1];
    if (i != j && (i == L[i] || rand() % 3)) {
      L[R[j] = R[i]] = j;
      L[R[i] = i + 1] = i;
      pat[1] = '.';
    } else
      pat[1] = '|';
    L[R[i]] = L[i];
    R[L[i]] = R[i];
    L[i] = R[i] = i;
    printf(pat);
  }
}*/