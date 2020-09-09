#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;

int main() {
	string in_file("primary_data.txt"), out_file("frequence_data.mif");
	ifstream fin(in_file);	assert(fin.is_open());
	ofstream fout(out_file);	assert(fout.is_open());

	//head of the .mif file
	fout << "---FREQUENCE MEMORY MAP" << endl;
	fout << "--HEIGHT: 24, WIDTH: 16" << endl << endl;
	fout << "WIDTH=16;" <<endl;
	fout << "DEPTH=24;" << endl;
	fout << "DATA_RADIX=HEX;" << endl;
	fout << "CONTENT" << endl;
	fout << "BEGIN" << endl;

	//handle the data
	string number, increment, symbol, result, annotation;
	while(!fin.eof()) {
		fin >> number >> increment >> symbol >> result >> annotation;
		//cout << number << " " << increment << " ";
		//cout << symbol << " " << result << " " << annotation << endl;
		fout << number[3] << number[4] << ": ";
		fout << result[4] << result[5] << result[6] << result[7];
		fout << ";" << endl;
	}

	//the tail
	fout << "END;" << endl;

	fin.close();	fout.close();
	return 0;
}
