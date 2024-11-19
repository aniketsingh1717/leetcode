/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(vector<int>&inorder, int target, int start, int end){
        for(int i = start; i<= end; i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }

    TreeNode* Tree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int index){
        if(inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[index]);

        int pos = find(inorder, postorder[index], inStart, inEnd);

        root->right = Tree(inorder, postorder, pos+1, inEnd , index-1);
        root->left = Tree(inorder, postorder, inStart, pos-1, index-(inEnd-pos)-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return Tree(inorder, postorder, 0, inorder.size()-1, inorder.size()-1);
        
    }
};