#include <graphics.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

void TicTacToe();


int snakegame();           
int endfunc(int e, int a);  //Function for snake game


void connect4();


int RandomMaker();
int Compare(int p, int c);
void RockPaperScissors();
int RPSmain();

int main2048();
void Start();
void Game2048();
void Display();
void Down();
void Up();
void Left();
void Right();
int Temp_counter();
void Random_creator();

int Matrix[4 + 1][4 + 1] = {0};
int grid_ref_x1[4] = {438, 601, 764, 927}; // grid reference along x axis
int grid_ref_y1[4] = {138, 301, 464, 627}; // grid reference along y axis
int last = 0, over = 0;

int main(){
	int h = GetSystemMetrics(SM_CYSCREEN);
	int w = GetSystemMetrics(SM_CXSCREEN);
	int page=0;
	int x1=270,x2=710,y1=280,y2=380;
	initwindow(w,h,"",-3,10);
	while(1){
		//To reduce  flickering
		setactivepage(page);
    	setvisualpage(1-page);
    	setcolor(WHITE);
    	setlinestyle(0,1,4);
    	cleardevice();
    	readimagefile("arcade.jpg",-3,-3,w,h);
    	setbkcolor(0);
    	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 75);
		outtextxy(w/2-200,100,"ARCADE");
		setlinestyle(0,1,5);
		setcolor(RED);
		rectangle(w/2-104,h/2-104,w/2+104,h/2+104);
		static int p1=w/2-100,p2=w/2+100,q1=h/2-100,q2=h/2+100;
		readimagefile("Snakegame.jpg",p1,q1,p2,q2);
		readimagefile("2048.jpg",p1+250,q1,p2+250,q2);
		readimagefile("Connect4.jpg",p1+500,q1,p2+500,q2);
		readimagefile("rps.jpg",p1+750,q1,p2+750,q2);
		readimagefile("TTT.jpg",p1+1000,q1,p2+1000,q2);
		if(GetAsyncKeyState(VK_RIGHT) && p1!=w/2-100-250*4)
		{
			while(GetAsyncKeyState(VK_RIGHT) );
			p1=p1-250;
			p2=p2-250;
			
		}
		if(GetAsyncKeyState(VK_LEFT) && p1!= w/2-100)
		{
			while(GetAsyncKeyState(VK_LEFT));
			p1=p1+250;
			p2=p2+250;
			
		}
		if(GetAsyncKeyState(VK_ESCAPE)){
			break;
		}
		if(GetAsyncKeyState(VK_RETURN) && p1==w/2-100)
		{
			while(GetAsyncKeyState(VK_RETURN));
			snakegame();
		}
		if(GetAsyncKeyState(VK_RETURN) && p1==w/2-350)
		{
			while(GetAsyncKeyState(VK_RETURN));
			main2048();
		}
		if(GetAsyncKeyState(VK_RETURN) && p1==w/2-600)
		{
			while(GetAsyncKeyState(VK_RETURN));
			connect4();
		}
		if(GetAsyncKeyState(VK_RETURN) && p1==w/2-850)
		{
			while(GetAsyncKeyState(VK_RETURN));
			RPSmain();
		}
		if(GetAsyncKeyState(VK_RETURN) && p1==w/2-1100)
		{
			while(GetAsyncKeyState(VK_RETURN));
			TicTacToe();
		}
			
		delay(30);
		page=1-page;
	}     
	
	getch();
    closegraph();
    return 0;
}

