curses:Courses_CUI.c
	gcc Courses_CUI.c -ocurses.e -lcursesw
.PHONY:clean#为目标
OBJ=iotool_s.o graphic_s.o
OBJ2=iotool.o graphic.o
demo:main1.e main2.e
iotool_s.o:iotool.c
	@gcc iotool.c -c -static -oiotool_s.o
graphic_s.o:graphic.c
	@gcc graphic.c -c -static -ographic_s.o
libdemo1.a:$(OBJ)
	@ar -r libdemo1.a $(OBJ)
main1.e:main.c libdemo1.a
	@gcc main.c -ldemo1 -L. -omain1.e
iotool.o:iotool.c
	@gcc iotool.c -c -fpic
graphic.o:graphic.c
	@gcc graphic.c -c -fpic
libdemo2.so:$(OBJ2)
	@gcc $(OBJ2) -shared -olibdemo2.so
main2.e:main.c libdemo2.so
	@gcc main.c -ldemo2 -omain2.e -L.
clean:
	rm -f *.o *.so *.a *.e a.out
	@echo "${PATH}"
