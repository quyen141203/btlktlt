#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

class Person {
private:
    string full_name;
    string cccd;
    string phone_number; 
    string date_of_birth;
    string email;
    string account;
    string password;

public:
    Person() {
        full_name = "";
        cccd = "";
        date_of_birth = "";
        phone_number = "";
        email = "";
        account = "";
        password = "";
    }
    // Virtual destructor
    ~Person() {}


    // Setters
    void setFullName(const string& name) {
        full_name = name;
    }

    void setCCCD(const string& id) {
        cccd = id;
    }

    void setDateOfBirth(const string& dob) {
        date_of_birth = dob;
    }

    void setPhoneNumber(const string& pn) {
        phone_number = pn;
    }
    void setEmail(const string& e) {
        email = e;
    }

    void setAccount(const string& acc) {
        account = acc;
    }

    void setPassword(const string& pass) {
        password = pass;
    }

    // Getters
    string getFullName() {
        return full_name;
    }

    string getCCCD() {
        return cccd;
    }

    string getDateOfBirth() {
        return date_of_birth;
    }

    string getEmail() {
        return email;
    }

    string getAccount() {
        return account;
    }

    string getPassword() {
        return password;
    }

};

class Student : public Person {
private:
    string student_id;
    string class_name;
    int cohort; // Khoá
    string school;
    string department;

public:
    Student() : cohort(0) {
        student_id = "";
        class_name = "";
        school = "";
        department = "";
    }
    // Destructor
    ~Student() {}

    // Setters
    void setStudentID(const string& id) {
        student_id = id;
    }

    void setClassName(const string& className) {
        class_name = className;
    }

    void setCohort(const int& c) {
        cohort = c;
    }

    void setSchool(const string& s) {
        school = s;
    }

    void setDepartment(const string& d) {
        department = d;
    }

    // Getters
    string getStudentID() {
        return student_id;
    }

    string getClassName() {
        return class_name;
    }

    int getCohort() {
        return cohort;
    }

    string getSchool() {
        return school;
    }

    string getDepartment() {
        return department;
    }

};

class Lecturer : public Person {
private:
    string staff_id;
    string school;
    string department;
    string office;
    string specialization;
public:
   Lecturer() {
        staff_id = "";
        school = "";
        department = "";
        office = "";
        specialization ="";
    }
    // Destructor
    ~Lecturer() {}
    
    // Setters
    void setStaffID(const string& id) {
        staff_id = id;
    }

    void setSchool(const string& s) {
        school = s;
    }

    void setDepartment(const string& d) {
        department = d;
    }

    void setOffice(const string& o) {
        office = o;
    }

    void setSpecialization(const string& sp) {
        specialization = sp;
    }
    // Getters
    string getStaffID() {
        return staff_id;
    }

    string getSchool() {
        return school;
    }

    string getDepartment() {
        return department;
    }

    string getOffice() {
        return office;
    }
    string getSpecialiazation() {
        return specialization;
    }

};

void handleFileOpenError(const string& filename) {
    cerr << "Error opening file: " << filename << endl;
    exit(1);
}

// File studentInfo
void readInformationStudent(vector<Student> &student) {
    ifstream fileStudent("D:\\Desktop\\BTLKTLT\\studentInfo.txt");
    if (!fileStudent.is_open()){
        cout << "Không thể mở file." << endl;
        return;
    } 
    
    string temp;
    string account, password, full_name, cccd, phone_number, date_of_birth, email, student_id, class_name, school, department;
    string cohortStr;
    int cohort;

    fileStudent.clear();
    fileStudent.seekg(0, ios::beg);

    while (fileStudent.peek()!=EOF) {
    getline(fileStudent >> ws, account, ',');
    getline(fileStudent >> ws, password, ',');
    getline(fileStudent >> ws, cccd, ',');
    getline(fileStudent >> ws, full_name, ',');
    getline(fileStudent >> ws, student_id, ',');
    getline(fileStudent >> ws, email, ',');
    getline(fileStudent >> ws, department, ',');
    getline(fileStudent >> ws, date_of_birth, ',');
    getline(fileStudent >> ws, class_name, ',');
    getline(fileStudent >> ws, cohortStr, ',');
    getline(fileStudent >> ws, school, '\n');
    stringstream(cohortStr) >> cohort;

    Student st;

    st.setAccount(account);
    st.setPassword(password);
    st.setCCCD(cccd);
    st.setFullName(full_name);
    st.setStudentID(student_id);
    st.setEmail(email);
    st.setDepartment(department);
    st.setDateOfBirth(date_of_birth);
    st.setClassName(class_name);
    st.setCohort(cohort);
    st.setSchool(school);

    student.push_back(st);
    }
    fileStudent.close();
}
// GHi lại cả file
void writeStudentInformation(vector<Student> students) {
    Student st;
    ofstream fileStudent("D:\\Desktop\\BTLKTLT\\studentInfo.txt", ::ios::app);
    if (!fileStudent.is_open()) {
        cout << "Không thể mở file để ghi." << endl;
        return;
    }
    for (auto& st : students) {
    fileStudent << st.getAccount() << ',' << st.getPassword() << ',' << st.getCCCD() << ',' << st.getFullName() << ','<< st.getStudentID() << ',' << st.getEmail() << ','<< st.getDepartment() << ',' << st.getDateOfBirth() << ',' << st.getClassName() << ',' << st.getCohort() << ','<< st.getSchool() << '\n';
    }
    fileStudent.close();
}
// Ghi lại 1 class 
void writeStudentInformation(Student& st) {
    ofstream fileStudent("D:\\Desktop\\BTLKTLT\\studentInfo.txt", ::ios::app);
    if (!fileStudent.is_open()) {
        cout << "Không thể mở file để ghi." << endl;
        return;
    }
    fileStudent << "\n";
    fileStudent << st.getAccount() << ',' << st.getPassword() << ',' << st.getCCCD() << ',' << st.getFullName() << ','<< st.getStudentID() << ',' << st.getEmail() << ','<< st.getDepartment() << ',' << st.getDateOfBirth() << ',' << st.getClassName() << ',' << st.getCohort() << ','<< st.getSchool() << '\n';
    fileStudent.close();
}

