#include <stdio.h>
#include <string.h>

#define MAXSTRING 47
int subs[MAXSTRING][MAXSTRING];

int levenshtein(char a[], char b[]) {
  size_t lenA = strlen(a);
  size_t lenB = strlen(b);

  int vi[3] = {0, -1, -1};
  int vj[3] = {-1, -1, 0};

  for (int i = 0; i < lenA + 1; i++) {
    for (int j = 0; j < lenB + 1; j++) {
      if (i == 0) {
        subs[i][j] = j;
      } else {
        if (j == 0) subs[i][j] = i;
        else {
          int smallest = 1000;
          for (int z = 0; z < 3; z++) {
            smallest = smallest < subs[i + vi[z]][j + vj[z]] ? smallest : subs[i + vi[z]][j + vj[z]];
          }
          if (a[i - 1] == b[j - 1]) subs[i][j] = subs[i - 1][j - 1];
          else subs[i][j] = smallest + 1;
        }
      }
    }
  }

  return subs[lenA][lenB];
}

int main() {
  char stringA[MAXSTRING], stringB[MAXSTRING];
  fgets(stringA, MAXSTRING, stdin);
  fgets(stringB, MAXSTRING, stdin);

  if (stringA[strlen(stringA) - 1] == '\n') stringA[strlen(stringA) - 1] = '\0';
  if (stringB[strlen(stringB) - 1] == '\n') stringB[strlen(stringB) - 1] = '\0';

  int dis = levenshtein(stringA, stringB);

  printf("Distance: %d\n\n", dis);

  size_t lenA = strlen(stringA);
  size_t lenB = strlen(stringB);

  for (int i = 0; i < lenA + 1; i++) {
    for (int j = 0; j < lenB + 1; j++) {
      printf ("%d ", subs[i][j]);
    }
    printf("\n");
  }
}
