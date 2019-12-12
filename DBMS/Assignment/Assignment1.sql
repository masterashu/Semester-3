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
WHERE
  nodeid in (1, 2)
GROUP by
  epoch
HAVING
  max(result_time) - min(result_time) > "00:00:01";
-- Q.6
SELECT
  epoch
FROM expt_table
GROUP by
  epoch
HAVING
  count(*) < 3
ORDER BY
  epoch;
-- Q. 7
SELECT
  e2.nodeid,
  e2.epoch,
  (
    CASE
      WHEN e1.temp IS null THEN (
        SELECT
          temp
        FROM expt_table
        WHERE
          nodeid = e2.nodeid
          AND epoch = (
            SELECT
              max(epoch)
            FROM expt_table
            WHERE
              epoch < e2.epoch
              AND nodeid = e2.nodeid
          )
      )
      ELSE e1.temp
    END
  )
FROM expt_table AS e1 FULL
OUTER JOIN (
    SELECT
      nodeid,
      epoch
    FROM (
        SELECT
          DISTINCT epoch
        FROM expt_table
      ) AS es,
      (
        SELECT
          DISTINCT nodeid
        FROM expt_table
      ) AS ns
  ) AS e2 ON (
    e2.nodeid = e1.nodeid
    and e2.epoch = e1.epoch
  )
ORDER BY
  e2.epoch,
  e2.nodeid;