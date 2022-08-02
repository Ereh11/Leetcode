# Write your MySQL query statement below
SELECT customer_id, count(*) as count_no_trans FROM visits
WHERE visit_id NOT IN 
(
    select visit_id from Transactions
)
GROUP BY customer_id 