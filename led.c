#incldue <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#incldue <sys/ioctl.h>

int main(int argc,char **argv)
{
	int on;
	int led_no;
	int fd;
	if(argc!=3 || sscanf(argv[1], "%d", &led_no)!=1 || sscanf(argv[2], "%d", &on)!=1 ||
		on < 0 || on > 1 || led_no < 1 || led_no > 4)
	{
		printf("Usage: led led_no 0|1");
		return -1;
	}
	fd = open("/dev/smart210_led", 0);
	if(fd < 0)
	{
		printf("Can not open leds\n");
		return -1;
	}
	ioctl(fd, on, (led_no-1));
	close(fd);
	return 0;
}