void TicTacToe()
{
	int h = GetSystemMetrics(SM_CYSCREEN);
	int w = GetSystemMetrics(SM_CXSCREEN);
	int page=0;
	int x1=433,y1=132,x2=650,y2=349;
	int player=1;
	int grid[3][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
	int grid_ref_x[3]={505,722,949};
	int grid_ref_y[3]={175,392,610};
	int grid_point[2]={0,0};
	int squares_filled=0,win=0;
	settextstyle(8,0,10);
	setlinestyle(0,1,8);
	while(1)
	{
		//To reduce flickering
		setactivepage(page);
    	setvisualpage(1-page);
    	cleardevice();
    	readimagefile("tttbg.jpg",-3,-3,w,h);
    	
    	//boxes
    	setcolor(BLACK);
    	setlinestyle(0,1,8);
		line(650,132,650,783);
		line(867,132,867,783);
		line(433,349,1084,349);
		line(433,566,1084,566);
		setcolor(15);
		
		//Input
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(grid[i][j]!=-1)
				{
					if(grid[i][j]==1)
					{
						
						outtextxy(grid_ref_x[i],grid_ref_y[j],"X");
					}
					else
					{
						outtextxy(grid_ref_x[i],grid_ref_y[j],"O");
					}
				}
			}
		}
		//Selected square and its movement
		setcolor(DARKGRAY);
		setlinestyle(1,1,8);
    	rectangle(x1,y1,x2,y2);
    	if(win==0)
    	{
	    	if(GetAsyncKeyState(VK_UP) && y1!=132)
			{
				grid_point[1]-=1;
	    		y1=y1-217;
	    		y2=y2-217;
			}
			if(GetAsyncKeyState(VK_DOWN) && y1!=566)
			{
				grid_point[1]+=1;
	    		y1=y1+217;
	    		y2=y2+217;
			}
			if(GetAsyncKeyState(VK_RIGHT) && x2!=1084)
			{
				grid_point[0]+=1;
	    		x1=x1+217;
	    		x2=x2+217;
			}
			if(GetAsyncKeyState(VK_LEFT) && x1!=433)
			{
				grid_point[0]-=1;
	    		x1=x1-217;
	    		x2=x2-217;
			}
		}
		//Marking squares and winning and losing conditions
		if(GetAsyncKeyState(VK_RETURN))
		{
			if(grid[grid_point[0]][grid_point[1]]== -1){
				while(GetAsyncKeyState(VK_RETURN));
				squares_filled++;
				grid[grid_point[0]][grid_point[1]]=player;
				player=1-player;
			}		
		}
		if(grid[0][0]==1 && grid[0][1]==1 && grid[0][2]==1 )
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		if(grid[1][0]==1 && grid[1][1]==1 && grid[1][2]==1)
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		if(grid[2][0]==1 && grid[2][1]==1 && grid[2][2]==1)
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		if(grid[0][0]==1 && grid[1][0]==1 && grid[2][0]==1)
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		if(grid[0][1]==1 && grid[1][1]==1 && grid[2][1]==1)
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		if(grid[0][2]==1 && grid[1][2]==1 && grid[2][2]==1)
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		if(grid[0][0]==1 && grid[1][1]==1 && grid[2][2]==1)
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		if(grid[0][2]==1 && grid[1][1]==1 && grid[2][0]==1)
		{
			outtextxy(333,0,"Player 1 Win");
			win++;
		}
		
		if(grid[0][0]==0 && grid[0][1]==0 && grid[0][2]==0 )
		{
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(grid[1][0]==0 && grid[1][1]==0 && grid[1][2]==0){
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(grid[2][0]==0 && grid[2][1]==0 && grid[2][2]==0)
		{
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(grid[0][0]==0 && grid[1][0]==0 && grid[2][0]==0)
		{
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(grid[0][1]==0 && grid[1][1]==0 && grid[2][1]==0)
		{
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(grid[0][2]==0 && grid[1][2]==0 && grid[2][2]==0)
		{
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(grid[0][0]==0 && grid[1][1]==0 && grid[2][2]==0)
		{
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(grid[0][2]==0 && grid[1][1]==0 && grid[2][0]==0)
		{
			outtextxy(333,0,"Player 2 Win");
			win++;
		}
		if(squares_filled==9 && win==0)
		{
			outtextxy(333,0,"Its a Draw");
		}
		//closing the window
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			delay(75);
			break;
		}
		//To reduce flickering
		delay(100);
		page=1-page;
	}
}

int endfunc(int e, int a)
{
   fflush(stdin);
	initwindow(GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN),"SCOREwindow");
	char sarr[20];
    if (e < 10)
    {
        e = e - 2;
    }
    if (e <= 9)
        {
            sarr[0] = char(48 + e);
            sarr[1] = '\0';
        }
        else if (10 <= e < 100)
        {
            sarr[0] = char(48 + (e / 10));
            sarr[1] = char(48 + e % 10);
            sarr[2] = '\0';
        }
        else
        {
            sarr[0] = char(48 + e / 100);
            sarr[1] = char(48 + (e % 100) / 10);
            sarr[2] = char(48 + ((e % 100) % 10));
            sarr[3] = '\0';
        }
    system("cls");
    readimagefile("gameover.jpeg",350,50,1100,400);
    if (a == 0)
    {
    	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    	setcolor(RED);
        outtextxy(400,400,"You died outside the boundary!!!\n");
    }
    else if (a == 1)
    {
    	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    	setcolor(RED);
        outtextxy(400,400,"You died into yourself!!!");
    }
    else
    {
    	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    	setcolor(GREEN);
    	outtextxy(500,400,"YOU WIN!!!    :)");	
	}
    
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    setcolor(WHITE);
    outtextxy(400,500,"Your score is : ");
    outtextxy(780,500,sarr);
    setcolor(LIGHTGREEN);
    outtextxy(300,600,"If you want to submit your score");
    outtextxy(300,650,"then press 'y' ");
    //record score
    int y=getch();
    if(y=='y')
    {
	    FILE *info;
	    int c ,i ;
	    char cha;
	    char arr[20]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ;
	    info=fopen("record.txt","a+");
	    fflush(stdin);
	    setcolor(WHITE);
	    cleardevice();
	    readimagefile("SNAKEE.jpeg", 0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
	    outtextxy(150,0,"Enter your name (Press '=' if you are done)\n");
	    int lol=0;
	    for(int i =0 ;i<20;i++)
	    {
	    	lol=getch();
			if(lol=='a')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"a");
	    		arr[i]='a';
			}
			else if(lol=='b')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"b");
	    		arr[i]='b';
			}else if(lol=='c')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"c");
	    		arr[i]='c';
			}else if(lol=='d')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"d");
	    		arr[i]='d';
			}else if(lol=='e')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"e");
	    		arr[i]='e';
			}else if(lol=='f')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"f");
	    		arr[i]='f';
			}else if(lol=='g')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"g");
	    		arr[i]='g';
			}else if(lol=='h')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"h");
	    		arr[i]='h';
			}else if(lol=='i')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"i");
	    		arr[i]='i';
			}else if(lol=='j')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"j");
	    		arr[i]='j';
			}else if(lol=='k')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"k");
	    		arr[i]='k';
			}else if(lol=='l')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"l");
	    		arr[i]='l';
			}else if(lol=='m')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"m");
	    		arr[i]='m';
			}else if(lol=='n')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"n");
	    		arr[i]='n';
			}else if(lol=='o')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"o");
	    		arr[i]='o';
			}else if(lol=='p')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"p");
	    		arr[i]='p';
			}else if(lol=='q')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"q");
	    		arr[i]='q';
			}else if(lol=='r')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"r");
	    		arr[i]='r';
			}else if(lol=='s')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"s");
	    		arr[i]='s';
			}else if(lol=='t')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"t");
	    		arr[i]='t';
			}else if(lol=='u')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"u");
	    		arr[i]='u';
			}else if(lol=='v')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"v");
	    		arr[i]='v';
			}else if(lol=='w')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"w");
	    		arr[i]='w';
			}else if(lol=='x')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"x");
	    		arr[i]='x';
			}else if(lol=='y')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"y");
	    		arr[i]='y';
			}else if(lol=='z')
	    	{
	    		settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50,"z");
	    		arr[i]='z';
			}
			else if(lol==' ')
			{
				settextstyle(8, HORIZ_DIR, 2);
	    		outtextxy(150+i*13,50," ");
	    		arr[i]=' ';
			}
			else if(lol=='=')
	    	{
	    		arr[i]='\0';
	    		break;
			}
		}
	     fflush(stdin);
	    	fprintf(info,"Player Name :%s\n",arr);
	    
	    time_t mytime;
    	mytime = time(NULL);
	    fflush(stdin);
	    fprintf(info,"Played Date:%s",ctime(&mytime));
		fprintf(info,"Score:%d\n",e);
			    
		for(i=0; i<=50; i++)
		fprintf(info,"%c",'_');
		fprintf(info,"\n");
	   //data
	   settextstyle(8, HORIZ_DIR, 4);
		outtextxy(150,120,"Wanna see past records press 'a' and open terminal afterwards\n");
		cha=getch();
			int denote;
	    char ch;
	    if(cha=='a'){
	    info=fopen("record.txt","r");
	    while(denote!=EOF){
	        denote=fscanf(info,"%c",&ch);
	        printf("%c" ,ch);
	    }
    }
    fclose(info);
    getch();
	    fclose(info);
	    return 0;
		}
	else
	{
		main();
		return 0;
	}
	
}

