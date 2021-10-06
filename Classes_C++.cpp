//Brendan Li

//include necessary libraries
#include <string>
#include <iostream>
using namespace std;

//Person Class
class Person {
private:
    string fullname; //last name followed by first
    string address;
    int age;
public:
    //no constructor necessary
    //this function allows user to input Person attributes
    void readPersonInfo(){
        //enter fullname
        cout << "Enter fullname: " << endl;
        cin>>fullname;
        //enter address
        cout << "Enter address: " << endl;
        cin>>address;
        //enter age
        cout << "Enter age: " << endl;
        cin>>age;
    }
    //this function displays the attributes of a person
    void printPersonInfo(){
        cout << "Name: " << fullname<<endl;
        cout << "Address: " << address<<endl;
        cout << "age: " << age<<endl;
    }
    //this function returns the person object's age
    int personAGE(){return age;}
    //this function returns the person object's fullname
    string personName(){return fullname;}
};


//Student class; derived from Person class
class Student : public Person {
private:
    string ID;
    string major;
    float gpa;
public:
    //this function allows user to input Student attributes; invokes readPersonInfo function
    void readStudentInfo(){
        Person::readPersonInfo();
        //enter ID
        cout << "Enter ID: " << endl;
        cin>>ID;
        //enter address
        cout << "Enter major: " << endl;
        cin>>major;
        //enter GPA
        cout << "Enter GPA: " << endl;
        cin>>gpa;
    }
    //this function prints the Student info
    void printStudentInfo(){
        Person::printPersonInfo();//invoke printPersonInfo function
        cout << "ID: " << ID <<endl;
        cout << "Major: " << major <<endl;
        cout << "GPA: " << gpa <<endl;
    }
    //this function returns the GPA of a student object
    float studentGPA(){return gpa;}
};

//The Course Class
class Course{
private:
    string ID;
    string title;
    int credits;
public:
    //Made a default constructor however it was not necessary for this assignment
    Course(){
        ID="";
        title="";
        credits=0;
    }
    //Constructor that took arguments for the Course objects attributes
    Course(string courseID, string courseTitle, int courseCredits){
        ID=courseID;
        title=courseTitle;
        credits=courseCredits;
    }
    //This function just prints the course object's information
    void printCourseInfo(){
        cout << "Course ID: " << ID <<endl;
        cout << "Course Title: " << title <<endl;
        cout << "Course Credits: " << credits <<endl;
    }
};

//This is the CourseSection class; derived from Course class
class CourseSection : public Course {
private:
    int sectionSize;
    Student *roster; //dynamic array for class roster
public:
    //constructor that fills the course attributes along with allocating memory for roster
    CourseSection(string courseID, string courseTitle, int courseCredits, int size):Course(courseID, courseTitle, courseCredits){
        sectionSize=size;
        roster = new Student[sectionSize];//dynamic allocation
    }
    //Allows user to fill roster information for student objects
    void fillRosterInfo(){
        for(int i=0; i<sectionSize; i++){
            Student place = Student();//create new students
            place.readStudentInfo();//invoke readStudentInfo function
            roster[i]=place;//update roster
            cout<<endl;
        }
    }
    //prints the information of section
    void printSectionInfo(){
        Course::printCourseInfo();//invoke printCourseInfo fnction
        cout<<endl;
        for(int i=0; i<sectionSize; i++){
            roster[i].printStudentInfo();//printStudentInfo function for each object
            cout<<endl;
        }
    }
    //calculates and prints the average GPA of the students on roster
    void printAverageGPA(){
        float sum=0;//sum variable
        for(int i=0; i<sectionSize; i++){
            sum=sum+roster[i].studentGPA();//add all GPAs
        }
        float avg=sum/sectionSize;//take average
        cout<<avg<<endl;
    }
    //Finds the max GPA in the students and prints the GPA and corresponding student
    void printMaxGPAinfo(){
        //place (index) keeps position of max GPA; max float keeps the max GPA
        int place=0;
        float max=0;
        //for loop goes through roster and checks GPA
        for(int i=0; i<sectionSize; i++){
            float check = roster[i].studentGPA();
            if(max<check){max=check; place=i;}//update max and place if the GPA of check is larger
        }
        //print results
        cout<<max<<endl;
        cout<<"The student with the highest GPA is: "<<roster[place].personName()<<endl;
    }
    //Finds the youngest student and prints the information of said student
    void printYoungestStudent() {
        //place (index) keeps position of youngest; young int keeps the youngest age
        int place = 0;
        int young = roster[0].personAGE();
        //for loop goes through roster and checks age
        for (int i = 1; i < sectionSize; i++) {
            int check = roster[i].personAGE();
            if (young > check) {//update young and place if the age of check is lower
                young = check;
                place = i;
            }
        }
        //print information of youngest
        roster[place].printStudentInfo();
    }
    //class destructor for dynamic memory
    ~CourseSection()
    { if (!roster) delete[] roster; }
};


//Main function
int main(){
    int num,cr;
    string id,tl;

    cout<<"Course ID?"<<endl;
    cin>>id;
    cout<<"Course Title?"<<endl;
    cin.get();//remove the leftover "new line" character from cin
    getline(cin,tl);//allows for spaces in the title but first clear the input buffer.
    cout<<"Course Credits?"<<endl;
    cin>>cr;
    cout<<"How many students in the course section?"<<endl;
    cin>>num;
    cin.get();//remove the leftover "new line" character from cin
    CourseSection sec(id, tl, cr, num);

    cout<<"Input the info of all students in the section: \n"<<endl;
    sec.fillRosterInfo();

    cout<<"The following is the section info (course and students info):\n";
    sec.printSectionInfo();

    cout<<"\nThe average GPA of the students in the section=";
    sec.printAverageGPA();

    cout<<"\nThe max GPA info:";
    sec.printMaxGPAinfo();

    cout<<"\nThe youngest student in the class:\n";
    sec.printYoungestStudent();
    return 0;
}