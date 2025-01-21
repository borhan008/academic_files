select distinct(s.Name) from students s, enrollments e
where e.StudentID = s.StudentID and e.CourseID IN (select CourseID from courses 
where DepartmentID = (select DepartmentID from departments where DepartmentName='Electrical'));