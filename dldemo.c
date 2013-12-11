#include <dlfcn.h>

main()
{
	void *handle=dlopen("./libdemo2.so",RTLD_LAZY);
	void(*fun)(int)=dlsym(handle,"diamond");
	fun(5);
}