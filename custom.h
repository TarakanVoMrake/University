#include <iostream>  //бібліотека для організації введення-виведення
#include <fstream>   //бібліотека надає інтерфейс для читання/запису даних з/в файл. 
#include <Windows.h> //бібліотека 
#include <string>    //бібліотека дає можливість використовувати рядки 
#include <string.h>  //бібліотека для роботи з рядками
#include <vector>    //бібліотека для створення векторів 
#include <sstream>   //бібліотека для маніпуляцій потоками рядків 
#include <stdlib.h>  //бібліотека для функцій rand та srand
#include <time.h>	 //бібліотека для операцій з часом
#include <cstdlib>   //бібліотека для функції exit
#include <algorithm>   //бібліотека для функції exit

using namespace std;

namespace Namespace {
	struct Math {
		int id;
		string name;
		string studied;
		string history;
		string formulas;
		string scientists;
		Math(int id1, string name1, string studied1, string history1, string formulas1, string scientists1) {
			id = id1;
			name = name1;
			studied = studied1;
			history = history1;
			formulas = formulas1;
			scientists = scientists1;
		}
	};

	void error(string str);
	void nameOutput(vector <Math> data);

	int menu() {
		system("cls");
		int choice;
		cout << "Введіть число для дії:" << endl
			<< "1 - Виведення даних" << endl
			<< "2 - Редагування даних" << endl
			<< "3 - Пошук даних" << endl
			<< "4 - Зберегти" << endl
			<< "5 - Вийти" << endl;
		cin >> choice;
		return choice;
	}
	int menuOutput() {
		system("cls");
		int choice;
		cout << "Введіть число для дії:" << endl
			<< "1 - Виведення всіх даних" << endl
			<< "2 - Часткове виведення даних" << endl
			<< "3 - Назад" << endl;
		cin >> choice;
		return choice;
	}
	int menuEditing() {
		system("cls");
		int choice;
		cout << "Введіть число для дії:" << endl
			<< "1 - Ввення даних" << endl
			<< "2 - Редагування даних" << endl
			<< "3 - Видалення даних" << endl
			<< "4 - Назад" << endl;
		cin >> choice;
		return choice;
	}
	int menuSearch(vector <Math> data) {
		system("cls");
		cout << "Розділи математики:" << endl;
		nameOutput(data);
		int choice;
		cout << endl << "Введіть число для дії:" << endl
			<< "1 - Шукати за ID" << endl
			<< "2 - Шукати за назвою" << endl
			<< "3 - Сортувати" << endl
			<< "4 - Фільтрувати" << endl
			<< "5 - Назад" << endl;
		cin >> choice;
		return choice;
	}
	int menuSort() {
		system("cls");
		int choice;
		cout << "Введіть число для дії:" << endl
			<< "1 - Сортувати за ID" << endl
			<< "2 - Сортувати за назвою" << endl
			<< "3 - Назад" << endl;
		cin >> choice;
		return choice;
	}
	int menuFiltr() {
		system("cls");
		int choice;
		cout << "Введіть число для дії:" << endl
			<< "1 - Фільтрувати за наявністю історії" << endl
			<< "2 - Фільтрувати за наявністю навчальних закладах" << endl
			<< "3 - Фільтрувати за наявністю формул" << endl
			<< "4 - Фільтрувати за наявністю вчених" << endl
			<< "5 - Назад" << endl;
		cin >> choice;
		return choice;
	}
	
	void nameOutput(vector <Math> data) {
		for (int i = 0; i < data.size(); i++) {
			cout << data[i].id << " - " << data[i].name << endl;
		}
	}
	void fullOutput(vector <Math> data) {
		system("cls");
		for (int i = 0; i < data.size(); i++) {
			cout << data[i].id << ") "
				<< data[i].name << endl
				<< data[i].studied << endl
				<< data[i].history << endl
				<< data[i].formulas << endl
				<< data[i].scientists << endl;
		}
		system("pause");
	}
	void partialOutput(vector <Math> data) {
		system("cls");
		int choice, index = -1;
		do {
			bool correct = false;
			system("cls");
			cout << "Введіть ID розділа, який треба вивести:\n";
			nameOutput(data);
			cin >> choice;
			system("cls");
			for (int i = 0; i < data.size(); i++) {
				if (data[i].id == choice) {
					index = i;
					correct = true;
					break;
				}
			}
			if (!correct) {
				error("Такого ID немає");
			}
		} while (index == -1);
		system("cls");
		cout << data[index].id << ") "
			<< data[index].name << endl
			<< data[index].studied << endl
			<< data[index].history << endl
			<< data[index].formulas << endl
			<< data[index].scientists << endl;
		system("pause");
	}

