### MySQL

#### 安装
> https://blog.csdn.net/xiegongmiao/article/details/103183052

#### 图解mysql
> https://xiaolincoding.com/mysql/

#### leetcode - SQL
| |题目|KEYWORD|
|  ---  |:-:|:-:|
|`select`|[584. 寻找用户推荐人](https://leetcode.cn/problems/find-customer-referee/?envType=study-plan&id=sql-beginner&plan=sql&plan_progress=11c2z63)|`ifnull(col_name, default_val)`|
|`select`|[183. 从不订购的客户](https://leetcode.cn/problems/customers-who-never-order/comments/)|`not in`子查询<br/>`left join` `is null`|
|`select`|[1873. 计算特殊奖金](https://leetcode.cn/problems/calculate-special-bonus/)|`union`<br/>`if(case, t, f)`<br/>`case when...then...else...end`<br>`模糊查询` `left(str, length)`|
|`update`|[627. 变更性别](https://leetcode.cn/problems/swap-salary/)|`if(case, t, f)`<br/>`case when...then...else...end`|
|`delete`|[196. 删除重复的电子邮箱](https://leetcode.cn/problems/delete-duplicate-emails/)|`min` `groupby`<br/>`去重delete`|
|`select`|[1667. 修复表中的名字](https://leetcode.cn/problems/fix-names-in-a-table/)|`left(str, length)`<br/>`substr(str, start)`<br/>`concat(str1, str2)`|
|`select`|[1484. 按日期分组销售产品](https://leetcode.cn/problems/group-sold-products-by-the-date/)|`count(distinct field)`<br/>`group_concat([distinct] field [order by field]separator ',')`|
|`select`|[1527. 患某种疾病的患者](https://leetcode.cn/problems/patients-with-a-condition/)|`locate(keyword, str)`<br/>`left(str, length)`<br/>`like`|
|`select`|[1965. 丢失信息的雇员](https://leetcode.cn/problems/employees-with-missing-information/)|`union all`<br/>`group by`➕`having`<br/>`not in`|
|`select`|[608. 树节点](https://leetcode.cn/problems/tree-node/)|`case when...then...else...end`|
|`select`|[176. 第二高的薪水](https://leetcode.cn/problems/second-highest-salary/)|`order by`+`limit`<br/>`ifnull(case, value)`<br/>`max(field)`|
|`select`|[175. 组合两个表](https://leetcode.cn/problems/combine-two-tables/)|`left join (on)`|
|`select`|[1581. 进店却未进行过交易的顾客](https://leetcode.cn/problems/customer-who-visited-but-did-not-make-any-transactions/)|`left join`<br/>`not_in`<br/>`count(field)`|
|`select`|[1148. 文章浏览I](https://leetcode.cn/problems/article-views-i/)|`select [distinct] field`<br/>`group by field`|
|`select`|[197. 上升的温度](https://leetcode.cn/problems/rising-temperature/)|`join`<br/>`datediff(d1, d2)`|
|`select`|[607. 销售员](https://leetcode.cn/problems/sales-person/)|`嵌套查询` `not in`|
|`select`|[1141. 查询近30天活跃用户数](https://leetcode.cn/problems/user-activity-for-the-past-30-days-i/)|`group by`➕`count`<br/>`date_diff`|
|`select`|[1693. 每天的领导和合伙人](https://leetcode.cn/problems/daily-leads-and-partners/)|`group by`➕`count(distinct field)`|
|`select`|[1729. 求关注者的数量](https://leetcode.cn/problems/find-followers-count/)|`group by`➕`count(distinct field)`|
|`select`|[586. 订单最多的客户](https://leetcode.cn/problems/customer-placing-the-largest-number-of-orders/)|`order by`➕`limit`<br/>`count(field)>=all(...)`|
|`select`|[511. 游戏玩法分析](https://leetcode.cn/problems/game-play-analysis-i/?envType=study-plan&id=sql-beginner&plan=sql&plan_progress=11c2z63)|`group by`➕`min(field)`|
|`select`|[1890. 2020年最后一次登录](https://leetcode.cn/problems/the-latest-login-in-2020/)|`group by`➕`max(field)`<br/>`year(timestamp)`|
|`select`|[1741. 查找每个员工花费的总时间](https://leetcode.cn/problems/find-total-time-spent-by-each-employee/)|`group by {fields}`➕`sum(field)`|