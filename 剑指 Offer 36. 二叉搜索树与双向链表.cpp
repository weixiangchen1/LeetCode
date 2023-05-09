/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;

Node() {}

Node(int _val) {
val = _val;
left = NULL;
right = NULL;
}

Node(int _val, Node* _left, Node* _right) {
val = _val;
left = _left;
right = _right;
}
};
*/
class Solution {
public:
	vector<Node*> vec;

	void InOrder(Node* root) {
		if (root == nullptr) return;
		InOrder(root->left);
		vec.push_back(root);
		InOrder(root->right);
	}

	Node* treeToDoublyList(Node* root) {
		if (!root) return nullptr;
		InOrder(root);

		Node* head = vec[0];
		Node* cur = vec[0];
		for (int i = 1; i < vec.size(); ++i) {
			cur->right = vec[i];
			vec[i]->left = cur;
			cur = vec[i];
		}
		vec[vec.size() - 1]->right = vec[0];
		vec[0]->left = vec[vec.size() - 1];

		return head;
	}
};




