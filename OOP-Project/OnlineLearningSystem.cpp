#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void homePage();
void studentMenu();
void instructorMenu();
void adminMenu();
void displayCoursesForStudent();
void enrollInCourse();
void submitAssignments();
void checkProgress();
void viewCertifications();
void addPeer(char*);
void displayPeer();
void createAssignments();
void gradeSubmissions();
void monitorStudentProgress();
const char getContentSection(int);
bool addContentSection(char*);
void issueCertifications();
void manageCertificates();
void viewAllCertificates();
void sendSystemNotification();
void sendNotificationToStudent();
void sendNotificationToInstructor();
void revokeCertificate();
void addCourse();
void removeCourse();
void assignInstructor();
void generateReports();
void viewCoursesForAdmin();

// Custom string utility functions
int getStringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


// Person (Abstract Base Class)
class Person {
protected:
    char name[100];
    char id[100];
    char email[100];

public:
    Person(const char* n, const char* i, const char* e) {
        copyString(name, n);
        copyString(id, i);
        copyString(email, e);
    }

    virtual void displayInfo() const = 0;
    virtual const char* getRole() const = 0;
    virtual void sendNotification(const char* message) const = 0;
};

// Student (Derived from Person)
class Student : public Person {
private:
    char studentID[100];
    char enrollmentDate[100];
    char completedCourses[5][100];
    int completedCount;
    char peerGroup[5][100];
    int peerCount;

public:
    Student(const char* n, const char* i, const char* e, const char* sid, const char* ed)
        : Person(n, i, e), completedCount(0) {
        copyString(studentID, sid);
        copyString(enrollmentDate, ed);
    }

    void enrollInCourse(const char* courseName) {
        if (completedCount < 5) {
            copyString(completedCourses[completedCount], courseName);
            completedCount++;
        }
        else {
            cout << "Cannot enroll in more than 5 courses." << endl;
        }
    }

    void displayInfo() const override {
        cout << "Name: " << name << ", ID: " << id << ", Email: " << email << ", Student ID: " << studentID << endl;
        cout << "Enrollment Date: " << enrollmentDate << endl;
        cout << "Completed Courses: ";
        for (int i = 0; i < completedCount; i++) {
            cout << completedCourses[i] << (i == completedCount - 1 ? "" : ", ");
        }
        cout << endl;
    }

    const char* getRole() const override {
        return "Student";
    }


    void sendNotification(const char* message) const override {
        cout << "Notification to Student: " << message << endl;
    }

    void submitAssignments() {
        // Define an array of courses available for submission
        const char* courses[] = {
            "Computer Basics",
            "Python Complete Course",
            "Web Development",
            "Data Structures and Algorithms",
            "Machine Learning",
            "Artificial Intelligence",
            "Database Management",
            "Networking Fundamentals",
            "Operating Systems",
            "Software Engineering"
        };

        const int numCourses = sizeof(courses) / sizeof(courses[0]);
        // Display courses available for the student to submit assignments for

        cout << "===========================================" << endl;
        cout << " Submit Assignments " << endl;
        cout << "===========================================" << endl;
        cout << "Select a course to submit an assignment for:" << endl;

        for (int i = 0; i < numCourses; i++) {
            cout << i + 1 << ". " << courses[i] << endl;
        }

        int courseChoice;
        cout << "Enter your choice (1-" << numCourses << "): ";
        cin >> courseChoice;


        if (courseChoice < 1 || courseChoice > numCourses) {
            cout << "Invalid choice. Please try again." << endl;
            return;
        }


        cin.ignore();
        char assignmentName[100];
        cout << "Enter the assignment name: ";
        cin.getline(assignmentName, sizeof(assignmentName));

        char submissionContent[500];
        cout << "Enter the assignment content: ";
        cin.getline(submissionContent, sizeof(submissionContent));



        cout << "===========================================" << endl;
        cout << " Assignment Submitted Successfully! " << endl;
        cout << "Course: " << courses[courseChoice - 1] << endl;
        cout << "Assignment: " << assignmentName << endl;
        cout << "Content: " << submissionContent << endl;
        cout << "===========================================" << endl;
    }

