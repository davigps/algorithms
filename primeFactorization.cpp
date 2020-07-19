#include <iostream>
using namespace std;

int f[100], expo[100], len;

void primeFact(int n) {
  if (n == 1) {
    len++;
    f[len] = 2;
    expo[len] = 0;
    return;
  }
  
  int d = 2;
  while (n > 1 && 1LL * d * d <= n) {
    int k = 0;
    while (n % d == 0) {
      n /= d;
      k++;
    }
    if (k > 0) {
      len++;
      f[len] = d;
      expo[len] = k;
    }
    d++;
  }

  if (n > 1) {
    len++;
    f[len] = n;
    expo[len] = 1;
  }
}

int main() {
  int n;
  cin >> n;

  primeFact(n);

  cout << "\nPRIMES:" << endl;

  int i = 1;
  while (f[i] != 0) {
    cout << f[i] << " ** " << expo[i] << endl;
    i++;
  }

  return 0;
}
