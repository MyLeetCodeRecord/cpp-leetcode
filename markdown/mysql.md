### MySQL

#### 安装
> https://blog.csdn.net/xiegongmiao/article/details/103183052

#### 图解mysql
> https://xiaolincoding.com/mysql/

#### leetcode - SQL入门
|       |  题目  |KEYWORD|
|  ---  |  :-:  |  :-:  |
|`select`|[584. 寻找用户推荐人](https://leetcode.cn/problems/find-customer-referee/)|`ifnull(col_name, default_val)`|
|`select`|[183. 从不订购的客户](https://leetcode.cn/problems/customers-who-never-order/comments/)|`not in`子查询<br/>`left join` `is null`|
|`select`|[1873. 计算特殊奖金](https://leetcode.cn/problems/calculate-special-bonus/)|`union`<br/>`if(case, t, f)`<br/>`case when...then...else...end`<br>`模糊查询` `left(str, length)`|
|`update`|[627. 变更性别](https://leetcode.cn/problems/swap-salary/)|`if(case, t, f)`<br/>`case when...then...else...end`|
|`delete`|[📌196. 删除重复的电子邮箱](https://leetcode.cn/problems/delete-duplicate-emails/)|`min` `groupby`<br/>`去重delete`|
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
|`select`|[511. 游戏玩法分析](https://leetcode.cn/problems/game-play-analysis-i/)|`group by`➕`min(field)`|
|`select`|[1890. 2020年最后一次登录](https://leetcode.cn/problems/the-latest-login-in-2020/)|`group by`➕`max(field)`<br/>`year(timestamp)`|
|`select`|[1741. 查找每个员工花费的总时间](https://leetcode.cn/problems/find-total-time-spent-by-each-employee/)|`group by {fields}`➕`sum(field)`|
|`select`|[1393. 股票的资本损益](https://leetcode.cn/problems/capital-gainloss/)|`group by`➕`sum(if(case, t, f))`|
|`select`|[1407. 排名靠前的旅行者](https://leetcode.cn/problems/market-analysis-i/)|`left join` `ifnull(field, default)`<br/>`group by`➕`sum`|
|`select`|[1158. 市场分析I](https://leetcode.cn/problems/market-analysis-i/)|`left join`<br/>`group by`➕`sum(if(case, 0, 1))➡️计数`|
|`select`|[182. 查找重复的电子邮箱](https://leetcode.cn/problems/duplicate-emails/?envType=study-plan&id=sql-beginner&plan=sql&plan_progress=ynevlgr)|`group by`➕`having`|
|`select`|[1050. 合作过至少三次的演员和导演](https://leetcode.cn/problems/actors-and-directors-who-cooperated-at-least-three-times/)|`group by`➕`having`|
|`select`|[1587. 银行账户概要 II](https://leetcode.cn/problems/bank-account-summary-ii/)|`group by`➕`having`<br/>`left join`|
|`select`|[1084. 销售分析III](https://leetcode.cn/problems/sales-analysis-iii/)|`in() and not in()`<br/>`group by`➕`having`|


#### leetcode - SQL基础
|       |  题目  |KEYWORD|
|  :-:  |  :-:  |  :-:  |
|`数值处理函数`|[1699. 两人之间的通话次数](https://leetcode.cn/problems/number-of-calls-between-two-persons/)|`if(case, t, f)用于交换`<br/>`group by`➕`count()`/`sum()`|
|            |[1251. 平均售价](https://leetcode.cn/problems/average-selling-price/)|`sum(price*units)/sum(units)`➡️均值<br/>`round(decimal, n)`|
|            |[1571. 仓库经理](https://leetcode.cn/problems/warehouse-manager/)|`group by`➕`sum(func\(field1, ...))`|
|            |[1445. 苹果和桔子](https://leetcode.cn/problems/apples-oranges/)|`group by`➕`sum(if(case, t, f))分情况讨论`|
|            |[1193. 每月交易I](https://leetcode.cn/problems/monthly-transactions-i/)|`group by`➕`sum(if(case, t, f))`|
|            |[1633. 各赛事的用户注册率](https://leetcode.cn/problems/percentage-of-users-attended-a-contest/)|`数字结果直接当常数使用` or `数字结果作为表的一列`<br/>`round(decimal, n)`|
|            |[1173. 即时食物配送I](https://leetcode.cn/problems/immediate-food-delivery-i/)|不分组也能用`sum()` `count(*)`<br/>`sum(布尔表达式)`等价于`sum(if(exp, 1, 0)`|
|            |[1211. 查询结果的质量和占比](https://leetcode.cn/problems/queries-quality-and-percentage/)|`group by`➕`count()` `sum()`|
|   `连接`    |[1607. 没有卖出的卖家](https://leetcode.cn/problems/sellers-with-no-sales/)|`left join on ...`<br/>`not in`|
|            |[619. 只出现一次的最大数字](https://leetcode.cn/problems/biggest-single-number/)|`select (...) as col`|
|            |[1112. 每个学生的最高成绩](https://leetcode.cn/problems/highest-grade-for-each-student/)|`in`|
|            |[1398. 购买了产品A和产品B却没有购买产品C的顾客](https://leetcode.cn/problems/customers-who-bought-products-a-and-b-but-not-c/)|`group by ... having ...`<br/>`sum(布尔表达式)`计数➡️检查存在性|
|            |[1440. 计算布尔表达式的值](https://leetcode.cn/problems/evaluate-boolean-expression/)|`case when` `全连接`|
|            |[1264. 页面推荐](https://leetcode.cn/problems/page-recommendations/)|`distinct` `in/not in`<br/>`join` `case when`|
|            |[570. 至少有5名直接下属的经理](https://leetcode.cn/problems/managers-with-at-least-5-direct-reports/)|`group by ... having ...`<br/>`join`|
|            |[1303. 求团队人数](https://leetcode.cn/problems/find-the-team-size/)|`group by ... having`<br/>`left join on ...`|
