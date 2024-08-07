-- 577. Employee Bonus
-- Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.
SELECT e.name, b.bonus
FROM Employee as e LEFT JOIN Bonus as b 
ON e.empId = b.empId
WHERE b.bonus IS NULL OR b.bonus < 1000;
