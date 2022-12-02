### MySQL

#### 安装
> https://blog.csdn.net/xiegongmiao/article/details/103183052

#### 图解mysql
> https://xiaolincoding.com/mysql/

#### leetcode - SQL
| |题目|KEYWORD|
|  ---  |:-:|:-:|
|`select`|[LC584. 寻找用户推荐人](https://leetcode.cn/problems/find-customer-referee/?envType=study-plan&id=sql-beginner&plan=sql&plan_progress=11c2z63)|`ifnull(col_name, 0)`|
|`select`|[LC183. 从不订购的客户](https://leetcode.cn/problems/customers-who-never-order/comments/)|`not in`子查询<br/>`left join`|
|`select`|[LC1873. 计算特殊奖金](https://leetcode.cn/problems/calculate-special-bonus/)|`union`<br/>`if(case, t, f)`<br/>`case when...then...else...end`|
|`update`|[LC627. 变更性别](https://leetcode.cn/problems/swap-salary/)|`if(case, t, f)`<br/>`case when...then...else...end`|
|`delete`|[196. 删除重复的电子邮箱](https://leetcode.cn/problems/delete-duplicate-emails/)|`min` `groupby`<br/>`去重delete`|
|`select`|[1667. 修复表中的名字](https://leetcode.cn/problems/fix-names-in-a-table/)|`left(str,length)`<br/>`substr(str, start)`<br/>`concat(str1, str2)`|
|`select`|[1484. 按日期分组销售产品](https://leetcode.cn/problems/group-sold-products-by-the-date/)|`count(distinct field)`<br/>`group_concat([distinct] field [order by field]separator ',')`|
|`select`|[1527. 患某种疾病的患者](https://leetcode.cn/problems/patients-with-a-condition/)|`locate(str, sub)`<br/>`left(str, length)`<br/>`like`|
|`select`|[1965. 丢失信息的雇员](https://leetcode.cn/problems/employees-with-missing-information/)|`union all`<br/>`group by`➕`having`<br/>`not in`|
|`select`|[608. 树节点](https://leetcode.cn/problems/tree-node/)|`case when...then...else...end`|
|`select`|[172. 第二高的薪水](https://leetcode.cn/problems/second-highest-salary/)|`order by`+`limit`<br/>`ifnull(case, value)`<br/>`max(field)`|