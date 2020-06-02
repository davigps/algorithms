#include <bits/stdc++.h>
using namespace std;

// Recursive function of Fibonacci
int fib(int n) {
  // If n == 1 || n == 0, then its fib is itself.
  if (n <= 1) return n;

  // Else, fib of n is the sum of its two antecessors, n-1 and n-2
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  cin >> n;

  cout << fib(n) << endl;
    
  return 0;
}
