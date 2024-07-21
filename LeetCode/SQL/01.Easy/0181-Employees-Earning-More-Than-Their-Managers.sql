-- 181. Employees Earning More Than Their Managers
-- Write a solution to find the employees who earn more than their managers.
-- Return the result table in any order
SELECT e1.name as Employee 
FROM Employee as e1 INNER JOIN Employee as e2
ON e1.managerId = e2.id AND e1.salary > e2.salary;
