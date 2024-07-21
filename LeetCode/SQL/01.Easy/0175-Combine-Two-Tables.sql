-- 175. Combine Two Tables
-- Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.
-- Return the result table in any order.
SELECT e1.name as Employee 
FROM Employee as e1 INNER JOIN Employee as e2
ON e1.managerId = e2.id AND e1.salary > e2.salary;
