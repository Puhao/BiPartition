BiPartition
===========

使用最大二分匹配，查找最多可能的八卦情侣数目  

这里根据根据男女性别对所有人进行二分，然后不存在搞基/les情况，不能劈腿，看最多能组成多少对情侣，这正是一个典型的求二分图的最大匹配，我们可以使用匈牙利算法(Hopcroft-Karp算法更高效)来找到最大匹配。
关于最大二分匹配，请点击[推荐阅读](http://ycool.com/post/cfnym64)。

如果是要把所有的可能出现的情侣关系找出来，那我们可以采用DFS的方法搜索所有八卦可能性。