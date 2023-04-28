#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>

using namespace std;

bool check_file(string name) {
	ifstream file(name.c_str());
	if (file.good() == true) {     /*if file is doesnt exist*/
		return true;
	} else {  // printf("file doesmt exist\n");
		return false;
	}
	file.close();
	return 0;
}

pair<string, int> get_data() {
    string student_name;
    int student_id;
    cout << "Student's full name: " << endl;
    getline(cin, student_name);

    cout << "Student's id number: " << endl;
    cin >> student_id;
    cin.ignore(); // add this line to consume the newline character

    return {student_name, student_id};
}
void retrieve_data(string file_name) {
	system("clear");	
    string student_name, student_id;
    bool check = check_file(file_name + ".txt");
    if (!check) {
        cout << "Student's data doesn't exist." << endl;
    } else {
        ifstream file(file_name + ".txt");
        getline(file, student_name);
        getline(file, student_id);
        file.close();

        cout << student_name << endl;
        cout << student_id << endl;
    }
}

void store_data(string student_name, int student_id) {
	string file_name = student_name + ".txt";
	bool check = check_file(file_name);
	if (!check) {
		ofstream file(file_name);
		file << "student's name: " << student_name << "\n";
		file << "student's id: " << student_id << "\n";
		file.close();
		cout << "done storing student's data";
	} else {
		string choice;
		cout << "student's file already exist, rewrite?";
		cin >> choice;
		if (choice == "yes") {
			ofstream file(file_name);
			file << "student's name: " << student_name << "\n";
			file << "student's id: " <<student_id << "\n";
			file.close();
		} else {
			cout << "closing";
		}
	}
}

void choice() {
	string choice;
	cout << "retrieve data or store data?: " << "\n";
	cin >> choice;
    cin.ignore(); // add this line to consume the newline character
	if (choice == "store") {	
		system("clear");
		auto datas = get_data();
		store_data(datas.first, datas.second);
	} else if (choice == "retrieve") {
		system("clear");
		auto datas = get_data();
		retrieve_data(datas.first);
	} else {
		printf("erm?\n");
	}
}

int main()
{
	system("clear");
	choice();
	return 0;
}