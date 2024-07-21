-- 607. Sales Person
-- Write a solution to find the names of all the salespersons who did not have any orders related to the company with the name "RED".
SELECT s.name FROM SalesPerson as s WHERE s.sales_id NOT IN
(SELECT o.sales_id
FROM Orders as o INNER JOIN Company as c
ON o.com_id = c.com_id AND c.name = "RED");
-- OR --
SELECT name FROM SalesPerson WHERE sales_id NOT IN
(SELECT sales_id FROM Orders WHERE com_id = 
(SELECT com_id FROM Company WHERE name = "RED"));