int snakegame()
{
 // direction
    int rx = 200, ry = 200, x[200], y[200], d;
    char arr[10];
    for (int i = 0; i < 200; i++)
    {
        x[i] = 0;
        y[i] = 0;
    }

    // Food eaten
    int f = 1;
    int chk = 100 ;

    // directions
    int dir = 1;
    int w=GetSystemMetrics(SM_CXSCREEN);
    int h=GetSystemMetrics(SM_CYSCREEN);
    initwindow(w, h, "", -3, -3);
    x[0] = 200, y[0] = 200;
    d = 1;
    int length = 1;
    int page = 0;
    for (;;)
    {
        setactivepage(page);
        setvisualpage(1 - page);
        if (f <= 9)
        {
            arr[0] = char(46 + f);
            arr[1] = '\0';
        }
        else if (10 <= f < 100)
        {
            arr[0] = char(48 + (f / 10));
            arr[1] = char(48 + f % 10);
            arr[2] = '\0';
        }
        else
        {
            arr[0] = char(48 + f / 100);
            arr[1] = char(48 + (f % 100) / 10);
            arr[2] = char(48 + ((f % 100) % 10));
            arr[3] = '\0';
        }
        setfillstyle(SOLID_FILL, BLACK);
        bar(0, 0, 1500, 820);
        setfillstyle(SOLID_FILL, YELLOW);
        // BORDER- start
        bar(0, 0, 1500, 20);
        bar(0, 0, 20, 820);
        bar(0, 830, 1500, 820);
        bar(1490, 10, 1500, 820);
        bar(1000, 10, 1005, 820);
        bar(1000, 410, 1490, 415);
        // BORDER- END
        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 5);
        setcolor(CYAN);
        outtextxy(1118, 30, "SCORE");
        outtextxy(1118, 440, "STATUS");
        outtextxy(1118, 600, "Instructions");
        setcolor(GREEN);
        outtextxy(1118, 500, "PLAYING");
        setcolor(15);
        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
        outtextxy(1068, 650, "Use arrow keys to play");
        outtextxy(1038, 700, "Press 'spacebar' to pause");
        setcolor(MAGENTA);
        outtextxy(1118, 300, "Get score : 100");
        outtextxy(1118, 350, "To WIN this game");
        setcolor(15);
        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
        outtextxy(1218, 90, arr);
        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
        outtextxy(1170 , 790 , "Game by Lakshya Arora");
        // food taken?
        if (x[0] == rx && y[0] == ry)
        {
            length += 1;
            f = f + 1;
            setfillstyle(1, 0);
            bar(rx, ry, rx + 20, ry + 20);

            // make food
            do
            {
                rx = (1 + rand() % 980);
                ry = (1 + rand() % 790);
            } while (getpixel(rx, ry) != 0 && rx > 20 && ry > 20);

            rx = rx / 20;
            rx = rx * 20;
            ry = ry / 20;
            ry = ry * 20;
            if(rx==0)
            {
            	rx=rx+20;
			}
			if(ry==0)
			{
				ry=ry+20;
			}
            setfillstyle(SOLID_FILL, RED);
        }
        setfillstyle(SOLID_FILL, RED);
        bar(rx, ry, rx + 20, ry + 20);
        label:
        if (GetAsyncKeyState(VK_RIGHT))
        {
            d = 1;
            fflush(stdin);
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            d = 2;
            fflush(stdin);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            d = 3;
            fflush(stdin);
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            d = 4;
            fflush(stdin);
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            getch();
            fflush(stdin);
            goto label;
        }
        else
        {
            d = 0;
            fflush(stdin);
        }
        switch (d)
        {
        case 0:
            if (dir == 1)
            {
                x[0] = x[0] + 20;
            }
            else if (dir == 2)
            {
                x[0] = x[0] - 20;
            }
            else if (dir == 3)
            {
                y[0] = y[0] - 20;
            }
            else if (dir == 4)
            {
                y[0] = y[0] + 20;
            }
            else
            {
                d = 0;
            }
            break;
        case 1:
            x[0] = x[0] + 20;
            dir = 1;
            break;
        case 2:
            x[0] = x[0] - 20;
            dir = 2;
            break;
        case 3:
            dir = 3;
            y[0] = y[0] - 20;
            break;
        case 4:
            dir = 4;
            y[0] = y[0] + 20;
            break;
        }
        setfillstyle(SOLID_FILL, GREEN);
        for (int i = 0; i < length; i++)
        {
            bar(x[i], y[i], x[i] + 20, y[i] + 20);
        }
        for (int i = 199; i > 0; i--)
        {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }
        delay(60);
        if (x[0] >= 1000 || x[0] <= 0 || y[0] <= 0 || y[0] >= 810)
        {
            endfunc(f, 0);
            break;
        }

        for (int i = 2; i < length; i++)
        {
            if (x[0] == x[i] && y[0] == y[i])
            {
                chk = i;
                break;
            }
        }
        if (x[0] == x[chk] && y[0] == y[chk])
        {
            endfunc(f, 1);
            break;
        }
        if(f==100)
        {
        	endfunc(f,2);
        	break;
		}
        page = 1 - page;
    }
    return 0;
}


