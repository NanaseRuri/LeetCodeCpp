DELETE
	FROM
		Person
	WHERE
		ID
	NOT IN
	(
		SELECT
			*
		FROM
		(
			SELECT
				min(id)
			FROM
				Person
			GROUP BY
				email
		) t
	)

DELETE 
FROM 
	Person 
WHERE 
	Id 
IN
	(SELECT 
		Id 
	FROM 
		(SELECT 
			Id,ROW_NUMBER() OVER(PARTITION BY Email ORDER BY Id) AS rowNumber 
		FROM
			Person) temp
	WHERE
		rowNumber > 1)