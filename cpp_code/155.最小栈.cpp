/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (56.98%)
 * Likes:    940
 * Dislikes: 0
 * Total Accepted:    254K
 * Total Submissions: 445.7K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * pop、top 和 getMin 操作总是在 非空栈 上调用。
 * 
 * 
 */

// @lc code=start
#define MAX 9999
class MinStack
{
public:
    /** initialize your data structure here. */
    int array[MAX];
    int top_p = 0;
    int min_arr[MAX];
    int p_min = 0;
    MinStack()
    {
        array[0] = INT_MAX;
        min_arr[0] = 0;
    }

    void push(int val)
    {
        this->array[++this->top_p] = val;
        if (this->array[this->min_arr[this->p_min]] > val)
        {
            this->min_arr[++this->p_min] = this->top_p;
        }
    }

    void pop()
    {

        if (this->min_arr[this->p_min] == this->top_p)
        {
            this->p_min--;
        }
        this->top_p--;
    }

    int top()
    {
        return this->array[this->top_p];
    }

    int getMin()
    {
        return this->array[this->min_arr[this->p_min]];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
