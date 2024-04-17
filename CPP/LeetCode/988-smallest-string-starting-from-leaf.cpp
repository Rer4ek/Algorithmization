#include <algorithm>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

	string smallestFromLeaf(TreeNode* root) {
		string ans;
		string path = "";
		dfs(root, path, ans);
		return ans;
	}

private:
	void dfs(TreeNode* root, string& path, string& ans) {
		if (root == nullptr)
			return;

		path.push_back(root->val + 'a');

		if (root->left == nullptr && root->right == nullptr) {
			reverse(path.begin(), path.end());
			if (ans == "" || ans > path)
				ans = path;
			reverse(path.begin(), path.end());
		}

		dfs(root->left, path, ans);
		dfs(root->right, path, ans);
		path.pop_back();
	}

 };