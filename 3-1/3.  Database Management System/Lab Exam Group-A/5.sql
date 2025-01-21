create view StudentDetails  as 
select s.StudentID, s.Name, s.Age, s.Gender,  d.DepartmentName
from students s, departments d where s.DepartmentID = d.DepartmentID;

select * from StudentDetails