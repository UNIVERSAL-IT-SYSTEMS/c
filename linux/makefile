demo:
	@gcc iotool.c -c -static
	@gcc graphic.c -c -static
	@ar -r libdemo1.a iotool.o graphic.o
	@gcc main.c -ldemo1 -L. -omain1
	@gcc iotool.c -c -fpic
	@gcc graphic.c -c -fpic
	@gcc iotool.o graphic.o -shared -olibdemo2.so
	@export LD_LIBRARY_PATH=.
	@gcc main.c -ldemo2 -omain2 -L.
	@rm -f iotool.o graphic.o


