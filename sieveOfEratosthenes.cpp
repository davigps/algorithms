#include <iostream>
using namespace std;

bool isPrime[1000000];

void soe(int limit) {
  for (int i = 2; i <= limit; i++) isPrime[i] = true;

  for (int i = 2; i * i <= limit; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  soe(n);

  cout << "\nPrimes until " << n << ":" << endl;

  for (int i = 0; i <= n; i++) {
    if (isPrime[i]) cout << i << endl;
  }

  return 0;
}
