SELECT
	id,
	IF(p_id IS null, 'Root', IF(id IN (SELECT p_id FROM tree),'Inner','Leaf')) Type
FROM
	tree