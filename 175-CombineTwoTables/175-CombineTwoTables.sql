-- Last updated: 8/4/2026, 12:24:46 PM
# Write your MySQL query statement below
SELECT 
   p.firstName, 
   p.lastName, 
   a.city, 
   a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;