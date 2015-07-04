#include<iostream>
#include<locale>
#include<windows.h>

using namespace std;

struct furn{
	int number;
	char name[33];
	int type;
	int broi;
	double pod;
	double price;
	double cena_vs;
};


int main(){
	furn zak[1000];

	setlocale (LC_ALL, "bulgarian");

	int n;
	cout << "Брой закуски(1000): ";
	cin >> n;

	while (n > 1000){
	cout << "Некоректно въведени данни, въведете брой закуски: ";
	cin >> n;
	}

	for (int i = 0; i < n; i++){
		
		cout << "Закуска номер: ";
		zak[i].number = i +1;
		cout << zak[i].number;
		cout << endl;

		cout << "Тип на закуската (1;33): ";
		cin >> zak[i].type;
		while (zak[i].type <= 0 || zak[i].type > 33){
		cout << "Некоректно зададен тип на закуската(1;33): ";
		cin >> zak[i].type;
		}

		cout << "Име на закуска: ";
		cin >> zak[i].name; 

		cout << "Брой произведени закуски:";
		cin >> zak[i].broi;

		cout << "Подобрители, които съдържа:";
		zak[i].pod = (0.2*zak[i].type+2);
		cout << zak[i].pod;
		cout << endl;

		cout << "Цена за един брой: ";
		zak[i].price = 0.3+(33-zak[i].type)*0.02;
		cout << zak[i].price;
		cout << endl;

		zak[i].cena_vs= zak[i].price * zak[i].broi;
		cout << "Цена общо за всички: "<< zak[i].cena_vs << endl;
		cout << endl;
	}

	cout << "******* Въведени данни *******" << endl;

	for (int i = 0; i < n; i++){

			cout << zak[i].number << " , " << zak[i].name << " , " << zak[i].type << " , " << zak[i].broi << " , " << zak[i].pod << " , " << zak[i].price << " лв. " << zak[i].cena_vs << " лв." << endl;

	}


	cout << "******* Сортирани данни *******" << endl;
	furn swap;
	for (int i = 0; i < n -1; i++){
		for (int j = 0; j < n - i -1; j++){
		
			if(zak[j].cena_vs < zak[j+1].cena_vs){
			swap = zak[j];
			zak[j] = zak[j+1];
			zak[j+1] = swap;
			}

		}
	
	}
	for (int i = 0; i < n; i++){
	
		cout << zak[i].number << " , " <<  zak[i].name << " , " << zak[i].type << " , "<< zak[i].broi << " , " << zak[i].pod << " , " << zak[i].price << " лв. " << zak[i].cena_vs << " лв." << endl;

	}

	cout << "******* Процент подобрители *******" << endl;
	double person_pod;
	cout << "Въведете процент подобрители:";
	cin >> person_pod;
	double sum = 0;
	for (int i = 0; i < n; i++){
		
		if ((person_pod) == (zak[i].pod)){
			sum += zak[i].cena_vs;
			cout << zak[i].number << " , " <<  zak[i].name << " , " << zak[i].type << " , "<< zak[i].broi << " , " << zak[i].pod << " , " << zak[i].price << " лв. " << zak[i].cena_vs << " лв. " <<endl;
			
		} 
	}
	if (sum == 0){
		cout << "Такъв вид закуска не е произвеждан днес." << endl;
	} else {
		cout << "Обща цена на артиколите с въведения от Вас процент: "<< sum << " .лв"<< endl;
	}
	system ("pause");
	return 0;
}