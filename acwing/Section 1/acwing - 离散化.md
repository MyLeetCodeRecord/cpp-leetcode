#### 离散化

##### 1. 去重
```CPP
vector<int> vi;
// 排序
sort(vi.begin(), vi.end());
// 去重, 并去掉末尾剩余元素
vi.erase(unique(vi.begin(), vi.end()), vi.end());
```

> [unique()](https://blog.csdn.net/hhmy77/article/details/82902389): 去重, 但不删除元素, 原数组剩余位置元素未被修改
> 
> `unique`, `sort`接受的是迭代器, 操作对象也是迭代器, 而不是容器本身, 所以这些函数执行时是无法添加或删除容器元素的
> 
> 因此要在取`unique`后返回的迭代器基础上, 继续`erase`末尾元素
```CPP
// 自己实现unique去重
vector<int>::iterator unique(vector<int> &a){
    for(int i=0, j=0; i<a.size(); i++){
        if(i>0 && a[i]!=a[i-1]){
            a[j++] = a[i];
        }
    }
    // a[0:j-1]是a中所有不同的数
    return a.begin() + j;
}
// 删除末尾元素
vi.erase(unique(vi), vi.end());
```

##### 2. 二分查找离散化的值
> 在**无重复有序数组**中查找target, 使用左侧/右侧端点模板都可以, 下面是左端点模板
```CPP
int find(int target){
    int l = 0;
    int r = vi.size()-1;    // 去重(erase)后的size
    while(l < r){
        int mid = (r-l)/2+l;
        if(vi[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
```