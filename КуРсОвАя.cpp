#include "custom.h" 

using namespace std;
using namespace Namespace;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector <Math> data;
	data = read();

	bool work = true;
	while (work) {
		switch (menu()) {
			case 1:
			{
				bool work1 = true;
				while (work1) {
					work1 = false;
					switch (menuOutput()) {
					case 1:
						if (data.size() != 0) fullOutput(data);
						else {
							error("Дані відсутні"); 
							checker(data);
						}
						break;
					case 2:
						if (data.size() != 0) partialOutput(data);
						else {
							error("Дані відсутні");
							checker(data);
						}
						break;
					case 3:
						break;
					default:
						work1 = true;
						error("Ви обрали неправильну дію");
					}
				}
				break;
			}
			case 2:
			{
				bool work1 = true;
				while (work1) {
					work1 = false;
					switch (menuEditing()) {
					case 1:
						data = input(data);
						break;
					case 2:
						if (data.size() != 0) data = edit(data);
						else {
							error("Дані відсутні");
							checker(data);
						}
						break;
					case 3:
						if (data.size() != 0) data = delete1(data);
						else {
							error("Дані відсутні");
							checker(data);
						}
						break;
					case 4:
						break;
					default:
						error("Ви обрали неправильну дію");
					}
				}
				break;
			}
			case 3:
			{
				if (data.size() != 0) {
					vector <Math> data1 = data;
					bool work1 = true;
					while (work1) {
						switch (menuSearch(data1)) {
						case 1:
						{
							work1 = false;
							searchByID(data1);
							break;
						}
						case 2:
						{
							work1 = false;
							searchByName(data1);
							break;
						}
						case 3:
						{
							bool work2 = true;
							while (work2) {
								work2 = false;
								switch (menuSort()) {
								case 1:
									data1 = sortByID(data1);
									break;
								case 2:
									data1 = sortByName(data1);
									break;
								case 3:
									break;
								default:
									work2 = true;
									error("Ви обрали неправильну дію");
								}
							}
							break;
						}
						case 4:
						{
							bool work2 = true;
							while (work2) {
								work2 = false;
								switch (menuFiltr()) {
								case 1:
									data1 = filtrByHistory(data1);
									break;
								case 2:
									data1 = filtrByEE(data1);
									break;
								case 3:
									data1 = filtrByFormulas(data1);
									break;
								case 4:
									data1 = filtrByScientists(data1);
									break;
								case 5:
									break;
								default:
									work2 = true;
									error("Ви обрали неправильну дію");
								}
							}
							break;
						}
						case 5:
						{
							work1 = false;
							break;
						}
						default:
						{
							work1 = true;
							error("Ви обрали неправильну дію");
						}
						}
					}
					break;
				}
				else {
					error("Дані відсутні");
					checker(data);
				}
				
			}
			case 4:
			{
				save(data);
				break;
			}
			case 5:
			{
				work = end();
				break;
			}
			default:
			{
				error("Ви обрали неправильну дію");
			}
		}
	}
	return 0;
}
