-- Last updated: 8/4/2026, 12:24:44 PM
# Write your MySQL query statement below
select e1.name as employee 
from employee e1
join employee e2 on e1.managerId = e2.id
where e1.salary > e2.salary;