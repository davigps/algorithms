#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001
#define MAXM 1001
// initializing FenWickTree 2D
int fwt[MAXN][MAXM], n, m;

// Function to add some value on specific index
void add(int x, int y, int val) {
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= m; j += j & -j) {
      fwt[i][j] += val;
    }
  }
}

// Function to get the sum some of an entire square until specific index
long long int query(int x, int y) {
  long long int sum = 0;
  
  for (int i = x; i > 0; i -= i & -i) {
    for (int j = y; j > 0; j -= j & -j) {
      sum += fwt[i][j];
    }
  }
  
  return sum;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int num;
      cin >> num;

      add(i, j, num);
    }
  }

  int commands;
  cin >> commands;

  while (commands--) {
    int type, x, y, value;
    cin >> type;

    if (type == 1) {
      cin >> x >> y >> value;

      add(x, y, value);

      cout << "Updated." << endl;
    } else {
      cin >> x >> y;
      cout << "Sum: " << query(x, y) << endl;
    }
  }

  return 0;
}
