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
	cout << "���� �������(1000): ";
	cin >> n;

	while (n > 1000){
	cout << "���������� �������� �����, �������� ���� �������: ";
	cin >> n;
	}

	for (int i = 0; i < n; i++){
		
		cout << "������� �����: ";
		zak[i].number = i +1;
		cout << zak[i].number;
		cout << endl;

		cout << "��� �� ��������� (1;33): ";
		cin >> zak[i].type;
		while (zak[i].type <= 0 || zak[i].type > 33){
		cout << "���������� ������� ��� �� ���������(1;33): ";
		cin >> zak[i].type;
		}

		cout << "��� �� �������: ";
		cin >> zak[i].name; 

		cout << "���� ����������� �������:";
		cin >> zak[i].broi;

		cout << "�����������, ����� �������:";
		zak[i].pod = (0.2*zak[i].type+2);
		cout << zak[i].pod;
		cout << endl;

		cout << "���� �� ���� ����: ";
		zak[i].price = 0.3+(33-zak[i].type)*0.02;
		cout << zak[i].price;
		cout << endl;

		zak[i].cena_vs= zak[i].price * zak[i].broi;
		cout << "���� ���� �� ������: "<< zak[i].cena_vs << endl;
		cout << endl;
	}

	cout << "******* �������� ����� *******" << endl;

	for (int i = 0; i < n; i++){

			cout << zak[i].number << " , " << zak[i].name << " , " << zak[i].type << " , " << zak[i].broi << " , " << zak[i].pod << " , " << zak[i].price << " ��. " << zak[i].cena_vs << " ��." << endl;

	}


	cout << "******* ��������� ����� *******" << endl;
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
	
		cout << zak[i].number << " , " <<  zak[i].name << " , " << zak[i].type << " , "<< zak[i].broi << " , " << zak[i].pod << " , " << zak[i].price << " ��. " << zak[i].cena_vs << " ��." << endl;

	}

	cout << "******* ������� ����������� *******" << endl;
	double person_pod;
	cout << "�������� ������� �����������:";
	cin >> person_pod;
	double sum = 0;
	for (int i = 0; i < n; i++){
		
		if ((person_pod) == (zak[i].pod)){
			sum += zak[i].cena_vs;
			cout << zak[i].number << " , " <<  zak[i].name << " , " << zak[i].type << " , "<< zak[i].broi << " , " << zak[i].pod << " , " << zak[i].price << " ��. " << zak[i].cena_vs << " ��. " <<endl;
			
		} 
	}
	if (sum == 0){
		cout << "����� ��� ������� �� � ����������� ����." << endl;
	} else {
		cout << "���� ���� �� ���������� � ��������� �� ��� �������: "<< sum << " .��"<< endl;
	}
	system ("pause");
	return 0;
}