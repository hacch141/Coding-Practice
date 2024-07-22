-- 620. Not Boring Movies
-- Write a solution to report the movies with an odd-numbered ID and a description that is not "boring".
-- Return the result table ordered by rating in descending order.
SELECT *
FROM Cinema
WHERE description != 'boring' AND MOD(id,2) = 1
ORDER BY rating DESC;
