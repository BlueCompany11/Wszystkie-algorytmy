#pragma once
#include<iostream>
#include<ctime>
#include<chrono>
#include<iomanip>
#include<ratio>
using namespace std;

class MierzenieCzasu {
private:
	chrono::high_resolution_clock::time_point _poczatek;
	chrono::high_resolution_clock::time_point _koniec;

public:
	void UstawStart() {
		_poczatek = chrono::high_resolution_clock::now();
	}

	void UstawKoniec() {
		_koniec = chrono::high_resolution_clock::now();
	}
	
	void WypiszPrzedzialCzasowy(double *wartoscPrzedzialuCzasowego=nullptr) {
		if (_poczatek == _koniec) {
			cout << "Przedzial czasowy, albo jest zerowy, albo zmienne _poczatek i _koniec nie zostaly zadeklarowane"<<endl;
			return;
		}
		chrono::duration<double> przedzialCzasowy = chrono::duration_cast<chrono::duration<double>>(_koniec - _poczatek);
		cout << "Czas to: " << przedzialCzasowy.count() << " sek." << endl;
		if(wartoscPrzedzialuCzasowego!=nullptr)
			*wartoscPrzedzialuCzasowego = przedzialCzasowy.count();
	}

};