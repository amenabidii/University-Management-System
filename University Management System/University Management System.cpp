#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class person {
	string name;
	int id, age;
public:
	//constructor
	person(string newname, int newage, int newid) {
		name = newname;
		id = newid;
		age = newage;
	}
	//setters
	void setname(string newname) {
		name = newname;
	}
	void setid(int newid) {
		id = newid;
	}
	void setage(int newage) {
		age = newage;
	}
	//getters
	string getname() {
		return name;
	}
	int getid() {
		return id;
	}
	int getage() {
		return age;
	}
	//functions
	virtual void displayInfo() {
		cout << "Name: " <<getname() << endl << "Age: " << getage() << endl << "ID: " << getid() << endl;
	}
	virtual void performRole() {
		cout << getname() << " has no assigned university role" << endl;
	}
	virtual double calculatePayment() {
		return 0;
	}
	virtual void accessUniversitySystem() {
		cout << getname() << " has no access to the university system" << endl;
	}
	virtual void addMember() {
		cout << "Adding a new member is not implemented for this role." << endl;
	}
};

class student : public person {
	string major;
	double gpa;
	double completedCredits;
public:
	//constructor
	student(string newname, int newage, int newid, string newmajor, double newgpa, double newcompletedCredits) : person(newname, newage, newid) {
		setname(newname);
		setage(newage);
		setid(newid);
		major = newmajor;
		gpa = newgpa;
		completedCredits = newcompletedCredits;
	}

	string getmajor() {
		return major;
	}
	double getgpa() {
		return gpa;
	}
	double getcompletedCredits() {
		return completedCredits;
	}
	//functions
	void displayInfo() override {
		cout << "Name: " << getname() << endl << "Age: " << getage() << endl << "ID: " << getid() << endl;
		cout << "Role: Student" << endl << "Major: " << getmajor() << endl << "GPA: " << getgpa() << endl << "Completed Credits: " << getcompletedCredits() << endl;
	}
	void performRole() override {
		cout << getname() << " is attending classes and completing assignments." << endl;
	}
	double calculatePayment() override {
		return 0;
	}
	void accessUniversitySystem() override {
		cout << getname() << " has access to the university system as a student." << endl;
	}
	void addMember() override {
		ofstream file("university_members.csv", ios::app);
		if (!file.is_open()) {
			cout << "Error opening file" << endl;
		}
		else {
			file << "Student," << getname() << "," << getid() << "," << getage() << "," << getmajor() << "," << getgpa() << "," << getcompletedCredits() << endl;
		}
		cout << "New student member added to the university_members.csv file." << endl;
		displayInfo();

		file.close();
	}
};

class graduateStudent : public student {
	string researchTopic, supervisor;
	double monthlyStipend;
public:
	//constructor
	graduateStudent(string newname, int newage, int newid, string newmajor, double newgpa, double newcompletedCredits, string newresearchTopic, string newsupervisor, double newmonthlyStipend) : student(newname, newage, newid, newmajor, newgpa, newcompletedCredits) {
		researchTopic = newresearchTopic;
		supervisor = newsupervisor;
		monthlyStipend = newmonthlyStipend;
	}
	//getters
	string getresearchTopic() {
		return researchTopic;
	}
	string getsupervisor() {
		return supervisor;
	}
	double getmonthlyStipend() {
		return monthlyStipend;
	}
	//functions
	void displayInfo() override {
		cout << "Name: " << getname() << endl << "Age: " << getage() << endl << "ID: " << getid() << endl;
		cout << "Role: Graduate Student" << endl << "Major: " << getmajor() << endl << "GPA: " << getgpa() << endl << "Completed Credits: " << getcompletedCredits() << endl;
		cout << "Research Topic: " << getresearchTopic() << endl << "Supervisor: " << getsupervisor() << endl << "Monthly Stipend: " << getmonthlyStipend() << " EGP" << endl;
	}
	void performRole() override {
		cout << getname() << " is conducting research and meeting with their supervisor." << endl;
	}
	double calculatePayment() override {
		return getmonthlyStipend();
	}
	void accessUniversitySystem() override {
		cout << getname() << " has access to the university system as a graduate student." << endl;
	}
	void addMember() override {
		ofstream file("university_members.csv", ios::app);
		if (!file.is_open()) {
			cout << "Error opening file" << endl;
		}
		else {
			file << "GraduateStudent," << getname() << "," << getid() << "," << getage() << "," << getmajor() << "," << getgpa() << "," << getcompletedCredits() << "," << getresearchTopic() << "," << getsupervisor() << "," << getmonthlyStipend() << endl;
		}
		cout << "New graduate student member added to the university_members.csv file." << endl;
		displayInfo();
		file.close();
	}
};

