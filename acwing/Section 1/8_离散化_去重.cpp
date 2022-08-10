#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vi{1,2,3,3,4,5,5,7,8};
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    for(vector<int>::iterator it=vi.begin(); it!=vi.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}