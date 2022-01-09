// IN THE NAME OF GOD
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
//cheat codes of the game = ^wIN;   ^P(|| ^P)LAY2(|| 4);
int hole[100][100] = {}, nobat = 1, start = 1 , first = 1;
int i_last[1000] = {} , j_last[1000] = {} ,i_last_pc[1000] = {}, j_last_pc[1000] = {}, mo_i = 1, mo_j = 1, mo_i_pc = 1, mo_j_pc = 1;//for function of ctrl z-saving movements
int LENGTH=1260,WIDTH=700;//dimontion of window
//object of drowing
int i_max = 7, j_max = 6, zarib = 1, x_mabda = 50, y_mabda = 25, i_pointer=-10000;
int x1_one_player, x2_one_player, y1_one_player, y2_one_player, x1_two_player, x2_two_player, y1_two_player, y2_two_player;//drow the window of choosing one player or two
int x1_level = LENGTH/2-150 , x2_level = LENGTH/2+150 , y1_1 = WIDTH/2-170 , y1_2 = WIDTH/2-70, y2_1 = WIDTH/2-50 , y2_2 = WIDTH/2+50 , y3_1 = WIDTH/2+70 , y3_2 = WIDTH/2+170;//drow the window of choosing the level of AI
int x1_back = 15, x2_back = 149, y1_back = 700-75, y2_back = 700-25;//drow the item to back to the menu
int color_background = COLOR(190,120,20);
//end of drowing
//object of code
int rang = 1, win = 0, player_1 = 1, player_2 = 0, HALAT = 0, level = 0, flag = 0, sett = 1, HALAT_D, LEVEL_D;// HALAT=1 is one player and so
int sec = 0, min_ = 0 , u_ = 1, LIMIT = 20, sec_limit = LIMIT-1;//time
float TIME = 0, sum_time = 0, time_limit = 0, x_clock = 10 , mrhle_clock = 1;//time
int win_player1 = 0, win_player2 = 0 , win_AI = 0, ST = 3, RAN = 1;//AI
char ch = 60, M[20000000], msg[200000], msg2[2000000], Setting[20000000], Q[20000000], raww[2000000], coll[2000000];
int A_AI[10000]={}, B_AI[10000]={}, iAI = 0, jAI = 0;

//drowin functins
void loading(void);
void drow_background(void);
void drow_board(int length, int width);
void drow_players(int);
void drow_ball(int i,int j);
void drow_ball_win(int i,int j);
void drow_menu(void);
void drow_back(void);
void drow_setting(void);//choose item
void drow_clear_setting(void);
void clearball(void);
void score_board(void);
void item_choose(int);
void clear_item_choose(int);
void turn(void);
void clear_turn(void);
void pointer(int);
void clear_pointer(void);
void pause(void);
void show_winner(void);
void setting(void);
void set_rang(void);
void first_or_second(void);
void pc_level(void);
void winner_party(void);
//end of drowin functions
void menu(void);
void single_or_two(void);
void game(void);
void column(void);
void column_pc(void);
int i_mousex(void);
void check_ball(int i,int j);
int win_check(int i,int j);
int back_click(void);
void time_function(void);
int cheatcode_win(void);
int cheatcode_playmore(void);
void set_default(void);
void exit_or_again(void);
int PC_1(void);
int PC_2(void);
int PC_3(void);
int win_check_AI(int);
int check_ball_AI(int ,int);
//
void AI_PC(int);
int win_AL(int);
int check_AI(int i, int j, int k);
int change(int k)
{
    int t = 0;
    if(k == 1)
        t = player_2;
    else
    {
        if(player_2 == 2) t = 1;
        else t = 2;
    }
    return t;
}
//
void hoosh(void);
void dim(void)
{
        if(mousex() >= 450 && mousex() <= 610 && mousey() >= 170 && mousey() <= 250)//up col
        {
            setcolor(0);
            line(450 , 250 , 610 , 250 );line(450 , 250 , 530 , 170 ); line(530 , 170 , 610 , 250 );
            setcolor(7); line(450 , 450 , 610 , 450 );
            line(680 , 250 , 760 , 170 ); line(450 , 450 , 530 , 530 ); line(680 , 450 , 760 , 530 );line(680 , 450 , 840 , 450 );
            line(760 , 170 , 840 , 250 ); line(530 , 530 , 610 , 450 ); line(760 , 530 , 840 , 450 );line(680 , 250 , 840 , 250 );
        }
        else if(mousex() >= 680 && mousex() <= 840 && mousey() >= 170 && mousey() <= 250)//up row
        {
            setcolor(0);
             line(680 , 250 , 760 , 170 ); line(680 , 250 , 840 , 250 );line(760 , 170 , 840 , 250 );
            setcolor(7);line(450 , 250 , 530 , 170 );line(450 , 450 , 530 , 530 ); line(680 , 450 , 760 , 530 );
            line(450 , 250 , 610 , 250 );  line(450 , 450 , 610 , 450 ); line(680 , 450 , 840 , 450 );
            line(530 , 170 , 610 , 250 );  line(530 , 530 , 610 , 450 ); line(760 , 530 , 840 , 450 );
        }
        else if(mousex() >= 450 && mousex() <= 610 && mousey() >= 450 && mousey() <= 530)//down col
        {
            setcolor(0);
             line(450 , 450 , 610 , 450 ); line(450 , 450 , 530 , 530 );line(530 , 530 , 610 , 450 );
            setcolor(7);line(450 , 250 , 610 , 250 ); line(680 , 250 , 840 , 250 );line(680 , 450 , 840 , 450 );
            line(450 , 250 , 530 , 170 ); line(680 , 250 , 760 , 170 );  line(680 , 450 , 760 , 530 );
            line(530 , 170 , 610 , 250 ); line(760 , 170 , 840 , 250 );  line(760 , 530 , 840 , 450 );
        }
        else if(mousex() >= 680 && mousex() <= 840 && mousey() >= 450 && mousey() <= 530)//down raw
        {
            setcolor(0);
             line(680 , 450 , 840 , 450 );line(760 , 530 , 840 , 450 );line(680 , 450 , 760 , 530 );
            setcolor(7);line(450 , 250 , 610 , 250 ); line(680 , 250 , 840 , 250 ); line(450 , 450 , 610 , 450 );
            line(450 , 250 , 530 , 170 ); line(680 , 250 , 760 , 170 ); line(450 , 450 , 530 , 530 );
            line(530 , 170 , 610 , 250 ); line(760 , 170 , 840 , 250 ); line(530 , 530 , 610 , 450 );
        }
}
void set_dimontion(void)
{
    int raw = 6, col = 7, zarib1, zarib2;
    setbkcolor(color_background);//drow
    cleardevice();//drow
    settextstyle(6, 0, 6);
    setcolor(0);
    outtextxy(170, 20, "WELCOME TO THE GAME:))");
    settextstyle(4, 0, 4);
    outtextxy(370, 120, "\"SET THE DIMENSIONS\"");
    settextstyle(3, 0, 3);
    outtextxy(1000, 600, "push Enter to continue...");
    settextstyle(6, 0, 6);
    outtextxy(420, 540, "column");
    outtextxy(720, 540, "raw");
    setcolor(7);
    for(int i = 0; i <= 80 ; i++)
    {
        line(450 + i, 250 - i, 610 - i, 250 - i);
    }
    for(int i = 0; i <= 80 ; i++)
    {
        line(680 + i, 250 - i, 840 - i, 250 - i);
    }
    for(int i = 0; i <= 80 ; i++)
    {
        line(450 + i, 450 + i, 610 - i, 450 + i);
    }
    for(int i = 0; i <= 80 ; i++)
    {
        line(680 + i, 450 + i, 840 - i, 450 + i);
    }

    setcolor(0);
    setlinestyle(0,0,3);
    /*
    line(450 , 250 , 610 , 250 ); line(680 , 250 , 840 , 250 ); line(450 , 450 , 610 , 450 ); line(680 , 450 , 840 , 450 );
    line(450 , 250 , 530 , 170 ); line(680 , 250 , 760 , 170 ); line(450 , 450 , 530 , 530 ); line(680 , 450 , 760 , 530 );
    line(530 , 170 , 610 , 250 ); line(760 , 170 , 840 , 250 ); line(530 , 530 , 610 , 450 ); line(760 , 530 , 840 , 450 );
    */
    setcolor(0);
    while(1)
    {
        dim();
        setcolor(0);
        if(kbhit())
        {
            ch = getch();
            if(ch == 13) break;
            if(ch == 27) {ch = 60; sett = 4; HALAT = 0; return;}
        }

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousex() >= 450 && mousex() <= 610)
            {
                if(mousey() >= 170 && mousey() <= 250)
                    col++;
                else if(mousey() >= 450 && mousey() <= 530)
                    col--;
            }
            else if(mousex() >= 680 && mousex() <= 840)
            {
                if(mousey() >= 170 && mousey() <= 250)
                    raw++;
                else if(mousey() >= 450 && mousey() <= 530)
                    raw--;
            }
            if(col == 21) col = 20;
            else if(col == 3) col = 4;
            if(raw == 21) raw = 20;
            else if(raw == 3) raw = 4;
        }
        settextstyle(9, 0, 9);
        sprintf(coll, "%.2d", col);
        outtextxy(460, 300 , coll);
        sprintf(raww, "%.2d", raw);
        outtextxy(700, 300 , raww);
        clearmouseclick(WM_LBUTTONDOWN);
    }
    i_max = col; j_max = raw;
    x_mabda = 50; y_mabda = 25;
    zarib1 = (WIDTH - 2 * y_mabda)/(j_max + 2);
    zarib2 = (LENGTH - 200 - 2 * x_mabda)/(i_max + 2);
    if(zarib1 <= zarib2) zarib = zarib1;
    else zarib = zarib2;

    x_mabda = (LENGTH - 200 - (i_max + 2) * zarib)/2 + 150;
    y_mabda = (WIDTH - (j_max + 2)* zarib)/2;
    delay(500);
}


