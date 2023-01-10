#### BFS

##### 1. 树的BFS
> <img src="https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tLzc1ZmM0MmEyY2ZhY2Y2ZTQxYTg2YjM0YjE4NjFkMmNkY2QyOTY1YjIwZDhlYmMwYTZkY2M0MWJiMWZiY2VhMzEtQkZTLWFuZC1ERlMtQWxnb3JpdGhtcy5wbmc?x-oss-process=image/format,png">


##### 2. 图的单源BFS
> <img src="https://pic.leetcode-cn.com/a3f28eeb94837d510ad7360e756881059e65ca78489d4d9bae6973884b9870bb-%E5%8D%95%E6%BA%90BFS.gif">2

###### [LC433. 最小基因变化](/markdown/LC433.%20%E6%9C%80%E5%B0%8F%E5%9F%BA%E5%9B%A0%E5%8F%98%E5%8C%96.md)

###### [LC399. 除法求值](/workspace/399.%E9%99%A4%E6%B3%95%E6%B1%82%E5%80%BC.cpp)

##### 3. 双向BFS
> 双向BFS和单向BFS是等价的
>
> ![双向BFS](/appendix/%E5%8F%8C%E5%90%91BFS.png)
> 
> ![双向BFS-2](/appendix/%E5%8F%8C%E5%90%91BFS-2.png)

###### [LC127. 单词接龙](/workspace/127.%E5%8D%95%E8%AF%8D%E6%8E%A5%E9%BE%99.cpp)


##### 4. 多源BFS
> <img src="https://pic.leetcode-cn.com/be6bdff2b8d983d2135e5d2675b4dae750fef16104c904e462d9b1d64ef6d8ed-%E5%A4%9A%E6%BA%90BFS.gif">
> 
> <img src="https://assets.leetcode-cn.com/solution-static/542/fig1.PNG">
>
> 与单源BFS的差别在于, 相当于引入超级源点(S), 在初始化`queue`时, 存储BFS所有起点(上图中的0)

###### [LC542. 01矩阵](/workspace/542.01-%E7%9F%A9%E9%98%B5.cpp)

###### [LC1162. 地图分析](/workspace/1162.%E5%9C%B0%E5%9B%BE%E5%88%86%E6%9E%90.cpp)