void connect4()
{
	int w,h;
	w=GetSystemMetrics(SM_CXSCREEN);
	h=GetSystemMetrics(SM_CYSCREEN);
	initwindow(w,h,"");
	setcolor(WHITE);
	rectangle(w/2-370,h/2-270,w/2+370,h/2+370);
	setfillstyle(SOLID_FILL,CYAN);
	floodfill(w/2-369,h/2-269,WHITE);
	settextstyle(8,0,20);
	outtextxy(w/2-300,50,"CONNECT 4");
	POINT cursorpos;
	int player =1;
	int sumh =1,sumv=1,sumd1=1,sumd2=1;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			setcolor(LIGHTCYAN);
			circle(w/2-300+100*j,h/2-200+100*i,45);
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(w/2-300+100*j,h/2-200+100*i,LIGHTCYAN);
		}	
	}	
	while(1)
	{
		
		GetCursorPos(&cursorpos);

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			while(GetAsyncKeyState(VK_LBUTTON));
			int p = getpixel(cursorpos.x,cursorpos.y);
			if(p==15)
			{
				
				if(cursorpos.y<h/2+250)
				{
					int colour= getpixel(cursorpos.x,cursorpos.y +100);
					if (colour==1 || colour==4)
					{
						if(player==1)
						{
							setfillstyle(SOLID_FILL,RED);
							floodfill(cursorpos.x,cursorpos.y,CYAN);
							player=2;
						}
						else
						{
							setfillstyle(SOLID_FILL,BLUE);
							floodfill(cursorpos.x,cursorpos.y,CYAN);
							player=1;
						}	
					}
				}
				else if(cursorpos.y>h/2+250&&cursorpos.y<h/2+350)
				{
					if(player==1)
					{
						setfillstyle(SOLID_FILL,RED);
						floodfill(cursorpos.x,cursorpos.y,CYAN);
						player=2;
					}
					else
					{
						setfillstyle(SOLID_FILL,BLUE);
						floodfill(cursorpos.x,cursorpos.y,CYAN);
						player=1;
					}
					
				}
			}
		}
		for(int i=0;i<6;i++)
		{
			int a=getpixel(cursorpos.x-300+100*i,cursorpos.y),b=getpixel(cursorpos.x-200+100*i,cursorpos.y);
			if(a==b && (a==1||a==4))
			{
				sumh=sumh+1;
				if(sumh==4)
				{
					if(player==1)
					{
						outtextxy(w/2-360,h/2,"PLAYER 2 WIN");
					}
					else if(player==2)
					{
						outtextxy(w/2-360,h/2,"PLAYER 1 WIN");
					}
					break;
				}
			}
			else
			{
				sumh=1;
			}
		}
		if(sumh==4)
		{
			delay(3000);
			break;
		}
		for(int i=0;i<6;i++)
		{
			int c=getpixel(cursorpos.x,cursorpos.y-300+100*i),d=getpixel(cursorpos.x,cursorpos.y-200+100*i);
			if(c==d && (c==1||c==4))
			{
				sumv=sumv+1;
				if(sumv==4)
				{
					if(player==1)
					{
						outtextxy(w/2-360,h/2,"PLAYER 2 WIN");
					}
					else if(player==2)
					{
						outtextxy(w/2-360,h/2,"PLAYER 1 WIN");
					}
					break;
				}
			}
			else
			{
				sumv=1;
			}
		}
		if(sumv==4)
		{
			delay(3000);
			break;
		}
		for(int i=0;i<6;i++)
		{
			int e=getpixel(cursorpos.x-300+100*i,cursorpos.y-300+100*i),f=getpixel(cursorpos.x-200+100*i,cursorpos.y-200+100*i);
			if(e==f && (e==1||e==4))
			{
				sumd1=sumd1+1;
				if(sumd1==4)
				{
					if(player==1)
					{
						outtextxy(w/2-360,h/2,"PLAYER 2 WIN");
					}
					else if(player==2)
					{
						outtextxy(w/2-360,h/2,"PLAYER 1 WIN");
					}
					break;
				}
			}
			else
			{
				sumd1=1;
			}
		}
		if(sumd1==4)
		{
			delay(3000);
			break;
		}
		for(int i=0;i<6;i++)
		{
			int g=getpixel(cursorpos.x+300-100*i,cursorpos.y-300+100*i),h=getpixel(cursorpos.x+200-100*i,cursorpos.y-200+100*i);
			if(g==h && (g==1||g==4))
			{
				sumd2=sumd2+1;
				if(sumd2==4)
				{
					if(player==1)
					{
						outtextxy(w/2-360,h/2,"PLAYER 2 WIN");
					}
					else if(player==2)
					{
						outtextxy(w/2-360,h/2,"PLAYER 1 WIN");
					}
					break;
				}
			}
			else
			{
				sumd2=1;
			}
		}
		if(sumd2==4)
		{
			delay(3000);
			break;
		}
		if(GetAsyncKeyState(VK_ESCAPE))//Exit Menu
		{
			delay(50);
			break;
		}
		delay(10);	
	}
}

