/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (55.95%)
 * Likes:    718
 * Dislikes: 0
 * Total Accepted:    224.4K
 * Total Submissions: 401.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 
 * 
 * 
 */

// @lc code=start
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
class Solution
{
public:
    // bool isBalanced(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return true;
    //     //获取左右孩子的高度
    //     int left = getHeight(root->left);
    //     int right = getHeight(root->right);
    //     return abs(right - left) <= 1 && isBalanced(root->left) && isBalanced(root->right); //左右相差1以内且左右孩子也是BST
    // }
    // int getHeight(TreeNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return 0;
    //     }
    //     return max(getHeight(root->left), getHeight(root->right)) + 1;
    // }

    //递归写法
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }
    int height(TreeNode *root)
    {
        // 左右孩子均bst
        if (root == nullptr)
            return true;
        // 左右孩子都为平衡数且高度相差不过1
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1 || left == -1 || right == -1)
        {
            return -1;
        }
        return max(left, right) + 1;
    }
};
// @lc code=end
