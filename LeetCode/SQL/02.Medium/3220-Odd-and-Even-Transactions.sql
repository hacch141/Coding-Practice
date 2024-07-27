-- 3220. Odd and Even Transactions
-- Write a solution to find the sum of amounts for odd and even transactions for each day. If there are no odd or even transactions for a specific date, display as 0.
-- Return the result table ordered by transaction_date in ascending order.
SELECT transaction_date,
    SUM(IF(amount % 2 = 1, amount, 0)) as odd_sum,
    SUM(IF(amount % 2 = 0, amount, 0)) as even_sum
FROM transactions
GROUP BY transaction_date
ORDER BY transaction_date;
