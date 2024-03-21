  #include<iostream>
  #include<vector>
  using namespace std;
  
  
  class Student {
  	private:
	  int Rollno, Age, Phone;
	  string Name; 
	public:
		Student(int stdrollno, string stdname, int stdage, int stdphone){
			Rollno = stdrollno;
			Name = stdname; 
			Age = stdage;
			Phone = stdphone;
		}
		void setRollno(int stdrollno){
			Rollno = stdrollno;
		}
		int getRollno(){
			return Rollno;
		}
		void setName(string stdname){
			Name = stdname;
		}
		string getName(){
			return Name;
		}
		void setAge(int stdage){
			Age = stdage;
		}
		int getAge(){
			return Age;
		}
		void setPhone(int stdphone){
			Phone = stdphone;
		}
		int getPhone(){
			return Phone;
		}
  };
// Create function to add new student
void addNewStudent(vector<Student> & students){
    int rollno, age, phone;
    string name;
    cout<<"\t\tEnter Rollno :";
    cin>>rollno;

    //check if student already exists
    for(int i=0; i<students.size(); i++){
        if(students[i].getRollno()==rollno){
            cout<<"\t\tStudent Already exists....."<<endl;
            return;
        }
    }
    cout<<"\t\tEnter Name :";
    cin>>name;
    cout<<"\t\tEnter Age :";
    cin>>age;
    cout<<"\t\tEnter Phone :";
    cin>>phone;

    Student newStudent(rollno, name, age, phone);
    students.push_back(newStudent);

    cout<<"\t\tStudent Added Successfully...."<<endl;
}


// Function to display all student records
void displayAllStudents(vector<Student> &students){
    if (students.empty()) {
        cout << "\t\tNo students found." << endl;
        return;
    }
    cout << "\t\tStudent Records:" << endl;
    cout << "\t\tRoll No\tName\tAge\tPhone" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\t\t" << students[i].getRollno() << "\t" << students[i].getName() << "\t" << students[i].getAge() << "\t" << students[i].getPhone() << endl;
    }
}


// Function to search for a student by roll number
void searchStudent(vector<Student> &students, int rollNo){
    for(size_t i = 0; i < students.size(); ++i){
        if(students[i].getRollno() == rollNo){
            cout << "\t\tStudent Record Found:" << endl;
            cout << "\t\tRoll No: " << students[i].getRollno() << endl;
            cout << "\t\tName: " << students[i].getName() << endl;
            cout << "\t\tAge: " << students[i].getAge() << endl;
            cout << "\t\tPhone: " << students[i].getPhone() << endl;
            return;
        }
    }
    cout << "\t\tStudent with Roll No " << rollNo << " not found." << endl;
}

// Function to update student record by roll number
void updateStudent(vector<Student> &students, int rollNo){
    for(size_t i = 0; i < students.size(); ++i){
        if(students[i].getRollno() == rollNo){
            string name;
            int age, phone;
            cout << "\t\tEnter New Name: ";
            cin >> name;
            students[i].setName(name);
            cout << "\t\tEnter New Age: ";
            cin >> age;
            students[i].setAge(age);
            cout << "\t\tEnter New Phone: ";
            cin >> phone;
            students[i].setPhone(phone);
            cout << "\t\tStudent Record Updated Successfully." << endl;
            return;
        }
    }
    cout << "\t\tStudent with Roll No " << rollNo << " not found." << endl;
}

// Function to delete student record by roll number
void deleteStudent(vector<Student> &students, int rollNo){
    for(size_t i = 0; i < students.size(); ++i){
        if(students[i].getRollno() == rollNo){
            students.erase(students.begin() + i);
            cout << "\t\tStudent Record Deleted Successfully." << endl;
            return;
        }
    }
    cout << "\t\tStudent with Roll No " << rollNo << " not found." << endl;
}

//main
int main(){
    vector<Student> students;
    students.push_back(Student(1, "Himanshu", 18, 8004642813));
    
    char choice;
    
    do{
        system("cls");
        int op;
        cout<<"\t\t---------------------------"<<endl;
        cout<<"\t\tStudent Record Management System"<<endl;
        cout<<"\t\t---------------------------"<<endl;
        cout<<"\t\t1. Add New Student"<<endl;
        cout<<"\t\t2. Display All Student"<<endl;
        cout<<"\t\t3. Search Student"<<endl;
        cout<<"\t\t4. Update Student"<<endl;
        cout<<"\t\t5. Delete Student"<<endl;
        cout<<"\t\t6. Exit"<<endl;
        cout<<"\t\tEnter your choice : ";
        cin>>op;
        switch(op){
            case 1:
                addNewStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                int rollNoSearch;
                cout << "\t\tEnter Roll No to Search: ";
                cin >> rollNoSearch;
                searchStudent(students, rollNoSearch);
                break;
            case 4:
                int rollNoUpdate;
                cout << "\t\tEnter Roll No to Update: ";
                cin >> rollNoUpdate;
                updateStudent(students, rollNoUpdate);
                break;
            case 5:
                int rollNoDelete;
                cout << "\t\tEnter Roll No to Delete: ";
                cin >> rollNoDelete;
                deleteStudent(students, rollNoDelete);
                break;
            case 6:
                exit(1);
            default:
                cout<<"\t\tInvalid Number......"<<endl;
        }
        cout<<"\t\tDo you want to Continue [yes / No ] ? :";
        cin>>choice;
        
    } while (choice == 'y' || choice == 'Y');
    
}  	