int main()//finished
{
    int i,j;
    srand(time(0));
    //cout<<"PLEASE ENTER THE DIMENSIONS OF THE GAME \"FIRST ROW THEN COLUMN\":"<<endl;
    //cin>>j_max>>i_max;
//    zarib1 = (WIDTH - 2 * y_mabda)/(j_max + 2);
//    zarib2 = (LENGTH - 200 - 2 * x_mabda)/(i_max + 2);
//    if(zarib1 <= zarib2) zarib = zarib1;
//    else zarib = zarib2;
//
//    x_mabda = (LENGTH - 200 - (i_max + 2) * zarib)/2 + 150;
//    y_mabda = (WIDTH - (j_max + 2)* zarib)/2;

    for(i=1 ; i <= 30 ; i++)//put a floor under the board
        hole[i][0] = -1;

    initwindow(LENGTH + 100,WIDTH);

    loading();//start app

    while(1)
    {
        menu();
        if(sett == 4) break;
        set_default();
        clearmouseclick(WM_LBUTTONDOWN);
    }

    closegraph();
	return 0;
}

void set_default(void)//finished
{
    sec = 0; min_ = 0; win = 0; flag = 0; sett = 1; ch = 60; first = 1; win_AI = 0; ST = 3; RAN = 1;
    if(player_1 == 2) player_1 = 4;
    if(start == 1) {rang =1;  level = 0; HALAT = 0; win_player1 = 0; win_player2 = 0;}
    else {rang = player_1; HALAT = HALAT_D; level = LEVEL_D;}
}

void menu(void)//finished
{
    if(start == 1)
    {
        set_dimontion();
        if(sett == 4) return;
        setbkcolor(color_background);//drow
        cleardevice();//drow
        drow_menu();//drow
        single_or_two();//choose
        if(HALAT == 1) pc_level();
        clearmouseclick(WM_LBUTTONDOWN);

        if(HALAT != 0) set_rang();//choose
        if(HALAT == 1) first_or_second();
    }
    if(HALAT != 0)
    {
        for(int i = 0; i <= 999; i++)
        {
            i_last[i] = 0; j_last[i] = 0;i_last_pc[i] = 0, j_last_pc[i] = 0;
        }
        if(start != 1 && HALAT == 1) {first_or_second(); HALAT == 1;}
          start = 1;
          game();
          if(player_1 == 4) player_1 = 2;
          if(start == 2)
          {if(win == player_1) win_player1++;
          else win_player2++;
          printf("\nplayer 1 is: %d\nplayer 2 is: %d\nEND\n\n", win_player1, win_player2);}
    }
    return;
}

void single_or_two(void)//finished
{
    clearmouseclick(WM_LBUTTONDOWN);
    drow_back();
    while(1)
    {
        if(kbhit())
        {
            ch = getch();
            if(ch == 27) {ch = 60; sett = 3; HALAT = 0; return;}
        }
        if(back_click() == 1) {HALAT = 0; return;}

        clear_item_choose(1);
        item_choose(1);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousey() < y2_one_player && mousey() > y1_one_player)
            {
                if(mousex() < x2_one_player && mousex() > x1_one_player)
                {
                    HALAT = 1;
                    HALAT_D = 1;
                    clearmouseclick(WM_LBUTTONDOWN);
                    return;
                }
                if(mousex() < x2_two_player && mousex() > x1_two_player)
                {
                    HALAT = 2;
                    HALAT_D = 2;
                    clearmouseclick(WM_LBUTTONDOWN);
                    return;
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }

    }
}

