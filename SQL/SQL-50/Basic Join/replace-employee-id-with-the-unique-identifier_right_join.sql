-- https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

select
    eu.unique_id, e.name
from
    employeeuni eu
right join
    employees e
on
    e.id = eu.id;