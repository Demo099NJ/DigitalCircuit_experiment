#include<iostream>
#include<fstream>
#include<string>
#include<assert.h>
using namespace std;

bool map(const string &infile, const string &outfile) {
	ifstream fin(infile);	assert(fin.is_open());
	ofstream fout(outfile);	assert(fout.is_open());

	//head of the file
	fout << "---KEY CODE MEMORY MAP" << endl;
	fout << "--HEIGHT = 78, WIDTH = 8" << endl << endl;
	fout << "WIDTH=8;" << endl;
	fout << "DEPTH=78;" << endl;
	fout << "DATA_RADIX=HEX;" << endl;
	fout << "CONTENT" << endl;
	fout << "BEGIN" << endl;

	//processing data
	char ch('\0');
	int previ(0), number(0), value(0);
	string operation, symbol;
	//int count(0);
	fin >> ch;
	//cout << ch;
	while(!fin.eof()) {
		for(int i = 0; i < 2; ++i) {
			fin >> ch;
			//cout << ch;
		}
		fin >> hex >> number >> ch >> operation >> symbol;
		//cout << hex << number << " " << ch << " " << operation << " " << symbol << " ";
		for(int i = 0; i < 3; ++i) {
			fin >> ch;
			//cout << ch;
		}
		fin >> hex >> value >> ch;
		//cout << hex << value << " " << ch << endl;
		fin >> ch;
		//cout << ch;
		//++count;
		int temp(0x10), multi(0xc);
		for(int i = 0; i < 6; ++i) {
			if(value - temp >= 0x0 && value - temp <= 0x9) { value -= multi; }
			temp += 0x10; multi += 0xc;
		}
		//for previ
		for(; previ < number; ++previ) {
			fout << hex << previ << ": " << "00;" << endl;
		}
		previ += 0x1;
		fout << hex << number << ": " << hex << value << ";" << endl;
	}
	for(int i = number + 0x1; i < 0x80; ++i) {
		fout << hex << i << ": " << "00;" << endl;
	}

	//the end
	fout << "END;";

	fin.close();	fout.close();
	return true;
}

int main() {
	string in_file("map.txt"), out_file("out_map.mif");
	map(in_file, out_file);
	return 0;
}
