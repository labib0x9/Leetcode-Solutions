-- https://leetcode.com/problems/average-time-of-process-per-machine/

select
    start_a.machine_id,
    round(avg(end_a.timestamp - start_a.timestamp)::numeric, 3) as processing_time
from
    activity start_a
join
    activity end_a
on
    start_a.machine_id = end_a.machine_id and
    start_a.process_id = end_a.process_id and
    start_a.activity_type = 'start' and
    end_a.activity_type = 'end'
group by
    start_a.machine_id;