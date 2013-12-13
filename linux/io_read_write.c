//ssize_t write(int fd, void *buf, size_t size);
// ssize>0实际写入的数据数
// ssize=-1写入错误
//ssize_t read(int fd, void *buf, size_t size);
// ssize>0:实际读入数据数
// ssize=0碰到文件结束符合EOF(ctrl+d)
// ssize=-1读取错误
main()
{
	char buf[100]={0};
	int s = write(0,"hello\n", 6);
	buf[0]=s+48;
	write(0,buf,1);
	read(0,"hello",5);
	puts(buf);
}