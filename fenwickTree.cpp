#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    // Array of tree's bits
    vector<int> bit;
    int n;
    
    // Initializing bits, all initialy with zero
    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    
    // For the sum query, decrease the index until 0.
    // Return total sum 
    int sum(int r) {
        int res = 0;
        for (++r; r > 0; r -= r & -r)
            res += bit[r];
        return res;           
    }
    
    // For the range sum query, make a query for R index
    // And another for L - 1 index, return the difference
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    
    // For add query, increase the index until the end
    // And update its value
    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }
};

int main() {
    int n;
    cout << "Number of items: ";
    cin >> n;
    
    cout << "Items:\n";
    FenwickTree tree = FenwickTree(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        tree.add(i, num);
    }
    
    while (true) {
        cout << "\nChoose your operation...\n";
        cout << "1 L R - Get the sum of [L, R] range.\n";
        cout << "2 I X - Add value X on index I.\n";
        cout << "3 - To exit.\n";
        cout << "Command: ";
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            cout << "Sum: " << tree.sum(l, r) << endl;
        } else if (op == 2) {
            int i, x;
            cin >> i >> x;
            tree.add(i, x);
            cout << "Value " << x << " added on index " << i << ".\n"; 
        } else break;
    }
    
    
    return 0;
}