// File Lecturer

void readInformationLecturer(vector<Lecturer> &lecturer) {
    ifstream fileLecturer("D:\\Desktop\\BTLKTLT\\LecturerInfo.txt");
    if (!fileLecturer.is_open()){
        cout << "Không thể mở file." << endl;
        return;
    } 
    
    string temp;
    string full_name,account, password, cccd, specialization, office, date_of_birth, email, staff_id, class_name, school, department;
    string cohortStr;
    int cohort;



    while (fileLecturer.peek()!=EOF) {
    getline(fileLecturer >> ws, account, ',');
    getline(fileLecturer >> ws, password, ',');
    getline(fileLecturer >> ws, cccd, ',');
    getline(fileLecturer >> ws, full_name, ',');
    getline(fileLecturer >> ws, staff_id, ',');
    getline(fileLecturer >> ws, email, ',');
    getline(fileLecturer >> ws, department, ',');
    getline(fileLecturer >> ws, specialization, ',');
    getline(fileLecturer >> ws, date_of_birth, ',');
    getline(fileLecturer >> ws, school, ',');
    getline(fileLecturer >> ws, office, '\n');

    Lecturer lt;
    lt.setAccount(account);
    lt.setPassword(password);
    lt.setCCCD(cccd);
    lt.setFullName(full_name);
    lt.setStaffID(staff_id);
    lt.setEmail(email);
    lt.setDepartment(department);
    lt.setSpecialization(specialization);
    lt.setDateOfBirth(date_of_birth);
    lt.setSchool(school);
    lt.setOffice(office);
  
    lecturer.push_back(lt);
    }
    fileLecturer.close();
}
// Ghi lại vector
void writeLecturerInformation(vector<Lecturer>& lecturer) {
    ofstream fileLecturer("D:\\Desktop\\BTLKTLT\\lecturerInfo.txt", ::ios::app);
    if (!fileLecturer.is_open()) {
        cout << "Không thể mở file để ghi." << endl;
        return;
    }
    Lecturer lt;
    for (auto & lt : lecturer) {
    fileLecturer << lt.getAccount() << ','<< lt.getPassword() << ','<< lt.getCCCD() << ','<< lt.getFullName() << ','<< lt.getStaffID() << ',' << lt.getEmail() << ',' << lt.getDepartment() << ',' << lt.getSpecialiazation() << ',' << lt.getDateOfBirth() << ',' << lt.getSchool() << ',' << lt.getOffice() << ',' << endl;
    }
    fileLecturer.close();
}

void writeLecturerInformation(Lecturer &lt) {
    ofstream fileLecturer("D:\\Desktop\\BTLKTLT\\lecturerInfo.txt", ::ios::app);
    if (!fileLecturer.is_open()) {
        cout << "Không thể mở file để ghi." << endl;
        return;
    }
    fileLecturer << lt.getAccount() << ','<< lt.getPassword() << ','<< lt.getCCCD() << ','<< lt.getFullName() << ','<< lt.getStaffID() << ',' << lt.getEmail() << ',' << lt.getDepartment() << ',' << lt.getSpecialiazation() << ',' << lt.getDateOfBirth() << ',' << lt.getSchool() << ',' << lt.getOffice() << ',' << endl;
    fileLecturer.close();
}

