-- 1587. Bank Account Summary II
-- Write a solution to report the name and balance of users with a balance higher than 10000. The balance of an account is equal to the sum of the amounts of all transactions involving that account.
SELECT u.name, SUM(t.amount) as balance
FROM Transactions as t INNER JOIN Users as u
ON t.account = u.account
GROUP BY t.account
HAVING SUM(t.amount) > 10000;
-- OR  --
WITH acc AS (
    SELECT account, SUM(amount) as balance
    FROM Transactions
    GROUP BY account
)
SELECT u.name, a.balance
FROM Users as u INNER JOIN acc as a
ON u.account = a.account
WHERE a.balance > 10000;
