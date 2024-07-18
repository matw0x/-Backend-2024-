SELECT departament_id, COUNT(departament_id), AVG(salary)
FROM Users
GROUP BY departament_id