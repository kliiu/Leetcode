# Leetcode notes

Record of my mistakes, thoughts and everything.

*Practice makes perfect.*

*坚持就是胜利*



# **计划**
基础
* 数组，队列，栈
* 链表
* 树与递归
* 哈希表
* 双指针


第一遍按tag刷，第二遍一题多解，多题同解
# So it begins
## 数组
### 2022.1.18
tag:数组 简单
1. 两数之和
2. 删除有序数组中的重复项
   > o(1)：空间复杂度，即运行过程中临时占用存储空间大小的量度不随
   > 处理数据量n大小而改变
3. 移除元素
4. 搜索插入位置
   用二分写的，注意边界值处理。此题也可暴力解

### 2022.1.20
1.存在重复元素
> STL:sort函数

53.最大子数组和

> pre=max(pre+x,x)
> maxAns=(pre,maxAns)

88.合并两个有序数组
> **二分法**
> 这题写了好久。一定要注意细节
> ![88题](pics/88题.png)

### 2022.1.22

350. 两个数组的交集
> 首先暴力循环没想到过了。
> 思路；用一个if_add数组存储标志nums2中的元素是否已经被添加过，遍历nums1，依次与nums2中元素比较。
> 若num2中元素已被添加过，跳过；若未添加过且与此元素相等加入ans并break，从nums1下一个元素开始依次与nums2中的比较

> char字符应用单引号而不是双引号，排错花了一定时间

121. 买卖股票的最佳时机
> 可能是动态规划问题
>
> 第一想法：双层循环遍历，从第i天买入，第j天卖出若卖出价格大于买入且利润大于之前则更新为maxprofit；
> **超时**

> 抽象具体比较过程，将其当成动态过程，只需要做一次扫描，在每一步寻找最优解；
> 维持更新最小买入和最大利润变量（最大利润变量>0）

> **记得返回答案 = =**
>
### 1.23
566. 重塑矩阵
> 暴力求解 AC
> 思路：首先判断是否合理（行列数相乘看是否相等），再将原矩阵全部展平为向量存储。
> 最后根据所求矩阵行列数，一行行填入答案。空间占用高，时间也高
>
> 官方解：通过两层索引，根据矩阵元素在矩阵中位置下标与列数的关系直接赋值：
> `ans[x/c][x%c]=nums[x/n][x%n]`;
> 时间空间均更优化
>
118. 杨辉三角
> 暴力解决 ，依次求前一行中两个元素的和
36. 有效的数独
   > 用一个二维数组9*9存储是否已经出现过
   ![36-1](pics/36.png)
   > 内存可以不使用vector或许会更好？
   >   ![36-2](pics/36-2.png)
73. 矩阵置0
   > 直接AC，但用时内存均不优。思路：先遍历一次用两个set保存需要置0的行列数，再遍历置0。
   > 一次遍历？不可。
   >
---
(从此开始将题解及思路写入单独文件。)
## 字符串
387.[字符串中的第一个唯一字符](/Problems/387字符串中的第一个唯一字符.md)

383.[赎金信](/Problems/242赎金信.md)

242.[有效的字母异位词](/Problems/242有效的字母异位词.md)
### date:0129

## 链表
141.[环形链表](/Problems/141环形链表.md)

21.[合并两个链表](/Problems/21合并两个有序链表.md)

### 0205 （过年偷懒了）链表完结撒花
203.[移除链表元素](/Problems/203移除链表元素.md)

206.[反转链表](/Problems/206反转链表.md)

83.[删除排序链表中的重复元素](/Problems/83删除排序链表中的重复元素.md)

## 栈/队列
20.[有效的括号](/Problems/20有效的括号.md)

232.[用栈实现队列](/Problems/232用栈实现队列.md)

104.[二叉树的最大深度](/Problems/104二叉树的最大深度.md)

101.[对称二叉树](Problems/101对称二叉树0.md)

226.[翻转二叉树](Problems/226翻转二叉树.md)

112.[路径总和](Problems/112路径总和.md)

700.[二叉搜索树中的搜索](Problems/700二叉搜索树中的搜索.md)

701.[二叉搜索树中的插入操作](Problems/701二叉搜索树中的插入操作.md)

98.[验证二叉搜索树](Problems/98-0验证二叉搜索树.md)

653.[两数之和 IV - 输入 BST](Problems/653两数之和IV-输入BST.md)

235.[二叉搜索树的最近公共祖先](/Problems/235二叉搜索树的最近公共祖先.md)

## **接下来开始刷Leetcode100**

先易后难

### **22.3.10**

70.[爬楼梯](/Problems/70爬楼梯.md)

### **22,3,11**

155.[最小栈](/Problems/155最小栈.md)

169.[多数元素](/Problems/169多数元素.md)

234.[回文链表](Problems/234回文链表.md)

## 220313

283.[移动零](Problems/283移动零.md)

338.[比特位计数](Problems/338比特位计数.md)

## 220321

448.[找到所有数组中消失的数字](/Problems/448找到所有数组中消失的数字.md)

461.[汉明距离](/Problems/461汉明距离.md)

## 220322
543.[二叉树的直径](/Problems/543二叉树的直径.md)

## 220323
617.[合并二叉树](/Problems/617合并二叉树.md)

## 中等题
## 220324
2.[两数相加](/Problems/2两数相加.md)

3.[无重复字符的最长字串](/Problems/3无重复字符的最长子串.md)

## 220325
5.[最长回文子串](/Problems/5最长回文子串.md)

11.[盛最多水的容器](/Problems/11盛最多水的容器.md)

## 220326
15.[三数之和](Problems/15三数之和.md)

17.[电话号码的字母组合](/Problems/17电话号码的字母组合.md)

19.[删除链表的倒数第N结点](/Problems/19删除链表的倒数第N个结点.md)

## 220328
22.[括号生成](Problems/22括号生成.md)

## 220329
31.[下一个排列](Problems/31下一个排列.md)

## 220405
33.[搜索旋转排序数组](/Problems/33搜索旋转排序数组.md)

## 220406
[34.在排序数组中查找元素的第一个和最后一个位置](/Problems/34在排序数组中查找元素的第一个和最后一个位置.md)

196.[删除重复的电子邮箱]([https://leetcode.cn/problems/delete-duplicate-emails/](https://leetcode.cn/problems/delete-duplicate-emails/))

```sql
 delete 
 from Person
 where id not in ( 
                   select MIN(id)
                   from person
                   group by email)
```

197.[上升的温度]([https://leetcode.cn/problems/rising-temperature/](https://leetcode.cn/problems/rising-temperature/))

```sql
select id 
from Weather w1
where  Temperature > (select Temperature
                      from Weather w2
                      where w2.recordDate=dateadd(dd,-1,w1.recordDate))
```
`dateadd(datepart,number,date)`在日期中添加或减去指定时间间隔。

如 `dateadd(yy,1,’2020-1-1’)`

得到: `2021-1-1 00:00:00.000`