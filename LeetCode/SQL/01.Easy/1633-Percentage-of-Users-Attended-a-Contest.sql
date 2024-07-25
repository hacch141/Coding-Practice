-- 1633. Percentage of Users Attended a Contest
-- Write a solution to find the percentage of the users registered in each contest rounded to two decimals.
-- Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.
WITH tmp AS (
    SELECT COUNT(user_id) as total_users
    FROM Users
)
SELECT r.contest_id, ROUND( 100 * COUNT(DISTINCT r.user_id) / tmp.total_users , 2) as percentage
FROM Register as r CROSS JOIN tmp
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;
-- OR --
-- subquery
SELECT r.contest_id, ROUND( 100 * COUNT(DISTINCT r.user_id) / (SELECT COUNT(user_id) FROM Users) , 2) as percentage
FROM Register as r
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;

