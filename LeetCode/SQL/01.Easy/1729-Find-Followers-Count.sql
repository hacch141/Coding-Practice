-- 729. Find Followers Count
-- Write a solution that will, for each user, return the number of followers.
SELECT user_id, COUNT(DISTINCT follower_id) as followers_count
FROM Followers
GROUP BY user_id;
