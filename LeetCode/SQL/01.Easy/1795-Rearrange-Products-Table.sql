-- 1795. Rearrange Products Table
-- Write a solution to rearrange the Products table so that each row has (product_id, store, price). If a product is not available in a store, do not include a row with that product_id and store combination in the result table.
(SELECT product_id, 'store1' as store, store1 as price
FROM Products
WHERE store1 IS NOT NULL)
UNION
(SELECT product_id, 'store2' as store, store2 as price
FROM Products
WHERE store2 IS NOT NULL)
UNION
(SELECT product_id, 'store3' as store, store3 as price
FROM Products
WHERE store3 IS NOT NULL)