// Hàm xoá file 
void deleteFileStudent () {
    ofstream fileStudent("D:\\Desktop\\BTLKTLT\\studentInfo.txt", ::ios::trunc);
        if (!fileStudent.is_open()) {
            cout << "Không thể mở file để ghi." << endl;
            return;
        }
    fileStudent.close();
}

void deleteFileLecturer () {
    ofstream fileLecturer("D:\\Desktop\\BTLKTLT\\LecturerInfo.txt", ::ios::trunc);
        if (!fileLecturer.is_open()) {
            cout << "Không thể mở file để ghi." << endl;
            return;
        }
    fileLecturer.close(); 
}

// Các hàm tạo, đổi mật khẩu, quên mật khẩu 
void createAccount(char option);
void logIn(char option);
void forgotPassword(char option);
void changePassword(char option);
void account(char& option){
    char option1;
    do {
    // Giao diện tài khoản
    cout << "\n\t\t ====== Person Account ====== \n";
    cout << "\n\t\t\t1. Create account ";
    cout << "\n\t\t\t2. Log in ";
    cout << "\n\t\t\t3. Forgot password";
    cout << "\n\t\t\t4. Change password";
    cout << "\n\t\t\t0. Exit";
    cout << "\n\n\n\t\t\tEnter Your Option: ";
    cin >> option1;
    cin.ignore();
    
    switch (option1)
    {
    case '1':
        createAccount(option);
        if (option1 == 0) continue;
        break;
    case '2':
        logIn(option);
        if (option == 0) continue;
        break;
    case '3':
        forgotPassword(option);
        break;
    case '4':
        changePassword(option);
        if (option == 0) continue;
        break;
    case '0':
        option = 0;
        break;
    default:
        cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
        option1 = 0;
        }
    } while (option == 0 && option1 == 0);
}

void createAccount(char option){
    string temp;
    string select;
    Student st;
    Lecturer lt;
    int cohort;

    vector<Student> students;
    vector<Lecturer> lecturer;
    int count;

    do 
    {
        count = 0;
        if (option == '1') {
            Student studentInformation;
            readInformationStudent(students);
            cout << "\n\t\t\tEnter Account Name:";
            getline(cin, temp);
            studentInformation.setAccount(temp);

            cout << "\n\t\t\tEnter Password:";
            getline(cin, temp);
            studentInformation.setPassword(temp);

            cout << "\n\t\t\tEnter CCCD number :";
            getline(cin, temp);
            studentInformation.setCCCD(temp);
                
            cout << "\n\t\t\tEnter Student's Name :";
            getline(cin, temp);
            studentInformation.setFullName(temp);

            cout << "\n\t\t\tEnter Student's ID :";
            getline(cin, temp);
            studentInformation.setStudentID(temp);

            cout << "\n\t\t\tEnter Email :";
            getline(cin, temp);
            studentInformation.setEmail(temp);

            cout << "\n\t\t\tEnter Student's Department :";
            getline(cin, temp);
            studentInformation.setDepartment(temp);

            cout << "\n\t\t\tEnter Date of Birth :";
            getline(cin, temp);
            studentInformation.setDateOfBirth(temp);

            cout << "\n\t\t\tEnter Class Name :";
            getline(cin, temp);
            studentInformation.setClassName(temp);

            cout << "\n\t\t\tEnter Cohort :";
            cin >> cohort;
            cin.ignore();
            studentInformation.setCohort(cohort);

            cout << "\n\t\t\tEnter School :";
            getline(cin, temp);
            studentInformation.setSchool(temp);

            for (auto& st : students) {
                if (st.getAccount() == studentInformation.getAccount()) {
                    cout << "\n\n\t\t\tAccount already exists!" <<endl;
                    count++;
                    break;
                }
            }
            if (count == 0) {
                writeStudentInformation(studentInformation);
                cout << "\t\t\tAccount has been stored successfully\n";
                cout << "\t\t\tDo you want to log in now? (y/n)";
                cin >> select;
                cin.ignore(); 

                if (select == "y" ) 
                {
                cout <<"\n\n\t\t\tLog in successfully!\n\n";
                cout <<"\n\t\t\tPress any key to continue...";
                break;
                }
                else cout << "\n\n\t\t\tAccount created. Press any key to continue...";

                cin.get();
            }
        } 
        if (option == '2') {
            Lecturer lecturerInformation;
            readInformationLecturer(lecturer);

            cout << "\n\t\t\tEnter Account Name: ";
            getline(cin, temp);
            lecturerInformation.setAccount(temp);

            cout << "\n\t\t\tEnter Password: ";
            getline(cin, temp);
            lecturerInformation.setPassword(temp);

            cout << "\n\t\t\tEnter CCCD number : ";
            getline(cin, temp);
            lecturerInformation.setCCCD(temp);

            cout << "\t\t\tEnter lecturer name : ";
            getline(cin, temp);
            lecturerInformation.setFullName(temp);
            
            cout << "\t\t\tEnter staff id : ";
            getline(cin, temp);
            lecturerInformation.setStaffID(temp);

            cout << "\t\t\tEnter email : ";
            getline(cin, temp);
            lecturerInformation.setEmail(temp);

            cout << "\t\t\tEnter department : ";
            getline(cin, temp);
            lecturerInformation.setDepartment(temp);

            cout << "\t\t\tEnter specialization : ";
            getline(cin, temp);
            lecturerInformation.setSpecialization(temp);

            cout << "\t\t\tEnter date of birth(yyyy/mm/dd) : ";
            getline(cin, temp);
            lecturerInformation.setDateOfBirth(temp);

            cout << "\t\t\tEnter school : ";
            getline(cin, temp);
            lecturerInformation.setSchool(temp);       
            
            cout << "\t\t\tEnter office : ";
            getline(cin, temp);
            lecturerInformation.setOffice(temp);

            for (auto& lt : lecturer) {
                if (lt.getAccount() == lecturerInformation.getAccount()) {
                    cout << "cout << \n\n\t\t\tAccount already exists! <<endl";
                    count++;
                    break;
                }
            }
            if (count == 0) {
                writeLecturerInformation(lecturerInformation);
                cout << "\t\t\tAccount has been stored successfully\n";
                cout << "\t\t\tDo you want to log in now? (y/n)";
                cin >> select;
                cin.ignore(); 

                if (select == "y" ) 
                {
                cout <<"\n\n\t\t\tLog in successfully!\n\n";
                cout <<"\n\t\t\tPress any key to continue...";
                cin.get();
                break;
                }
                else cout << "\n\n\t\t\tAccount created. Press any key to continue...";

                cin.get();
            }
        }     
    } while (count != 0);
}

