/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            while (size--) {
                Node* tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);

                for (auto& x : tmp->children) {
                    q.push(x);
                }
            }
            ans.push_back(vec);
        }

        return ans;
    }
};
