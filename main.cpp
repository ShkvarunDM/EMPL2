#include <iostream>
#include <Windows.h>
#include "emp3.cpp"
#include <conio.h>


using namespace std;

string get_str(){
    string s;
    getline(cin,s);
    if (cin.fail() || string::npos != s.find_first_of("0123456789")){
        cin.clear();
        cout << "INPUT ERROR! Enter a new string!"<< endl;
        getline(cin,s);
    }
    return s;
}


void Create_Director(director& dir){

     int salary;

     fflush(stdin);
     cout<<"Enter lastname Director\n";
     dir.set_ln(get_str());
     cout << "\n";

     cout<<"Enter firstname Director\n";
     dir.set_fn(get_str());
     cout << "\n";

     cout<<"Enter middlename Director\n";
     dir.set_mn(get_str());
     cout << "\n";

     cout<<"Enter salary Director\n";
     cin>>salary;
     dir.set_salary(salary);
     cout << "\n";

     cout<<"Director created\n";

     system("pause");

 }

 void Create_Secretary(secretary& sec){

     int salary;

     fflush(stdin);
     cout<<"Enter lastname Secretary\n";
     sec.set_ln(get_str());
     cout << "\n";

     cout<<"Enter firstname Secretary\n";
     sec.set_fn(get_str());
     cout << "\n";

     cout<<"Enter middlename Secretary\n";
     sec.set_mn(get_str());
     cout << "\n";

     cout<<"Enter salary Secretary\n";
     cin>>salary;
     sec.set_salary(salary);
     cout << "\n";

     cout<<"Secretary created\n";

     system("pause");

 }

void Create_Employee(director& dir){

    int salary;
    employee em;

    fflush(stdin);
	cout << "Enter lastname Employee\n";
	em.set_ln(get_str());
	cout <<"\n";

	cout << "Enter firstname Employee\n";
	em.set_fn(get_str());
	cout <<"\n";

	cout << "Enter middlename Employee\n";
	em.set_mn(get_str());
	cout <<"\n";

    cout<<"Enter salary Employee\n";
    cin>>salary;
    em.set_salary(salary);
    cout <<"\n";

    cout<<"Employee created\n";

	dir.add_empl(em);
	cout<<"Employee added to the list\n";

	system("pause");

 }

void Create_Programmer(director dir){

    int salary;
    programmer pr;

    fflush(stdin);
	cout << "Enter lastname Programmer\n";
	pr.set_ln(get_str());
	cout <<"\n";

	cout << "Enter firstname Programmer\n";
	pr.set_fn(get_str());
	cout <<"\n";

	cout << "Enter middlename Programmer\n";
	pr.set_mn(get_str());
	cout <<"\n";

	cout<<"Enter level Programmer\n";
    pr.set_level(get_str());
    cout <<"\n";

    cout<<"Enter technology Programmer\n";
    cout<<"q - end enter\n";
    string s = get_str();
    while(s!="q"){
        pr.add_technology(s);
        cout<<"technology added to the list\n";
        s = get_str();
    }

    cout<<"Enter salary Programmer\n";
    cin>>salary;
    pr.set_salary(salary);
    cout <<"\n";

    cout<<"Programmer created\n";

	dir.add_prog(pr);
	cout<<"Programmer added to the list\n";

	system("pause");
}


void Create_Driver(director& dir){

    int salary;
    driver dr;

    fflush(stdin);
	cout << "Enter lastname Driver\n";
	dr.set_ln(get_str());
	cout <<"\n";

	cout << "Enter firstname Driver\n";
	dr.set_fn(get_str());
	cout <<"\n";

	cout << "Enter middlename Driver\n";
	dr.set_mn(get_str());
	cout <<"\n";

	cout<<"Enter categories Driver\n";
    cout<<"q - end enter\n";

    string s = get_str();
    while(s!="q"){
        dr.add_categories(s);
        cout<<"categories added to the list\n";
        s = get_str();
    }
    cout <<"\n";

    cout<<"Enter transport Driver\n";
    cout<<"q - end enter\n";
    s = get_str();
    while(s!="q"){
        dr.add_transport(s);
        cout<<"transport added to the list\n";
        s = get_str();
    }

    cout<<"Enter salary Driver\n";
    cin>>salary;
    dr.set_salary(salary);
    cout <<"\n";

    cout<<"Driver created\n";

	dir.add_driver(dr);
	cout<<"Driver added to the list\n";

	system("pause");

}

