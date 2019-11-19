-- Q.1
SELECT
  result_time,
  nodeid
FROM expt_table
where
  light > 550;
-- Q.2
SELECT
  AVG(light),
  AVG(temp)
FROM expt_table
WHERE
  TIME(result_time) BETWEEN "18:00:00"
  AND "21:00:00";
-- Q.3
SELECT
  AVG(light),
  AVG(temp)
FROM expt_table
WHERE
  voltage <= 418
  AND TIME(result_time) BETWEEN "18:00:00"
  AND "21:00:00";
-- Q.4
SELECT
  HOUR(result_time) as 'Time',
  avg(calib_temp.calib) as "Average Calibirated Temp"
FROM expt_table,
  calib_temp
where
  nodeid = 2
  AND expt_table.temp = calib_temp.raw
  AND TIME(result_time) BETWEEN "17:00:00"
  AND "22:00:00"
GROUP by
  HOUR(result_time)
order by
  HOUR(result_time);
-- Q.5
SELECT
	epoch
FROM expt_table,
  calib_temp
GROUP by
  epoch
HAVING
	max(result_time) - min(result_time) > "00:00:01";
-- Q.6
SELECT
  epoch
FROM expt_table
GROUP by epoch
HAVING count(*) < 3;
-- Q. 7


