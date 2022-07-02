/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, string> dataBase;
public:
    Solution() {
        srand(time(0));
    }

    string encode(string longUrl) {
        int key;
        // 生成一个dataBase中没有的key
        while (true) {
            key = rand();
            if (dataBase.count(key) == 0)
                break;
        }
        dataBase[key] = longUrl;
        return string("http://tinyurl.com/") + to_string(key);
    }

    string decode(string shortUrl) {
        // 使用key去dataBase中查找key对应的原始内容
        int p = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(p, int(shortUrl.size()) - p));
        return dataBase[key];
    }
};
// @lc code=end

