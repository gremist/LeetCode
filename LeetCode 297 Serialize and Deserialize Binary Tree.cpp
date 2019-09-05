// LeetCode 297 Serialize and Deserialize Binary Tree.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serializeHelper(data, root);
        return data;
    }
    
    void serializeHelper(string &data, TreeNode *root) {
        if (!root) {
            data += '#';
            return;
        }
        data += to_string(root->val);
        data += '#';
        serializeHelper(data, root->left);
        serializeHelper(data, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    TreeNode * deserializeHelper(istringstream &iss) {
        string buf;
        getline(iss, buf, '#');
        if (buf.empty()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(buf));
        root->left  = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));