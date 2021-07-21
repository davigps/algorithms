#include <bits/stdc++.h>
using namespace std;

// Initialize global variables, like
// length of a block, numbers array, size of numbers array (n)
// and quantity of queries (m)
#define MAXN 1000000
int len, nums[MAXN], n, m;

// Struct of a query
struct Query {
	int l, r;
};

// Initialize queries array
Query queries[MAXN];

// Compare function where it tries to mantain the
// first blocks and sort by right index on same block.
bool compare(Query a, Query b) {
	int aBlock = a.l / len, bBlock = b.l / len;

	if (aBlock != bBlock) {
		return aBlock < bBlock;
	}
	
	return a.r < b.r;
}

// query all the results and print each
void queryResults() {
	// get a block length
	len = ceil(sqrt(n + .0));
	
	// Sort all queries
	sort(queries, queries + m, compare);
	
	// Initialize current variables
	int curL = 0, curR= 0;
	int curSum = 0;
	
	// For each query
	for (int i = 0; i < m; i++) {
		// get its left and right indexes
		int l = queries[i].l, r = queries[i].r;
		
		// Remove extra elements from previous range.
		while (curL < l) {
			curSum -= nums[curL];
			curL++;
		}
		
		// Both whiles add elements from current range
		while (curL > l) {
			curSum += nums[curL-1];
			curL--;
		}
		while (curR <= r) {
			curSum += nums[curR];
			curR++;
		}
		
		// Remove elements of previous range;
		while (curR > r+1) {
			curSum -= nums[curR-1];
			curR--;
		}
             
        printf("Sum of [%d, %d] is %d\n", l, r, curSum);
	}
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		Query q;
		q.l = a;
		q.r = b;
		queries[i] = q;
	}
	
	queryResults();
	
	return 0;
}
