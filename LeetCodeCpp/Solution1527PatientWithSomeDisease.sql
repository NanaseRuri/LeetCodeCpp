SELECT
	patient_id,patient_name,conditions
FROM
	Patients
WHERE
	conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%' 

SELECT
	patient_id,patient_name,conditions
FROM
	Patients
WHERE
	LEFT(conditions, 5) = 'DIAB1' OR LOCATE(' DIAB1',conditions) != 0