void logIn(char option) {
    string temp;
    vector<Student> student;
    vector<Lecturer> lecturer;
    Person personLogIn;
    Student st;
    Lecturer lt;
    const int maxAttemps = 3;
    int attempts = 0;
    int count;
    cout << option;
    do {
        count = 0;
        cout << "\n\t\t\tEnter Account Name: ";
        getline(cin, temp);
        personLogIn.setAccount(temp);

        cout << "\n\t\t\tEnter Password: ";
        getline(cin, temp);
        personLogIn.setPassword(temp);

        if (option == '1') {
            readInformationStudent(student);
            for (auto& st : student){
                if (personLogIn.getAccount() == st.getAccount() && personLogIn.getPassword() == st.getPassword()) {
                    cout <<"\n\n\t\t\tLog in successfully!\n\n";
                    cout <<"\n\t\t\tPress any key to continue...";
                    cin.get();
                    count++;
                    break;
                }
            }
            if (count != 0) break;
            if (count == 0) {
                cout << "\n\t\t\tIncorrect account or password! Please re-enter." << endl;
                attempts++;
            }
            if (attempts >= maxAttemps) {
                cout << "\n\t\t\tToo many incorrect attempts. Exiting." << endl;
                break;
            }
        }   
        if (option == '2') {
            readInformationLecturer(lecturer);
            for (auto& lt : lecturer){
                if (personLogIn.getAccount() == lt.getAccount() && personLogIn.getPassword() == lt.getPassword()) {
                    cout <<"\n\n\t\t\tLog in successfully!\n\n";
                    cout <<"\n\t\t\tPress any key to continue...";
                    cin.get();
                    count++;
                    break;
                }
            }
            if (count == 0) {
                cout << "\n\t\t\tIncorrect account or password! Please re-enter." << endl;
                attempts++;
            }
            if (attempts >= maxAttemps) {
                cout << "\n\t\t\tToo many incorrect attempts. Exiting." << endl;
                break;
            }
        }

    } while (count == 0);
}

