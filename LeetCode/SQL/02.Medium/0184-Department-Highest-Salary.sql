-- 184. Department Highest Salary
-- Write a solution to find employees who have the highest salary in each of the departments.
WITH mxsalary AS (
    SELECT departmentId,
           MAX(salary) as mxsal
    FROM Employee
    GROUP BY departmentId
),
emp AS (
    SELECT e.*
    FROM Employee as e INNER JOIN mxsalary m
    ON e.departmentId = m.departmentId AND e.salary = m.mxsal
)
SELECT d.name as Department,
       e.name as Employee, 
       e.salary as Salary
FROM emp as e INNER JOIN Department as d
ON e.departmentId = d.id
