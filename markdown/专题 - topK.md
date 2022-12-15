#### topK

##### 1. 堆 `O(nlogk)`

###### [剑指offer59. 数据流的第 K 大数值](/%E5%89%91%E6%8C%87offer/59.%20%E6%95%B0%E6%8D%AE%E6%B5%81%E7%9A%84%E7%AC%ACk%E5%A4%A7%E6%95%B0%E5%80%BC.md)
> 维护一个大小不超过`K`的`priority_queue`(小顶堆, 因为要弹出的是小元素)

###### [剑指offer60. 出现频率最高的K个数字](/%E5%89%91%E6%8C%87offer/60.%20%E5%87%BA%E7%8E%B0%E9%A2%91%E7%8E%87%E6%9C%80%E9%AB%98%E7%9A%84k%E4%B8%AA%E6%95%B0%E5%AD%97.md)
> 先统计频次, 然后将元素以`<frequency, element>`的`pair`组织起来, 放到大小为`K`的`priority_queue`中, 按第一维`frequency`排序


##### 2. [多路归并](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%A4%9A%E8%B7%AF%E5%BD%92%E5%B9%B6.md)
> 