    void checkProgress() {
        cout << "===========================================" << endl;
        cout << "         Checking Progress                 " << endl;
        cout << "===========================================" << endl;
        cout << "Enter number of Completed Courses" << endl;
        cin >> completedCount;
        if (completedCount == 0) {
            cout << "You have not enrolled in any courses yet." << endl;
            return;
        }

        int progress[5];

        // Ask the user to input progress for each completed course
        for (int i = 0; i < completedCount; i++) {
            cout << "Enter progress for the course \"" << completedCourses[i] << "\" (0-100): ";
            cin >> progress[i];


            while (progress[i] < 0 || progress[i] > 100) {
                cout << "Invalid input. Progress must be between 0 and 100. Try again: ";
                cin >> progress[i];
            }
        }



        cout << "===========================================" << endl;
        for (int i = 0; i < completedCount; i++) {
            if (progress[i] == 100) {
                cout << "Course: " << completedCourses[i]
                    << "completed" << endl;
            }

            else {
                cout << "Course: " << completedCourses[i]
                    << "Underway" << endl;
            }
            cout << "===========================================" << endl;
        }
    }
    void viewCertifications() {
        cout << "===========================================" << endl;
        cout << "          View Certifications              " << endl;
        cout << "===========================================" << endl;
        cout << "Enter the number of courses completed" << endl;
        cin >> completedCount;
        if (completedCount == 0) {
            cout << "No courses completed yet. Complete courses to earn certifications." << endl;
            return;
        }


        int progress[5];
        for (int i = 0; i < completedCount; i++) {
            cout << "Enter progress for the course \"" << completedCourses[i] << "\" (0-100): ";
            cin >> progress[i];


            while (progress[i] < 0 || progress[i] > 100) {
                cout << "Invalid input. Progress must be between 0 and 100. Try again: ";
                cin >> progress[i];
            }
        }


        bool hasCertifications = false;
        cout << "===========================================" << endl;
        cout << "  Certifications Earned                   " << endl;
        cout << "===========================================" << endl;
        int count;
        for (int i = 0; i < completedCount; i++) {
            if (progress[i] == 100) {
                cout << "- Certification earned for " << count + 1 << endl;
                hasCertifications = true;
            }
        }

        if (!hasCertifications) {
            cout << "No certifications earned yet. Complete courses to earn certifications." << endl;
        }

        cout << "===========================================" << endl;
    }
    void addPeer(const char* peerID) {

        const char* predefinedPeers[5] = {
            "ahmed",
            "amir",
            "sohail",
            "shahmeer",
            "kamran"
        };


        peerCount = 0;
        for (int i = 0; i < 5; i++) {
            copyString(peerGroup[i], predefinedPeers[i]);
            peerCount++;
        }

        cout << "Peer group has been populated with peers:" << endl;
        for (int i = 0; i < peerCount; i++) {
            cout << i + 1 << ". " << peerGroup[i] << endl;
        }
    }
    void displayPeers() const {
        cout << "Peer Group: ";
        for (int i = 0; i < peerCount; i++) {
            cout << peerGroup[i] << (i == peerCount - 1 ? "" : ", ");
        }
        cout << endl;
    }

};

// Instructor (Derived from Person)
class Instructor : public Person {
private:
    char employeeID[100];
    char department[100];
    char assignedCourses[5][100];
    int courseCount;


public:
    Instructor(const char* n, const char* i, const char* e, const char* empID, const char* dept)
        : Person(n, i, e), courseCount(0) {
        copyString(employeeID, empID);
        copyString(department, dept);

        copyString(assignedCourses[0], "Computer Basics");
        copyString(assignedCourses[1], "Python Complete Course");
        copyString(assignedCourses[2], "Web Development");
        copyString(assignedCourses[3], "Data Structures and Algorithms");
        copyString(assignedCourses[4], "Machine Learning");

    }

    void assignCourse(const char* courseName) {
        if (courseCount < 5) {
            copyString(assignedCourses[courseCount], courseName);
            courseCount++;
        }
        else {
            cout << "Cannot assign more than 5 courses." << endl;
        }
    }

    void displayInfo() const override {
        cout << "Name: " << name << ", ID: " << id << ", Email: " << email << ", Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
        cout << "Assigned Courses: ";
        for (int i = 0; i < courseCount; i++) {
            cout << assignedCourses[i] << (i == courseCount - 1 ? "" : ", ");
        }
        cout << endl;
    }

    const char* getRole() const override {
        return "Instructor";
    }

    void sendNotification(const char* message) const override {
        cout << "Notification to Instructor: " << message << endl;
    }
    void createAssignments() {
        cout << "===========================================" << endl;
        cout << " Create Assignment " << endl;
        cout << "===========================================" << endl;
        cout << "Enter total courses" << endl;
        cin >> courseCount;


        if (courseCount == 0) {
            cout << "No courses assigned to this instructor." << endl;
            return;
        }


        cout << "Select a course to create an assignment for:" << endl;
        for (int i = 0; i < courseCount; i++) {
            cout << i + 1 << ". " << assignedCourses[i] << endl;
        }


        char courseName[100];
        cout << "Enter the exact course name: ";
        cin.ignore();
        cin.getline(courseName, sizeof(courseName));


        bool courseFound = false;
        for (int i = 0; i < courseCount; i++) {
            if (strcmp(courseName, assignedCourses[i]) == 0) {
                courseFound = true;
                break;
            }
        }

        if (!courseFound) {
            cout << "Invalid course name. Please try again." << endl;
            return;
        }


        char assignmentType[100];
        char assignmentDescription[500];

        cout << "Enter the type of assignment (e.g., Quiz, Homework, Project): ";
        cin.getline(assignmentType, sizeof(assignmentType));

        cout << "Enter a brief description of the assignment: ";
        cin.getline(assignmentDescription, sizeof(assignmentDescription));

        // Store or display the assignment details
        cout << "Assignment Created!" << endl;
        cout << "Course: " << courseName << endl;
        cout << "Assignment Type: " << assignmentType << endl;
        cout << "Assignment Description: " << assignmentDescription << endl;
    }

