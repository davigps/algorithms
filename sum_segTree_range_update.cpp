#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
// Initializing data structures, the segtree must have 4 times more space than original array
int segtree[4 * MAXN], lazy[4 * MAXN], arr[MAXN];

void push(int v, int l, int r) {
	if (lazy[v]) {
		segtree[v] += lazy[v] * (r - l + 1);
		if (l != r) {
			lazy[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v];
		}
		lazy[v] = 0;
	}
}

// SegmentTree build function
// Must run in main with initial values, like: (v == 1, tl == 0, tr == n - 1)
void build(int a[], int v, int tl, int tr) {
  // If the two pointers are equal, than its a leaf, so assign a value
  if (tl == tr) {
    segtree[v] = a[tl];
  } else {
    // Else, calculate mid and build to left and the right child
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    // After the calls, assign its value according with its children
    segtree[v] = segtree[v*2] + segtree[v*2+1];
  }
}

// As this is a Sum segment Tree, we need a query sum function
int query(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l <= tl && tr <= r) return segtree[v];
	if (r < tl || tr < l) return 0;
	
	int tm = (tl + tr) / 2;
	return query(v*2, tl, tm, l, r) +
				 query(v*2+1, tm+1, tr, l, r);
}

// Update the value of some position
void update(int v, int tl, int tr, int l, int r, int add) {
	push(v, tl, tr);
	if (l <= tl && tr <= r) {
		lazy[v] += add;
		push(v, tl, tr);
		return;
	}
	if (r < tl || tr < l) return;
	
	int tm = (tl + tr) / 2;
	update(v*2, tl, tm, l, r, add);
	update(v*2+1, tm+1, tr, l, r, add);
	
	segtree[v] = segtree[v*2] + segtree[v*2+1];
}

// Test Sum Segment Tree
int main() {
	int n;
	cout << "Array's Length: ";
	cin >> n;
	
	cout << "Elements:\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	build(arr, 1, 0, n-1);
	
	while (true) {
		cout << "\nChoose one option:\n";
		cout << "1 - get sum between L and R, use: '1 L R'\n";
		cout << "2 - set number X in pos I, use: '2 X I'\n";
		cout << "3 - see initial array\n";
		cout << "4 - exit\n";
		cout << "> ";
		
		int option;
		cin >> option;
		
		if (option == 4) break;
		
		else if (option == 3) {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		
		else if (option == 2) {
			int pos, newVal;
			cin >> newVal >> pos;
			
			update(1, 0, n-1, pos, newVal);
			
			cout << "Value updated!\n";
		}
		
		else if (option == 1) {
			int l, r;
			cin >> l >> r;
			
			int result = query(1, 0, n-1, l, r);
			
			cout << "The sum of this segment is " << result << endl;
		}
	}

	return 0;
}

