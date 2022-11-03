SELECT p.email
FROM Person p
GROUP BY p.email
HAVING COUNT(*) > 1