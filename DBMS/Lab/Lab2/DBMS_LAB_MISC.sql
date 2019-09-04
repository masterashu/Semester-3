/*Q.1*/
select substr(first_name, 1, 3) from employees;
/*Q.2*/
select a.first_name, a.last_name, b.department_id from departments b, employees a where a.department_id=b.department_id and (department_id = 30 or department_id = 100) order by first_name, last_name;
/*Q.3*/
select department_name, avg(salary) from employees natural join departments group by department_id having count(*) >= 10;
/*Q.4*/
select first_name, last_name, salary from employees where salary >= (select salary from employees where last_name = "Bell");
/*Q.5*/
 select job_id, max_salary from employees natural join jobs where max_salary >= 4000;
/*Q.6*/
 select employee_id, first_name, last_name as "average salary" from employees natural join jobs where salary >= ((min_salary+max_salary)/2);

