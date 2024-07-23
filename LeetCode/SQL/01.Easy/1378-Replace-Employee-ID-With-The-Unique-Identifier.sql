-- 1378. Replace Employee ID With The Unique Identifier
-- Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.
SELECT e2.unique_id, e1.name
FROM Employees as e1 LEFT JOIN EmployeeUNI as e2
ON e1.id = e2.id;
