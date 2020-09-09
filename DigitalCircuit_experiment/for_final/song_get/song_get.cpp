#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;

int look_up_table(int number) {
	int result(0);
	switch(number) {
		case 0: result = 00; break;
		case 1: result = 01; break;
		case 2: result = 9; break;
		case 3: result = 17; break;
		case 4: result = 21; break;
		case 5: result = 29; break;
		case 6: result = 37; break;
		case 7: result = 45; break;
		case 8: result = 02; break;
		case 9: result = 10; break;
		case 10: result = 18; break;
		case 11: result = 22; break;
		case 12: result = 30; break;
		case 13: result = 38; break;
		case 14: result = 46; break;
		case 15: result = 03; break;
		case 16: result = 11; break;
		case 17: result = 19; break;
		case 18: result = 23; break;
		case 19: result = 31; break;
		case 20: result = 39; break;
		case 21: result = 47; break;
		//
		case 22: result = 8; break;
		case 23: result = 12; break;
		case 24: result = 13; break;
		case 25: result = 14; break;
		case 26: result = 15; break;
		case 27: result = 16; break;
		//
		case 28: result = 20; break;
		//
		case 29: result = 24; break;
		case 30: result = 25; break;
		case 31: result = 26; break;
		case 32: result = 27; break;
		case 33: result = 28; break;
		//
		case 34: result = 32; break;
		case 35: result = 33; break;
		case 36: result = 34; break;
		case 37: result = 35; break;
		case 38: result = 36; break;
		//
		case 39: result = 40; break;
		case 40: result = 41; break;
		case 41: result = 42; break;
		case 42: result = 43; break;
		case 43: result = 44; break;
		//
		case 44: result = 4; break;
		case 45: result = 5; break;
		case 46: result = 6; break;
		case 47: result = 7; break;
	}
	return result;
}

int map_table(int number) {
	int result(0);
	switch(number) {
		case 0x0: result = 0xb2; break;
		case 0x1: result = 0x165; break;
		case 0x2: result = 0x2ca; break;
		case 0x3: result = 0x594; break;
		case 0x4: result = 0xbd; break;
		case 0x5: result = 0x17a; break;
		case 0x6: result = 0x2f4; break;
		case 0x7: result = 0x5e9; break;
		case 0x8: result = 0xc8; break;
		case 0x9: result = 0x190; break;
		case 0xa: result = 0x321; break;
		case 0xb: result = 0x643; break;
		case 0xc: result = 0xd4; break;
		case 0xd: result = 0x1a8; break;
		case 0xe: result = 0x351; break;
		case 0xf: result = 0x6a3; break;
		case 0x10: result = 0xe1; break;
		case 0x11: result = 0x1c2; break;
		case 0x12: result = 0x384; break;
		case 0x13: result = 0x708; break;
		case 0x14: result = 0xee; break;
		case 0x15: result = 0x1dc; break;
		case 0x16: result = 0x3b9; break;
		case 0x17: result = 0x773; break;
		case 0x18: result = 0xfc; break;
		case 0x19: result = 0x1f9; break;
		case 0x1a: result = 0x3f2; break;
		case 0x1b: result = 0x7e4; break;
		case 0x1c: result = 0x10b; break;
		case 0x1d: result = 0x217; break;
		case 0x1e: result = 0x42e; break;
		case 0x1f: result = 0x85c; break;
		case 0x20: result = 0x11b; break;
		case 0x21: result = 0x237; break;
		case 0x22: result = 0x46e; break;
		case 0x23: result = 0x8dc; break;
		case 0x24: result = 0x12c; break;
		case 0x25: result = 0x258; break;
		case 0x26: result = 0x4b1; break;
		case 0x27: result = 0x962; break;
		case 0x28: result = 0x13e; break;
		case 0x29: result = 0x27c; break;
		case 0x2a: result = 0x4f8; break;
		case 0x2b: result = 0x9f1; break;
		case 0x2c: result = 0x151; break;
		case 0x2d: result = 0x2a2; break;
		case 0x2e: result = 0x544; break;
		case 0x2f: result = 0xa89; break;
	}
	return result;
}

int song_transfer(const string &infile, const string &outfile) {
	ifstream fin(infile);	assert(fin.is_open());
	ofstream fout(outfile);	assert(fout.is_open());

	//the header
	fout << "---SONG MEMORY MAP" << endl;
	fout << "--HEIGHT = , WIDTH = 8" << endl << endl;
	fout << "WIDTH=8;" << endl;
	fout << "DEPTH=;" << endl;
	fout << "DATA_RADIX=HEX;" << endl;
	fout << "CONTENT" << endl;
	fout << "BEGIN" << endl;

	//the data
	int count(0);
	int score(0), number(0);
	fin >> score;
	//cout << score << endl;
	while(!fin.eof()) {
		number = look_up_table(score);
		//fout << hex << count << ": " << hex << map_table(number) << ";" << endl;
		fout << hex << count << ": " << hex << number << ";" << endl;
		++count;
		fin >> score;
		//cout << score << endl;
	}
	int result(1);
	while(result < count) {
		result *= 2;
	}
	for(int i = count; i < result; ++i) {
		fout << hex << i << ": " << "00;" << endl;
	}

	//the tail
	fout << "END;" << endl;
	cout << "In file \"" << infile << "\", count = " << count << ", result = " << result << endl;
	fin.close();	fout.close();
	return 0;
}

int main(int argc, char *argv[]) {
	string in_file, out_file;
	for(int i = 1; i < argc; ++i) {
		string temp = argv[i];
		in_file = temp + ".txt";
		out_file = temp + "_mem.mif";
		song_transfer(in_file, out_file);
	}
	return 0;
}
