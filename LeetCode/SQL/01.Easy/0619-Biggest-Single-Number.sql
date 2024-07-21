-- 619. Biggest Single Number
-- A single number is a number that appeared only once in the MyNumbers table.
-- Find the largest single number. If there is no single number, report null.
SELECT MAX(num) as num FROM
(SELECT num
FROM MyNumbers
GROUP BY num
HAVING COUNT(num) = 1) as tmp;
-- OR --
WITH single AS (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
)
SELECT MAX(num) AS num
FROM single;
-- A Common Table Expression (CTE) is a named temporary result set that you can 
-- reference within a SELECT, INSERT, UPDATE, or DELETE statement. CTEs are 
-- defined using the WITH keyword, and they provide a way to write more readable 
-- and maintainable queries by breaking down complex queries into simpler, reusable parts.

