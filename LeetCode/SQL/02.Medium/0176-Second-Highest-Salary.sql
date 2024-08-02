-- 176. Second Highest Salary
-- Write a solution to find the second highest salary from the Employee table. If there is no second highest salary, return null (return None in Pandas).
SeLECT MAX(salary) as SecondHighestSalary
FROM Employee
WHERE salary NOT IN (SELECT MAX(salary) FROM Employee);
-- OR --
SeLECT MAX(salary) as SecondHighestSalary
FROM Employee
WHERE salary != (SELECT MAX(salary) FROM Employee);
-- OR --
SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
