#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vi{1,2,5,5,4,3,3,7,4,8};
    sort(vi.begin(), vi.end());
    // cout<<*unique(vi.begin(), vi.end())<<endl;  // (*返回值)是重复元素的开始位置
    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    for(vector<int>::iterator it=vi.begin(); it!=vi.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}