void changePassword(char option) {
    string temp;
    Student st;
    Lecturer lt;
    vector<Lecturer> lecturer;
    vector<Student> student;
    const int maxAttemps = 3;
    int attempts = 0;
    int count;
    do {
    count = 0;
    if (option == '1') {
        Student studentChange;
        readInformationStudent(student);

        cout << "\n\t\t\tEnter Accountx Name: ";
        getline(cin, temp);
        studentChange.setAccount(temp);

        cout << "\n\t\t\tEnter odd Password: ";
        getline(cin, temp);
        studentChange.setPassword(temp);
        for (auto& st : student) {
            if (st.getAccount() == studentChange.getAccount() || st.getPassword() == studentChange.getPassword()) {
               cout << "\n\t\t\tEnter new password: ";
               getline(cin, temp);
               studentChange.setPassword(temp);
               writeStudentInformation(student);
               cout << "\n\t\t\tPassword changed successfully. ";
               cout <<"\n\t\t\tPress any key to continue...";
               cin.get();
               count++;
            }
        }                
    }
    if (count == 0) {
        cout << "\n\t\t\tIncorrect account or password! Please re-enter." << endl;
    } 
    
    } while (count == 1);    
}

void forgotPassword(char option) {
    string temp;
    vector<Student> student;
    vector<Lecturer> lecturer;
    int count;
    do {
    count = 0;
    if (option == 1) {
        Student studentChange;
        readInformationStudent(student);
        deleteFileStudent();
        cout << "\n\t\t\tEnter Account Name: ";
        getline(cin, temp);
        studentChange.setAccount(temp);

        cout << "\n\t\t\tEnter odd Password: ";
        getline(cin, temp);
        studentChange.setPassword(temp);
        for (auto& st : student) {
            if (st.getAccount() == studentChange.getAccount() || st.getPassword() == studentChange.getPassword()) {
               cout << "\n\t\t\tEnter new password: ";
               getline(cin, temp);
               studentChange.setPassword(temp);
               writeStudentInformation(student);
               cout << "\n\t\t\tPassword changed successfully. ";
               cout <<"\n\t\t\tPress any key to continue...";
               cin.get();
               count++;
            }
        }                
    }
    if (count == 0) {
        cout << "\n\t\t\tIncorrect account or password! Please re-enter." << endl;
    } 
    
    } while (count == 1);    
}

// Hàm display menu
void displayMenu() {
    cout << "\t\t====== Person Management Database System ======\n";
    cout << "\n\t\t\tYou are : ";
    cout << "\n\t\t\t1. Student";
    cout << "\n\t\t\t2. Lecture";
    cout << "\n\t\t\t3. Parents";
    cout << "\n\t\t\t0. Exit";
    cout << "\n\n\n\t\t\tEnter Your Option: ";
}

// Các hàm display của sinh viên 
// Display toàn bộ sinh viên
void displayStudentInfo(Student st) {

   
    cout << left << setw(26) << st.getFullName()
         << left << setw(26) << st.getStudentID()
         << left << setw(26) << st.getDateOfBirth()
         << left << setw(26) << st.getCohort()
         << left << setw(26) << st.getDepartment()
         << left << st.getSchool() << endl;
}
void allInfoStudent(){
    vector<Student> students;
    Student st;
    readInformationStudent(students);

    cout << "\n\t\t\t\t\t======All student infomation======\n";
    
    cout<< left << setw(26) << "Name"
        << left << setw(26) << "ID"
        << left << setw(26) << "Date of birth"
        << left << setw(26) << "Cohort"
        << left << setw(26) << "Department"
        << left << setw(26) << "School" << endl;
    for (const auto& st : students) {
        displayStudentInfo(st);
    }
    cout <<"\n\t\t\tPress any key to continue...";
    cin.get();
}

// Tìm kiếm sinh viên theo,..
// Hàm tìm sinh viên
void compareStudentInfo (string temp, int& count) {
    vector<Student> students;
    Student st;

    readInformationStudent(students);
    for (auto& st : students) {
            if (temp == st.getStudentID() || temp == st.getFullName()) {
                
            cout<< left << setw(26) << "Name"
                << left << setw(26) << "ID"
                << left << setw(26) << "Date of birth"
                << left << setw(26) << "Cohort"
                << left << setw(26) << "Department"
                << left << setw(26) << "School" << endl;
                displayStudentInfo(st);
                count++;
                return;
            }
            
        }
}

void searchStudentInfo(){
    char option;
    string temp;
    Student st;
    int count;

    cout << "\n\t\t\tDo you want to search by student id or name? ";
    cout << "\n\t\t\t1.Student id";
    cout << "\n\t\t\t2.Name";
    cout << "\n\t\t\t0.Exit";
    cout << "\n\n\n\t\t\tEnter your option : ";
    cin >> option;
    cin.ignore();
    
    switch (option)
    {
    case '1':
        do{
        count = 0;
        cout << "\n\n\t\t\tEnter student id : ";
        getline(cin, temp);
        compareStudentInfo(temp,count);
        if (count == 0) {
            cout << "\n\t\t\tDoes not exist. Please re-enter";
        }       
        } while(count == 0);
        break;
    case '2':
        do {
        count = 0;
        cout << "\n\n\t\t\tEnter student name : ";
        getline(cin, temp);
        compareStudentInfo(temp,count);
        if (count == 0) {
            cout << "\n\t\t\tDoes not exist. Please re-enter";
        }       
        } while(count == 0);
        break;
    case '0': 
        break;
    default:
        cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
        break;
    }

}

