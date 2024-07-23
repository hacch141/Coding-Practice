-- 1280. Students and Examinations
-- Write a solution to find the number of times each student attended each exam.
-- Return the result table ordered by student_id and subject_name.
SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) as attended_exams
FROM Students as s CROSS JOIN Subjects as sub
LEFT JOIN Examinations as e
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY s.student_id, sub.subject_name
ORDER BY s.student_id, sub.subject_name;
