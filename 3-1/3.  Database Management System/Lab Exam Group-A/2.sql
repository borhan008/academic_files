select s.Name from students s, enrollments e, courses  c
where s.StudentID = e.StudentID and 
e.CourseID = c.CourseID and c.courseName = 'Data Structure'