class professor : public person {
	string department, coursesTaught;
	double salary;
public:
	//constructor
	professor(string newname, int newage, int newid, string newdepartment, double newsalary, string newcoursesTaught) : person(newname, newage, newid) {
		setname(newname);
		setage(newage);
		setid(newid);
		department = newdepartment;
		salary = newsalary;
		coursesTaught = newcoursesTaught;
	}
	//setters
	void setdepartment(string newdepartment) {
		department = newdepartment;
	}
	void setsalary(double newsalary) {
		salary = newsalary;
	}
	void setcoursesTaught(string newcoursesTaught) {
		coursesTaught = newcoursesTaught;
	}

	//getters
	string getdepartment() {
		return department;
	}
	double getsalary() {
		return salary;
	}
	string getcoursesTaught(){
		return coursesTaught;
	}

	//functions (override)
	void displayInfo() override {
		cout << "Name: " << getname() << endl << "Age: " << getage() << endl << "ID: " << getid() << endl;

		cout << "Role: Professor" << endl << "Department: " << getdepartment() << endl
			<< "Salary: " << getsalary()<<" EGP" << endl << "Courses Taught: " << getcoursesTaught() << endl;
	}

	void performRole() override {
		cout << "Dr. " << getname() << " is teaching " << getdepartment() << " courses." << endl;
	}
	double calculatePayment() override {
		return getsalary();
	}
	void accessUniversitySystem() override {
		cout << "Dr. " << getname() << " has access to the university system as a professor." << endl;
	}
	void addMember() override {
		ofstream file("university_members.csv", ios::app);
		if (!file.is_open()) {
			cout << "Error opening file" << endl;
		}
		else {
			file << "Professor," << getname() << "," << getid() << "," << getage() << "," << getdepartment() << "," << getsalary() << "," << getcoursesTaught() << endl;
		}
		cout << "New professor member added to the university_members.csv file." << endl;
		displayInfo();
		file.close();
	}
};

class staff : public person {
	string department, position;
	double salary;
public:
	//constructor
	staff(string newname, int newage, int newid, string newdepartment, string newposition, double newsalary) : person(newname, newage, newid) {
		setname(newname);
		setage(newage);
		setid(newid);
		department = newdepartment;
		position = newposition;
		salary = newsalary;
	}
	//setters
	void setdepartment(string newdepartment) {
		department = newdepartment;
	}
	void setposition(string newposition) {
		position = newposition;
	}
	void setsalary(double newsalary) {
		salary = newsalary;
	}

	//getters
	string getdepartment() {
		return department;
	}
	string getposition() {
		return position;
	}
	double getsalary() {
		return salary;
	}

	//functions (override)
	void displayInfo() override {
		cout << "Name: " << getname() << endl << "Age: " << getage() << endl << "ID: " << getid() << endl;

		cout << "Role: Staff" << endl << "Department: " << getdepartment() << endl
			<< "Position: " << getposition() << endl << "Salary: " << getsalary() << " EGP" << endl;
	}

