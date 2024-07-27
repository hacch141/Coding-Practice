-- 1731. The Number of Employees Which Report to Each Employee
-- For this problem, we will consider a manager an employee who has at least 1 other employee reporting to them.
-- Write a solution to report the ids and the names of all managers, the number of employees who report directly to them, and the average age of the reports rounded to the nearest integer.
-- Return the result table ordered by employee_id.
SELECT e1.reports_to as employee_id, 
        e2.name, COUNT(*) as reports_count, 
        ROUND(AVG(e1.age)) as average_age
FROM Employees as e1 INNER JOIN Employees as e2
ON e1.reports_to = e2.employee_id
GROUP BY e1.reports_to
ORDER BY employee_id;
