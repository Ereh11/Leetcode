# Write your MySQL query statement below
SELECT name, SUM(IF(distance IS NULL, 0, distance)) AS travelled_distance 
FROM Users
LEFT JOIN Rides ON Users.id = Rides.user_id
GROUP BY Users.id
ORDER BY travelled_distance DESC, name;