// Hàm display của giáo viên
void displayLecturerInfo(Lecturer lt) {

    cout << "\t\t"
        << left << setw(26) << lt.getFullName()
        << left << setw(26) << lt.getStaffID()
        << left << setw(26) << lt.getDepartment()
        << left << setw(26) << lt.getSpecialiazation()
        << left << setw(26) << lt.getDateOfBirth()
        << left << setw(26) << lt.getSchool()
        << left << lt.getOffice() << endl;
}

void allInfoLecturer(){
    vector<Lecturer> lecturers;
    Lecturer lt;
    readInformationLecturer(lecturers);

    cout << "\n\t\t\t\t\t======All lecturer infomation======\n";
    cout << "\n\n\t\t"
        << left << setw(26) << "Name"
        << left << setw(26) << "ID"
        << left << setw(26) << "Department"
        << left << setw(26) << "Specialization"
        << left << setw(26) << "Date of birth"
        << left << setw(26) << "School" 
        << left << "Office" << endl;
    for (auto& lt : lecturers) {
        displayLecturerInfo(lt);
    }
}
void compareLecturerInfo (string temp, int& count) {
    vector<Lecturer> lecturers;
    Lecturer lt;

    readInformationLecturer(lecturers);
    for (auto& lt : lecturers) {
            if (temp == lt.getStaffID() || temp == lt.getFullName()) {
                cout << "\n\n\t\t"
                    << left << setw(26) << "Name"
                    << left << setw(26) << "ID"
                    << left << setw(26) << "Department"
                    << left << setw(26) << "Specialization"
                    << left << setw(26) << "Date of birth"
                    << left << setw(26) << "School" 
                    << left << "Office" << endl;
                displayLecturerInfo(lt);
                count++;
                cout << "\n\t\t\tPress any key to continue...";
                cin.get();
                return;
                
            }
            if (count == 0) {
            cout << "\n\t\t\tDoes not exist. Please re-enter";
        }       
            
        }
}

void searchLecturerInfo(){
    char option;
    string temp;
    Lecturer lt;
    int count;

    cout << "\n\t\t\tDo you want to search by staff id or name? ";
    cout << "\n\t\t\t1.Staff id";
    cout << "\n\t\t\t2.Name";
    cout << "\n\t\t\t0.Exit";
    cout << "\n\n\n\t\t\tEnter your option : ";
    cin >> option;
    cin.ignore();
    
    switch (option)
    {
    case '1':
        do{
        count = 0;
        cout << "\n\n\t\t\tEnter staff id : ";
        getline(cin, temp);
        compareLecturerInfo(temp,count);     
        } while(count == 0);
        break;
    case '2':
        do {
        count = 0;
        cout << "\n\n\t\t\tEnter student name : ";
        getline(cin, temp);
        compareLecturerInfo(temp,count);
        } while(count == 0);
        break;
    case '0': 
        break;
    default:
        cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
        break;
    }

}

