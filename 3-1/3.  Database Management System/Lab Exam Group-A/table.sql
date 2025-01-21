CREATE DATABASE exam;
use exam;

create table departments (
	DepartmentID int primary key,
	DepartmentName varchar(100)  not null
);
create table students (
	StudentID int PRIMARY KEY,
	Name varchar(100)  not null,
	Age int not null,
	Gender char,
	DepartmentID int,
	foreign key (DepartmentID) references departments(DepartmentID),

);
create table courses(
	CourseID varchar(50) primary key,
	CourseName varchar(100)  not null,
	DepartmentID int not null,
	foreign key (DepartmentID) references departments(DepartmentID),
);



create table enrollments(
	EnrollmentID int primary key,
	StudentID int,
	CourseID varchar(50),
	foreign key  (CourseID) references courses(CourseID),
	foreign key  (StudentID) references students(StudentID)
);




INSERT INTO departments(DepartmentID, DepartmentName) values 
(101, 'Computer Science'),
(102, 'Mechanical'),
(103, 'ELectrical'),
(104, 'Civil');

INSERT INTO students (StudentID,Name,Age,Gender,DepartmentID) values 
(1, 'Alice Smith', 20, 'F', 101),
(2, 'Bob Johnson', 21, 'M', 102),
(3, 'Charlie Lee', 22, 'M', 103),
(4, 'Diana Brown', 20, 'F', 101),
(5, 'Eva White', 23, 'F', 104);

INSERT INTO courses (CourseID, courseName, DepartmentID ) values 
('C101', 'Data Structure', 101),
('C102', 'Thermodynamics', 102),
('C103', 'Circuits', 103),
('C104', 'Structural Design', 104);

INSERT INTO enrollments (EnrollmentID, StudentID, CourseID) values
(1,1,'C101'),
(2,2,'C102'),
(3,3,'C103'),
(4,4,'C101'),
(5,5,'C104');