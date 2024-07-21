# 182. Duplicate Emails

# Write your MySQL query statement below
SELECT p.email 
FROM Person as p 
GROUP BY email 
HAVING COUNT(p.id) > 1;
