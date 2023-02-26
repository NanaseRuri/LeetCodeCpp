SELECT
	sell_date,
	COUNT(distinct product) num_sold,
	GROUP_CONCAT(distinct product) products
FROM
	Activities
GROUP BY
	sell_date