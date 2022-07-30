/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // 用vector模拟栈
        vector<int> sk;
        for(int ast: asteroids){
            bool alive = true;
            while(alive && ast<0 && !sk.empty() && sk.back()>0){
                if(sk.back() <= -ast){
                    if(sk.back() == -ast)
                        alive = false;
                    sk.pop_back();
                }
                else{
                    alive = false;
                }
            }
            if(alive == true){
                sk.push_back(ast);
            }
        }
        return sk;
    }
};
// @lc code=end

