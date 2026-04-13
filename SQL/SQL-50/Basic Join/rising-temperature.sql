-- https://leetcode.com/problems/rising-temperature/description/

select
    today.id 
from
    weather today
inner join
    weather yesterday
on
    today.recordDate = yesterday.recordDate + interval '1 day'
where
    today.temperature > yesterday.temperature;