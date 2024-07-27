-- 1741. Find Total Time Spent by Each Employee
-- Write a solution to calculate the total time in minutes spent by each employee on each day at the office. Note that within one day, an employee can enter and leave more than once. The time spent in the office for a single entry is out_time - in_time.
SELECT event_day as day,
        emp_id,
        SUM(out_time) - SUM(in_time) as total_time
FROM Employees
GROUP BY emp_id, event_day;
