/*1. 通勤车油耗【难度1星】
第一题. 字节跳动在北京有N个工区，形成一个环状，Bytebus是往返在各个工区的通勤车，按工区的顺序行驶，其中第 i 个工区有汽油 gas[i] 升。你有一辆油箱容量无限的的Bytebus，从第 i 个工区开往第 i+1 个工区需要消耗汽油 cost[i] 升。你从其中的一个工区出发，开始时油箱为空。如果你可以绕环路行驶一周，则返回出发时工区的编号，否则返回 -1。
输入:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
输出: 3
    追问：
如果油箱容量有限，怎么考虑？

时间复杂度:
O(n2)
解题思路：
两层循环遍历，用一个临时变量表示当前油量，不能超过油箱最大值，也不能< 0。
*/

/*2.  糖果屋【难度3星】
第二题. 小明要在街上一排互相相邻的糖果屋拿糖，但不能在两个相邻的糖果屋同时拿糖。给定一个数组列表，每个元素代表每间房子中的糖的数目，小明一次最多能拿多少糖。
追问：
糖果屋由一排变成环状，这时候小明一次最多能拿多少糖。
基本样例输入输出：
输入: [1,5,3,1,7]
输出: 12
追问样例输入输出：
输入: [2,3,2]
输出: 3
时间复杂度:
O(n)
解题思路：
    1. 动态规划，递归式：
f(0) = nums[0]
f(1) = max(num[0], num[1])
f(k) = max( f(k-2) + nums[k], f(k-1) )
    2. 在上面的基础上，增加两种情况：
1）拿第一家，不拿最后一家。
2）拿最后一家，不能拿最后一家
可以将第一问写好的方法抽象成一个函数，然后比较两种情况的最大值，得到结果。
*/

/*3. 程序员买咖啡【难度1星】
在公司楼下的咖啡厅上，每一杯美式咖啡的售价为 5 元；程序员在排队购买咖啡，一次购买一杯。
每位程序员只买一杯咖啡，然后向你付 5 元、10 元或 20 元。你必须给每个程序员正确找零。
注意，一开始你手头没有任何零钱，并且每位程序员急于回去写代码因此不能等待后边有零钱了再找。
如果你能给每位程序员正确找零，返回 true ，否则返回 false 。
输入描述
第一行输入一个数组，数组的项取值仅为 5、10、20 三种，例如 [5, 5, 5, 10, 20]（数组项少于 1000）
输出描述
如果能正常找零，输出 true
如果不能正常找零，输入 false
示例1
输入
[5, 5, 5, 10, 20]
输出
true
解题思路：
先判断是否需要找零，如果不需要（只有5元的时候不需要），把收到的零钱存到一个收入的数组里面
如果需要找零，那么从收入的数组里面判断有无对应的零钱（其实就三种情况 [5],[5,10],[5,5,5]）即可
*/

/*4. 快速找出完全二叉树的最后一个叶子节点（难度4星，30分钟，满分5分）
一棵完全二叉树，采用链式存储，给定它的根节点，快速找出最后一个叶子结点，并打印出其值。
struct BinaryTreeNode
    {
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
      };
思路：类似于二分查找，首先遍历最左分支，求出二叉树的高度；然后对于每个子树的根节点，先从他的右子树开始，沿着左分支一直走到最后一层，如果深度等于树的深度且该最后节点右边没有节点，则为所求；否则，右侧有节点，则遍历右子树，深度小于树的深度，则遍历左子树。时间复杂度是O(logn)
判分标准：
若采用层次遍历或回溯等O(n)时间复杂度，编码完成2分
        若采用二分查找或其他类似O(logN)时间复杂度，编码完成4分
        若考虑满二叉树等边界优化得5分

编码：*/

// BinaryTreeNode* getLastNode(BinaryTreeNode* root)
// {
//         if(!root || (!root->left && !root->right))return root;
//         int depth = 0;
//         BinaryTreeNode* curNode = root;
//         while(curNode)//计算二叉树的深度
//         {
//                 depth++;
//                 curNode = curNode->left;
//         }
//         int level = 0,tmpDepth = 0;
//         while(root)
//         {
//                 level++;//当前遍历到哪一层,跟节点是第一层
//                 if(level == depth)break;//防止右子树为空
//                 curNode = root;
//                 if(curNode->right)
//                 {
//                         BinaryTreeNode* pCur = curNode;//当前节点的父节点
//                         curNode = curNode->right;
//                         tmpDepth = level + 1;
//                         while(curNode->left)
//                         {
//                                 tmpDepth++;
//                                 pCur = curNode;
//                                 curNode = curNode->left;
//                         }
//                         if(tmpDepth < depth)root = root -> left;//二分查找左子树
//                         else if(!pCur->right || pCur->right == curNode)return curNode;
//                         else root = root->right;//二分查找右子树
//                 }
//                 else root = root->left;
//         }
//         return root;
// }

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	fmt.Println(input.Text())
}
