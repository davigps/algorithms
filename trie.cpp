#include <bits/stdc++.h>
using namespace std;

#define SIZE 26

typedef struct TrieNode {
    bool endOfWord;
    struct TrieNode *children[SIZE];
} TrieNode;

TrieNode *newNode() {
    TrieNode *node = new TrieNode();

    node->endOfWord = false;

    for (int i = 0; i < SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(TrieNode *root, string key) {
    TrieNode *current = root;

    for (char c : key) {
        int index = c - 'a';

        if (!current->children[index]) {
            current->children[index] = newNode();
        }

        current = current->children[index];
    }

    current->endOfWord = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *current = root;

    for (char c : key) {
        int index = c - 'a';

        if (!current->children[index]) {
            return false;
        }

        current = current->children[index];
    }

    return current->endOfWord;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> words;
    while (n--) {
        string current;
        getline(cin, current);
        words.push_back(current);
    }

    TrieNode *root = newNode();

    for (string word : words) {
        insert(root, word);
    }

    int q;
    cin >> q;
    cin.ignore();

    vector<string> searchs;
    while (q--) {
        string current;
        getline(cin, current);

        bool result = search(root, current);

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
