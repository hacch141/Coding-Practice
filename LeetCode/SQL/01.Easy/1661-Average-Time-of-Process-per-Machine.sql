-- 1661. Average Time of Process per Machine
-- There is a factory website that has several machines each running the same number of processes. Write a solution to find the average time each machine takes to complete a process.
-- The time to complete a process is the 'end' timestamp minus the 'start' timestamp. The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run.
-- The resulting table should have the machine_id along with the average time as processing_time, which should be rounded to 3 decimal places.
WITH A1 AS (
    SELECT * 
    FROM Activity
    WHERE activity_type = "start"
),
A2 AS (
    SELECT * 
    FROM Activity
    WHERE activity_type = "end"
)
SELECT A1.machine_id, ROUND( (SUM(A2.timestamp) - SUM(A1.timestamp)) / COUNT(*) , 3) as processing_time
FROM A1 INNER JOIN A2
ON A1.machine_id = A2.machine_id AND A1.process_id = A2.process_id
GROUP BY A1.machine_id;
-- OR --
SELECT a1.machine_id, ROUND( (SUM(a2.timestamp) - SUM(a1.timestamp)) / COUNT(a1.machine_id) , 3) as processing_time
FROM Activity as a1 INNER JOIN Activity as a2
ON a1.machine_id = a2.machine_id AND a1.process_id = a2.process_id
WHERE a1.activity_type = 'start' AND a2.activity_type = 'end'
GROUP BY a1.machine_id;
