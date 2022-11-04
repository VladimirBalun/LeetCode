SELECT e.event_day AS day, e.emp_id, SUM(e.out_time - e.in_time) AS total_time
FROM Employees e
GROUP BY e.event_day, e.emp_id