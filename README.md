# Class-Implementation-C++
Creating classes, class inheritance, maximum/minimum value sorting, and dynamic memory allocation.


Summary of Approach

/////Class Person
•	To begin this class, the private variables were declared, including two strings and an int (fullname, address, and age).

•	Next, all the public functions were created. A class constructor was unnecessary because C++ automatically generates a default constructor when no other constructors are created. 
•	The first function created was a void function called readPersonInfo(); this fills in the private attributes of a Person object using keyboard input operations. 
•	The second function was a void function called printPersonInfo(); this displays the private attributes of a Person object. 
•	The third function was a function called personAGE(); this returns the age of a Person object. 
•	The final function was a function called personName(); this returns the fullname of a Person object. A deconstructor was not necessary for this class because there was no dynamic memory allocation.


/////Class Student
•	Next, the Student class was created, which is a derived class of the base class Person. Three private variables were declared, including two strings and a float (ID, major, and gpa).
•	Then the public functions were created. Again, a class constructor was unnecessary because of the default constructor automatically created. 
•	The first function created was a void function called readStudentInfo(); this function calls the function readPersonInfo() from the base class and then fills in the Student class’s private attributes using keyboard input operations. 
•	The second function was a void function called printStudentInfo(); this function invokes the function printPersonInfo() from the base class and then prints the Student class’s private attributes. 
•	The final function was a function called studentGPA(); this function returned a Student object’s GPA attribute. A deconstructor was not necessary for this class because there was no dynamic memory allocation.



/////Class Course
•	Next, the Course class was created. At the beginning of this class, three private variables were declared, including two strings and an int (ID, title, and credits). 
•	Then all the public functions were created. First, a class constructor was made that is used to fill the data of the class’s three private attributes. 
•	Finally, a void function called printCourseInfo() was created; this function displays the three private attributes of the class.
Class CourseSection
•	Lastly, the CourseSection class was made; this is a derived class of the Course class. To begin, two private variables were declared, including an int and a Student object pointer (sectionSize and *roster). 
•	Next, all the public functions were created. First, a class constructor was made; this constructor takes (as arguments) the three attributes of the Course that the section belongs to along with the section size. This constructor invokes the base class’s constructor with the three Course attributes and then dynamically creates the *roster using the sectionSize attribute. 
•	A void function called fillRosterInfo() was created; this function reads the info of all the students in the section one at a time by invoking the readStudentInfo() inside of a for loop. Then it inserts each Student object into the roster list.
•	A void function called printSectionInfo() was created; this function prints the section’s information, including course information and the information of each student. The information of each student is printed by invoking the printStudentInfo() function, for each object in the roster, inside of a for loop.
•	A void function called printAverageGPA() was created; this function prints the average GPA of the students in the section by invoking the studentGPA() function inside of a for loop, summing the GPAs, and dividing by the section size. 
•	A void function called printMaxGPAinfo() was created; this function prints the max GPA and identifies the student who has this GPA. The highest GPA was found by creating an index variable and a max variable; then a for loop was used to sort through the roster and if the student’s GPA is higher than the previous, the index and max were updated. 
•	A void function called printYoungestStudent() was created; this function prints the information of the youngest student. The youngest student was found by creating an index variable and a youngest variable (beginning at roster[0]); then a for loop was used to sort through the roster and if the student’s age is lower than the previous, the index and youngest were updated.
•	Lastly, a destructor was created to delete the dynamically allocated memory (*roster).
