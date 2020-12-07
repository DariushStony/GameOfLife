#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
using namespace std;

char world[100][100];

void Draw(int h ,int w)
{	

	system("cls");
	
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
			if(world[i][j])
				cout<<"*";
			else
				cout<<" ";
				
		cout<<endl;
	}
}

void Evolution(int h,int w)
{
	char new_World[h][w];
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			new_World[i][j]=world[i][j];
	
	for(int i=1;i<h-1;i++)
	{
		for(int j=1;j<w-1;j++)
		{
			int live=0;
			for(int r=i-1;r<i+2;r++)
				for(int q=j-1;q<j+2;q++)
					if(world[(r+h)%h][(q+w)%w])
						live++;
			
			if(world[i][j])	live--;			
						
						
			//new_World[j][i] = (live==3 or (live==2 and world[j][i]));
						
			if(live > 3)
				new_World[i][j] = 0;
			else if((live == 2 and world[i][j]) or live == 3)
				new_World[i][j] = 1;
			else if(live < 2)
				new_World[i][j] = 0;
		}
	}

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			world[i][j] = new_World[i][j];
	}
		
}

int main()
{
	int w=30;
	int h=30;
	
	srand(unsigned (time(NULL)));
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			world[i][j] = rand() < RAND_MAX / 10 ? 1 : 0;
		
	while(1)	
	{
		Draw(h,w);
		Evolution(h,w);
		sleep(1);	
	}
	
	return 0;
}
