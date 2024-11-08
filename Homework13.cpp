#include <iostream>
#include <string.h>

using namespace std;

struct Student {
private:
    char* name;
    char* surname;
    double averageMark;
public:
    Student() {
        name = new char[9] {'B', 'o', 'r', 'y', 's', 'l', 'a', 'v', '\0' };
        surname = new char[11] {'L', 'i', 'n', 'c', 'h', 'e', 'v', 's', 'k', 'y', '\0'};
        averageMark = 11.2;
    }

    void AssingValues(const char* name, const char* surname, double averageMark) {
        delete[] this->name;
        this->name = nullptr;

        delete[] this->surname;
        this->surname = nullptr;

        this->name = new char[strlen(name) + 1];

        for (int i = 0; i < strlen(name) + 1; i++) {
            this->name[i] = (char)name[i];
        }

        this->surname = new char[strlen(surname) + 1];

        for (int i = 0; i < strlen(surname) + 1; i++) {
            this->surname[i] = (char)surname[i];
        }

        this->averageMark = averageMark;
    }

    

    const char* getName() {
        return name;
    }

    const char* getSurname() {
        return surname;
    }

    double getAverageMark() {
        return averageMark;
    }

    /*~Student() {
        delete[] name;
        name = nullptr;

        delete[] surname;
        surname = nullptr;
    }*/
};

struct Group {
private:
    char* groupName;
    int amountOfStudents;
    Student* arrayOfStudents;
public:
    Group() {
        groupName = new char[4] {'P', '3', '8', '\0'};
        amountOfStudents = 1;
        arrayOfStudents = new Student[1];
        arrayOfStudents[0].AssingValues("Boryslav", "Linchevsky", 11.2);
    }

    void AddStudent(Student student) {
        Student* tempArrOfStudents = new Student[amountOfStudents];
        for (int i = 0; i < amountOfStudents; i++) {
            tempArrOfStudents[i].AssingValues(
                arrayOfStudents[i].getName(),
                arrayOfStudents[i].getSurname(),
                arrayOfStudents[i].getAverageMark());
        }


        delete[] arrayOfStudents;
        arrayOfStudents = nullptr;

        amountOfStudents--;

        arrayOfStudents = new Student[amountOfStudents];

        for (int i = 0; i < amountOfStudents - 1; i++) {
            arrayOfStudents[i].AssingValues(
                tempArrOfStudents[i].getName(),
                tempArrOfStudents[i].getSurname(),
                tempArrOfStudents[i].getAverageMark());
        }

        delete[] tempArrOfStudents;
        tempArrOfStudents = nullptr;

        arrayOfStudents[amountOfStudents - 1].AssingValues(
            student.getName(),
            student.getSurname(),
            student.getAverageMark());
    }

    void DeleteStudent(Student student) {
        if (amountOfStudents - 1 < 0) {
            cout << "There's no student in the group , add someone to have act to delete someone." << endl;
        }
        else {
            int numberOfStudent; // Value for index Student that need to delete.
            cout << "Write number of student that you want to delete: ";
            cin >> numberOfStudent; // User writing index for Value.
            cin.ignore();
            cout << "\n <----------------------------->" << endl;
            /*amountOfStudents--;*/ // removing Student from ammount Of Students.


            //delete[] tempArrOfStudents;
            //tempArrOfStudents = nullptr; // Clearing Temp Arr.

    //        Student* tempArrOfStudents = new Student[amountOfStudents]; // initialization of Temp Arr.
    //        for (int i = 0; i < amountOfStudents + 1; i++) {
    //            int numberForCycle = 0;
    //            const int SecondNumberForCycle = 0;
    //            if (i == numberOfStudent - 1) {
    //                continue;
    //            }
    //            
    //            Student* tempArrOfStudents;

                //for (int i = 0; i < amountOfStudents - 1; i++) {
                //	arrayOfStudents[i].AssingValues(
                //		tempArrOfStudents[i].getName(),
                //		tempArrOfStudents[i].getSurname(),
                //		tempArrOfStudents[i].getAverageMark());
                //}
    //        }

            Student* tempArrOfStudents = new Student[amountOfStudents];
            for (int i = 0; i < amountOfStudents; i++) {
                tempArrOfStudents[i].AssingValues(
                    arrayOfStudents[i].getName(),
                    arrayOfStudents[i].getSurname(),
                    arrayOfStudents[i].getAverageMark());
            }


            delete[] arrayOfStudents;
            arrayOfStudents = nullptr;

            amountOfStudents--;

            arrayOfStudents = new Student[amountOfStudents];



            delete[] tempArrOfStudents;
            tempArrOfStudents = nullptr;

        }
        
    }

