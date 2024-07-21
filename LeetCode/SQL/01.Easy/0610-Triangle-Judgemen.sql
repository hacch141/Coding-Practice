-- 610. Triangle Judgement
-- Report for every three line segments whether they can form a triangle.
SELECT x, y, z,
    CASE 
        WHEN (x + y) > z AND (y + z) > x AND (z + x) > y THEN 'Yes' 
        ELSE 'No'
    END as triangle
FROM Triangle;
