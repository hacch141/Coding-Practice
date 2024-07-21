-- 511. Game Play Analysis I

# Write your MySQL query statement below
SELECT player_id, MIN(event_date) as first_login
FROM Activity
GROUP BY player_id;
