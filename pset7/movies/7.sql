SELECT title, rating FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = '2010' AND rating IS NOT NULL
ORDER BY rating DESC, title ASC;