-- 1965. Employees With Missing Information
-- Write a solution to report the IDs of all the employees with missing information. The information of an employee is missing if:
-- The employee's name is missing, or
-- The employee's salary is missing.
-- Return the result table ordered by employee_id in ascending order.
WITH tmp AS (
    SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
    UNION
    SELECT * FROM Employees RIGHT JOIN Salaries USING(employee_id)
)
SELECT tmp.employee_id as employee_id
FROM tmp
WHERE tmp.name IS NULL OR tmp.salary IS NULL
ORDER BY employee_id;
