-- 1075. Project Employees I
-- Write an SQL query that reports the average experience years of all the employees for each project, rounded to 2 digits.
SELECT p.project_id, ROUND(AVG(e.experience_years),2) as average_years
FROM Project as p INNER JOIN Employee as e
ON p.employee_id = e.employee_id
GROUP BY p.project_id;
