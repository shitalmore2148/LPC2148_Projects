#include<lpc214x.h>
#define led1 (1<<0)
#define led2 (1<<1)
#define sw (1<<16)
#define button ((IO1PIN &(sw))==0)
int main()
{
	int result,count=1;
	IO0DIR=0xf;
	IO1DIR=0x0;
	while(1)
	{
		if(button)
		{
			count++;
			result=count;
			if(result==1)
			{
				IO0SET=led1;
				IO0CLR=led2;
			}
			else if(result==2)
			{
				IO0SET=led2;
				IO0CLR=led1;
				count++;
			}
		}
		if(!button)
		{
			
			IO0CLR=led1;
			IO0CLR=led2;
		}
	}
}