int RPSmain()
{

    initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "RPS");

    RockPaperScissors();
    return 0;
}

void RockPaperScissors()
{
	int player = 0, computer = 0;
	int p, c;

	int page=0;
	char pl[2],co[2];

    for (int i = 0; i < 5; i++)
    {
    	setbkcolor(15);
        cleardevice();


        setcolor(0);
        settextstyle(8, 0, 10);
        
        //HEADING
        outtextxy(10, 50, "ROCK PAPER SCISSORS");
        settextstyle(8, 0, 5);
        
        //INSTRUCTIONS
        outtextxy(1150, 200, "Instructions");
        settextstyle(8, 0, 3);
        line(1075, 200, 1075, GetSystemMetrics(SM_CYSCREEN));
        outtextxy(1080,300,"1. Rock breaks Scissors.");
        outtextxy(1080,350,"2. Scissors cut Paper.");
        outtextxy(1080,400,"3. Paper wraps Rock.");
        outtextxy(1080,450,"4. You have 5 turns to WIN.");
        outtextxy(1250,500, "ENJOY!");
        
        outtextxy(20, 200, "Press 'r' for Rock, Press 'p' for Paper, Press 's' for Scissors");
        outtextxy(150, 250, "PLAYER");
        outtextxy(775, 250, "COMPUTER");
        
        //SCOREBOARD
        outtextxy(1080,600,"SCOREBOARD");
        outtextxy(1080,675,"Player:");
        outtextxy(1080,725,"Computer:");

        // Take player input
        getch();
        if (GetAsyncKeyState(0x52))
        {
        	while(GetAsyncKeyState(0x52));
            p = 1;
            readimagefile("rock.jpg", 50, 300, 350, 600);
		            delay(2000);
		        c = RandomMaker() + 1;
		        if (c == 1)
		        {
		            readimagefile("rock.jpg", 600, 300, 900, 600);
		        }
		        else if (c == 2)
		        {
		            readimagefile("paper.jpg", 580, 300, 990, 700);
		        }
		        else if (c == 3)
		        {
		            readimagefile("scissors.jpg", 600, 300, 900, 600);
		        }
        }
        else if (GetAsyncKeyState(0x50))
        {
        	while(GetAsyncKeyState(0x50));
            p = 2;
            readimagefile("paper.jpg", 30, 300, 440, 700);
            		            delay(2000);
		        c = RandomMaker() + 1;
		        if (c == 1)
		        {
		            readimagefile("rock.jpg", 600, 300, 900, 600);
		        }
		        else if (c == 2)
		        {
		            readimagefile("paper.jpg", 580, 300, 990, 700);
		        }
		        else if (c == 3)
		        {
		            readimagefile("scissors.jpg", 600, 300, 900, 600);
		        }
        }
        else if (GetAsyncKeyState(0x53))
        {
        	while(GetAsyncKeyState(0x53));
            p = 3;
            readimagefile("scissors.jpg", 50, 300, 350, 600);
            		            delay(2000);
		        c = RandomMaker() + 1;
		        if (c == 1)
		        {
		            readimagefile("rock.jpg", 600, 300, 900, 600);
		        }
		        else if (c == 2)
		        {
		            readimagefile("paper.jpg", 580, 300, 990, 700);
		        }
		        else if (c == 3)
		        {
		            readimagefile("scissors.jpg", 600, 300, 900, 600);
		        }
        }
        else if (GetAsyncKeyState(VK_ESCAPE))
        {
           break;
        }
        int check = Compare(p, c);
        if (check == -1)
        {
            player++;
            computer++;
            outtextxy(350, 750, "It's a DRAW. Both scored 1 point!");
        }
        else if (check == 0)
        {
            computer++;
            outtextxy(350, 750, "Computer scored 1 point!");
        }
        else
        {
            player++;
            outtextxy(350, 750, "Player scored 1 point!");
        }
        pl[0]=(char)(player+48);pl[1]='\0';
        co[0]=(char)(computer+48);co[1]='\0';
        outtextxy(1300,675,pl);
        outtextxy(1300,725,co);
        delay(4000);
    }
    
    if(player>computer)
    	outtextxy(1350,675,"WIN");
    else if(player<computer)
        outtextxy(1350,725,"WIN");
    else
    	outtextxy(1350,700,"DRAW");

	delay(4000);
}

