/*Q.1*/
select department_name, location_id, street_address, city, state_province, country_name from departments natural join locations natural join countries;
/*Q.2*/
select first_name, last_name, department_id, department_name from employees natural join departments;
/*Q.3*/
select first_name, last_name, job_title, department_id, department_name from employees natural join jobs natural join departments natural join locations where country_id = (select country_id from countries where country_name="London");
/*Q.4*/
select a.employee_id, a.first_name, a.last_name, a.manager_id, b.first_name, b.last_name from employees a, employees b where a.manager_id = b.employee_id;
/*Q.5*/
select first_name, last_name, hire_date from employees where hire_date >= (select hire_date from employees where last_name = "Jones");
/*Q.6*/
select first_name, last_name, department_id, department_name from employees natural join departments;
/*Q.7*/
select employee_id, job_title, (end_date-start_date) as "days" from job_history natural join jobs where department_id = 90;
/*Q.8*/
select a.department_id, a.department_name, b.first_name from departments a, employees b where a.manager_id = b.employee_id;
/*Q.9*/
select a.department_name, b.first_name, b.last_name, c.city from departments a, employees b, locations c where a.manager_id=b.employee_id and a.location_id=c.location_id;
/*Q.10*/
select job_title, ((min_salary+max_salary)/2) as "Average Salary" from jobs;
/*Q.11*/
select b.job_title, a.first_name, a.last_name, (a.salary-b.min_salary) as "salary difference" from employees a, jobs b where a.job_id = b.job_id;
/*Q.12*/
select * from job_history where employee_id in (select distinct employee_id from employees where salary >= 10000);
/*Q.13*/
select a.department_name, b.first_name, b.last_name, c.start_date from departments a, employees b, job_history c where a.manager_id = b.employee_id and a.manager_id = c.employee_id and a.department_id = c.department_id and c.end_date-c.start_date >=5474;



