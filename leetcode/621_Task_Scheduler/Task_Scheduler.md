# 621. Task_Scheduler

## Question description

​	Given a char array representing tasks CPU need to do. It contains capital letters A to Z
where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

​	However, there is a non-negative cooling interval n that means between two same tasks, 
there must be at least n intervals that CPU are doing different tasks or just be idle.You need to return the least number of intervals the CPU will take to finish all the given tasks.

## Analysis

1. 初始想法，將所有任務次數統計之後，找出最頻煩的任務先將它排列。

   ```
   A B C D
   4 3 2 2
   ```

 2. 設 interval 為 n
    2.1	假設 n = 2 則
    	A _ _ A _ _ A _ _ A
    	AB_AB_AB_A
    	AB_ABCABCA
    	ABDABCABCAD => 此最佳結果為任務總數

    2.2	n = 1 應該也是同上 => 最佳結果為任務總數

    2.2	n = 3
    	A _ _ _ A _ _ _ A _ _ _ A
    	AB_ _ AB _ _ AB _ _ A
    	AB_ _ AB _ CAB _ CA
    	ABD_ABDCAB _ CA => 最佳結果為 (n + 1) * ( count(A) - 1) + 1

	3. 暫時推論，當 n 相對於任務數越小越好排，就是等於任務總數

	4. 考慮最高頻率之任務有複數

    ```
    A B C D E
    4 4 3 2 2
    ```

    4.1	將AB 視為同一個任務，且 n = 4
    	AB _ _ _ AB _ _ _ AB_ _ _ AB
    	AB_ _ CAB_ _ CAB_ _ CAB
    	ABD_CABD_CAB_ _CAB
    	ABD_CABDECAB_ECAB = > 最佳結果為 (n + 1) * ( count(A) - 1) + 2

    4.2	當 n = 3, n = 2, n = 1 => 最佳結果為 任務總數

	5. ！！！Note 任務排序應該均勻且來回 放置

    EX：A _ _ _ _ A _ _ _ _ A _ _ _ _ A

    ​	A 1 _ _ _ A 1 _ _ _ A 1 _ _ _ A
    	A 1 _ _ 2 A 1 _ _ 2 A 1 _ _ 2 A <= 第2次可以從後面開始放

## Conclusion

最後公式推導為
max( 任務總數, (n + 1) * ( count(A) - 1) + 有幾個相同最高頻率任務 )