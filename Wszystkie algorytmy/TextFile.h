#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class TextFile {
private:
	ifstream reader;
	ofstream saver;
public:
	void ReadFromTextFile(string fileName, vector<int>& arr) {
		reader.open(fileName);
		string text;
		vector<string> combineText;
		if (reader.is_open()) {
			while (getline(reader,text)) {
				combineText.push_back(text);
			}
			reader.close();
		}
		else {
			cout << "Nie mo¿na otworzyæ pliku " << fileName << endl;
		}
		//zamina wielu linii na jedna dluga
		text = "";
		for (int i = 0, y = combineText.size(); i <y ; i++)
		{
			text += combineText[i];
			text += " ";
		}
		combineText.clear();
		stringstream ss(text);
		int var;
		while (ss.good()) {
			ss >> var;
			arr.push_back(var);
		}
		arr.pop_back();
	}
	void SaveToTextFile(string text) {
		cout << "Funkcja jeszcze nie zaimplementowana";
	}

	static void Example() {
		vector<int> myArray;
		TextFile textFile;
		textFile.ReadFromTextFile("Text.txt", myArray);
		for (int i = 0,size=myArray.size(); i <size; i++)
		{
			cout << myArray[i] << " ";
		}
	}
};