-- 586. Customer Placing the Largest Number of Orders
-- Write a solution to find the customer_number for the customer who has placed the largest number of orders.
-- The test cases are generated so that exactly one customer will have placed more orders than any other customer.
SELECT customer_number
FROM Orders 
GROUP BY customer_number
ORDER BY COUNT(order_number) DESC
LIMIT 1;
-- OR --
SELECT customer_number 
FROM (
    SELECT customer_number, count(order_number) as orderCNT
    FROM Orders
    GROUP BY customer_number
) as temp
WHERE orderCNT = (SELECT MAX(orderCNT) FROM (
    SELECT customer_number, count(order_number) as orderCNT
    FROM Orders
    GROUP BY customer_number
) as temp2);
