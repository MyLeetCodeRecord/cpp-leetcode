class Solution {
public:
    int divide(int x){
        int ans = 0;
        for(int i=2; i<=x/i; i++){
            while(x % i == 0){
                x /= i;
                ans += i;
            }
        }
        if(x != 1)
            ans += x;
        return ans;
    }
    int smallestValue(int n) {
        int _min = n;
        n = divide(n);
        while(n < _min){
            _min = n;
            n = divide(n);
        }
        return _min;
    }
};