SELECT
	epoch,
	max(result_time), min(result_time),
	max(result_time) - min(result_time)
FROM expt_table,
  calib_temp
GROUP by
  epoch;
-- HAVING
-- 	max(result_time) - min(result_time) > "00:00:01";
