#include "information_manage.h"
#include <stdio.h>

int get_input()
{
	int temp;
	printf("input your command:\n");
	scanf("%d",&temp);
	return temp;
}

int event_process(int the_message)
{
	int flag = MAINTAIN;
	switch(the_message)
	{
		case SEARCH:
			search(the_message);
			break;
		case CREATE:
			create();
			break;
		case READ:
			read();
			break;
		case UPDATE:
			update(the_message);
			break;
		case DELETE:
			delete(the_message);
			break;
		default:
			flag = QUIT;
			break;
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	int message=1;
	print_manual();
	
	// message process
	while(message != QUIT)
	{
		message = get_input();
		event_process(message);
	}
	printf("You are quited\n");
	return 0;
}