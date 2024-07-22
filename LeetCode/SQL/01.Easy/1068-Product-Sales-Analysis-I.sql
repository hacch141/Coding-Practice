-- 1068. Product Sales Analysis I
-- Write a solution to report the product_name, year, and price for each sale_id in the Sales table.
SELECT p.product_name, s.year, s.price
FROM Sales as s INNER JOIN Product as p
ON s.product_id = p.product_id;