	vector<Math> input(vector <Math> data) {
		system("cls");
		int quantity;
		cout << "Введіть кількість розділів, які хочете внести до бази даних: ";
		cin >> quantity;
		cin.get();
		for (int i = 0; i < quantity; i++)
		{
			string id, name, studied, history, formulas, scientists;
			bool correct = true;
			do {
				cout << "Введіть ID розділу: ";
				getline(cin, id);
				correct = true;
				for (int i = 0; i < data.size(); i++) {
					if (data[i].id == stoi(id)) {
						correct = false;
						break;
					}
				}
				if (!correct) {
					error("Такий ID вже існує");
				}
			} while (!correct);
			cout << "Введіть назву розділу математики: ";
			getline(cin, name);
			cout << "Введіть де навчається: ";
			getline(cin, studied);
			cout << "Введіть історію: ";
			getline(cin, history);
			cout << "Введіть головні формули: ";
			getline(cin, formulas);
			cout << "Введіть найвидатніших вчених: ";
			getline(cin, scientists);
			cout << endl;
			Math* AaA = new Math(stoi(id), name, studied, history, formulas, scientists);
			data.push_back(*AaA);
		}
		system("cls");
		cout << "Дані добавлено" << endl;
		system("pause");
		return data;
	}
	vector<Math> edit(vector <Math> data) {
		int choice, index = -1;
		do {
			bool correct = false;
			system("cls");
			cout << "Введіть ID розділу, який треба змінити:\n";
			nameOutput(data);
			cin >> choice;
			system("cls");
			for (int i = 0; i < data.size(); i++) {
				if (data[i].id == choice) {
					index = i;
					correct = true;
					break;
				}
			}
			if (!correct) {
				error("Такого ID немає");
			}
		} while (index == -1);
		cout << data[index].id << ") "
			<< data[index].name << endl
			<< data[index].studied << endl
			<< data[index].history << endl
			<< data[index].formulas << endl
			<< data[index].scientists << endl;

		int id;
		string name, studied, history, formulas, scientists;
		cin.get();
		id = data[index].id;
		cout << "Введіть нову назву розділу математики: ";
		getline(cin, name);
		cout << "Введіть де навчається: ";
		getline(cin, studied);
		cout << "Введіть історію: ";
		getline(cin, history);
		cout << "Введіть головні формули: ";
		getline(cin, formulas);
		cout << "Введіть найвидатніших вчених: ";
		getline(cin, scientists);
		cout << endl;

		cout << data[index].id << ") "
			<< data[index].name << endl
			<< data[index].studied << endl
			<< data[index].history << endl
			<< data[index].formulas << endl
			<< data[index].scientists << endl;

		Math* AaA = new Math(id, name, studied, history, formulas, scientists);
		data[index] = *AaA;
		system("cls");
		cout << "Дані змінено" << endl;
		system("pause");
		return data;
	}
	vector<Math> delete1(vector <Math> data) {
		system("cls");
		int choice, index = -1;
		do {
			bool correct = false;
			system("cls");
			cout << "Введіть ID розділу, який треба видалити:\n";
			nameOutput(data);
			cin >> choice;
			system("cls");
			for (int i = 0; i < data.size(); i++) {
				if (data[i].id == choice) {
					index = i;
					correct = true;
					break;
				}
			}
			if (!correct) {
				error("Такого ID немає");
			}
		} while (index == -1);
		auto iter = data.cbegin() + index;
		system("cls");
		data.erase(iter);
		system("cls");
		cout << "Дані видалено" << endl;
		system("pause");
		return data;
	}

