-- https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

select
    eu.unique_id, e.name
from
    employees e
left join
    employeeuni eu
on
    e.id = eu.id;