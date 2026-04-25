#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int id;
    int left;
    int right;
    int depth;
};

vector<Node> tree;
int n;

void calculateDepths(int nodeId, int depth) {
    if (nodeId == -1) return;
    tree[nodeId].depth = depth;
    calculateDepths(tree[nodeId].left, depth + 1);
    calculateDepths(tree[nodeId].right, depth + 1);
}

void swapAtDepth(int k) {
    for (int i = 1; i <= n; i++) {
        if (tree[i].depth % k == 0) {
            swap(tree[i].left, tree[i].right);
        }
    }
}

void inorderTraversal(int nodeId, vector<int>& result) {
    if (nodeId == -1) return;
    inorderTraversal(tree[nodeId].left, result);
    result.push_back(nodeId);
    inorderTraversal(tree[nodeId].right, result);
}

int main() {
    cin >> n;
    tree.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        tree[i].id = i;
        cin >> tree[i].left >> tree[i].right;
    }
    
    // Calculate depths (root is node 1 with depth 1)
    calculateDepths(1, 1);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        swapAtDepth(k);
        
        vector<int> result;
        inorderTraversal(1, result);
        
        for (size_t j = 0; j < result.size(); j++) {
            cout << result[j];
            if (j < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
