#### topK

##### 0. 快速选择
###### [剑指offer76. 数组中第K大的数字](/%E5%89%91%E6%8C%87offer/76.%20%E6%95%B0%E7%BB%84%E4%B8%AD%E7%AC%ACK%E5%A4%A7%E7%9A%84%E6%95%B0%E5%AD%97.md)

##### 1. 堆 `O(nlogk)`

###### [LC703. 数据流中第K大元素](/workspace/703.数据流中的第-k-大元素.cpp)
> 维护一个大小不超过`K`的`priority_queue`(小顶堆, 因为要弹出的是小元素)

###### [剑指offer60. 出现频率最高的K个数字](/%E5%89%91%E6%8C%87offer/60.%20%E5%87%BA%E7%8E%B0%E9%A2%91%E7%8E%87%E6%9C%80%E9%AB%98%E7%9A%84k%E4%B8%AA%E6%95%B0%E5%AD%97.md)
> 先统计频次, 然后将元素以`<frequency, element>`的`pair`组织起来, 放到大小为`K`的`priority_queue`中, 按第一维`frequency`排序


##### 2. [多路归并](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%A4%9A%E8%B7%AF%E5%BD%92%E5%B9%B6.md)
