/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 *
 * https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (78.85%)
 * Likes:    726
 * Dislikes: 0
 * Total Accepted:    160.1K
 * Total Submissions: 203.1K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 * 
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL
 * 的节点将直接作为新二叉树的节点。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * 输出: 
 * 合并后的树:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 注意: 合并必须从两个树的根节点开始。
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
    // // 深度优先搜索0
    // TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    // {
    //     if (root1 == nullptr)
    //     {
    //         return root2;
    //     }
    //     if (root2 == nullptr)
    //     {
    //         return root1;
    //     }
    //     TreeNode *merged = new TreeNode(root1->val + root2->val);
    //     merged->left = mergeTrees(root1->left, root2->left);
    //     merged->right = mergeTrees(root1->right, root2->right);
    //     return merged;
    // }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        //首先判断两个二叉树是否为空，如果两个二叉树都为空，则合并后的二叉树也为空，
        //如果只有一个二叉树为空，则合并后的二叉树为另一个非空的二叉树。
        if (root2 == nullptr)
        {
            return root1;
        }
        if (root1 == nullptr)
        {
            return root2;
        }
        // 如果两个而二叉树都不为空，则首先计算合并后的根节点值，然后从合并后的二叉树与两个原始二叉树的节点开始广度优先搜索
        auto merged = new TreeNode(root1->val + root2->val);
        //使用三个队列存储：合并后的节点，两个原始二叉树的节点
        auto q = queue<TreeNode *>();
        auto queue1 = queue<TreeNode *>();
        auto queue2 = queue<TreeNode *>();
        q.push(merged);
        queue1.push(root1);
        queue2.push(root2);
        while (!queue1.empty() && !queue2.empty())
        {
            auto node = q.front(), node1 = queue1.front(), node2 = queue2.front();
            q.pop();
            queue1.pop();
            queue2.pop();
            auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
            if (left1 != nullptr || left2 != nullptr)
            {
                if (left1 != nullptr && left2 != nullptr)
                {
                    auto left = new TreeNode(left1->val + left2->val);
                    node->left = left;
                    q.push(left);
                    queue1.push(left1);
                    queue2.push(left2);
                }
                else if (left1 != nullptr)
                {
                    node->left = left1;
                }
                else
                {
                    node->left = left2;
                }
            }
            if (right1 != nullptr || right2 != nullptr)
            {
                if (right1 != nullptr && right2 != nullptr)
                {
                    auto right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    q.push(right);
                    queue1.push(right1);
                    queue2.push(right2);
                }
                else if (right1 != nullptr)
                {
                    node->right = right1;
                }
                else
                {
                    node->right = right2;
                }
            }
        }
        return merged;
    }
};
// @lc code=end