	void searchByID(vector <Math> data) {
		partialOutput(data);
	}
	void searchByName(vector <Math> data) {
		system("cls");
		string choice;
		int index = -1;
		cin.get();
		do {
			bool correct = false;
			system("cls");
			cout << "Введіть назву розділа, який треба вивести:\n";
			nameOutput(data);
			getline(cin, choice);
			system("cls");
			for (int i = 0; i < data.size(); i++) {
				if (data[i].name == choice) {
					index = i;
					correct = true;
					break;
				}
			}
			if (!correct) {
				error("Такої назви немає");
			}
		} while (index == -1);
		system("cls");
		cout << data[index].id << ") "
			<< data[index].name << endl
			<< data[index].studied << endl
			<< data[index].history << endl
			<< data[index].formulas << endl
			<< data[index].scientists << endl;
		system("pause");
	}
	vector <Math> sortByID(vector <Math> data) {
		sort(data.begin(), data.end(), [](Math& el1, Math& el2) {return el1.id < el2.id; });
		return data;
	}
	vector <Math> sortByName(vector <Math> data) {
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.size() - 1; j++) {
				if (strcmp(data[j].name.c_str(), data[j + 1].name.c_str()) > 0) {
					swap(data[j], data[j + 1]);
				}
			}
		}
		return data;
	}
	vector <Math> filtrByHistory(vector <Math> data) {
		vector <Math> data1;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].history.length() > 0) {
				data1.push_back(data[i]);
			}
		}
		return data1;
	}
	vector <Math> filtrByEE(vector <Math> data) {
		vector <Math> data1;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].studied.length() > 0) {
				data1.push_back(data[i]);
			}
		}
		return data1;
	}
	vector <Math> filtrByFormulas(vector <Math> data) {
		vector <Math> data1;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].formulas.length() > 0) {
				data1.push_back(data[i]);
			}
		}
		return data1;
	}
	vector <Math> filtrByScientists(vector <Math> data) {
		vector <Math> data1;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].scientists.length() > 0) {
				data1.push_back(data[i]);
			}
		}
		return data1;
	}

	vector<string> split(string n, char I) {
		vector<string> bI;
		string token;
		istringstream tokenstream(n);
		while (getline(tokenstream, token, I)){
			bI.push_back(token);
		}
		return bI;
	}
	vector<Math> read() {
		ifstream fin("AreasOfMath.txt");
		vector<Math> data;
		if (fin.is_open()) {
			string currentStr;
			while (getline(fin, currentStr)) {
				vector<string> currentData = split(currentStr, '|');
				Math* bI = new Math(stoi(currentData[0]), currentData[1], currentData[2], currentData[3], currentData[4], currentData[5]);
				data.push_back(*bI);
			}
			cout << "Дані зчитано з файлу AreasOfMath.txt" << endl;
			system("pause");
		}
		else {
			error("Файлу AreasOfMath.txt ще не існує. Дані не зчитано");
		}
		fin.close();
		return data;
	}
	void save(vector <Math> data) {
		system("cls");
		ofstream fout("AreasOfMath.txt");
		for (int i = 0; i < data.size(); i++) {
			fout << data[i].id << "|"
				<< data[i].name << "|"
				<< data[i].studied << "|"
				<< data[i].history << "|"
				<< data[i].formulas << "|"
				<< data[i].scientists << endl;
		}
		fout.close();
		cout << "Дані збережено\n";
		system("pause");
	}

	void checker(vector <Math> data) {
		bool correct;
		int choice, index = -1;
		do {
			correct = true;
			system("cls");
			cout << "Хочете ввести дані?" << endl
				<< "1 - Так" << endl
				<< "2 - Ні" << endl;
			cin >> choice;
			system("cls");
			if (choice == 1) input(data);
			else if (choice == 2);
			else correct = false;
			if (!correct) {
				error("Ви обрали неправильну дію");
			}
		} while (!correct);
	}
	bool end() {
		system("cls");
		cout << "Закінчення роботи...";
		srand(time(NULL));
		int time = 999 + rand() % 1999;
		Sleep(time);
		system("cls");
		return false;
	}
	void error(string str) {
		system("cls");
		cout << str << endl;
		system("pause");
	}
}