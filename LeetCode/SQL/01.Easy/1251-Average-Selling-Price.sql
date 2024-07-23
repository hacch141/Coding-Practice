-- 1251. Average Selling Price
-- Write a solution to find the average selling price for each product. average_price should be rounded to 2 decimal places.
SELECT p.product_id, 
IFNULL(ROUND(SUM(u.units * p.price) / SUM(u.units) , 2), 0) as average_price
FROM Prices as p LEFT JOIN UnitsSold as u
ON u.product_id = p.product_id AND u.purchase_date BETWEEN p.start_date AND  p.end_date
GROUP BY p.product_id;
