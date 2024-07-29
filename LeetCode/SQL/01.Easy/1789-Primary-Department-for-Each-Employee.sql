-- 1789. Primary Department for Each Employee
-- Employees can belong to multiple departments. When the employee joins other departments, they need to decide which department is their primary department. Note that when an employee belongs to only one department, their primary column is 'N'.
-- Write a solution to report all the employees with their primary department. For employees who belong to one department, report their only department.
SELECT employee_id, department_id
FROM Employee as e1
WHERE primary_flag = 'Y' OR employee_id IN (
    SELECT e2.employee_id
    FROM Employee as e2
    GROUP BY employee_id
    HAVING COUNT(*) = 1
);
-- OR --
(SELECT employee_id, department_id
FROM Employee as e1
GROUP BY e1.employee_id
HAVING COUNT(*) = 1 )
UNION
(SELECT employee_id, department_id
FROM Employee as e2
WHERE primary_flag = 'Y');
