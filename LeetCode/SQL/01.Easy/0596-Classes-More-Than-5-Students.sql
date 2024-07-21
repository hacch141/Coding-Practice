-- 596. Classes More Than 5 Students
-- Write a solution to find all the classes that have at least five students.
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;
