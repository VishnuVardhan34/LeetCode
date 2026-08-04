-- Last updated: 8/4/2026, 12:24:41 PM
# Write your MySQL query statement below
select c.name as Customers
from Customers c
left join Orders o on c.id = o.customerId
where o.customerId is NULL;