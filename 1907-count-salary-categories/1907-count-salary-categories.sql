# Write your MySQL query statement below
select "High Salary" as category, count(*) as accounts_count from accounts where income > 50000 union all
select "Average Salary" as category, count(*) as accounts_count from accounts where income <= 50000 and income >= 20000 union all
select "Low Salary" as category, count(*) as accounts_count from accounts where income < 20000;