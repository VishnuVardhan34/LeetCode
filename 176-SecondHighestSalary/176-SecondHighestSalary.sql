-- Last updated: 8/4/2026, 12:24:45 PM
SELECT 
   (SELECT DISTINCT salary 
    FROM Employee 
    ORDER BY salary DESC 
    LIMIT 1 OFFSET 1) AS SecondHighestSalary;