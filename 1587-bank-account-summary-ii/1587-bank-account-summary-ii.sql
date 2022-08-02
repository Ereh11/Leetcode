# Write your MySQL query statement below
SELECT Users.name 'Name', sum(Transactions.amount) 'Balance' 
FROM Users INNER JOIN Transactions ON Users.account=Transactions.account
GROUP BY Users.account
HAVING SUM(Transactions.amount) > 10000;