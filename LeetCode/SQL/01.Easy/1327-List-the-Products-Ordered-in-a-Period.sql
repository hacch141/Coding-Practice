-- 1327. List the Products Ordered in a Period
-- Write a solution to get the names of products that have at least 100 units ordered in February 2020 and their amount.
SELECT p.product_name, SUM(o.unit) as unit
FROM Orders as o INNER JOIN Products as p
ON o.product_id = p.product_id AND o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY o.product_id
HAVING SUM(o.unit) >= 100;