void pc_level(void)//finished
{
    setbkcolor(color_background);//drow
    cleardevice();//drow

    setcolor(0);
    rectangle(x1_level, y1_1, x2_level, y1_2);
    rectangle(x1_level, y2_1, x2_level, y2_2);
    rectangle(x1_level, y3_1, x2_level, y3_2);
    setfillstyle(1,COLOR(253, 124, 15));
    bar(x1_level, y1_1, x2_level, y1_2);
    bar(x1_level, y2_1, x2_level, y2_2);
    bar(x1_level, y3_1, x2_level, y3_2);

    setbkcolor(COLOR(253, 124, 15));
    settextstyle(6,0,6);
    outtextxy(x1_level+65,y1_1+10,"Easy");
    outtextxy(x1_level+30,y2_1+10,"Normal");
    outtextxy(x1_level+65,y3_1+10,"Hard");

    drow_back();

    while(1)
    {
        if(kbhit())
        {
        ch = getch();
        if(ch == 27) {ch = 60; HALAT = 0; return;}
        }
        if(back_click() == 1) {HALAT = 0; return;}

        clear_item_choose(3);
        item_choose(3);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousex() < x2_level && mousex() > x1_level)
            {
                if(mousey() <= y1_2 && mousey() >= y1_1)
                {
                    level = 1;
                    LEVEL_D = 1;
                    break;
                }
                else if(mousey() <= y2_2 && mousey() >= y2_1)
                {
                    level = 2;
                    LEVEL_D = 2;
                    break;
                }
                else if(mousey() <= y3_2 && mousey() >= y3_1)
                {
                    level = 3;
                    LEVEL_D = 3;
                    break;
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void first_or_second(void)//finished
{

    setbkcolor(color_background);
    cleardevice();

    setcolor(0);
    setfillstyle(1,COLOR(253, 124, 15));
    setlinestyle(0,0,5);

    int kh = x2_one_player - x1_one_player;

    rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
    bar(x1_one_player,y1_one_player,x2_one_player,y2_one_player);//blue
    rectangle(x1_two_player,y1_two_player,x1_two_player+kh,y2_two_player);
    bar(x1_two_player,y1_two_player,x1_two_player+kh,y2_two_player);//red
    settextstyle(6,0,6);
    setbkcolor(COLOR(253, 124, 15));
//    setfillstyle(1,1);
    outtextxy(x1_one_player+30,y2_one_player-kh/2-70, "YES");
//    setfillstyle(1,4);
    outtextxy(x1_two_player+50,y2_two_player-kh/2-70, "NO" );
    settextstyle(4,0,4);
    setbkcolor(color_background);
    outtextxy(250,150,"DO YOU WANT TO PLAY FIRST ?");

    drow_back();
    clearmouseclick(WM_LBUTTONDOWN);
    while(1)
    {
        if(kbhit())
        {
            ch = getch();
            if(ch == 27) {ch = 60; HALAT = 0; return;}
        }
        if(back_click() == 1) {HALAT = 0; return;}
        clear_item_choose(2);
        item_choose(2);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousey() < y2_one_player && mousey() > y1_one_player)
            {
                if(mousex() < x2_one_player && mousex() > x1_one_player)
                {
                    first = 1;
                    return;
                }
                if(mousex() < x1_two_player+kh && mousex() > x1_two_player)
                {
                    first = 2;
                    flag = 1;
                    return;
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void set_rang(void)//finished
{

    setbkcolor(color_background);
    cleardevice();

    setcolor(0);
    setfillstyle(1,COLOR(253, 124, 15));
    setlinestyle(0,0,5);

    int kh = x2_one_player - x1_one_player;

    rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
    bar(x1_one_player,y1_one_player,x2_one_player,y2_one_player);//blue
    rectangle(x1_two_player,y1_two_player,x1_two_player+kh,y2_two_player);
    bar(x1_two_player,y1_two_player,x1_two_player+kh,y2_two_player);//red

    setfillstyle(1,1);
    fillellipse(x1_one_player+kh/2,y2_one_player-kh/2-30, kh/2-10, kh/2-10);
    setfillstyle(1,4);
    fillellipse(x1_two_player+kh/2,y2_two_player-kh/2-30, kh/2-10, kh/2-10);
    settextstyle(6,0,6);
    if(HALAT == 2) outtextxy(270,150,"COLOR OF PLAYER 1:");
    if(HALAT == 1) outtextxy(270,150,"CHOSE YOUR COLOR :");

    drow_back();

    while(1)
    {
        if(kbhit())
        {
            ch = getch();
            if(ch == 27) {ch = 60; HALAT = 0; return;}
        }
        if(back_click() == 1) {HALAT = 0; return;}
        clear_item_choose(2);
        item_choose(2);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousey() < y2_one_player && mousey() > y1_one_player)
            {
                if(mousex() < x2_one_player && mousex() > x1_one_player)
                {
                    rang = 1;
                    player_1 = rang;
                    player_2 = 2;
                    return;
                }
                if(mousex() < x1_two_player+kh && mousex() > x1_two_player)
                {
                    rang = 4;
                    player_1 = rang;
                    player_2 = 1;
                    return;
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void game(void)//finished
{
    clearmouseclick(WM_LBUTTONDOWN);
    cleardevice();
    drow_background();
    drow_board(LENGTH-200, WIDTH);

    if(HALAT == 1) drow_players(2);
    else if(HALAT == 2) drow_players(1);

    turn();//DROW FUNCTION
    drow_setting();

    for(int i=1 ; i <= i_max ; i++)
        {
            printf("|");
            for(int j=1 ; j <= j_max ; j++)
            {
                hole[i][j] = 0; printf("%d|", hole[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    if(HALAT == 1) column_pc();
    else if(HALAT == 2) column();

    if(ch != 27 && (sett != 3 && sett !=4))
    {
        show_winner();
        winner_party();
        exit_or_again();
    }
    for(int i=1 ; i <= i_max ; i++)
    {
        printf("|");
        for(int j=1 ; j <= j_max ; j++)
        {
            hole[i][j] = 0; printf("%d|", hole[i][j]);
        }
        printf("\n");
    }
    ch = 60;
    return;
}

void exit_or_again(void)//finished
{
    setbkcolor(color_background);
    cleardevice();

    setcolor(0);
    setfillstyle(1,COLOR(253, 124, 15));
    setlinestyle(0,0,5);

    int kh = x2_one_player - x1_one_player;

    rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
    bar(x1_one_player,y1_one_player,x2_one_player,y2_one_player);//blue
    rectangle(x1_two_player,y1_two_player,x1_two_player+kh,y2_two_player);
    bar(x1_two_player,y1_two_player,x1_two_player+kh,y2_two_player);//red
    settextstyle(6,0,6);
    setbkcolor(COLOR(253, 124, 15));
//    setfillstyle(1,1);
    outtextxy(x1_one_player+30,y2_one_player-kh/2-70, "YES");
//    setfillstyle(1,4);
    outtextxy(x1_two_player+50,y2_two_player-kh/2-70, "NO" );
    settextstyle(4,0,4);
    setbkcolor(color_background);
    outtextxy(210,150,"DO YOU WANT TO CONTINUE THIS GAME ?");

    drow_back();
    clearmouseclick(WM_LBUTTONDOWN);
    while(1)
    {
        if(kbhit())
        {
            ch = getch();
            if(ch == 27) {ch = 60; HALAT = 0; return;}
        }
        if(back_click() == 1) {HALAT = 0; return;}
        clear_item_choose(2);
        item_choose(2);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousey() < y2_one_player && mousey() > y1_one_player)
            {
                if(mousex() < x2_one_player && mousex() > x1_one_player)
                {
                    start = 2;
                    return;
                }
                if(mousex() < x1_two_player+kh && mousex() > x1_two_player)
                {
                    sett = 3;
                    return;
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

void column_pc(void)//finished
{
    ch = 60; clearmouseclick(WM_LBUTTONDOWN);
    int x, y, i, j = 0, run = 1, i_ = 1;
    while(1)
    {
        TIME = clock();

        if(RAN == 1 || run == 1)
        {
            clear_pointer();
            pointer(i);
            RAN = 0; run =0;
        }
        if(ismouseclick(WM_MOUSEMOVE))
        {
            clear_pointer();
            if( mousex() >=zarib+x_mabda && mousex() <i_max*zarib+zarib+x_mabda )
            {
                i = i_mousex();
                pointer(i);
            }
            clearmouseclick(WM_MOUSEMOVE);
        }

        if(kbhit() || ismouseclick(WM_RBUTTONDOWN))//click RIGHTBUTTOM for pause, kbhit for setting , cheatcode or ctrl Z
        {
            //if ismouseclick RIGHTBUTTOM
            if(ismouseclick(WM_RBUTTONDOWN)) ch = 'p'; clearmouseclick(WM_RBUTTONDOWN);//pause
            // else if kbhit
            if(kbhit())
            {
                ch = getch();
                if(ch == 27)//open setting with Esc
                {
                    setting();
                    if(sett == 4 || sett == 3) { ch = 27; return;}
                }
                if(ch == 26 && mo_i > 1 && mo_i_pc > 1 && mo_i +1 >= mo_i_pc)//ctrl z
                {
                    mo_i--; mo_j--;
                    mo_i_pc--; mo_j_pc--;
                    hole[i_last[mo_i]][j_last[mo_j]] = 0;
                    hole[i_last_pc[mo_i_pc]][j_last_pc[mo_j_pc]] = 0;
                    clearball();
                }

                if(ch == 23)//cheat code
                {
                    if(cheatcode_win() == 1)
                    return;
                }
                if(ch == 16 || ch == -16)//cheet code
                {
                    cheatcode_playmore();
                }

            }
            getimage(480,205,875,465,Q);
            pause();
            putimage(480,205,Q,0);
        }//finished part 1

        if(ch == 'a' || ch == 'A'|| ch == 'd'|| ch == 'D')
        {
            if(ch == 'a' || ch == 'A' )
            {
                i--;
                clear_pointer();
                if(i < 1) i = 1;
            }
            else
            {
                i++;
                clear_pointer();
                if(i > i_max) i = i_max;
            }
            i_pointer = i;
            run = 1;
            ch = 60;
        }
        if((ch == 32 || ch == 13) && i >= 1 && i <= i_max)
        {
            time_limit = 0; u_ = 0; RAN = 1; x_clock = 10; mrhle_clock = 1;
            j=1;
            check_ball(i,j);
            if(win_check(i,j)!=0) { ch = 60; return;}
            clear_turn();
            turn();
            ch = 60;
            flag++;
        }
//****************************************************

        drow_clear_setting();//for choosing setting
        //finished part 2
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if((mousex() >= x1_back && mousex() <= x2_back+90 && mousey() >= y1_back && mousey() <= y2_back))
            {
                setting();
                if(sett == 4 || sett == 3) { ch = 27; return;}
            }
        }
        if(ismouseclick(WM_LBUTTONDOWN) || time_limit == LIMIT)//droping ball or time has done
        {
            if(time_limit == LIMIT)
            {
                if(rang == 1) rang = 4;
                else rang = 1;

                if(level == 1) i=PC_1();
                else if(level == 2) i=PC_2();
                else if(level == 3) i=PC_3();
                j=1;
                check_ball(i,j);
                if(win_check(i,j)!=0) { ch = 60; return;}
                clear_turn();
                turn();
                time_limit = 0;
            }
            else
            {
                time_limit = 0; u_ = 0;  x_clock = 10; mrhle_clock = 1;
                if(sett == 1)
                {
                    j=1;
                    x = mousex();
                    if(x>zarib+x_mabda && x<=(i_max+1)*zarib+x_mabda)
                    {
                        i=i_mousex();
                        if(hole[i][j_max] == 0)
                        {
                            check_ball(i,j);
                            if(win_check(i,j)!=0) { ch = 60; return;}
                            flag++;
                        }
                    }
                    clear_turn();
                    turn();
                }
            }
            //*****************
            for(int i=i_max ; i >= 1 ; i--)
            {
                printf("|");
                for(int j=1 ; j <= j_max ; j++)
                {
                    printf("%d|", hole[j][i]);
                }
                printf("\n");
            }
            printf("\n");


            clearmouseclick(WM_LBUTTONDOWN);
        }//finished par 3
        if(first == 2)
        {
            if(rang == 1) rang = 4;
            else rang = 1;
            clear_turn();
            turn();
            first = 1;
        }
        if(flag == 1)
        {
            if(level == 1) i_=PC_1();
            else if(level == 2) i_=PC_2();
            else if(level == 3) i_=PC_3();
            j=1;
            check_ball(i_,j);
            if(win_check(i_,j)!=0) {ch = 60;  return;}
            flag--;
            clear_turn();
            turn();

            //*****************
            for(int i=i_max ; i >= 1 ; i--)
            {
                printf("|");
                for(int j=1 ; j <= j_max ; j++)
                {
                    printf("%d|", hole[j][i]);
                }
                printf("\n");
            }
            printf("\n");


        }

        TIME = clock() - TIME;
        time_function();
    }
    return;
}

void column(void)//finished
{
    ch = 60; clearmouseclick(WM_LBUTTONDOWN);
    int x,y,i = 0,j = 0, run = 1;
    while(1)
    {
        TIME = clock();
        if(RAN == 1 || run == 1)
        {
            clear_pointer();
            pointer(i);
            RAN = 0; run =0;
        }
        if(ismouseclick(WM_MOUSEMOVE))
        {
            clear_pointer();
            if( mousex() >=zarib+x_mabda && mousex() <i_max*zarib+zarib+x_mabda )
            {
                i = i_mousex();
                pointer(i);
            }
            clearmouseclick(WM_MOUSEMOVE);
        }


        if(kbhit() || ismouseclick(WM_RBUTTONDOWN))//click RIGHTBUTTOM for pause, kbhit for setting , cheatcode or ctrl Z
        {
            //if ismouseclick RIGHTBUTTOM
            if(ismouseclick(WM_RBUTTONDOWN)) ch = 'p'; clearmouseclick(WM_RBUTTONDOWN);//pause
            // else if kbhit
            if(kbhit())
            {
                ch = getch();
                if(ch == 27)//open setting with Esc
                {
                    setting();
                    if(sett == 4 || sett == 3) { ch = 27; return;}
                }
                if((ch == 26 && mo_i > 1))//ctrl z
                {
                    mo_i--; mo_j--;
                    clearball();
                    hole[i_last[mo_i]][j_last[mo_j]] = 0;
                    if(rang == 1) rang = 4;
                    else rang = 1;
                    clear_turn();
                    turn();
                }

                if(ch == 23)//cheat code
                {
                    if(cheatcode_win() == 1)
                    return;
                }
                //fillellipse(500,500,60,60);
            }
            getimage(480,205,875,465,Q);
            pause();
            putimage(480,205,Q,0);

        }//finished part 1

        if(ch == 'a' || ch == 'A'|| ch == 'd'|| ch == 'D' )
        {
            if(ch == 'a' || ch == 'A' )
            {
                i--;
                clear_pointer();
                if(i < 1) i = 1;
            }
            else
            {
                i++;
                clear_pointer();
                if(i > i_max) i = i_max;
            }
            i_pointer = i;
            run = 1;
            ch = 60;
        }
        if((ch == 32 || ch == 13) && i >= 1 && i <= i_max)//space to drop ball
        {
            time_limit = 0; u_ = 0; RAN = 1; x_clock = 10; mrhle_clock = 1;
            j=1;
            check_ball(i,j);
            if(win_check(i,j)!=0) { ch = 60; return;}
            clear_turn();
            turn();
            ch = 60;
        }

        drow_clear_setting();//for choosing setting
        //finished part 2
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if((mousex() >= x1_back && mousex() <= x2_back+90 && mousey() >= y1_back && mousey() <= y2_back))
            {
                setting();
                if(sett == 4 || sett == 3) { ch = 27; return;}
            }
        }
        if(ismouseclick(WM_LBUTTONDOWN) || time_limit == LIMIT )//droping ball or time has done
        {
            if(time_limit == LIMIT)
            {
                if(rang == 1) rang = 4;
                else rang = 1;
                clear_turn();
                turn();
                time_limit = 0;
            }
            else
            {
                time_limit = 0; u_ = 0; RAN = 1; x_clock = 10; mrhle_clock = 1;
                if(sett == 1)
                {
                    j=1;
                    x = mousex();
                    if(x>zarib+x_mabda && x<=(i_max+1)*zarib+x_mabda)
                    {
                        i=i_mousex();
                        check_ball(i,j);
                        if(win_check(i,j)!=0) { ch = 60; return;}
                    }
                    clear_turn();
                    turn();
                }
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }//finished par 3

        TIME = clock() - TIME;
        time_function();
    }
    return;
}

void check_ball(int i,int j)//finished
{
    if(j>j_max)
    {
        return;
    }
    if(hole[i][j] == 0)
    {
        if(rang == 1)
        {
            hole[i][j] = 1;
        }
        else
        {
            hole[i][j] = 2;
        }
        if(HALAT == 2)
            {i_last[mo_i] = i; j_last[mo_j] = j ; mo_i++; mo_j++;}
        else
        {
            if(nobat == 1) {i_last[mo_i] = i; j_last[mo_j] = j; mo_i++; mo_j++; nobat++;}
            else {i_last_pc[mo_i_pc] = i; j_last_pc[mo_j_pc] = j; mo_i_pc++; mo_j_pc++; nobat--;}
        }
        drow_ball(i,j);
    }
    else
    {
        check_ball(i,j+1);
    }
}

int win_check(int i, int j)//finished
{
    int r, full = 0;
    if(rang == 1) rang = 2;
    else rang = 1;
    for(i=1; i<=i_max; i++)
    {
        for(j = 1 ; j<=j_max; j++)
        {
        if(hole[i][j]==rang && hole[i+1][j+1]==rang && hole[i+2][j+2]==rang && hole[i+3][j+3]==rang)
            {
                for(r=0 ; r<=3 ; r++)
                    drow_ball_win(i+r,j+r);
                win = rang;
                return rang;
            }
        else if(hole[i][j]==rang && hole[i+1][j-1]==rang && hole[i+2][j-2]==rang && hole[i+3][j-3]==rang)
            {
                for(r=0 ; r<=3 ; r++)
                    drow_ball_win(i+r,j-r);
                win = rang;
                return rang;
            }
        else if(hole[i][j] == rang && hole[i][j-1] == rang && hole[i][j-2] == rang && hole[i][j-3] == rang)
            {
                for(r=0 ; r<=3 ; r++)
                    drow_ball_win(i,j-r);
                win = rang;
                return rang;
            }
        else if(hole[i][j]==rang && hole[i-1][j]==rang && hole[i-2][j]==rang && hole[i-3][j]==rang)
            {
                for(r=0 ; r<=3 ; r++)
                    drow_ball_win(i-r,j);
                win = rang;
                return rang;
            }

        }
    }
    if(rang == 2) rang = 1;
    else rang = 4;
    for(i=1; i<=i_max; i++)
    {
        if(hole[i][j_max]==0) return 0;
        else full++;
    }
    if(full == i_max) {win=3; return 10;}

}

int i_mousex(void)//finished
{
        int x = ((mousex()-x_mabda)/zarib);
        return x;
}

int back_click(void)//finished
{
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        if(mousex() >= x1_back && mousex() <= x2_back && mousey() >= y1_back && mousey() <= y2_back)
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

void time_function(void)//finished
{
    float y = 0;
    int a = 120, b = 500;
    //getimage(60 , 500 , 135 , 548 , N);
    TIME /= 1000;
    sum_time += TIME;
    settextstyle(4,0,4);
    if(sum_time >= 1)
    {
        time_limit++;
        if(time_limit == LIMIT+1) time_limit = 0;
        sec++;
        if(sec == 60)
        {
            sec = 0;
            min_++;
        }
        //printf("%.2d:%.2d\n", min_ , sec);
        setcolor(0);
        setbkcolor(COLOR(253, 124, 15));
        sprintf(msg, "%.2d:%.2d", min_ , sec);
        outtextxy(60, 570 , msg);
        setlinestyle(0,0,3);
        rectangle(57 , 568, 188, 607);
        //putimage(60 , 170 , N , 0);
        setbkcolor(rang);
        if(rang == player_1)
        {
            sprintf(msg2,"%.2d", sec_limit-u_ );
            outtextxy(x_mabda-120, 220 , msg2);
        }
        else
        {
            sprintf(msg2,"%.2d", sec_limit-u_ );
            outtextxy(getmaxx()-x_mabda+58 , 220 , msg2);
        }
        setbkcolor(color_background);
        setcolor(0);//analog clock
        setlinestyle(0,0,4);
        circle(a, b, 60);
        setfillstyle(1, 4);
        fillellipse(a, b, 58, 58);
        if(mrhle_clock == 1)
        {
        y = -sqrt(2500 - x_clock*x_clock);
        line(a, b, a+x_clock , b+y);
        x_clock += 10;
        if(x_clock == 50) mrhle_clock = 2;
        }
        else if(mrhle_clock == 2)
        {
            y = sqrt(2500 - x_clock*x_clock);
            line(a, b, a + x_clock , b+y);
            x_clock -= 10;
            if(x_clock == -50) mrhle_clock = 1;
        }
        u_++;
        if(u_ == LIMIT) {u_ = 0; mrhle_clock = 1; x_clock = 10;}
        sum_time = 0;
    }
}

int cheatcode_win(void)//finished
{
    ch = getch();
    if(ch == 'I' )
    {
        ch = getch();
        if(ch == 'N' ){
        if(HALAT == 1)
        {
            if(player_1 == 1) win = 1;
            else win = 2;
        }
        else
        {
            win = rang;
            if(win == 4) win = 2;
        }
        return 1;}
    }
    return 0;
}

int cheatcode_playmore(void)//finished
{
    ch = getch();
    if(ch == 'L')
    {
        ch = getch();
        if(ch == 'A')
        {
            ch = getch();
            if(ch == 'Y')
            {
                 ch = getch();

                 if(ch == '2')
                    {flag = -2; return 1;}

                 else if(ch == '4')
                    {flag = -4; return 1;}

            }
        }
    }
    return 0;
}
//drowing functions//17up
void loading(void)//finished
{
    int p = 0, q = 0 , qq;
    setbkcolor(0);
    cleardevice();
    setcolor(0);
    setlinestyle(0,0,6);
    settextstyle(6, 0 , 5);
    setcolor(15);
    outtextxy(560 , 280 , "loading...");
    //rectangle(498 , 320 , 800 , 362);
    setcolor(7);
    bar(400 , 340 , 900 , 360);
    setfillstyle(1, 1);
    setcolor(1);
    setcolor(1);
    for(int i = 1; i <= 290; i += 2)
    {
        arc(800, 350, 215, 215 + i, 150);
        delay(2);
    }
    for(int i = 1; i <= 302; i += 2)
    {
        arc(520, 350, 30, 30 + i, 180);
        delay(2);
    }
    for(p = 0; p <= 500 ; p += 10 )
    {
        qq=p/10;
        delay(50-qq);
        delay(10);
        bar(400 , 340 , 400+p , 360);
    }
    delay(1000);
}

void drow_background(void)//finished
{
    int n = 20,i=-1000;
    while(i < getmaxx()+1000)
    {
        setfillstyle(1, COLOR(215,133,63));
        i += n;
        bar(i, 0, i + n, getmaxy()+1000);
        setfillstyle(1, COLOR(210,105,30));
        i += n;
        bar(i, 0, i + n, getmaxy()+1000);
        setfillstyle(1, COLOR(139,69,19));
        i += n;
        bar(i, 0, i + n, getmaxy()+1000);
        setfillstyle(1, COLOR(160,82,45));
        i += n;
        bar(i, 0, i + n, getmaxy()+1000);
    }
}

void drow_board(int length, int width)//finished
{
    int i,j,k=90,n=4;

    for(i=255-zarib ; i<255-zarib/n ; i++)//right
    {
        setcolor(COLOR(i,i-k,0));
        line(i-255+zarib+(i_max+1)*zarib+x_mabda,y_mabda-i+255,i-255+zarib+(i_max+1)*zarib+x_mabda,(j_max+2)*zarib+y_mabda+i-255);
    }

    for(i=255-zarib ; i<255-zarib/n ; i++)//left
    {
        setcolor(COLOR(i,i-k,0));
        line(-i+255+x_mabda,y_mabda-i+255,-i+255+x_mabda,(j_max+2)*zarib+y_mabda+i-255);
    }

    for(i=255-zarib ; i<255-zarib/n ; i++)//down
    {
        setcolor(COLOR(i,i-k,0));
        line(x_mabda-i+255,i-255+zarib+(j_max+1)*zarib+y_mabda,(i_max+2)*zarib+x_mabda+i-254,i-255+zarib+(j_max+1)*zarib+y_mabda);
    }


    setcolor(0);
    setlinestyle(2,5,2);
    setfillstyle(1, 6);
    bar(zarib+x_mabda,zarib+y_mabda,(i_max+1)*zarib+x_mabda,(j_max+1)*zarib+y_mabda);
    setfillstyle(1, color_background);

    for(i=zarib*3/2+x_mabda ; i<=zarib*(i_max+1)-zarib/2+x_mabda ; i+=zarib)
    {
        for(j=zarib*3/2+y_mabda ; j<=zarib*(j_max+1)-zarib/2+y_mabda ; j+=zarib)
        {
            setcolor(0);
            fillellipse(i,j,zarib/2,zarib/2);
        }
    }

    setcolor(0);
    line(x_mabda+zarib,y_mabda+zarib,x_mabda+zarib,y_mabda+(j_max+1)*zarib);//left
    line(x_mabda+(i_max+1)*zarib,y_mabda+zarib,x_mabda+(i_max+1)*zarib,y_mabda+(j_max+1)*zarib);//right
    line(x_mabda+zarib,y_mabda+zarib,x_mabda+(i_max+1)*zarib,y_mabda+zarib);//up
    line(x_mabda+zarib,y_mabda+(j_max+1)*zarib,x_mabda+(i_max+1)*zarib,y_mabda+(j_max+1)*zarib);//down
}

void drow_players(int a)//finished
{
    int R0 = 40;
    setcolor(color_background);
    setfillstyle(1, COLOR(255, 128, 0));
    bar(x_mabda-30,90,x_mabda-150,300);
    bar(getmaxx()-x_mabda+30,90,getmaxx()-x_mabda+150,300);
    setcolor(0);
    rectangle(x_mabda-30,90,x_mabda-150,300);
    rectangle(getmaxx()-x_mabda+30,90,getmaxx()-x_mabda+150,300);
    setcolor(0);
    if(rang == 1)
    {
        setfillstyle(1,4);
        fillellipse(getmaxx()-x_mabda+90,240,R0,R0);
        setfillstyle(1,1);
        fillellipse(x_mabda-90,300-60,R0,R0);
    }
    else
    {
        setfillstyle(1,1);
        fillellipse(getmaxx()-x_mabda+90,300-60,R0,R0);
        setfillstyle(1,4);
        fillellipse(x_mabda-90,300-60,R0,R0);
    }
    setbkcolor(COLOR(255, 128, 0));
    settextstyle(3,0,3);
    if(a == 1)
    {
        setcolor(0);
        outtextxy(x_mabda-145,110,"PLAYER 1");
        outtextxy(getmaxx()-x_mabda+35,110,"PLAYER 2");
    }
    else if(a == 2)
    {
        settextstyle(6,0,4);
        outtextxy(x_mabda-141,110,"YOU");
        settextstyle(6,0,4);
        outtextxy(getmaxx()-x_mabda+62,110,"PC");
    }
}

void drow_ball(int i,int j)//finished
{

    int x_ball = i*zarib+zarib/2+x_mabda , y_ball = y_mabda-zarib/2-3*zarib  , x, y, r, time_local = 35, a = 1;
    x = -500;
    y = -500;
    r = zarib/2;
    setlinestyle(0,0,2);

    getimage(x-r,y-r,x+r,y+r,M);
    int max_y_ball = (j_max+2)*zarib-zarib/2-j*zarib+y_mabda;

    setcolor(0);
    setfillstyle(1,rang);

    while(y_ball <= max_y_ball-zarib)//down1
    {
        putimage(x-r,y-r,M,0);
        //putimage(x_mabda,0,M,0);
        x=x_ball;
        y=y_ball;
        getimage(x-r,y-r,x+r,y+r,M);
        fillellipse(x,y,r,r);
        y_ball+=zarib;
        delay(time_local);
    }
    //Beep(500,100);

    if(j < j_max-1){
    for(int i = 45; i >= 5; i -= 10)
    {
        //putimage(x_mabda,0,M,0);
        putimage(x-r,y-r,M,0);
        x = x_ball;
        y = y_ball;
        getimage(x-r,y-r,x+r,y+r,M);
        fillellipse(x,y,r,r);
        y_ball -= i;
        delay(time_local);
    }
    for(int i = 5; i <= 45; i += 10)
    {
        putimage(x-r,y-r,M,0);
        //putimage(x_mabda,0,M,0);
        x = x_ball;
        y = y_ball;
        getimage(x-r,y-r,x+r,y+r,M);
        fillellipse(x,y,r,r);
        y_ball += i;
        delay(time_local);
    }
    Beep(500,10);
    }

    for(int i = 35; i >= 5; i -= 10)
    {
        putimage(x-r,y-r,M,0);
        //putimage(x_mabda,0,M,0);
        x = x_ball;
        y = y_ball;
        getimage(x-r,y-r,x+r,y+r,M);
        setcolor(0);
        setfillstyle(1,rang);
        fillellipse(x,y,r,r);
        y_ball -= i;
        delay(time_local);
    }
    for(int i = 5; i <= 45; i += 10)
    {
        putimage(x-r,y-r,M,0);
        //putimage(x_mabda,0,M,0);
        x = x_ball;
        y = y_ball;
        getimage(x-r,y-r,x+r,y+r,M);
        setcolor(0);
        setfillstyle(1,rang);
        fillellipse(x,y,r,r);
        y_ball += i;
        delay(time_local);
    }
    Beep(500,10);
    if(rang == 1) rang = 4;
    else rang = 1;
    return;
}

void drow_ball_win(int i, int j)//finished
{
    int x_ball,y_ball;
    x_ball = i*zarib+zarib/2+x_mabda;
    y_ball = (j_max+2)*zarib-zarib/2-j*zarib+y_mabda;
    setlinestyle(1,0,7);
    setcolor(2);
    circle(x_ball,y_ball,zarib/2);
    return;
}

void drow_menu(void)//finished
{
    setcolor(0);
    settextstyle(6,0,7);
    outtextxy(LENGTH/4-40,WIDTH/5," (; \"4 IN a ROW\" :D");
    setcolor(0);
    setfillstyle(1,COLOR(253, 124, 15));
    setlinestyle(0,0,5);

    int x_bar1=LENGTH/4+100,y_bar1=WIDTH/5+100,x_bar2=LENGTH-(LENGTH/4+100),y_bar2=WIDTH/5+100;
    int x_bar11=LENGTH/2-10 ,y_bar11=3*WIDTH/5+100 ,x_bar22=LENGTH-(LENGTH/2-10) ,y_bar22=3*WIDTH/5+100 ;
    int x=(x_bar11-x_bar1) ,y=(y_bar11-y_bar1);

    rectangle(x_bar1,y_bar1,x_bar11,y_bar11);
    bar(x_bar1,y_bar1,x_bar11,y_bar11);//one player
    rectangle(x_bar2+95,y_bar2,x_bar22,y_bar22);
    bar(x_bar2+95,y_bar2,x_bar22,y_bar22);//two player
    setcolor(0);
    setlinestyle(0,0,4);
    setfillstyle(1,0);

    arc(x_bar1+x/2+1, y_bar11-100,0,180, (x-60)/2+1);
    line(x_bar1+30,y_bar11-20,x_bar11-30,y_bar11-20);//down
    line(x_bar1+30, y_bar11-100, x_bar1+30, y_bar11-20);
    line(x_bar11-30, y_bar11-100, x_bar11-30, y_bar11-20);
    circle(x_bar1+x/2 , y_bar11-211 , 40);
    x_bar1+=225;
    x_bar11+=225;
    arc(x_bar1+x/2+1, y_bar11-100,0,180, (x-60)/2+1);
    line(x_bar1+30,y_bar11-20,x_bar11-30,y_bar11-20);//down
    line(x_bar1+30, y_bar11-100, x_bar1+30, y_bar11-20);
    line(x_bar11-30, y_bar11-100, x_bar11-30, y_bar11-20);
    circle(x_bar1+x/2 , y_bar11-211 , 40);
    x_bar1+=100;
    x_bar11+=100;
    arc(x_bar1+x/2+1, y_bar11-100,0,180, (x-60)/2+1);
    line(x_bar1+30,y_bar11-20,x_bar11-30,y_bar11-20);//down
    line(x_bar1+30, y_bar11-100, x_bar1+30, y_bar11-20);
    line(x_bar11-30, y_bar11-100, x_bar11-30, y_bar11-20);
    circle(x_bar1+x/2 , y_bar11-211 , 40);
    x_bar1-=100;
    x_bar11-=100;
    setfillstyle(1,COLOR(253, 124, 15));
    fillellipse(x_bar1+x/2+1, y_bar11-100, (x-60)/2+1, (x-60)/2+1);
    bar(x_bar11-32,y_bar11-100,x_bar1+32,y_bar11-22);
    x_bar1-=225;
    x_bar11-=225;
    x1_one_player = x_bar1, x2_one_player = x_bar11, y1_one_player = y_bar1, y2_one_player = y_bar11;
    x1_two_player = x_bar2+95, x2_two_player = x_bar22, y1_two_player = y_bar2, y2_two_player = y_bar22;
    int jab=x1_two_player;
    x1_two_player = x2_two_player;
    x2_two_player = jab;
}

void drow_back(void)//finished
{
    setfillstyle(1, COLOR(253, 124, 15));//back click
    bar(x1_back, y1_back, x2_back, y2_back);
    setlinestyle(0, 0, 6);
    setcolor(0);
    rectangle(x1_back, y1_back, x2_back, y2_back);
    settextstyle(4,0,4);
    setbkcolor(COLOR(253, 124, 15));
    outtextxy(x1_back+4, y1_back+6, "Menu");
    setbkcolor(color_background);
}

void drow_setting(void)//finished
{
    setfillstyle(1, COLOR(253, 124, 15));//SETTING
    bar(x1_back, y1_back, x2_back+90, y2_back);
    setlinestyle(0, 0, 6);
    setcolor(0);
    rectangle(x1_back, y1_back, x2_back+90, y2_back);
    settextstyle(4,0,4);
    setbkcolor(COLOR(253, 124, 15));
    outtextxy(x1_back+4, y1_back+6, "SETTING");
    setbkcolor(color_background);
}

void drow_clear_setting(void)//finished
{
   if(mousex() >= x1_back && mousex() <= x2_back+90 && mousey() >= y1_back && mousey() <= y2_back)
   {
        setcolor(7);
        rectangle(x1_back, y1_back, x2_back+90, y2_back);
   }
   else
   {
        setcolor(0);
        rectangle(x1_back, y1_back, x2_back+90, y2_back);
   }
}

void clearball(void)//finished
{
    setlinestyle(0, 0 , 2);
    setfillstyle(1,color_background);
    if(mo_i > 0)fillellipse(i_last[mo_i]*zarib+zarib/2+x_mabda, (j_max+2)*zarib-zarib/2-j_last[mo_j]*zarib+y_mabda , zarib/2 , zarib/2);
    if(HALAT == 1 && mo_i > 0)
                fillellipse(i_last_pc[mo_i_pc]*zarib+zarib/2+x_mabda, (j_max+2)*zarib-zarib/2-j_last_pc[mo_j_pc]*zarib+y_mabda , zarib/2 , zarib/2);

}

void score_board(void)//finished
{
    char k1[100] , k2[100];
        setcolor(0);
        rectangle(560,250,790,355);
        setfillstyle(1, COLOR(253, 124, 15));
        bar(560,250,790,355);
        settextstyle(3,0,3);
        //ch = getch();
        setbkcolor(COLOR(253, 124, 15));
        sprintf(k1,"player 1 :  %d", win_player1);
        outtextxy(615, 252 , k1);
        sprintf(k2,"player 2 :  %d", win_player2);
        outtextxy(615, 300 , k2);
        clearmouseclick(WM_LBUTTONDOWN);
        while(!kbhit())
        {
            if(ismouseclick(WM_LBUTTONDOWN)) break;
        }
        clearmouseclick(WM_LBUTTONDOWN);
}

void item_choose(int a)//finished
{
    int x = x2_one_player-x1_one_player;
    setcolor(7);
    setlinestyle(0,0,6);
    if(a == 1)
    {
        if(mousey() <= y2_one_player && mousey() >= y1_one_player)
        {
            if(mousex() <= x2_one_player && mousex() >= x1_one_player)
            {
                rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
            }
            if(mousex() <= x2_two_player && mousex() >= x1_two_player)
            {
                rectangle(x1_two_player,y1_two_player,x2_two_player,y2_two_player);
            }
        }
        else if(mousex() >= x1_back && mousex() <= x2_back && mousey() >= y1_back && mousey() <= y2_back)
        {
            rectangle(x1_back, y1_back, x2_back, y2_back);
        }
    }
    else if(a == 2)
    {
        if(mousey() <= y2_one_player && mousey() >= y1_one_player)
        {
            if(mousex() <= x2_one_player && mousex() >= x1_one_player)
            {
                rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
            }
            if(mousex() <= x1_two_player+x && mousex() >= x1_two_player)
            {
                rectangle(x1_two_player, y1_two_player, x1_two_player+x, y2_two_player);
            }
        }
        else if(mousex() >= x1_back && mousex() <= x2_back && mousey() >= y1_back && mousey() <= y2_back)
        {
            rectangle(x1_back, y1_back, x2_back, y2_back);
        }
    }
    else if(a == 3)
    {
        if(mousex() < x2_level && mousex() > x1_level)
        {
            if(mousey() <= y1_2 && mousey() >= y1_1)
            {
                rectangle(x1_level, y1_1, x2_level, y1_2);
            }
            else if(mousey() <= y2_2 && mousey() >= y2_1)
            {
               rectangle(x1_level, y2_1, x2_level, y2_2);
            }
            else if(mousey() <= y3_2 && mousey() >= y3_1)
            {
                rectangle(x1_level, y3_1, x2_level, y3_2);
            }
        }
        else if(mousex() >= x1_back && mousex() <= x2_back && mousey() >= y1_back && mousey() <= y2_back)
        {
            rectangle(x1_back, y1_back, x2_back, y2_back);
        }
    }
}

void clear_item_choose(int a)//finished
{
    int x = x2_one_player-x1_one_player;
    setcolor(0);
    setlinestyle(0,0,6);
    if(a == 1)
    {
        if(mousey() <= y2_one_player && mousey() >= y1_one_player)
        {
            if(mousex() > x2_one_player || mousex() < x1_one_player)
            {
                rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
            }
            if(mousex() > x2_two_player || mousex() < x1_two_player)
            {
                rectangle(x1_two_player,y1_two_player,x2_two_player,y2_two_player);
            }
        }
        else
        {
            rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
            rectangle(x1_two_player,y1_two_player,x2_two_player,y2_two_player);
            if(!(mousex() >= x1_back && mousex() <= x2_back && mousey() >= y1_back && mousey() <= y2_back))//back
            {
              rectangle(x1_back, y1_back, x2_back, y2_back);//back
            }
        }
    }
    else if(a == 2)
    {
        if(mousey() <= y2_one_player && mousey() >= y1_one_player)
        {
            if(mousex() > x2_one_player || mousex() < x1_one_player)
            {
                rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
            }
            if(mousex() > x1_two_player+x || mousex() < x1_two_player)
            {
                rectangle(x1_two_player,y1_two_player,x1_two_player+x,y2_two_player);
            }
            rectangle(x1_back, y1_back, x2_back, y2_back);//back
        }
        else
        {
            rectangle(x1_one_player,y1_one_player,x2_one_player,y2_one_player);
            rectangle(x1_two_player,y1_two_player,x1_two_player+x,y2_two_player);
            if(!(mousex() >= x1_back && mousex() <= x2_back && mousey() >= y1_back && mousey() <= y2_back))//back
            {
              rectangle(x1_back, y1_back, x2_back, y2_back);//back
            }
        }
    }
    else if(a == 3)
    {
        if(mousex() < x2_level && mousex() > x1_level)
        {
            if(mousey() > y1_2 || mousey() < y1_1)
            {
                rectangle(x1_level, y1_1, x2_level, y1_2);
            }
            if(mousey() > y2_2 || mousey() < y2_1)
            {
               rectangle(x1_level, y2_1, x2_level, y2_2);
            }
            if(mousey() > y3_2 || mousey() < y3_1)
            {
                rectangle(x1_level, y3_1, x2_level, y3_2);
            }
            rectangle(x1_back, y1_back, x2_back, y2_back);//back
        }
        else
        {
            rectangle(x1_level, y1_1, x2_level, y1_2);
            rectangle(x1_level, y2_1, x2_level, y2_2);
            rectangle(x1_level, y3_1, x2_level, y3_2);
            if(!(mousex() >= x1_back && mousex() <= x2_back && mousey() >= y1_back && mousey() <= y2_back))//back
            {
              rectangle(x1_back, y1_back, x2_back, y2_back);//back
            }
        }
    }

}

void turn(void)//FINISHED
{
    int R0 = 40;
        setcolor(COLOR(200,255,255));
        setlinestyle(1,0,3);
        if(rang == 1)
        {
            if(player_1 == 1 ) circle(x_mabda-90,300-60,R0);
            else circle(getmaxx()-x_mabda+90,300-60,R0);
        }
        else
        {
            if(player_1 == 1 ) circle(getmaxx()-x_mabda+90,300-60,R0);
            else circle(x_mabda-90,300-60,R0);
        }
}

void clear_turn(void)//FINISHED
{
    int R0 = 40;
        setcolor(0);
        setlinestyle(1,0,3);
        if(rang==4)
        {
            if(player_1 == 1 )circle(x_mabda-90,300-60,R0);
            else circle(getmaxx()-x_mabda+90,300-60,R0);
        }
        else
        {
            if(player_1 == 1) circle(getmaxx()-x_mabda+90,300-60,R0);
            else circle(x_mabda-90,300-60,R0);
        }
}

void pointer(int i)//finished
{
        if(i < 1 || i > i_max) return;
        i_pointer = i;
        if(rang == 1)
            setcolor(1);
        else
            setcolor(4);
        setlinestyle(1,1,2);
        for(int r=0 ; zarib/5>r ; r++)
        {
            line(x_mabda+i_pointer*zarib+zarib/2-zarib/5+r , zarib+y_mabda-zarib/5-10+r , x_mabda+i_pointer*zarib+zarib/2+zarib/5-r , zarib+y_mabda-zarib/5-10+r);//up
        }
}

void clear_pointer(void)//finished
{
    getimage(x_mabda+i_pointer*zarib+zarib/2-zarib/4 , zarib+y_mabda-zarib , x_mabda+i_pointer*zarib+zarib/2+zarib/4 , zarib+y_mabda-4*zarib/5+5 , M);
    putimage(x_mabda+i_pointer*zarib+zarib/2-zarib/4 , zarib+y_mabda-zarib/4-10 , M , 0);
}

void pause(void)//finished
{
    if(ch == 'p' || ch == 'P')
            {
                setfillstyle(1, COLOR(253, 124, 15));
                bar(485,210,870,460);
                setcolor(0);
                setlinestyle(0,0,2);
                rectangle(485,210,870,460);
                settextstyle(6,0,6);
                setbkcolor(COLOR(253, 124, 15));
                outtextxy(555, 300, "PAUSE");
                setbkcolor(color_background);
                while(1)
                {
                    if(kbhit())
                    {ch = getch();}
                    if(ch == 'r' || ch =='R' || ismouseclick(WM_RBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        clearmouseclick(WM_RBUTTONDOWN);
                        break;
                    }
                }
            }
}

void show_winner(void)//FINISHED
{
    settextstyle(6,0,5);
    setcolor(9);
    if(win==1)
    {
       if(HALAT == 2 )
       {
            if(player_1 == 1) outtextxy(getmaxx()/2-170,getmaxy()-80,"player 1 won!");
            else outtextxy(getmaxx()/2-170,getmaxy()-80,"player 2 won!");
       }
       else if(HALAT == 1)
       {
            if(player_1 == 1) outtextxy(getmaxx()/2-170,getmaxy()-80," YOU won! ;)");
            else outtextxy(getmaxx()/2-170,getmaxy()-80," YOU LOST ;(!");
       }
    }
    else if(win == 2)
    {
        if(HALAT == 2 )
            {
                if(player_1 == 1) outtextxy(getmaxx()/2-170,getmaxy()-80,"player 2 won!");
                else outtextxy(getmaxx()/2-170,getmaxy()-80,"player 1 won!");
            }
        else if(HALAT == 1)
        {
            if(player_1 == 1 ) outtextxy(getmaxx()/2-170,getmaxy()-80," YOU LOST! ;(");
            else outtextxy(getmaxx()/2-165,getmaxy()-80," YOU won! :)");
        }
    }
    else
    {
        outtextxy(getmaxx()/2-170,getmaxy()-80,"No Winner!;(");
    }
}

void setting(void)//finished
{
        getimage(300,160,900,600,Setting);
        setcolor(0);
        rectangle(550,162,800,550);
        setfillstyle(1, COLOR(253, 124, 15));
        bar(550,162,800,550);
        settextstyle(3,0,3);
        setbkcolor(COLOR(253, 124, 15));
        outtextxy(630, 185 , "Resume");
        outtextxy(610, 270 , "Score Board");
        outtextxy(600, 365 , "Back TO Menu");
        outtextxy(620, 460 , "Exit Game");

        clearmouseclick(WM_LBUTTONDOWN);
        while(1)
        {
            if(mousex() >= 560 && mousex() <= 790 && mousey() >= 175 && mousey() <= 260)//Resume
                {
                    setcolor(7);
                    outtextxy(630, 185 , "Resume");
                    setcolor(0);
                    outtextxy(610, 270 , "Score Board");
                    outtextxy(600, 365 , "Back TO Menu");
                    outtextxy(620, 460 , "Exit Game");
                }
                else if(mousex() >= 560 && mousex() <= 790 && mousey() >= 270 && mousey() <= 355)//Score board
                {
                    setcolor(7);
                    outtextxy(610, 270 , "Score Board");
                    setcolor(0);
                    outtextxy(630, 185 , "Resume");
                    outtextxy(600, 365 , "Back TO Menu");
                    outtextxy(620, 460 , "Exit Game");
                }
                else if(mousex() >= 560 && mousex() <= 790 && mousey() >= 365 && mousey() <= 450)//Back to menu
                {
                    setcolor(7);
                    outtextxy(600, 365 , "Back TO Menu");
                    setcolor(0);
                    outtextxy(630, 185 , "Resume");
                    outtextxy(610, 270 , "Score Board");
                    outtextxy(620, 460 , "Exit Game");
                }
                else if(mousex() >= 560 && mousex() <= 790 && mousey() >= 460 && mousey() <= 545)//Exis game
                {
                    setcolor(7);
                    outtextxy(620, 460 , "Exit Game");
                    setcolor(0);
                    outtextxy(630, 185 , "Resume");
                    outtextxy(600, 365 , "Back TO Menu");
                    outtextxy(610, 270 , "Score Board");
                }

            if(kbhit())
            {
                ch = getch();
                if(ch == 27 || ch == 'R' || ch == 'r')
                {
                    sett = 1; ch = 60; break;
                }
            }
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                if(mousex() >= 560 && mousex() <= 790 && mousey() >= 175 && mousey() <= 260)//Resume
                {
                    sett = 1;
                    break;
                }
                else if(mousex() >= 560 && mousex() <= 790 && mousey() >= 270 && mousey() <= 355)//Score board
                {
                    score_board();
                    sett = 1;
                    break;
                }
                else if(mousex() >= 560 && mousex() <= 790 && mousey() >= 365 && mousey() <= 450)//Back to menu
                {
                    sett = 3;
                    break;
                }
                else if(mousex() >= 560 && mousex() <= 790 && mousey() >= 460 && mousey() <= 545)//Exis game
                {
                    sett = 4;
                    break;
                }

            }
        }
        putimage(300,160,Setting ,0);
        clearmouseclick(WM_LBUTTONDOWN);

    return ;
}

void winner_party(void)//finished
{
    int x,y,color1;

    setlinestyle(0,0,10);
    srand(time(0));
    char m[20000];
    clearmouseclick(WM_LBUTTONDOWN);
    if(win != player_2 || HALAT == 2)
    {
        while(!kbhit())
        {
            if(ismouseclick(WM_LBUTTONDOWN)) break;
            outtextxy(220, 150 , "PRESS ANY KEY TO CONTINUE");
            color1 = rand()%15+1;
            setcolor(color1);
            circle(rand()%1361,rand()%701,1);
            delay(10);
        }
    }
    else
    {
        while(!kbhit())
        {
            if(ismouseclick(WM_LBUTTONDOWN)) break;
            color1 = rand()%15+1;
            setcolor(color1);
            outtextxy(220, 150 , "PRESS ANY KEY TO CONTINUE");
            delay(1000);
        }
    }
    clearmouseclick(WM_LBUTTONDOWN);
    return;
}
//end of drowing functions//22+17up
// AI
int PC_1(void)//finished
{
    int a[500] = {}, t = 1, columnpc = 0, random;
    for(int p = 1 ; p <= i_max ; p++)
    {
        if(hole[p][j_max] == 0)
        {
            a[t] = p;
            t++;
        }
    }
    random = rand()%(t-1)+1;
    columnpc = a[random];
    if(level != 3) printf("random\n");
    return columnpc;
}

int PC_2(void)//finished
{
    int a = 0;
    if(player_1 == 4) player_1 = 2;
    for(int i = 1 ; i <= i_max ; i++)//win
    {
        a = check_ball_AI(i , 1);
        if( a!= 0)
        {
            win_check_AI(1);
            if(win_AI != 0)
            {
                if(win_AI != player_1)
                {
                    hole[i][a] = 0;
                    printf("wiin");
                    if(player_1 == 2) player_1 = 4;
                    return i;
                }
            }
        }
        hole[i][a] = 0;
    }
    win_AI = 0;
    if(rang == 1) rang = 4;
    else rang = 1;
    for(int i = 1 ; i <= i_max ; i++)//block
    {
        a = check_ball_AI(i , 1);
        if(a!= 0)
        {
            win_check_AI(1);
            if(win_AI != 0)
            {
                if(player_1 == 4) player_1 = 2;
                if(win_AI == player_1)
                {
                    hole[i][a] = 0;
                    printf("block\n");
                    if(rang == 4) rang = 1;
                    else rang = 4;
                    if(player_1 == 2) player_1 = 4;
                    return i;
                }
                if(player_1 == 2) player_1 = 4;
            }
        }
        hole[i][a] = 0;
    }
    if(rang == 4) rang = 1;
    else rang = 4;
    if(player_1 == 2) player_1 = 4;
    return PC_1();
}

int PC_3(void)//finished
{
    int a = 0;
    if(player_1 == 4) player_1 = 2;
    for(int i = 1 ; i <= i_max ; i++)//win
    {
        a = check_ball_AI(i , 1);
        if( a!= 0)
        {
            win_check_AI(1);
            if(win_AI != 0)
            {
                if(win_AI != player_1)
                {
                    hole[i][a] = 0;
                    printf("win\n");
                    if(player_1 == 2) player_1 = 4;
                    return i;
                }
            }
        }
        hole[i][a] = 0;
    }
    win_AI = 0;
    if(rang == 1) rang = 4;
    else rang = 1;
    for(int i = 1 ; i <= i_max ; i++)//block
    {
        a = check_ball_AI(i , 1);
        if(a!= 0)
        {
            win_check_AI(1);
            if(win_AI != 0)
            {
                if(player_1 == 4) player_1 = 2;
                if(win_AI == player_1)
                {
                    hole[i][a] = 0;
                    printf("block\n");
                    if(rang == 4) rang = 1;
                    else rang = 4;
                    if(player_1 == 2) player_1 = 4;
                    return i;
                }
                if(player_1 == 2) player_1 = 4;
            }
        }
        hole[i][a] = 0;
    }

    if(player_1 == 4) player_1 = 2;

    for(int e = 2; e <= i_max-3; e++)
    {
        if(hole[e][1] == player_1 && hole[e+1][1] == player_1 && hole[e+2][1] == 0 && hole[e-1][1] == 0)
        {
            printf("e\n");
            if(rang == 4) rang = 1;
            else rang = 4;

            if(player_1 == 2) player_1 = 4;
            if(hole[e+3][1] == 0) return e+2;
            else return e-1;
        }
    }
    int r=1, hard=5;;
    while(r <= hard)
    {
        //hoosh();
        r++;
    }
    int i = 1, k = 0;
    ST = 2;
    while(1)//check one step forward
    {

        k++;
        i = PC_1();
        a = check_ball_AI(i , 1);
        if(a != 0)
        {
            hole[i][a] = 0;

            hole[i][a+1] = player_1;
            if(win_check_AI(1) == 0)
            {
                printf("yes\n");
                if(rang == 4) rang = 1;
                else rang = 4;
                if(player_1 == 2) player_1 = 4;
                hole[i][a+1] = 0;
                hole[i][a] = 0;
                ST = 3;
                return i;
            }
            printf("i=%d\nnot%d\n", i, k);
        }
        hole[i][a+1] = 0;
        hole[i][a] = 0;
        i++;
        if(k == 20)
        {
            if(rang == 4) rang = 1;
            else rang = 4;
            if(player_1 == 2) player_1 = 4;
            break;
        }
    }
    ST = 3;
    printf("Random\n");
    return PC_1();


}

int check_ball_AI(int i,int j)//finished
{
    if(j>j_max)
    {
        return 0;
    }
    if(hole[i][j] == 0)
    {
        if(rang == 1)
        {
            if(ST == 3) hole[i][j] = 1;
            return j;
        }
        else
        {
            if(ST == 3) hole[i][j] = 2;
            return j;

        }
    }
    else
    {
        return check_ball_AI(i,j+1);
    }
}

int win_check_AI(int t)//finished
{
    int r, j ,i;
    if(t == 1)
    {
        if(rang == 4) rang = 2;}
    else
    {
        if(rang == 4) rang = 1;
        else rang = 2;
    }
    for(i=1; i<=i_max; i++)
    {
        for(j = 1 ; j<=j_max; j++)
        {
        if(hole[i][j]==rang && hole[i+1][j+1]==rang && hole[i+2][j+2]==rang && hole[i+3][j+3]==rang)
        {
                win_AI = rang;
                if(t == 1)
                {
                    if(rang == 2) rang = 4;
                }
                else
                {
                    if(rang == 1) rang = 4;
                    else rang = 1;
                }
                return i;
        }
        else if(hole[i][j]==rang && hole[i+1][j-1]==rang && hole[i+2][j-2]==rang && hole[i+3][j-3]==rang)
        {
                win_AI = rang;
                if(t == 1)
                {
                    if(rang == 2) rang = 4;
                }
                else
                {
                    if(rang == 1) rang = 4;
                    else rang = 1;
                }
                return i;
        }
        else if(hole[i][j] == rang && hole[i][j-1] == rang && hole[i][j-2] == rang && hole[i][j-3] == rang)
        {
                win_AI = rang;
                if(t == 1)
                {
                    if(rang == 2) rang = 4;
                }
                else
                {
                    if(rang == 1) rang = 4;
                    else rang = 1;
                }
                return i;
        }
        else if(hole[i][j]==rang && hole[i-1][j]==rang && hole[i-2][j]==rang && hole[i-3][j]==rang)
        {
                win_AI = rang;
                if(t == 1)
                {
                    if(rang == 2) rang = 4;
                }
                else
                {
                    if(rang == 1) rang = 4;
                    else rang = 1;
                }
                return i;
            }

        }
    }

    if(t == 1)
    {
        if(rang == 2) rang = 4;
    }
    else
    {
        if(rang == 1) rang = 4;
        else rang = 1;
    }
    return 0;
}

//void AI_PC(int bar)
//{
//    int turn_AI = 0, t = 2;
//    if(bar == )
//    for(int i=1; i <= i_max; i++)
//    {
//        if(t == 1) t = 2;
//        else t = 1;
//        turn_AI = change(t);
//        check_AI(i, 1, 2);
//        if(win_AI == 1) return i;
//        AI_PC(bar+1);
//    }
//}
//int win_AI(int t)
//{
//    for(int i=1; i<=i_max; i++)
//    {
//        for(int j = 1 ; j<=j_max; j++)
//        {
//        if(hole[i][j]==t && hole[i+1][j+1]==t && hole[i+2][j+2]==t && hole[i+3][j+3]==t)
//        {
//                return 1;
//        }
//        else if(hole[i][j]==t && hole[i+1][j-1]==t && hole[i+2][j-2]==t && hole[i+3][j-3]==t)
//        {
//                return 1;
//        }
//        else if(hole[i][j] == t && hole[i][j-1] == t && hole[i][j-2] == t && hole[i][j-3] == t)
//        {
//                return 1;
//        }
//        else if(hole[i][j]==t && hole[i-1][j]==t && hole[i-2][j]==t && hole[i-3][j]==t)
//        {
//                return 1;
//            }/////////////////
//
//        }
//    }
//    return 0;
//}
//int check_AI(int i, int j, int k)
//{
//    if(j>j_max)
//    {
//        return 0;
//    }
//    if(hole[i][j] == 0)
//    {
//        if(rang == 1)
//        {
//            if(k == 2) hole[i][j] = 1;
//            A_AI[]
//            return j;
//        }
//        else
//        {
//            if(k == 2) hole[i][j] = 2;
//            return j;
//        }
//    }
//    else
//    {
//        return check_AI(i, j+1, k);
//    }
//}