	void RenameStudent(Student student) {
		Student* tempArrOfStudents = new Student[amountOfStudents];
        int UserNumber;
        cout << "Enter Index of Student: " << endl;
        cin >> UserNumber;
		tempArrOfStudents[UserNumber].AssingValues(
			arrayOfStudents[UserNumber].getName(),
			arrayOfStudents[UserNumber].getSurname(),
			arrayOfStudents[UserNumber].getAverageMark());

		delete[] arrayOfStudents;
		arrayOfStudents = nullptr;

		arrayOfStudents = new Student[amountOfStudents];



		delete[] tempArrOfStudents;
		tempArrOfStudents = nullptr;
	}

    void PrintGroupInfo() {
        cout << "Group name: " << this->groupName << endl;
        cout << "Amount of students: " << this->amountOfStudents << endl;
        for (int i = 0; i < amountOfStudents; i++) {
            cout << "Student: " << i + 1 << endl;
            cout << "Name: " << this->arrayOfStudents[i].getName() << endl;
            cout << "Surname: " << this->arrayOfStudents[i].getSurname() << endl;
            cout << "Average mark: " << this->arrayOfStudents[i].getAverageMark() << endl;
        }
    }

    const char* getGroupName() {
        return this->groupName;
    }

    void setGroupName(const char* groupName) {
        delete[] this->groupName;
        this->groupName = nullptr;

        this->groupName = new char[strlen(groupName) + 1];

        for (int i = 0; i < strlen(groupName) + 1; i++) {
            this->groupName[i] = (char)groupName[i];
        }
    }

    int getAmountOfStudents() {
        return this->amountOfStudents;
    }

    void setAmountOfStudents(int amountOfStudents) {
        this->amountOfStudents = amountOfStudents;
    }

    Student* getStudentsArray() {
        return this->arrayOfStudents;
    }

    void setStudentsArray(Student* arrayOfStudents, int n) {
        delete[] this->arrayOfStudents;
        this->arrayOfStudents = nullptr;

        this->arrayOfStudents = new Student[n];

        for (int i = 0; i < n; i++) {
            this->arrayOfStudents[i] = (Student)arrayOfStudents[i];
        }
    }

    ~Group() {
        delete[] groupName;
        groupName = nullptr;

        delete[] arrayOfStudents;
        arrayOfStudents = nullptr;
    }
};

int main()
{
    Student obj = Student();

    /*cout << obj.getName() << endl;
    cout << obj.getSurname() << endl;
    cout << obj.getAverageMark() << endl;*/

    obj.AssingValues("Ivan", "Ivanov", 8.8);
    /*cout << obj.getName() << endl;
    cout << obj.getSurname() << endl;
    cout << obj.getAverageMark() << endl;*/

    Group p38 = Group();

    p38.PrintGroupInfo();

    cout << "-----------------------" << endl;
   /* p38.AddStudent(obj);
    p38.PrintGroupInfo();*/

    while (true)
    {
        int TempValueForUser;
        cout << "Choose option : 1 - Add student , 2 - Delete Student , 3 - Rename student , 4 - Show all students : " << endl;
        cin >> TempValueForUser;
        if (TempValueForUser == 1) { // Condition Add Someone to Group.
            p38.AddStudent(obj);
            cout << "-----------------------" << endl;
        }
        else if (TempValueForUser == 2) { // Condition Delete someone of Students.
            p38.DeleteStudent(obj);
            cout << "-----------------------" << endl;
        }
        else if (TempValueForUser == 3) { // Condition Rename someone of Students.
            p38.RenameStudent(obj);
            cout << "-----------------------" << endl;
        }
        else if (TempValueForUser == 4) { // Condition Print All Students.
            p38.PrintGroupInfo();
            cout << "-----------------------" << endl;
        }
        else { // This condition (Условие) for restarting or stoping programm.
            cout << "Something went wrong and program giving error , call developer to fix it." << endl;
            cout << "-----------------------" << endl;
            cout << "Try again? Yes or No: " << endl;
            string ChoosingUserForContinue;
            cin >> ChoosingUserForContinue;
            if (ChoosingUserForContinue == "Yes") {
                continue;
            }
            else {
                break;
            }
        }

    }
}