int Compare(int p, int c)		//TO COMPARE PLAYER AND COMPUTER TURN
{
    if (p == c)
        return (-1);
    else if ((p == 1 && c == 2) || (p == 2 && c == 3) || (p == 3 && c == 1))
        return 0;
    else
        return 1;
}
int RandomMaker()	//TO GENERATE RANDOM VARIABLE FOR COMPUTER
{
    int temp;
    srand(time(NULL));
    temp = rand() % 4;
    return temp;
}


int main2048()
{

    initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "2048");
    setbkcolor(15);

    Game2048();

    getch();
    return 0;
}

void Game2048()
{
    int page = 0;
    int aro;
    char Arrow;
    int temp;
    Start();
    while (!(GetAsyncKeyState(VK_ESCAPE))) //  HERE IF USER WANT TO EXIT THEN PRESS ESC KEY
    {
        //to reduce flickering of window
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        // OUTLINE OF GAME
        setcolor(0);
        settextstyle(10, 0, 10);
        outtextxy(620, 20, "2048");
        settextstyle(10, 0, 2);

        setlinestyle(0, 0, 2);
        rectangle(432, 132, 1084, 783);

        // INSTRUCTIONS
        outtextxy(40, 230, "1. Combine tiles containing same");
        outtextxy(40, 280, "numbers.");
        outtextxy(40, 330, "2. Use arrow keys to toggle.");
        outtextxy(40, 380, "3. Reach the 2048 tile before");
        outtextxy(40, 430, "all spaces are occupied.");
        

        settextstyle(10, 0, 4);
        outtextxy(100, 180, "INSTRUCTIONS");
        outtextxy(1150, 180, "STATUS: Playing");
        
        settextstyle(10,0,6);
        Arrow = getch();
        aro = Arrow;
        if (over == 0)
        {
            if (GetAsyncKeyState(VK_UP))
                Up();
            else if (GetAsyncKeyState(VK_DOWN))
                Down();
            else if (GetAsyncKeyState(VK_LEFT))
                Left();
            else if (GetAsyncKeyState(VK_RIGHT))
                Right();
        }
        else
        {
            outtextxy(1150, 400, "GAME OVER!");
            if (GetAsyncKeyState(VK_ESCAPE))
                break;
        }
        Random_creator();
        Display();

        temp = Temp_counter();
        if (temp == 1)
        {
            outtextxy(1150, 400, "YOU WON!");
            if (GetAsyncKeyState(VK_ESCAPE))
                break;
        }
        if (temp == 0)
        {
            over++;
        }
        delay(50);
        page = 1 - page;
    }
}
void Display()
{
    int i, j;
    system("cls");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (Matrix[i][j] == 0)
            {
                outtextxy(grid_ref_x1[i] + 20, grid_ref_y1[j] + 20, " "); // 0 is replaced by space in display
            }
            else if (Matrix[i][j] == 2)
                readimagefile("2.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 4)
                readimagefile("4.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 8)
                readimagefile("8.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 16)
                readimagefile("16.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 32)
                readimagefile("32.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 64)
                readimagefile("64.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 128)
                readimagefile("128.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 256)
                readimagefile("256.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 512)
                readimagefile("512.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 1024)
                readimagefile("1024.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
            else if (Matrix[i][j] == 2048)
                readimagefile("2048.2048.jpg", grid_ref_x1[i], grid_ref_y1[j], grid_ref_x1[i] + 150, grid_ref_y1[j] + 150);
        }
    }
}

void Start()
{
    Matrix[3][1] = 2;
    Matrix[3][3] = 4;
    Matrix[2][2] = 2;
    Matrix[2][3] = 2;
    Matrix[1][2] = 2;

    Display();
}

void Down()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        j = 2;
        while (1)
        {
            while (Matrix[i][j] == 0)
            {
                if (j == -1)
                    break;
                j--;
            }
            if (j == -1)
                break;
            while (j < 4 - 1 && (Matrix[i][j + 1] == 0 || Matrix[i][j] == Matrix[i][j + 1]))
            {
                Matrix[i][j + 1] += Matrix[i][j];
                Matrix[i][j] = 0;
                j++;
            }
            j--;
        }
    }
}

void Up()
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        j = 1;
        while (1)
        {
            while (Matrix[i][j] == 0)
            {
                if (j == 4)
                    break;
                j++;
            }
            if (j == 4)
                break;
            while (j > 0 && (Matrix[i][j - 1] == 0 || Matrix[i][j] == Matrix[i][j - 1]))
            {
                Matrix[i][j - 1] += Matrix[i][j];
                Matrix[i][j] = 0;
                j--;
            }
            j++;
        }
    }
}

void Right()
{
    int i, j;
    for (j = 0; j < 4; j++)
    {
        i = 2;
        while (1)
        {
            while (Matrix[i][j] == 0)
            {
                if (i == -1)
                    break;
                i--;
            }
            if (i == -1)
                break;
            while (i < 4 - 1 && (Matrix[i + 1][j] == 0 || Matrix[i][j] == Matrix[i + 1][j]))
            {
                Matrix[i + 1][j] += Matrix[i][j];
                Matrix[i][j] = 0;
                i++;
            }
            i--;
        }
    }
}

void Left()
{
    int i, j;
    for (j = 0; j < 4; j++)
    {
        i = 1;
        while (1)
        {
            while (Matrix[i][j] == 0)
            {
                if (i == 4)
                    break;
                i++;
            }
            if (i == 4)
                break;
            while (i > 0 && (Matrix[i - 1][j] == 0 || Matrix[i][j] == Matrix[i - 1][j]))
            {
                Matrix[i - 1][j] += Matrix[i][j];
                Matrix[i][j] = 0;
                i--;
            }
            i++;
        }
    }
}

void Random_creator()
{
    int temp1, temp2, add, i, j;
    srand(time(NULL));
    temp1 = rand() % 4; // i

    srand(time(NULL));
    temp2 = rand() % 4; // j

    if ((temp1 + temp2) % 2 == 0)
        add = 2;
    else
        add = 4;

    for (i = 0; i < temp1; i++)
    {
        for (j = temp2; j < 4; j++)
        {
            if (Matrix[i][j] == 0)
            {
                Matrix[i][j] = add;
                return;
            }
        }
    }
}

int Temp_counter()
{
    /* IT SHOULD FIND MAX VALUE FROM WHOLE MATRIX  */
    int temp = 0, i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (Matrix[i][j] == 2048)
                return (1);
            if (Matrix[i][j] == 0)
                temp = 1;
        }
    }
    if (temp == 1)
    {
        last = 0;
        return (-99);
    }
    else
    {
        if (last == 1)
        {
            return (0);
        }
        last = 1;
        return (-99);
    }
}
