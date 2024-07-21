-- 183. Customers Who Never Order
-- Write a solution to find all customers who never order anything.
-- Return the result table in any order.
SELECT c.name as Customers 
FROM Customers as c
WHERE c.id NOT IN(SELECT customerId FROM Orders);