    void gradeSubmissions() {
        cout << "===========================================" << endl;
        cout << " Grade Submissions " << endl;
        cout << "===========================================" << endl;


        const char* courses[] = {
             "Computer Basics",
             "Python Complete Course",
             "Web Development",
             "Software E ngineering",
             "Data Structures and Algorithms",
             "Machine Learning",
             "Artificial Intelligence",
             "Database Management",
             "Networking Fundamentals",
             "Operating Systems",
             "Software Engineering"
        };

        const int numCourses = sizeof(courses) / sizeof(courses[0]);


        char studentName[100];
        cout << "Enter the student's name: ";
        cin.ignore();
        cin.getline(studentName, sizeof(studentName));


        char courseName[100];
        cout << "Enter the course name: ";
        cin.getline(courseName, sizeof(courseName));


        bool courseFound = false;
        for (int i = 0; i < numCourses; i++) {
            if (strcmp(courses[i], courseName) == 0) {
                courseFound = true;
                break;
            }
        }

        if (!courseFound) {
            cout << "Invalid course name. Please try again." << endl;
            return;
        }


        double grade;
        cout << "Enter the grade (e.g., 95.5): ";
        cin >> grade;


        cout << "Grade submitted successfully!" << endl;
        cout << "Student: " << studentName << endl;
        cout << "Course: " << courseName << endl;
        cout << "Grade: " << grade << endl;
    }

    void monitorStudentProgress() {
        cout << "===========================================" << endl;
        cout << " Monitor Student Progress " << endl;
        cout << "===========================================" << endl;
        cin >> courseCount;

        if (courseCount == 0) {
            cout << "No courses assigned to this instructor." << endl;
            return;
        }


        cout << "Assigned Courses:" << endl;
        for (int i = 0; i < courseCount; i++) {
            cout << i + 1 << ". " << assignedCourses[i] << endl;
        }


        char courseName[100];
        cout << "Enter the exact course name to monitor progress: ";
        cin.ignore();
        cin.getline(courseName, sizeof(courseName));


        bool courseFound = false;
        for (int i = 0; i < courseCount; i++) {
            if (strcmp(courseName, assignedCourses[i]) == 0) {
                courseFound = true;
                break;
            }
        }

        if (!courseFound) {
            cout << "Invalid course name. Please try again." << endl;
            return;
        }


        int numStudents;
        cout << "Enter the number of students in the course: ";
        cin >> numStudents;
        cin.ignore();

        if (numStudents <= 0) {
            cout << "Invalid number of students. Exiting." << endl;
            return;
        }


        vector<string> studentNames(numStudents);
        vector<int> progress(numStudents);


        for (int i = 0; i < numStudents; i++) {
            cout << "Enter the name of student " << i + 1 << ": ";
            getline(cin, studentNames[i]);

            cout << "Enter the progress percentage of " << studentNames[i] << " (0-100): ";
            cin >> progress[i];
            cin.ignore();

            if (progress[i] < 0 || progress[i] > 100) {
                cout << "Invalid progress percentage. Setting progress to 0." << endl;
                progress[i] = 0;
            }
        }


        cout << "Progress Report for Course: " << courseName << endl;
        cout << "-------------------------------------------" << endl;
        for (int i = 0; i < numStudents; i++) {
            cout << "Student: " << studentNames[i]
                << ", Progress: " << progress[i] << "%" << endl;
        }
        cout << "-------------------------------------------" << endl;


        cout << "Students with progress below 50%:" << endl;
        bool lowProgressFound = false;
        for (int i = 0; i < numStudents; i++) {
            if (progress[i] < 50) {
                cout << "- " << studentNames[i] << endl;
                lowProgressFound = true;
            }
        }

        if (!lowProgressFound) {
            cout << "All students are progressing well." << endl;
        }
    }
    void issueCertifications() {
        cout << "Issuing certificates..." << endl;
    }
};
class Certificate {
private:
    int certificateID;
    string issueDate;
    string courseTitle;
    string recipient;

public:

    Certificate(int id, const string& date, const string& course, const string& student)
        : certificateID(id), issueDate(date), courseTitle(course), recipient(student) {}


    void displayCertificate() const {
        cout << "\n===========================================" << endl;
        cout << "           Certificate of Completion        " << endl;
        cout << "===========================================" << endl;
        cout << "Certificate ID: " << certificateID << endl;
        cout << "Issued to: " << recipient << endl;
        cout << "Course Title: " << courseTitle << endl;
        cout << "Issue Date: " << issueDate << endl;
        cout << "===========================================\n" << endl;
    }
};


