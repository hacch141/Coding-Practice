-- 182. Duplicate Emails
-- Write a solution to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL.
-- Return the result table in any order.
SELECT p.email 
FROM Person as p 
GROUP BY email 
HAVING COUNT(p.id) > 1;
