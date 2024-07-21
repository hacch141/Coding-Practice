-- 197. Rising Temperature

# Write your MySQL query statement below
SELECT w2.id
FROM Weather as w1 INNER JOIN Weather as w2
ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
WHERE w1.temperature < w2.temperature;

SELECT w2.id
FROM Weather as w1 INNER JOIN Weather as w2
ON w1.recordDate = DATE_SUB(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature < w2.temperature;

SELECT w2.id
FROM Weather as w1 INNER JOIN Weather as w2
ON w2.recordDate = DATE_ADD(w1.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature < w2.temperature;
