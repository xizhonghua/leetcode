
SELECT Score, 
    (SELECT count(DISTINCT Score) + 1 from Scores as s1 where s2.Score < s1.Score) as Rank
from Scores s2

ORDER BY score DESC
