-- 197. Rising Temperature
-- Write a solution to find all dates' Id with higher temperatures compared to its previous dates (yesterday).
-- Return the result table in any order.
SELECT w2.id
FROM Weather as w1 INNER JOIN Weather as w2
ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
WHERE w1.temperature < w2.temperature;
-- OR --
SELECT w2.id
FROM Weather as w1 INNER JOIN Weather as w2
ON w1.recordDate = DATE_SUB(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature < w2.temperature;
-- OR --
SELECT w2.id
FROM Weather as w1 INNER JOIN Weather as w2
ON w2.recordDate = DATE_ADD(w1.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature < w2.temperature;
