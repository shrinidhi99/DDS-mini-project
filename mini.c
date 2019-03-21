/*
	Name: Shrinidhi Anil Varna(17CO145)
	      Vybhav Pai(17CO252)
	      Rakshith S(17CO233)
*/

#include<stdio.h>
#include<stdlib.h>
char wave[10000000];						//character array to store ON and OFF signals during the process
int k=0;
int t[6][6];                                                    //two dimensional array used to store time difference between setting transitions (heating and cooling)
	
int nylon(int state)				
{
	printf("Nylon:\n");
	int i,cur = 1;
	if(t[state][cur] >= 0)
	{
		for(i=1;i<=t[state][cur];i++,k++)
		wave[k] = '_';		
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		
		return cur;
	}
	if(t[state][cur] < 0)
	{
		for(i=t[state][cur];i<=0;i++,k++)
		wave[k] = '_';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
}
int seq(int state)
{
	printf("Sequential fabric:\n");
	int i,cur = 2;
	if(t[state][cur] >= 0)
	{
		for(i=1;i<=t[state][cur];i++,k++)
		wave[k] = '-';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
	if(t[state][cur] < 0)
	{
		for(i=t[state][cur];i<=0;i++,k++)
		wave[k] = '_';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
}
int wool(int state)
{
	printf("Wool:\n");
	int i,cur = 3;
	if(t[state][cur] >= 0)
	{
		for(i=1;i<=t[state][cur];i++,k++)
		wave[k] = '-';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
	if(t[state][cur] < 0)
	{
		for(i=t[state][cur];i<=0;i++,k++)
		wave[k] = '_';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
}
int linen(int state)
{
	printf("Linen:\n");
	int i,cur = 4;
	if(t[state][cur] >= 0)
	{
		for(i=1;i<=t[state][cur];i++,k++)
		wave[k] = '-';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
	if(t[state][cur] < 0)
	{
		for(i=t[state][cur];i<=0;i++,k++)
		wave[k] = '_';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
}

int cotton(int state)
{
	printf("Cotton\n");
	int i,cur = 5;						// current state in which it is at the moment
	if(t[state][cur] >= 0)
	{
		for(i=1;i<=t[state][cur];i++,k++)
		wave[k] = '-';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
	if(t[state][cur] < 0)
	{
		for(i=t[state][cur];i<=0;i++,k++)
		wave[k] = '_';
		for(i=1;i<=15;i++,k++)
		wave[k] = '_';
		return cur;
	}
}
void display()
{
	printf("Waveform:-\n");
	printf("%s",wave);
	printf("\n\n\n\n");
}

void main()
{
	int ch,i,prev;							//below are the calculated time intervals for different setting transitions in the form t[previous_setting][current_setting]
	t[0][0] = 0 , t[1][1] = 6,t[2][2] = 6,t[3][3] = 6,
	t[4][4] = 6, t[5][5] = 6, t[1][2] = 12,t[1][3] = 15,
	t[1][4] = 57,t[1][5] = 76,t[2][3] = 10,t[2][4] = 51,
	t[2][5] = 70,t[3][4] = 47,t[3][5] = 67,t[4][5] = 25,
	t[2][1] = 0,t[3][1] = -10,t[4][1] = -113,t[5][1] = -162,
	t[3][2] = 2,t[4][2] = -99,t[5][2] = -147,t[4][3] = -87,
	t[5][3] = -137,t[5][4] = -33; 
	printf("\n\t\t\t\tState: ON\n\n");
	printf("Options:\n1.Nylon\n2.Sequential fabrics\n3.Wool\n4.Linen\n5.Cotton\n6.Display waveform\n7.OFF\n");
	scanf("%d",&ch);							// ch is choice of cloth material 
	i=0;
	for(;;)
	{		
		if(i==0)
		prev = ch;
		if(i++!=0)
		{
			printf("\nShift setting to :\n");		
			scanf("%d",&ch);
		}
		switch(ch)
		{
			case 1:
			{
				prev = nylon(prev);				// here we are storing the previous state of the iron box so that we can feed this information to the next state
				printf("Your current state is: 1.Nylon\n");
				break;
			}
			case 2:
			{
				prev = seq(prev);
				printf("Your current state is: 2.Sequential fabrics\n");
				break;
			}
			case 3:
			{
				prev = wool(prev);
				printf("Your current state is: 3.Wool\n");
				break;
			}
			case 4:
			{
				prev = linen(prev);
				printf("Your current state is: 4.Linen\n");
				break;
			}
			case 5:
			{
				prev = cotton(prev);
				printf("Your current state is: 5.Cotton\n");	
				break;
			}
			case 6:
			{
				display();						//to display the waveform generated during the process at any posedge of a wave signal
				break;
			}
			case 7:
			{
				printf("\nState: OFF\n");
				display();
				exit(0);
				break;
			}
		}
	}
}


