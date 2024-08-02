-- 177. Nth Highest Salary
-- Write a solution to find the nth highest salary from the Employee table. If there is no nth highest salary, return null.
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT e1.salary 
      FROM Employee as e1
      WHERE N = (
          SELECT COUNT(DISTINCT e2.salary) 
          FROM Employee as e2
          WHERE e2.salary >= e1.salary
      )
  );
END
-- OR --
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N-1;
    RETURN (
        SELECT salary
        FROM (
            SELECT DISTINCT salary
            FROM Employee
            ORDER BY salary DESC
            LIMIT 1 OFFSET N
        ) AS TempTable
    );
END 
