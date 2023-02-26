--UPDATE
--	USERS
--SET
--	name = CONCAT(UPPER(LEFT(name, 1)), LOWER(RIGHT(name, LENGTH(name) - 1)))

SELECT 
	user_id, 
	CONCAT(UPPER(LEFT(name, 1)), LOWER(RIGHT(name, LENGTH(name) - 1))) name
FROM
	Users
ORDER BY
	user_id