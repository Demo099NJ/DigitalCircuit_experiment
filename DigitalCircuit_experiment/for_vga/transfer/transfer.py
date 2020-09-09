#filename transfer.py
from PIL import Image

def compression(im_name, width, height):
	# openfile
	picture = Image.open('picture/' + im_name + '.jpg')
	# operating
	compress_im = picture.resize((width, height), Image.NEAREST)
	# compress_im = picture.resize((width, height), Image.BILINEAR)
	# compress_im = picture.resize((width, height), Image.BICUBIC)
	# compress_im = picture.resize((width, height), Image.ANTIALIAS)
	compress_im.save('picture/' + im_name + '_compressed.jpg')
	return im_name + '_compressed'

def crop_image(im_name, l, t, w, h):
	# openfile
	picture = Image.open('picture/' + im_name + '.jpg')
	# size
	left = l
	top = t
	width = w
	height = h
	# operating
	crop_im = picture.crop((left, top, left + width, top + height))
	crop_im.save('picture/' + im_name + '_crop.jpg')
	return im_name + '_crop'

def generate_mif(im_name, l, c, width, height):
	picture = Image.open('picture/' + im_name + '.jpg')
	pixel = picture.load()
	print picture.size
	#print picture.size[0]
	#print picture.size[1]
	
	# the final file
	doc = open('document/' + im_name + '.mif', "w")
	
	# the line and column of pixel
	line = l#0 #688
	column = c#0 #1280
	# for counting the amount of pixels
	count = 0
	# the pixels, departed into red, green and blue
	#vga_r = 0
	#vga_g = 0
	#vga_b = 0
	# using another array, for red, green and blue
	vga = [0, 0, 0]
	# the address of the pixels
	h_addr = 0
	v_addr = 0
	address = 0
	
	# the head of the file
	print >> doc, '--VGA Memory Map'
	print >> doc, '---Height: 480,Width: 640\n'
	print >> doc, 'WIDTH=12;'
	print >> doc, 'DEPTH=327680;'
	print >> doc, 'DATA_RADIX=HEX;'
	print >> doc, 'CONTENT'
	print >> doc, 'BEGIN'
	
	# write datas into the file
	for x in range(0, 640):
		for y in range(0, 480):
			# get red, green, and blue in one pixel
			for z in range(0, 3):
				vga[z] = ((pixel[column + x, line + y][z] & 0xf0) >> 4)
		
			# calculate the address of each pixels in .mif file
			address = (x << 9 | (~(0x7ffff << 9))) & (y | (0x7ffff << 9))
		
			# write into file
			print >> doc, '%x: %x%x%x;' % (address, vga[0], vga[1], vga[2])
			#print 'x = %x, y = %x' % (x, y)
			#print '%x: %x%x%x;' % (address, vga_r, vga_g, vga_b)
			
			# increase count
			count = count + 1
		
		# another loop
		for y in range(480, 512):
			# set to white
			address = (x << 9 | (~(0x7ffff << 9))) & (y | (0x7ffff << 9))
			# write into file
			print >> doc, '%x: 000;' % address
			count = count + 1

	# the final sign
	print >> doc, 'END;'
	# the amount
	print count
	# close the file
	doc.close()
	return im_name + '.mif'

def main():
	#picture_name = 'cornfield'
	#picture_name = 'whale'
	#picture_name = 'milu_deer'
	#picture_name = 'horse'
	#picture_name = 'deer'
	picture_name = 'yak'

	new_file_name = compression(picture_name, 640, 480)
	generate_mif(new_file_name, 0, 0, 640, 480)

main()
#picture.show()
#Image.close()
#print("{:x} {:x}" .format(pixel[0, 0]))
#pixel[x,y] = value
