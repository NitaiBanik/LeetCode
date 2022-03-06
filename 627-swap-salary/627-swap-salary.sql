# Write your MySQL query statement below

Update salary
Set
    sex = Case sex
        when 'm' then 'f'
        else 'm'
    end