	void performRole() override {
		cout << getname() << " is working in the " << getdepartment() << " department as a " << getposition() << "." << endl;
	}
	double calculatePayment() override {
		return getsalary();
	}
	void accessUniversitySystem() override {
		cout << getname() << " has access to the university system as a staff member." << endl;
	}
	void addMember() override {
		ofstream file("university_members.csv", ios::app);
		if (!file.is_open()) {
			cout << "Error opening file" << endl;
		}
		else {
			file << "Staff," << getname() << "," << getid() << "," << getage() << "," << getdepartment() << "," << getposition() << "," << getsalary() << endl;
		}
		cout << "New staff member added to the university_members.csv file." << endl;
		displayInfo();
		file.close();
	}
};

int main(){
	/*
	person p("Amen", 21, 900244027);	
	student s("Ahmed", 22, 900245031, "Data Science", 3.7, 65);
	professor d("Ibrahim", 52, 800245011, "Physics", 100000, "Physics 1 | Physics 2 | Physics Lab");
	staff st("Mohamed", 35, 700245012, "Administration", "HR Manager", 80000);
	
	instead of adding datas manually, I will read them from a file called "universityMembers.txt" 
	and store them in an array of person pointers. 
	Each line in the file will contain the data for one university member, 
	with the first word indicating the role (person, student, professor, or staff), 
	followed by the name, age, ID, and any additional information specific to that role.
	The program will then create the appropriate object for each line and store it in the array. 
	Finally, it will loop through the array and call the displayInfo() and performRole() functions for each member.
	*/

	ifstream file("university_members.csv");

	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return 1;
	}

	person* universityMembers[50];
	int memberCount = 0;

	string line;

	while (getline(file, line)) {

		stringstream ss(line);

		string role, name, id, age;
		string major, gpa, completedCredits;
		string researchTopic, supervisor, monthlyStipend;
		string department, salary, coursesTaught, position;

		// Reading every column
		getline(ss, role, ',');
		getline(ss, name, ',');
		getline(ss, id, ',');
		getline(ss, age, ',');

		getline(ss, major, ',');
		getline(ss, gpa, ',');
		getline(ss, completedCredits, ',');

		getline(ss, researchTopic, ',');
		getline(ss, supervisor, ',');
		getline(ss, monthlyStipend, ',');

		getline(ss, department, ',');
		getline(ss, salary, ',');
		getline(ss, coursesTaught, ',');
		getline(ss, position, ',');

		// Common conversions
		int intId = stoi(id);
		int intAge = stoi(age);


		if (role == "Student") {

			double doubleGpa = stod(gpa);
			double doubleCredits = stod(completedCredits);

			universityMembers[memberCount] =
				new student(
					name,
					intAge,
					intId,
					major,
					doubleGpa,
					doubleCredits
				);

			memberCount++;
		}

		else if (role == "GraduateStudent") {
			double doubleGpa = stod(gpa);
			double doubleCredits = stod(completedCredits);
			double doubleStipend = stod(monthlyStipend);
			universityMembers[memberCount] =
				new graduateStudent(
					name,
					intAge,
					intId,
					major,
					doubleGpa,
					doubleCredits,
					researchTopic,
					supervisor,
					doubleStipend
				);
			memberCount++;
		}

		else if (role == "Professor") {

			double doubleSalary = stod(salary);

			universityMembers[memberCount] =
				new professor(
					name,
					intAge,
					intId,
					department,
					doubleSalary,
					coursesTaught
				);

			memberCount++;
		}


		else if (role == "Staff") {

			double doubleSalary = stod(salary);

			universityMembers[memberCount] =
				new staff(
					name,
					intAge,
					intId,
					department,
					position,
					doubleSalary
				);

			memberCount++;
		}
	}

	//console Menu
	cout << "=========================================" << endl;
	cout << "University Management System" << endl;
	cout << "=========================================" << endl<<endl;
	cout << "1. Display all university members \n2. Display roles \n3. Display payroll "<<endl
		<<"4. Access university systems \n5. Search member by ID \n6. Add Member \n7. Exit" << endl<<endl;

	int choice;
	cout << "--> Enter your choice: ";
	cin >> choice;

	while (choice < 1 || choice > 7) {
		cout << "Invalid choice. Please enter a number between 1 and 7: ";
		cin >> choice;
	}

	if (choice == 1) {
		for (int i = 0; i < memberCount; i++) {
			universityMembers[i]->displayInfo();
			cout << "-----------------------------------------" << endl;
		}
	}
	else if (choice == 2) {
		for (int i = 0; i < memberCount; i++) {
			universityMembers[i]->performRole();
			cout << "-----------------------------------------" << endl;
		}
	}
	else if (choice == 3) {
		for (int i = 0; i < memberCount; i++) {
			cout << universityMembers[i]->getname() << " Payment: " << universityMembers[i]->calculatePayment() << " EGP" << endl;
			cout << "-----------------------------------------" << endl;
		}
	}
	else if (choice == 4) {
		for (int i = 0; i < memberCount; i++) {
			universityMembers[i]->accessUniversitySystem();
			cout << "-----------------------------------------" << endl;
		}
	}
	else if (choice == 5) {
		int searchId;
		cout << "Enter ID to search: ";
		cin >> searchId;
		bool found = false;
		for (int i = 0; i < memberCount; i++) {
			if (universityMembers[i]->getid() == searchId) {
				universityMembers[i]->displayInfo();
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Member with ID " << searchId << " not found." << endl;
		}
	}
	else if (choice == 6) {
		string newRole, newName, newMajor, newDepartment,
			newPosition, newCoursesTaught, newResearchTopic,
			newSupervisor;
		int newAge, newId;
		double newGpa, newCompletedCredits, newSalary,
			newMonthlyStipend;
		cout << "Enter role (Student/GraduateStudent/Professor/Staff): ";
		cin >> newRole;
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, newName);
		cout << "Enter age: ";
		cin >> newAge;
		cout << "Enter ID: ";
		cin >> newId;

		
		
		if (newRole == "Student") {
			cout << "Enter major: ";
			cin.ignore();
			getline(cin, newMajor);
			cout << "Enter GPA: ";
			cin >> newGpa;
			cout << "Enter completed credits: ";
			cin >> newCompletedCredits;
			universityMembers[memberCount] = new student(newName, newAge, newId, newMajor, newGpa, newCompletedCredits);
			universityMembers[memberCount]->addMember();
		}
		else if (newRole == "GraduateStudent") {
			cout << "Enter major: ";
			cin >> newMajor;
			cout << "Enter GPA: ";
			cin >> newGpa;
			cout << "Enter completed credits: ";
			cin >> newCompletedCredits;
			cout << "Enter research topic: ";
			cin.ignore();
			getline(cin, newResearchTopic);
			cout << "Enter supervisor: ";
			getline(cin, newSupervisor);
			cout << "Enter monthly stipend: ";
			cin >> newMonthlyStipend;
			universityMembers[memberCount] = new graduateStudent(newName, newAge, newId, newMajor, newGpa, newCompletedCredits, newResearchTopic, newSupervisor, newMonthlyStipend);
			universityMembers[memberCount]->addMember();
		}
		else if (newRole == "Professor") {
			cout << "Enter department: ";
			cin.ignore();
			getline(cin, newDepartment);
			cout << "Enter salary: ";
			cin >> newSalary;
			cout << "Enter courses taught (comma-separated): ";
			cin.ignore();
			getline(cin, newCoursesTaught);
			universityMembers[memberCount] = new professor(newName, newAge, newId, newDepartment, newSalary, newCoursesTaught);
			universityMembers[memberCount]->addMember();
		}
		else if (newRole == "Staff") {
			cout << "Enter department: ";
			cin.ignore();
			getline(cin, newDepartment);
			cout << "Enter position: ";
			getline(cin, newPosition);
			cout << "Enter salary: ";
			cin >> newSalary;
			universityMembers[memberCount] = new staff(newName, newAge, newId, newDepartment, newPosition, newSalary);
			universityMembers[memberCount]->addMember();
		}
		else {
			memberCount--;
			cout << "Invalid role entered. Member not added." << endl;
		}
		memberCount++;
	}
	else if (choice == 7) {
		cout << "Exiting the program." << endl;
	}
	
	
	file.close();
	return 0;
}

