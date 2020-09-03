#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
int fwt[MAXN], n;

void update(int idx, int val) {
    while (idx <= n) {
        fwt[idx] += val;
        idx += (idx & -idx);
    } 
}

int query(int r) {
    int res = 0;
    
    while (r > 0) {
        res += fwt[r];
        r -= (r & -r);
    }
    
    return res;
}

int main() {
    cout << "Number of items: ";
    cin >> n;
    
    cout << "Items:\n";
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        update(i, num);
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
            cout << "Sum: " << query(r) - query(l - 1) << endl;
        } else if (op == 2) {
            int i, x;
            cin >> i >> x;
            update(i, x);
            cout << "Value " << x << " added on index " << i << ".\n"; 
        } else break;
    }
    
    
    return 0;
}
