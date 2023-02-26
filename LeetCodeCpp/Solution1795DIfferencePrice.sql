SELECT
	 product_id,'store1' store, store1 price
FROM
	Products
WHERE
	store1 IS NOT NULL

UNION ALL

SELECT
	product_id, 'store2' store, store2 price
FROM 
	Products 
WHERE 
	store2 is not null

UNION ALL

SELECT 
	product_id, 'store3' store, store3 price
FROM 
	Products 
WHERE 
	store3 is not null;