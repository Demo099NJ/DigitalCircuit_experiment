#include<iostream>
#include<fstream>
#include<string>
#include<assert.h>
using namespace std;

int main() {
	string filename_in("previous");
	ifstream fin(filename_in + ".txt");
	assert(fin.is_open());
	string filename_out("changed");
	ofstream fout(filename_out + ".mif");

	//#the head of the file
	fout << "--CHAR POINT Memory Map" << endl;
	fout << "---EACH CHAR: 9 * 16, TOTAL CHAR: 256" << endl << endl;
	fout << "WIDTH=12;" << endl;
	fout << "DEPTH=4096;" << endl;
	fout << "DATA_RADIX=HEX;" << endl;
	fout << "CONTENT" << endl;
	fout << "BEGIN" << endl;

	//data
	string data;
	for(int i = 0; i < 4096; ++i) {
		fin >> data;
		fout << hex << i << ": " << data << ";" << endl;
	}

	//the end
	fout << "END;" << endl;
	fin.close();
	fout.close();
	return 0;
}