// Hàm update thông tin sinh viên, giáo viên
void updateStudentInfo(){

    Student st;
    vector<Student> student;
    string temp;
    string newInfo;
    string mssv;    
    char option;
    int count1, count2;
    do {
    cout << "\n\t\t\tEnter your student ID : ";
    getline(cin, mssv);
    readInformationStudent(student);
    for (auto& st : student) {
       if(mssv == st.getStudentID()) {
    cout << "\n\t\t\t======Update student information======\n";
    cout << "\n\t\t\t1.Update name";
    cout << "\n\t\t\t2.Update Student ID";
    cout << "\n\t\t\t3.Update Email";
    cout << "\n\t\t\t4.Update Department";
    cout << "\n\t\t\t5.Update Date of birth";
    cout << "\n\t\t\t6.Update class name";
    cout << "\n\t\t\t7.Update cohort";
    cout << "\n\t\t\t8.Update school";
    cout << "\n\t\t\t0.Exit";
    cout << "\n\n\n\t\t\tEnter your option : ";
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case '1':  
        st.setFullName("");
        deleteFileStudent();                
        cout << "\n\t\t\tEnter new name : ";
        getline(cin, newInfo);
        st.setFullName(newInfo);
        writeStudentInformation(student);
        
        cout << "\n\t\t\tName change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);

        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;

    case '2':  
        st.setStudentID("");
        deleteFileStudent();
        cout << "\n\t\t\tEnter new student ID : ";
        getline(cin, newInfo);
        st.setStudentID(newInfo);
        writeStudentInformation(student);
                
        cout << "\n\t\t\tID change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);

        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;

    case '3':  
        st.setEmail("");
        deleteFileStudent();
        cout << "\n\t\t\tEnter new email : ";
        getline(cin, newInfo);
        st.setEmail(newInfo);
        writeStudentInformation(student);
                
        cout << "\n\t\t\tEmail change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);
        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;
            
    case '4':  
        st.setDepartment("");
        deleteFileStudent();
        cout << "\n\t\t\tEnter new department : ";
        getline(cin, newInfo);
        st.setDepartment(newInfo);
        writeStudentInformation(student); 

        cout << "\n\t\t\tDeparment change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);
        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;
            
    case '5':    
        st.setDateOfBirth("");
        deleteFileStudent();

        cout << "\n\t\t\tEnter new date of birth : ";
        getline(cin, newInfo);
        st.setDateOfBirth(newInfo);
        writeStudentInformation(student);              
        cout << "\n\t\t\tDate of birth change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);
        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;

    case '6':  
        st.setClassName("");
        deleteFileStudent();
        
        cout << "\n\t\t\tEnter new class name : ";
        getline(cin, newInfo);
        st.setDateOfBirth(newInfo);
        writeStudentInformation(student);               
        cout << "\n\t\t\tClass name change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);
        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;
          
    case '7':  
        int cohort, newCohort;
        deleteFileStudent();
        cout << "\n\t\t\tEnter new cohort: ";
        cin >> newCohort;
        cin.ignore();
        st.setCohort(newCohort);
        writeStudentInformation(student);           
        cout << "\n\t\t\tCohort change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);
        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;
           
    case '8':  
        st.setSchool("");
        deleteFileStudent();
        cout << "\n\t\t\tEnter new school : ";
        getline(cin, newInfo);
        st.setSchool(newInfo);
        writeStudentInformation(student);              
        cout << "\n\t\t\tSchool change successful. Do you want to change any more information?(y/n) ";
        getline(cin, temp);
        if (temp == "y") count2 = 1;
        else count2 = 0;
        break;
            
    case '0':
        break;
    default:
        cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
        break;
    }   
        }
    }
    } while (count2 != 0);
}

