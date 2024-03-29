SELECT
	name 
FROM
	SalesPerson s 
LEFT JOIN 
(
	SELECT
		sales_id 
	FROM
		company 
	INNER JOIN 
		Orders 
	ON 
		sales_id.com_id = company.com_id and c.name = 'RED'
) t
ON 
	s.sales_id = t.sales_id 
WHERE
	t.sales_id IS NULL;