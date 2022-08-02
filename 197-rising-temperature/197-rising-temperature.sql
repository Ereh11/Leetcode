# Write your MySQL query statement below
SELECT DISTINCT (W1.id) 
from Weather W1, Weather W2 
where W1.recordDate = W2.recordDate + Interval 1 day and W1.temperature > W2.temperature 