// Update giáo viên
void updateLecturerInfo() {
    Lecturer lt;
    vector <Lecturer> lecturer;
    string temp;
    string newInfo;
    char option;
    int count2;
    bool check;
    Lecturer lttemp;
    do {
    cout << "\n\t\t\tEnter your staff ID : ";
    getline(cin, temp);
    readInformationLecturer(lecturer);
    for (auto& lt : lecturer) {
        if (temp == lt.getStaffID()) {
            cout << "\n\t\t\t\t\t======Update lecturer information======\n";
            cout << "\n\t\t\t1.Update name";
            cout << "\n\t\t\t2.Update staff ID";
            cout << "\n\t\t\t3.Update email";
            cout << "\n\t\t\t4.Update department";
            cout << "\n\t\t\t5.Update specialization";
            cout << "\n\t\t\t6.Update date of birth";
            cout << "\n\t\t\t7.Update school";
            cout << "\n\t\t\t8.Update office";
            cout << "\n\t\t\t0.Exit";
            cout << "\n\n\n\t\t\tEnter your option : ";
            cin >> option;
            cin.ignore();

            switch (option)
            {
            case '1':
                lt.setFullName("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new name : ";
                getline(cin, newInfo);
                lt.setFullName(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tName change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 = 1;
                else count2 = 0;
                break;
                
            case '2':
                lt.setStaffID("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new staff ID : ";
                getline(cin, newInfo);
                lt.setStaffID(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tStaff id change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 =1;
                else count2 = 0;
                break;
                   
            case '3':
                lt.setEmail("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new email : ";
                getline(cin, newInfo);
                lt.setEmail(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tEmail change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 =1;
                else count2 = 0;
                break;
            case '4':
                lt.setDepartment("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new department : ";
                getline(cin, newInfo);
                lt.setDepartment(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tDepartment change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 =1;
                else count2 = 0;
                break;
            case '5':
                lt.setSpecialization("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new specialization : ";
                getline(cin, newInfo);
                lt.setSpecialization(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tspecialization change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 =1;
                else count2 = 0;
                break;
               
            case '6':               
                lt.setDateOfBirth("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new date of birth : ";
                getline(cin, newInfo);
                lt.setDateOfBirth(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tDate of birth change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 =1;
                else count2 = 0;
                break;
              
            case '7':
                lt.setSchool("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new school : ";
                getline(cin, newInfo);
                lt.setSchool(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tSchool change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 =1;
                else count2 = 0;
                break;
                
            case '8':
                lt.setOffice("");
                deleteFileLecturer();
                cout << "\n\t\t\tEnter new office : ";
                getline(cin, newInfo);
                lt.setOffice(newInfo);
                writeLecturerInformation(lecturer);

                cout << "\n\t\t\tOffice change successful. Do you want to change any more infomation ?";
                getline(cin, temp);
                if (temp ==  "y") count2 =1;
                else count2 = 0;
                break;
            case '0' : 
                break;
            default:
                cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
                break;

        }
        }
    }
    if (option == 0) break;
    } while (count2 != 0);
}
// Hàm của phụ huynh xem thông tin 
void parents (char &option) {
    Student st;
    string temp;
    vector <Student> student;
    readInformationStudent(student);
    cout << "\n\t\t\tEnter your child's student ID : ";
    getline(cin, temp);
    for (auto & st : student) {
        if (temp == st.getStudentID()) {
             cout << "\n\n\t\t"
                << left << setw(26) << "Name"
                << left << setw(26) << "ID"
                << left << setw(26) << "Date of birth"
                << left << setw(26) << "Cohort"
                << left << setw(26) << "Department"
                << left << setw(26) << "School" << endl;
            displayStudentInfo(st);
            option = 0;
            break;
        } else {
            cout << "\n\t\t\tInvalid student ID. Please re-enter!";
            option = 1;
        }
    }
}

int main()
{
    char option1,option2, option3, optiontemp;   
    // Xử lý với file
    fstream fileStudent("D:\\Desktop\\BTLKTLT\\studentInfo.txt",ios::in | ios::out | ios::app);
    fstream fileLecture("D:\\Desktop\\BTLKTLT\\lecturerInfo.txt",ios::in | ios::out | ios::app);
    if (!fileStudent.is_open()) {
        handleFileOpenError("studentInfo.txt");
    }
    if (!fileLecture.is_open()) {
        handleFileOpenError("lecturerInfo.txt");
    }
    if (!fileStudent.is_open() || !fileLecture.is_open()) {
        cout << "Error opening one or more files. The program will exit." << endl;
        return 1; 
    }
    
    do 
    {
    displayMenu();
    cin >> option1;
    cin.ignore(); 
    switch (option1)
    {
    case '1':
        account(option1);
        break;
    case '2':
        account(option1);
        break;
    case '3':
        parents(option1);
        break;
    case '0':
        break;
    default:
        cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
        break;
    }
    if (option1 == 0) continue;
    optiontemp = option1;
    do {
    switch (optiontemp) {
        case '1':; 
            cout << "\n\t\t====== Student Management Database System ======\n";
            cout << "\n\t\t\t1. Display All Students Information";
            cout << "\n\t\t\t2. Update Student Information";
            cout << "\n\t\t\t3. Search Student Information";
            cout << "\n\t\t\t4. CPA "; // thêm sau
            cout << "\n\t\t\t0. Exit";
            cout << "\n\n\n\t\t\tEnter Your Option: ";
            cin >> option2;
            cin.ignore(); 
            switch (option2)
            {
                case '1':
                    allInfoStudent();
                    break;
                case '2':
                    updateStudentInfo();
                    break;
                case '3':
                    searchStudentInfo();
                    break;
                case '0':
                    break;
                default:
                    cout << "\n\t\t\tInvalid Option, Please Enter Right Option !\n";
                    break;
                }  
        
        break;   
        case '2':
            cout << "\n\t\t====== Lecturer Management Database System ======\n";
            cout << "\n\t\t\t1. Display All Students Information";
            cout << "\n\t\t\t2. Display All Lecture Information";
            cout << "\n\t\t\t3. Update Lecture Information";
            cout << "\n\t\t\t4. Search Lecture Information";
            cout << "\n\t\t\t0. Exit";
            cout << "\n\n\n\t\t\tEnter Your Option: ";               
            cin >> option3;
            cin.ignore(); 
            switch (option3)
            {
                case '1':
                    allInfoStudent();
                    break;
                case '2':
                    allInfoLecturer();
                    break;
                case '3':
                    updateLecturerInfo();
                    break;
                case '4':
                    searchLecturerInfo();
                    break;
                case '0':
                    break;
                
            } 
            break;
        case '0':
            cout << "\n\t\t\t====== Thank You ======";
            break;
            }
        } while (option2 != '0' && option3 != '0');

    } while (option1 != '0' && option2 != '0' && option3 != '0' && optiontemp != '0');
           
    fileStudent.close();
    fileLecture.close();

    return 0;
}

