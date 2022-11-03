SELECT e.name AS Employee
FROM Employee e
    JOIN Employee em ON e.managerId = em.id AND e.salary > em.salary