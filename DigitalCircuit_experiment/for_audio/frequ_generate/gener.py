#filename: gener.py

def transfer(x):
	result = (int)(x * 65536) / 48000
	return result + 1

def main():
	x = 0
	in_file_name = 'primary.txt'
	in_file = open(in_file_name, 'r')
	#amount = 12
	name_number = [0, 0, 0, 0]
	for i in range(0, 4):
		name_number[i] = int(input());
	for i in range(0, 12):
		#x = input('frequence = ')
		result = transfer(x)
		print '%x' % result
	in_file.close()
	return

main()
