class Trie {
public:
	struct Node
	{
		Node* son[26];
		bool is_end;

		Node() {
			for (int i = 0; i < 26; ++i) {
				son[i] = nullptr;
				is_end = false;
			}
		}
	}*root;

	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node* p = root;
		for (auto x : word) {
			int u = x - 'a';
			if (!p->son[u]) p->son[u] = new Node();
			p = p->son[u];
		}
		p->is_end = true;
	}

	bool search(string word) {
		Node*p = root;
		for (auto x : word) {
			int u = x - 'a';
			if (!p->son[u]) return false;
			p = p->son[u];
		}
		return p->is_end;
	}

	bool startsWith(string prefix) {
		Node*p = root;
		for (auto x : prefix) {
			int u = x - 'a';
			if (!p->son[u]) return false;
			p = p->son[u];
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/