# 183. Customers Who Never Order

# Write your MySQL query statement below
SELECT c.name as Customers 
FROM Customers as c
WHERE c.id NOT IN(SELECT customerId FROM Orders);