void Show_Director(director& dir){

    cout<<"Director's data\n";

    cout<<"\nLastname: "<< dir.get_ln();
    cout<<"\nFirstname: "<< dir.get_fn();
    cout<<"\nMiddlename: "<< dir.get_mn();
    cout<<"\nSalary: "<< dir.get_salary();
    cout <<"\n";

    system("pause");

}

void Edit_Employee(director& dir){

    int number;

    fflush(stdin);

    cout << "Enter number employee\n";
    cin >> number;

    if (number < 0 || number > dir.get_emp_vec().size()){
        cout << "Error number! Enter new number employee\n";
        cin.clear();
        cin >> number;
    }

    cout << "Enter lastname employee\n";
    string lastname = get_str();

    cout << "Enter firstname employee\n";
    string firstname = get_str();

    cout << "Enter middlename employee\n";
    string middlename = get_str();

    int salary;
    cin >> salary;

    dir.get_emp_vec()[number].set_ln(lastname);
    dir.get_emp_vec()[number].set_fn(firstname);
    dir.get_emp_vec()[number].set_mn(middlename);
    dir.get_emp_vec()[number].set_salary(salary);

    cout << "Employee edit\n";

}


void Delete_Employee(director& dir){
    int index;

    fflush(stdin);
	cout << "Enter number emloyee\n";
	cin >> index;

	dir.del_empl(index);
	cout<<"Employee removed from the list\n";
    cout <<"\nНажмите enter для продолжения...\n"; _getch();

}



char getMainMenu()
{
	char ch;
	cout << "1. Создать директора." << endl;
	cout << "2. Меню директора." << endl;
	cout << "3. Создать секретаря." << endl;
	cout << "4. вывести сотрудников." << endl;
	cout << "E. Выход." << endl;
	cout << "> ";
	cin >> ch;
	return toupper(ch);
}



void showMenuDirector(director& dir)
{
	if (dir.get_ln() == "") {
		cout << "Директор еще не создан!" << endl;
		cout << endl << "Нажмите enter для продолжения..." << endl;_getch();
		return;
	}
	char ch;

	bool flg = true;

	while (flg) {
		system("cls");
		cout << "1. Hire an employee" << endl;
		cout << "2. Dismiss an employee" << endl;
		cout << "3. Hire an programmer " << endl;
		cout << "4. Hire an driver" << endl;
		cout << "5. Edit employee's data " << endl;
		cout << "6. Show director's data" << endl;
		cout << "E. Exit to the main menu" << endl;
		cout << "> ";
		cin >> ch;

		ch = toupper(ch);

		switch (ch) {
		case '1': Create_Employee(dir); break;
		case '2': Delete_Employee(dir);break;
		case '3': Create_Programmer(dir); break;
		case '4': Create_Driver(dir); break;
		case '5': Edit_Employee(dir); break;
		case '6': Show_Director(dir); break;
		case 'E': flg = false; break;
		default: cout << endl << "There is no such command\n"; _getch(); break;
		}

	}
	return;

}


int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	director dir;
	secretary sec;

	char ch;

	while (true) {
		system("cls");
		ch = getMainMenu();

		switch (ch) {
		case '1': Create_Director(dir); break;
		case '2': showMenuDirector(dir); break;
		case '3': Create_Secretary(sec); break;
		case '4': sec.show_employee(dir); break;
		//case '4': showMenuSecretary(sec, dir); cout << endl << "Нажмите enter для продолжения..." << endl; _getch(); break;
		case 'E': exit(0); break;
		default: cout << endl << "Такой команды нет!Нажмите enter для продолжения..." << endl; _getch(); break;
		}
	}

    return 0;
}




