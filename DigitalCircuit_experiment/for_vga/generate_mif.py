#filename: generate_mif.py

def generate(filename, line, column):
	doc = open(filename + '.mif', 'w')

	#the head of the file
	print >> doc, '--VGA Memory Map'
	print >> doc, '---Height = 30, Width = 70\n'
	print >> doc, 'WIDTH=8'
	print >> doc, 'DEPTH=%d' % (line * column)
	print >> doc, 'DATA_RADIX=HEX'
	print >> doc, 'CONTENT'
	print >> doc, 'BEGIN'

	address = 0
	#the real 
	for i in range(0, line * column):
		print >> doc, '%x: 00;' % address
		address += 1
	
	#the end of the file
	print >> doc, 'END;'
	doc.close()
	print 'the amount is %d' % address


def main():
	line = 30
	column = 70
	filename = 'displayer'
	generate(filename, line, column)

main()