void certificateMenu() {

    Certificate cert1(1, "2022-08-13", "Advanced C++ Programming", "Ahmed");
    Certificate cert2(2, "2017-11-04", "Data Structures and Algorithms", "Nabeel");
    Certificate cert3(2, "2015-03-12", "Web Development", "Maleeha");
    Certificate cert4(2, "2014-12-23", "Database Management", "Aqbar");
    Certificate cert5(2, "2019-05-18", "Artificial Intelligence", "Rehan");
    while (true) {
        cout << "===========================================" << endl;
        cout << "           Certificate Menu                 " << endl;
        cout << "===========================================" << endl;
        cout << "1. View Certificate for Ahmed" << endl;
        cout << "2. View Certificate for Nabeel" << endl;
        cout << "3. View Certificate for Maleeha" << endl;
        cout << "4. View Certificate for Aqbar" << endl;
        cout << "5. View Certificate for Rehan" << endl;
        cout << "6. Exit to Main Menu" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cert1.displayCertificate();
            break;
        case 2:
            cert2.displayCertificate();
            break;
        case 3:
            cert3.displayCertificate();
            break;
        case 4:
            cert4.displayCertificate();
            break;
        case 5:
            cert5.displayCertificate();
            break;
        case 6:
            cout << "Exiting to Main Menu..." << endl;
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}

class Assignment {
private:
    int assignmentID;
    char description[500];
    double maxScore;
    char dueDate[100];

public:

    Assignment(int id, const char* desc, double maxSc, const char* due) {
        assignmentID = id;
        strcpy(description, desc);
        maxScore = maxSc;
        strcpy(dueDate, due);
    }


    void displayAssignmentInfo() const {
        cout << "Assignment ID: " << assignmentID << endl;
        cout << "Description: " << description << endl;
        cout << "Max Score: " << maxScore << endl;
        cout << "Due Date: " << dueDate << endl;
    }



    int getAssignmentID() const {
        return assignmentID;
    }

    void setAssignmentID(int id) {
        assignmentID = id;
    }

    const char* getDescription() const {
        return description;
    }

    void setDescription(const char* desc) {
        strcpy(description, desc);
    }

    double getMaxScore() const {
        return maxScore;
    }

    void setMaxScore(double score) {
        maxScore = score;
    }

    const char* getDueDate() const {
        return dueDate;
    }

    void setDueDate(const char* date) {
        strcpy(dueDate, date);
    }
};


class Admin : private Person {
private:
    char adminID[100];
    char privileges[100];
    char department[100];

public:
    Admin(const char* n, const char* i, const char* e, const char* aid, const char* priv, const char* dept)
        : Person(n, i, e) {
        copyString(adminID, aid);
        copyString(privileges, priv);
        copyString(department, dept);
    }

    void displayInfo() const override {
        cout << "Name: " << name << ", ID: " << id << ", Email: " << email << ", Admin ID: " << adminID << endl;
        cout << "Privileges: " << privileges << endl;
        cout << "Department: " << department << endl;
    }

    const char* getRole() const override {
        return "Admin";
    }

    void sendNotification(const char* message) const override {
        cout << "Notification to Admin: " << message << endl;
    }

    void addCourse() {
        cout << "===========================================" << endl;
        cout << " Add a New Course " << endl;
        cout << "===========================================" << endl;


        static const char* courses[20] = {
            "Computer Basics",
            "Python Complete Course",
            "Web Development",
            "Software Engineering",
            "Data Structures and Algorithms",
            "Machine Learning",
            "Artificial Intelligence",
            "Database Management",
            "Networking Fundamentals",
            "Operating Systems"
        };

        static const char* instructors[20] = {
            "Saim",
            "Waleed",
            "Mubeen",
            "Bushra",
            "Waqas",
            "Zain",
            "Jameel",
            "Kasim",
            "Haseeb",
            "Sabeeha"
        };


        char courseName[100];
        char instructorName[100];

        cout << "Enter the course name: ";
        cin.ignore();
        cin.getline(courseName, sizeof(courseName));

        cout << "Enter the instructor's name: ";
        cin.getline(instructorName, sizeof(instructorName));


        static int numCourses = 20;


        if (numCourses < 20) {

            courses[numCourses] = courseName;
            instructors[numCourses] = instructorName;


            numCourses++;


            cout << "Course '" << courseName << "' by instructor '" << instructorName << "' has been added successfully!" << endl;
        }
        else {
            cout << "Cannot add more courses. The course list is full." << endl;
        }


        cout << "Course added successfully!" << endl;
        cout << "Course: " << courseName << ", Instructor: " << instructorName << endl;
    }

    void removeCourse() {
        cout << "===========================================" << endl;
        cout << " Remove a Course " << endl;
        cout << "===========================================" << endl;


        static const char* courses[10] = {
            "Computer Basics",
            "Python Complete Course",
            "Web Development",
            "Instructor3",
            "Data Structures and Algorithms",
            "Machine Learning",
            "Artificial Intelligence",
            "Database Management",
            "Networking Fundamentals",
            "Operating Systems"
        };

        static const char* instructors[10] = {
            "Saim",
            "Waleed",
            "Mubeen",
            "Bushra",
            "Waqas",
            "Zain",
            "Jameel",
            "Kasim",
            "Haseeb",
            "Sabeeha"
        };


        static int numCourses = 10;


        char courseToRemove[100];
        cout << "Enter the name of the course to remove: ";
        cin.ignore();
        cin.getline(courseToRemove, sizeof(courseToRemove));

        bool courseFound = false;
        int courseIndex = -1;

        for (int i = 0; i < numCourses; i++) {
            if (strcmp(courses[i], courseToRemove) == 0) {
                courseFound = true;
                courseIndex = i;
                break;
            }
        }

        if (courseFound) {
            for (int i = courseIndex; i < numCourses - 1; i++) {
                courses[i] = courses[i + 1];
                instructors[i] = instructors[i + 1];
            }

            numCourses--;


            cout << "Course '" << courseToRemove << "' has been removed successfully!" << endl;
        }
        else {
            cout << "Course not found!" << endl;
        }

        cout << "Updated Course List: " << endl;
        for (int i = 0; i < numCourses; i++) {
            cout << "Course: " << courses[i] << ", Instructor: " << instructors[i] << endl;
        }
    }


    void assignInstructor() {
        cout << "===========================================" << endl;
        cout << " Assign Instructor to a Course " << endl;
        cout << "===========================================" << endl;

        static const char* courses[10] = {
            "Computer Basics",
            "Python Complete Course",
            "Web Development",
            "Instructor3",
            "Data Structures and Algorithms",
            "Machine Learning",
            "Artificial Intelligence",
            "Database Management",
            "Networking Fundamentals",
            "Operating Systems"
        };

        static const char* instructors[10] = {
           "Saim",
            "Waleed",
            "Mubeen",
            "Bushra",
            "Waqas",
            "Zain",
            "Jameel",
            "Kasim",
            "Haseeb",
            "Sabeeha"
        };

        static int numCourses = 10;


        char courseToAssign[100];
        cout << "Enter the name of the course to assign an instructor to: ";
        cin.ignore();
        cin.getline(courseToAssign, sizeof(courseToAssign));


        char newInstructor[100];
        cout << "Enter the name of the new instructor: ";
        cin.getline(newInstructor, sizeof(newInstructor));

        bool courseFound = false;
        int courseIndex = -1;

        for (int i = 0; i < numCourses; i++) {
            if (strcmp(courses[i], courseToAssign) == 0) {
                courseFound = true;
                courseIndex = i;
                break;
            }
        }

        if (courseFound) {

            instructors[courseIndex] = newInstructor;


            cout << "Instructor for course '" << courseToAssign << "' has been changed to '" << newInstructor << "'." << endl;
        }
        else {
            cout << "Course not found!" << endl;
        }

        cout << "Updated Course List: " << endl;
        for (int i = 0; i < numCourses; i++) {
            cout << "Course: " << courses[i] << ", Instructor: " << instructors[i] << endl;
        }
    }

    void generateReports() {
        cout << "\n===========================================" << endl;
        cout << "            Report on Courses              " << endl;
        cout << "===========================================" << endl;
        static const char* courses[10] = {
            "Computer Basics",
            "Python Complete Course",
            "Web Development",
            "Instructor3",
            "Data Structures and Algorithms",
            "Machine Learning",
            "Artificial Intelligence",
            "Database Management",
            "Networking Fundamentals",
            "Operating Systems"
        };

        static const char* instructors[10] = {
           "Saim",
            "Waleed",
            "Mubeen",
            "Bushra",
            "Waqas",
            "Zain",
            "Jameel",
            "Kasim",
            "Haseeb",
            "Sabeeha"
        };

        static int numCourses = 10;

        cout << "Current Course List:" << endl;
        for (int i = 0; i < numCourses; i++) {
            cout << i + 1 << ". Course: " << courses[i] << ", Instructor: " << instructors[i] << endl;
        }

        cout << "\n===========================================" << endl;
        cout << "            Performing Actions             " << endl;
        cout << "===========================================" << endl;
        cout << "\nAdding a new course..." << endl;
        addCourse();
        cout << "\nRemoving a course..." << endl;
        removeCourse();
        cout << "\nAssigning a new instructor..." << endl;
        assignInstructor();


        cout << "\n===========================================" << endl;
        cout << "        Final Course List After Actions    " << endl;
        cout << "===========================================" << endl;

        for (int i = 0; i < numCourses; i++) {
            cout << i + 1 << ". Course: " << courses[i] << ", Instructor: " << instructors[i] << endl;
        }

        cout << "\n===========================================" << endl;
        cout << "         Report Generation Complete        " << endl;
        cout << "===========================================" << endl;
    }
    void manageCertificates() {
        while (true) {
            cout << "===========================================" << endl;
            cout << " Manage Certificates " << endl;
            cout << "===========================================" << endl;
            cout << "1. View Certificates" << endl;
            cout << "2. Issue Certificate" << endl;
            cout << "3. Revoke Certificate" << endl;
            cout << "4. Back to Admin Menu" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                viewAllCertificates();
                break;
            case 2:
                issueCertificate();
                break;
            case 3:
                revokeCertificate();
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    void viewAllCertificates() {
        cout << "===========================================" << endl;
        cout << " List of Issued Certificates " << endl;
        cout << "===========================================" << endl;
        cout << "1. Certificate of Completion - John Doe - Python Complete Course" << endl;
        cout << "2. Certificate of Completion - Alice Smith - Machine Learning" << endl;
        cout << "===========================================" << endl;
    }

    void issueCertificate() {
        char studentName[100];
        char courseName[100];
        cout << "Enter the student's name: ";
        cin.ignore();
        cin.getline(studentName, sizeof(studentName));
        cout << "Enter the course name: ";
        cin.getline(courseName, sizeof(courseName));


        cout << "Certificate issued to " << studentName << " for completing the course: " << courseName << endl;
    }

    void revokeCertificate() {
        char certificateDetails[200];
        cout << "Enter the details of the certificate to revoke (e.g., Student Name and Course Name): ";
        cin.ignore();
        cin.getline(certificateDetails, sizeof(certificateDetails));


        cout << "Certificate for " << certificateDetails << " has been revoked." << endl;
    }
    void sendSystemNotification() {
        cout << "===========================================" << endl;
        cout << " Send System Notification " << endl;
        cout << "===========================================" << endl;
        cout << "1. Send to a Student" << endl;
        cout << "2. Send to an Instructor" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        char name[100];
        char message[500];


        switch (choice) {
        case 1:
            cout << "Enter the Student's name: ";
            cin.getline(name, sizeof(name));
            cout << "Enter the message: ";
            cin.getline(message, sizeof(message));
            sendNotificationToStudent(name, message);
            break;
        case 2:
            cout << "Enter the Instructor's name: ";
            cin.getline(name, sizeof(name));
            cout << "Enter the message: ";
            cin.getline(message, sizeof(message));
            sendNotificationToInstructor(name, message);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    void sendNotificationToStudent(const char* studentName, const char* message) {

        cout << "Notification sent to Student: " << studentName << endl;
        cout << "Message: " << message << endl;
    }

    void sendNotificationToInstructor(const char* instructorName, const char* message) {


        cout << "Notification sent to Instructor: " << instructorName << endl;
        cout << "Message: " << message << endl;
    }
};


class Course {
private:
    char courseName[100];
    char instructorName[100];

public:
    Course(const char* name, const char* instructor) {
        copyString(courseName, name);
        copyString(instructorName, instructor);
    }

    const char* getCourseName() const {
        return courseName;
    }

    void displayCourse() const {
        cout << "Course: " << courseName << ", Instructor: " << instructorName << endl;
    }
};
Course predefinedCourses[10] = {
    Course("Computer Basics", "Instructor1"),
    Course("Python Complete Course", "Instructor2"),
    Course("Web Development", "Instructor3"),
    Course("Data Structures and Algorithms", "Instructor4"),
    Course("Machine Learning", "Instructor5"),
    Course("Artificial Intelligence", "Instructor6"),
    Course("Database Management", "Instructor7"),
    Course("Networking Fundamentals", "Instructor8"),
    Course("Operating Systems", "Instructor9"),
    Course("Software Engineering", "Instructor10")
};

class Module {
private:
    char moduleTitle[100];
    int moduleID;
    char contentSections[5][100];
    Course& associatedCourse;

public:
    // Constructor
    Module(const char* title, int id, Course& course, const char sections[][100], int sectionCount)
        : associatedCourse(course) {
        copyString(moduleTitle, title);
        moduleID = id;


        for (int i = 0; i < sectionCount && i < 5; i++) {
            copyString(contentSections[i], sections[i]);
        }


        for (int i = sectionCount; i < 5; i++) {
            contentSections[i][0] = '\0';
        }
    }
public:

    const char* getContentSection(int index) const {
        if (index >= 0 && index < 5) {
            return contentSections[index];
        }
        return nullptr;
    }


    bool addContentSection(const char* section) {
        for (int i = 0; i < 5; i++) {
            if (contentSections[i][0] == '\0') {
                copyString(contentSections[i], section);
                return true;
            }
        }
        return false;
    }
    void displayModule() const {
        cout << "Module Title: " << moduleTitle << "\nModule ID: " << moduleID << endl;
        associatedCourse.displayCourse();

        cout << "Content Sections:\n";
        for (int i = 0; i < 5 && contentSections[i][0] != '\0'; i++) {
            cout << "  " << i + 1 << ". " << contentSections[i] << endl;
        }
    }
};
class Notification {
private:
    int notificationID;
    string message;
    string dateSent;

public:

    Notification(int id, const string& msg, const string& date)
        : notificationID(id), message(msg), dateSent(date) {}


    void sendToStudent(const string& studentName) const {
        cout << "===========================================" << endl;
        cout << " Notification Sent to Student: " << studentName << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Notification ID: " << notificationID << endl;
        cout << "Message: " << message << endl;
        cout << "Date Sent: " << dateSent << endl;
        cout << "===========================================\n" << endl;
    }


    void sendToInstructor(const string& instructorName) const {
        cout << "===========================================" << endl;
        cout << " Notification Sent to Instructor: " << instructorName << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Notification ID: " << notificationID << endl;
        cout << "Message: " << message << endl;
        cout << "Date Sent: " << dateSent << endl;
        cout << "===========================================\n" << endl;
    }


    void broadcast(const string students[], int studentCount, const string instructors[], int instructorCount) const {
        cout << "\n===========================================" << endl;
        cout << " Broadcasting Notification " << endl;
        cout << "===========================================" << endl;

        for (int i = 0; i < studentCount; i++) {
            sendToStudent(students[i]);
        }
        for (int i = 0; i < instructorCount; i++) {
            sendToInstructor(instructors[i]);
        }
        cout << "Notification broadcast complete.\n" << endl;
    }
};


void notificationMenu() {

    Notification notif1(201, "Submit assignment on due date.", "2024-12-08");
    Notification notif2(202, "Classes are rescheduled.", "2025-02-24");


    const int studentCount = 3;
    const int instructorCount = 2;
    string students[studentCount] = { "Ahmed", "Bashir", "Raheem" };
    string instructors[instructorCount] = { "Dr. Waqas", "Prof. Hajra" };

    while (true) {
        cout << "===========================================" << endl;
        cout << "           Notification Menu                " << endl;
        cout << "===========================================" << endl;
        cout << "1. Send Notification to a Student" << endl;
        cout << "2. Send Notification to an Instructor" << endl;
        cout << "3. Broadcast Notification" << endl;
        cout << "4. Exit to Main Menu" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter the student name: ";
            string studentName;
            cin.ignore();
            getline(cin, studentName);
            notif1.sendToStudent(studentName);
            break;
        }
        case 2: {
            cout << "Enter the instructor name: ";
            string instructorName;
            cin.ignore();
            getline(cin, instructorName);
            notif2.sendToInstructor(instructorName);
            break;
        }
        case 3:
            notif1.broadcast(students, studentCount, instructors, instructorCount);
            break;
        case 4:
            cout << "Exiting to Main Menu..." << endl;
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}
class Assessment {
private:
    int assessmentID;
    string assessmentType;
    double totalMarks;
    double score;

public:

    Assessment(int id, string type, double marks)
        : assessmentID(id), assessmentType(type), totalMarks(marks), score(0) {}


    void takeAssessment() {
        cout << "Enter your score for the " << assessmentType << " (out of " << totalMarks << "): ";
        cin >> score;
        if (score > totalMarks) {
            cout << "Score cannot exceed total marks!" << endl;
            score = totalMarks;
        }
        cout << "Assessment completed! Your score: " << score << endl;
    }


    void viewScore() const {
        cout << "Your score for the " << assessmentType << " (Assessment ID: " << assessmentID << ") is: " << score << " out of " << totalMarks << endl;
    }


    void displayAssessmentInfo() const {
        cout << "Assessment ID: " << assessmentID << endl;
        cout << "Assessment Type: " << assessmentType << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }


    int getAssessmentID() const { return assessmentID; }
    string getAssessmentType() const { return assessmentType; }
    double getTotalMarks() const { return totalMarks; }
    double getScore() const { return score; }
};


void assessmentMenu() {

    Assessment assessment1(1, "Final Exam", 100);
    Assessment assessment2(2, "Midterm Quiz", 50);

    while (true) {
        cout << "===========================================" << endl;
        cout << " Assessment Menu " << endl;
        cout << "===========================================" << endl;
        cout << "1. Take Assessment" << endl;
        cout << "2. View Assessment Score" << endl;
        cout << "3. View All Assessments" << endl;
        cout << "4. Back to Home" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            int id;
            cout << "Enter Assessment ID to take the assessment: ";
            cin >> id;

            if (id == assessment1.getAssessmentID()) {
                assessment1.takeAssessment();
            }
            else if (id == assessment2.getAssessmentID()) {
                assessment2.takeAssessment();
            }
            else {
                cout << "Assessment not found." << endl;
            }
        }
        break;
        case 2:
        {
            int id;
            cout << "Enter Assessment ID to view the score: ";
            cin >> id;

            if (id == assessment1.getAssessmentID()) {
                assessment1.viewScore();
            }
            else if (id == assessment2.getAssessmentID()) {
                assessment2.viewScore();
            }
            else {
                cout << "Assessment not found." << endl;
            }
        }
        break;
        case 3:

            cout << "\nAll Assessments:" << endl;
            assessment1.displayAssessmentInfo();
            assessment2.displayAssessmentInfo();
            break;
        case 4:
            cout << "Returning to Home Page..." << endl;
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}


void displayCoursesForStudent() {
    cout << "===========================================" << endl;
    cout << " Available Courses " << endl;
    cout << "===========================================" << endl;
    for (int i = 0; i < 10; i++) {
        predefinedCourses[i].displayCourse();
    }
}
void displayCoursesForAdmin() {
    cout << "===========================================" << endl;
    cout << "                 Courses                   " << endl;
    cout << "===========================================" << endl;
    for (int i = 0; i < 10; i++) {
        predefinedCourses[i].displayCourse();
        cout << "-------------------------------------------" << endl;
    }
}
void displayCoursesForInstructor() {
    cout << "===========================================" << endl;
    cout << "                 Courses                   " << endl;
    cout << "===========================================" << endl;
    for (int i = 0; i < 10; i++) {
        predefinedCourses[i].displayCourse();
        cout << "-------------------------------------------" << endl;
    }
}


void enrollInCourse() {
    char courseName[100];
    cout << "Enter the course name to enroll in: ";
    cin.ignore();
    cin.getline(courseName, sizeof(courseName));
    cout << "You have enrolled in the course: " << courseName << endl;
}
void submitAssignments()
{
    cout << "submitting assignment" << endl;
}
void checkProgress() {
    cout << "Checking progress..." << endl;
}

void viewCertifications() {
    cout << "Viewing certifications..." << endl;
}


void gradeSubmissions() {
    cout << "Generating Submission...";
}

void monitorStudentProgress() {
    cout << "Monitoring student progress..." << endl;
}

void issueCertifications() {
    cout << "Issuing certificates..." << endl;
}

void addCourse() {
    cout << "Adding a new course..." << endl;
}

void removeCourse() {
    cout << "Removing a course..." << endl;
}

void assignInstructor() {
    cout << "Assigning instructor..." << endl;
}

void generateReports() {
    cout << "Generating reports..." << endl;
}
void moduleMenu(Module& module);
void homePage() {
    const char sections[][100] = {
        "Introduction to Programming",
        "Basic Syntax",
        "Control Structures"
    };

    while (true) {
        cout << "=========================================================" << endl;
        cout << "Agha Ahsan=============Home Page=============Jibran Malik " << endl;
        cout << "==========================Menu=========================== " << endl;
        cout << "1. Login as Student" << endl;
        cout << "2. Login as Instructor" << endl;
        cout << "3. Login as Admin" << endl;
        cout << "4. Access Module Menu" << endl;
        cout << "5. Manage Assessment" << endl;
        cout << "6. View Certificates" << endl;
        cout << "7. Send Notifications" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string email, password;
            cout << "Enter Student Email: ";
            cin >> email;
            cout << "Enter Student Password: ";
            cin >> password;

            studentMenu();
            break;
        }
        case 2: {
            string email, password;
            cout << "Enter Instructor Email: ";
            cin >> email;
            cout << "Enter Instructor Password: ";
            cin >> password;

            instructorMenu();
            break;
        }
        case 3: {
            string email, password;
            cout << "Enter Admin Email: ";
            cin >> email;
            cout << "Enter Admin Password: ";
            cin >> password;

            adminMenu();
            break;
        }
        case 4: {
            Module module("Programming Basics Module", 201, predefinedCourses[0], sections, 3);
            moduleMenu(module);
            break;
        }
        case 5:
            assessmentMenu();
            break;
        case 6:
            certificateMenu();
            break;
        case 7:
            notificationMenu();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}


void moduleMenu(Module& module) {
    while (true) {
        cout << "===========================================" << endl;
        cout << " Module Menu " << endl;
        cout << "===========================================" << endl;
        cout << "1. View Module Details" << endl;
        cout << "2. Add Content Section" << endl;
        cout << "3. List Content Sections" << endl;
        cout << "4. Back to Previous Menu" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            module.displayModule();
            break;
        case 2: {
            char newSection[100];
            cin.ignore();
            cout << "Enter the new content section: ";
            cin.getline(newSection, sizeof(newSection));
            if (module.addContentSection(newSection)) {
                cout << "Content section added successfully!" << endl;
            }
            else {
                cout << "The module already has the maximum number of content sections (5)." << endl;
            }
            break;
        }
        case 3:
            cout << "Listing content sections:" << endl;
            for (int i = 0; i < 5; i++) {
                const char* section = module.getContentSection(i);
                if (section && section[0] != '\0') {
                    cout << i + 1 << ". " << section << endl;
                }
            }
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
void studentMenu() {
    Student student("John Doe", "S1001", "johndoe@example.com", "ST123", "01-01-2024");
    const char* ID;
    while (true) {
        cout << "===========================================" << endl;
        cout << " Student Menu " << endl;
        cout << "===========================================" << endl;
        cout << "1. Enroll in Courses" << endl;
        cout << "2. Submit Assignments" << endl;
        cout << "3. Check Progress" << endl;
        cout << "4. View Certifications" << endl;
        cout << "5. Add Peer" << endl;
        cout << "6. Display Peer" << endl;
        cout << "7. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: displayCoursesForStudent(); enrollInCourse(); break;
        case 2: student.submitAssignments(); break;
        case 3: student.checkProgress(); break;
        case 4: student.viewCertifications(); break;
        case 5: student.addPeer(ID); break;
        case 6: student.displayPeers(); break;
        case 7: homePage(); return;
        default: cout << "Invalid choice. Try again." << endl; break;
        }
    }
}
void instructorMenu() {
    Instructor instructor("Dr. Smith", "I1001", "drsmith@example.com", "E1001", "Computer Science");
    while (true) {
        cout << "===========================================" << endl;
        cout << " Instructor Menu " << endl;
        cout << "===========================================" << endl;
        cout << "1. Create Assignments" << endl;
        cout << "2. Grade Submissions" << endl;
        cout << "3. Monitor Student Progress" << endl;
        cout << "4. Issue Certifications" << endl;
        cout << "5. Display Courses for Instructor" << endl;
        cout << "6. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            instructor.createAssignments();
            break;
        case 2:
            instructor.gradeSubmissions();
            break;
        case 3:
            instructor.monitorStudentProgress();
            break;
        case 4:
            instructor.issueCertifications();
            break;
        case 5:
            displayCoursesForInstructor();
            break;
        case 6:
            homePage();
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}


void adminMenu() {
    Admin admin("Admin", "A1001", "admin@example.com", "A1001", "Full Access", "System");
    while (true) {
        cout << "===========================================" << endl;
        cout << " Admin Menu " << endl;
        cout << "===========================================" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. Remove Course" << endl;
        cout << "3. Assign Instructor" << endl;
        cout << "4. Generate Reports" << endl;
        cout << "5. View Courses" << endl;
        cout << "6. Send System Notification" << endl;
        cout << "7. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1: admin.addCourse(); break;
        case 2: admin.removeCourse(); break;
        case 3: admin.assignInstructor(); break;
        case 4: admin.generateReports(); break;
        case 5: displayCoursesForAdmin(); break;
        case 6: admin.sendSystemNotification(); break;
        case 7: homePage(); return;
        default: cout << "Invalid choice. Try again." << endl; break;
        }
    }

}

int main() {
    homePage();
    return 0;
}