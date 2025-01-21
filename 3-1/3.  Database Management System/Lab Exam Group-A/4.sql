UPDATE students set DepartmentID = 
(select DepartmentID from departments where DepartmentName='Civil')
where Name = 'Eva White'
