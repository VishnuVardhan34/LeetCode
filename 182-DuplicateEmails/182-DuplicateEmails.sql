-- Last updated: 8/4/2026, 12:24:40 PM
# Write your MySQL query statement below
select email as Email
from person
group by email
having COUNT(*) > 1;