# 181. Employees Earning More Than Their Managers

# Write your MySQL query statement below
SELECT e1.name as Employee 
FROM Employee as e1 INNER JOIN Employee as e2
ON e1.managerId = e2.id AND e1.salary > e2.salary;
