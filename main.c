#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>



const int startMapX=0;
const int startMapY=0;

//const int height = 25 ;
//const int width = 81 ;

const int rows = 8 ;
const int columns = 20 ;

struct person
{
    char phone[15],name[30] ;
};

struct car
{
    int x,y ;
    char Tpname[10];
    int Tpcoe ;
    struct person driver ;
    char pelak[4];
    int carNumber;
} carlist[18];

struct point
{

    int x,y;


};

struct homeMap
{

    struct point position ;
    bool isFilled ;


} board[8][20];



void gotoxy(int x,int y)
{
    HANDLE consoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorCOORD;
    cursorCOORD.X=x;
    cursorCOORD.Y=y;
    SetConsoleCursorPosition(consoleHandle, cursorCOORD);

}


void setTextColor(int textColor,int backColor)
{
    //backColor=0;
    HANDLE consoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute= ((backColor&0x0F)<<4) + (textColor&0x0F);
    SetConsoleTextAttribute(consoleHandle,colorAttribute);
    return;
}

void loadMap(char name[10])
{

    FILE *fptr;
    char c;
    fptr = fopen(name, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);




}


void delay(int milliseconds)
{
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void initMapData(struct homeMap board[8][columns])
{

    int xPosition = 0 ;
    int yPosition = 0 ;
    for (int i = 0 ; i <rows ; i++ )
    {

        yPosition = i*3 + 2;
        //xPosition = 1 ;
        for(int j = 0 ; j < columns ; j++)
        {

            board[i][j].isFilled = false ;
            board[i][j].position.x = j*4 + 1 ;
            board[i][j].position.y = yPosition ;

        }
    }






}
void initCarData(struct car carlist[18])
{
    srand((time(NULL)));
    char nameDrivers[18][30]=
    {
        "ali ebrahimi",
        "alireza akbari",
        "reza hassani",
        "farhad gholami",
        "amir azami",
        "bahram noori",
        "mohammad asgari",
        "reza bahrami",
        "saber abari",
        "hamed mohammadi",
        "ali mostafaei",
        "hassan beigi",
        "amir rezaei",
        "gholam koohestani",
        "hamed ahmadi",
        "ahmad sadeghi",
        "akbar mahmoodi",
        "ali meshkini",
    };
    char phoneDrivers[18][15]=
    {
        "09011234567",
        "09154587652",
        "09365678941",
        "09127963245",
        "09022389762",
        "09158974653",
        "09127895634",
        "09247965432",
        "09019876435",
        "09876543987",
        "09034586721",
        "09157418956",
        "09039658742",
        "09157536985",
        "09758536974",
        "09157542395",
        "09369563675",
        "09018659423",
    };
    char carName[3][10]=
    {
        "pride",
        "peju",
        "perado",
    };
    int carCoe[3]=
    {
        1,
        2,
        3,
    };
    char pelakCar[18][4]=
    {
        "  1",
        "  2",
        "  3",
        "  4",
        "  5",
        "  6",
        "  7",
        "  8",
        "  9",
        " 10",
        " 11",
        " 12",
        " 13",
        " 14",
        " 15",
        " 16",
        " 17",
        " 18",
    };
    int carNumber[18]=
    {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12,
        13,
        14,
        15,
        16,
        17,
        18,
    };
    for(int i=0; i<18; i++)
    {

        strcpy (carlist[i].driver.name, nameDrivers[i]);
        strcpy(carlist[i].driver.phone, phoneDrivers[i]);
        carlist[i].x=0;
        carlist[i].y=0;
        strcpy (carlist[i].pelak, pelakCar[i]);
        carlist[i].carNumber =carNumber[i];





        int num = (rand() % (2 - 0 + 1)) + 0;
        switch (num)
        {
        case 0:
            strcpy( carlist[i].Tpname,carName[0]);
            carlist[i].Tpcoe=carCoe[0];
            break;
        case 1:
            strcpy( carlist[i].Tpname,carName[1]);
            carlist[i].Tpcoe=carCoe[1];
            break;
        case 2:
            strcpy( carlist[i].Tpname,carName[2]);
            carlist[i].Tpcoe=carCoe[2];
            break;
        }
    }

}
void placeCar(struct car carlist[18],struct homeMap board[8][columns])
{
    int i=0;
    int k,g;
    int row,column;
    int remain,result;
    bool areCarsPlace=false;
    srand((time(NULL)));
    while (areCarsPlace!=true)
    {

        row = (rand() % (7 - 0 + 1)) + 0;

        column = (rand() % (19 - 0 + 1)) + 0;
        if (board[row][column].isFilled == false)
        {

            carlist[i].x=board[row][column].position.x;
            carlist[i].y=board[row][column].position.y;
            board[row][column].isFilled = true;
            i++;


        }


        if(i==18)
        {
            areCarsPlace=true;
        }




    }
}

void drawCars(struct car carlist[18])
{
    for(int i=0; i<18; i++)
    {

        gotoxy(carlist[i].x,carlist[i].y);
        setTextColor(0,14);
        printf("%s",carlist[i].pelak);
        setTextColor(7,0); //baraye bargardandan rang default console

    }
}
void printSpace(int x,int y)
{
    gotoxy(x,y);
    printf("   ");
}
void printCar(char carPelak[4], int x, int y)
{
    gotoxy(x,y);
    setTextColor(0,14);
    printf("%s",carPelak);
    setTextColor(7,0);

}

void randomPlaceCars(struct car carlist[18],struct homeMap board[8][columns])
{

    int i;
    int state;
    int row;
    int column;
    for(i=0; i<18; i++)
    {
        state = (rand() % (9 - 1 + 1)) + 1;
        switch(state)
        {
        case 1: // jabeja nashavad
            break;
        case 2: // 1 sotoon be aghab

            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row][column-1].isFilled==false)
            {
                if(column-1>=0 )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row][column-1].position.x;
                    carlist[i].y=board[row][column-1].position.y;
                    board[row][column-1].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);

                }
            }
            break;
        case 3 : // 1 radif aghab & 1 sotoon bala
            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row-1][column-1].isFilled==false)
            {
                if(column-1>=0  && row-1>=0 )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row-1][column-1].position.x;
                    carlist[i].y=board[row-1][column-1].position.y;
                    board[row-1][column-1].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);

                }
            }
            break;
        case 4 : //1 radif aghab & 1 sotoon payin
            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row+1][column-1].isFilled==false)
            {
                if(column-1>=0  && row+1<=7 )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row+1][column-1].position.x;
                    carlist[i].y=board[row+1][column-1].position.y;
                    board[row+1][column-1].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);

                }
            }
            break;
        case 5 : //1 sotoon bala
            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row-1][column].isFilled==false)
            {
                if(row-1>=0  )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row-1][column].position.x;
                    carlist[i].y=board[row-1][column].position.y;
                    board[row-1][column].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);

                }
            }
            break;
        case 6 : //1 sotoon bala & 1 radif jolo
            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row-1][column+1].isFilled==false)
            {
                if(column+1<=19 && row-1>=0  )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row-1][column+1].position.x;
                    carlist[i].y=board[row-1][column+1].position.y;
                    board[row-1][column+1].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);

                }
            }
            break;
        case 7 ://1 radif jolo
            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row][column+1].isFilled==false)
            {
                if( column+1<=19  )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row][column+1].position.x;
                    carlist[i].y=board[row][column+1].position.y;
                    board[row][column+1].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);

                }
            }
            break;
        case 8 : //1 radif paein & 1 sotoon jolo
            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row+1][column+1].isFilled==false)
            {
                if(column+1<=19  && row+1<=7 )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row+1][column+1].position.x;
                    carlist[i].y=board[row+1][column+1].position.y;
                    board[row+1][column+1].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);

                }
            }
            break;

        case 9 ://1 radif paein

            column=(carlist[i].x -1) / 4;
            row=(carlist[i].y - 2) /3;
            if(board[row+1][column].isFilled==false)
            {
                if(  row+1<=7 )
                {
                    board[row][column].isFilled=false;
                    printSpace(board[row][column].position.x,board[row][column].position.y);
                    carlist[i].x=board[row+1][column].position.x;
                    carlist[i].y=board[row+1][column].position.y;
                    board[row+1][column].isFilled=true;
                    printCar(carlist[i].pelak,carlist[i].x,carlist[i].y);
                }
            }

            break;
        default :
            break;


        }

    }







}
void setBeginAndEnd(struct car carlist[18],struct homeMap board[8][columns])
{
    char key;
    int keyNum;
    key=getch();
    keyNum= (int) key;
    gotoxy(carlist[17].x,carlist[17].y);
    int row,column;

    column=(carlist[17].x -1) / 4;
    row=(carlist[17].y - 2) /3;

    bool isBeginSet=false;
    bool isDistSet=false;
    int distLocationRow=0;
    int distLocationColumn=0;
    int beginLocationRow=0;
    int beginLocationColumn=0;
    int i,j;
    struct car selectedCar[16];
    int nSelectedCar=0;
    bool isCarNumberEntered=false;
    bool secondDigit=false;
    bool enterKey=false;
    int yStartPrint=2;
    int xStartPrint=85;
    int xLastPrint;
    int yLastPrint;
    int xPrint=xStartPrint;
    int yPrint=yStartPrint;
    bool allSelectedCarChecked = false;



    while (keyNum==108 || keyNum==76) //montazer zadan L(capital L) ya l(small L) mimanad
    {

        if(kbhit())
        {

            key=getch();
            keyNum=(int)key;
            if(keyNum==-32) //montazer arrow keys mimanad
            {

                if(kbhit())
                {
                    key=getch();
                    keyNum=(int)key;

                    switch (keyNum)
                    {
                    case 72:
                        //cursor be bala miravad
                        if(row-1>=0)
                        {
                            row=row-1;
                            gotoxy(board[row][column].position.x,board[row][column].position.y);
                        }
                        keyNum=108;
                        break;
                    case 80:
                        //cursor be paein miravad
                        if(row+1<=7)
                        {
                            row=row+1;
                            gotoxy(board[row][column].position.x,board[row][column].position.y);
                        }
                        keyNum=108;
                        break;
                    case 75:
                        //cursor be chap miravad
                        if(column-1>=0)
                        {
                            column=column-1;
                            gotoxy(board[row][column].position.x,board[row][column].position.y);
                        }
                        keyNum=108;
                        break;
                    case 77:
                        //cursor be rast miravad
                        if(column+1<=19)
                        {
                            column=column+1;
                            gotoxy(board[row][column].position.x,board[row][column].position.y);
                        }
                        keyNum=108;
                        break;

                    }
                }
            }
            if(keyNum==13)
            {
                //montazer zadan enter baraye chap setareha mimanad
                if(isBeginSet==false && isDistSet==false)
                {
                    //chap setare mabda'a
                    if(board[row][column].isFilled==false)
                    {
                        setTextColor(2,7);
                        printf("*");
                        setTextColor(7,0);
                        gotoxy(board[row][column].position.x,board[row][column].position.y);
                        beginLocationColumn=column;
                        beginLocationRow=row;
                        isBeginSet=true;
                    }
                }
                else if(isBeginSet==true && isDistSet==false)
                {
                    //chap setare maghsad
                    if(board[row][column].isFilled==false)
                    {
                        setTextColor(4,7);
                        printf("*");
                        setTextColor(7,0);
                        gotoxy(board[row][column].position.x,board[row][column].position.y);
                        distLocationColumn=column;
                        distLocationRow=row;
                        isDistSet=true;


                        if(isBeginSet==true && isDistSet==true)
                        {

                            bool allHomeChecked=false;
                            int state=1;
                            int k;

                            while(allHomeChecked==false)
                            {
                                //khaneha ra dar fasele 2 khanei khod check mikonad
                                switch(state)
                                {
                                case 1:
                                    //khaneh dar jahat sotoon 2khane aghab ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationColumn-k>=0)
                                        {
                                            if(board[beginLocationRow][beginLocationColumn-k].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if ( carlist[i].x==board[beginLocationRow][beginLocationColumn-k].position.x && carlist[i].y==board[beginLocationRow][beginLocationColumn-k].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    state++;
                                    break;
                                case 2://khaneh dar jahat sotoon 2khane be bala va radif 2khane aghab bala ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationColumn-k>=0 && beginLocationRow-k>=0)
                                        {
                                            if(board[beginLocationRow-k][beginLocationColumn-k].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if(carlist[i].x==board[beginLocationRow-k][beginLocationColumn-k].position.x && carlist[i].y==board[beginLocationRow-k][beginLocationColumn-k].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }

                                                }
                                            }
                                        }

                                    }
                                    state++;
                                    break;
                                case 3://khaneh dar jahat radif 2khane be bala ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationRow-k>=0)
                                        {
                                            if(board[beginLocationRow-k][beginLocationColumn].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if(carlist[i].x==board[beginLocationRow-k][beginLocationColumn].position.x && carlist[i].y==board[beginLocationRow-k][beginLocationColumn].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    state++;
                                    break;
                                case 4://khaneh dar jahat sotoon 2khane be bala va radif 2khane joloo ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationRow-k>=0 && beginLocationColumn+k<=19)
                                        {
                                            if(board[beginLocationRow-k][beginLocationColumn+k].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if(carlist[i].x==board[beginLocationRow-k][beginLocationColumn+k].position.x && carlist[i].y==board[beginLocationRow-k][beginLocationColumn+k].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    state++;
                                    break;
                                case 5:////khane hara radif 2khane joloo ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationColumn+k<=19)
                                        {
                                            if(board[beginLocationRow][beginLocationColumn+k].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if(carlist[i].x==board[beginLocationRow][beginLocationColumn+k].position.x && carlist[i].y==board[beginLocationRow][beginLocationColumn+k].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }

                                                }
                                            }
                                        }
                                    }
                                    state++;
                                    break;
                                case 6:////khaneh dar jahat sotoon 2khane be paein va radif 2khane joloo  ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationRow+k<=7 && beginLocationColumn+k<=19)
                                        {
                                            if(board[beginLocationRow+k][beginLocationColumn+k].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if(carlist[i].x==board[beginLocationRow+k][beginLocationColumn+k].position.x && carlist[i].y==board[beginLocationRow+k][beginLocationColumn+k].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    state++;
                                    break;
                                case 7://khaneh hara dar jahat sotoon 2khane be paein ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationRow+k<=7)
                                        {
                                            if(board[beginLocationRow+k][beginLocationColumn].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if(carlist[i].x==board[beginLocationRow+k][beginLocationColumn].position.x && carlist[i].y==board[beginLocationRow+k][beginLocationColumn].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    state++;
                                    break;
                                case 8://khaneh dar jahat sotoon 2khane be paein va radif 2khane aghab  ra chek mikonad
                                    for(k=1; k<3; k++)
                                    {
                                        if(beginLocationRow+k<=7 && beginLocationColumn-k>=0)
                                        {
                                            if(board[beginLocationRow+k][beginLocationColumn-k].isFilled==true)
                                            {
                                                for(i=0; i<18; i++)
                                                {
                                                    if(carlist[i].x==board[beginLocationRow+k][beginLocationColumn-k].position.x && carlist[i].y==board[beginLocationRow+k][beginLocationColumn-k].position.y)
                                                    {
                                                        selectedCar[nSelectedCar]=carlist[i];
                                                        nSelectedCar++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    allHomeChecked=true;
                                    break;



                                }




                            }

                            if (nSelectedCar == 0)//mashini peida nashod va baad az 2s namayesh chap shode pak mishavad va barname be kar khod edame midahad
                            {
                                gotoxy(xPrint,yPrint++);
                                printf(" No Car Found");
                                delay(2000);
                                gotoxy(xPrint,yPrint-1);
                                printf("                ");
                                gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                printf(" ");

                                gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                printf(" ");
                                keyNum=108;
                                break;




                            }
                            else // mashin peida shod va etela'at mashinha chap mishavad
                            {
                                int distance=abs (board[beginLocationRow][beginLocationColumn].position.x - board[distLocationRow][distLocationColumn].position.x)+
                                             abs(board[beginLocationRow][beginLocationColumn].position.y - board[distLocationRow][distLocationColumn].position.y);

                                for(i=0; i<nSelectedCar; i++)
                                {
                                    gotoxy(xPrint,yPrint++);
                                    printf("%s", selectedCar[i].driver.name);
                                    gotoxy(xPrint,yPrint++);
                                    printf("%s", selectedCar[i].driver.phone);
                                    gotoxy(xPrint,yPrint++);
                                    printf("%s", selectedCar[i].pelak);
                                    gotoxy(xPrint,yPrint++);
                                    printf("%s", selectedCar[i].Tpname);
                                    gotoxy(xPrint,yPrint++);
                                    printf("cost = %d\n",2000+500*(selectedCar[i].Tpcoe *distance));
                                    gotoxy(xPrint,yPrint++);

                                }

                                gotoxy(xPrint,yPrint++);
                                printf("Print Your Car Number");

                                gotoxy(xPrint,yPrint++);
                                while(isCarNumberEntered==false)//montazer adad mimanad
                                {


                                    if(kbhit())
                                    {
                                        //karbar dokmei ra feshar dade
                                        key=getch();

                                        if( (int) key==49 || (int) key==50 ||(int) key==51
                                                ||(int) key==52 ||(int) key==53 ||(int) key==54
                                                ||(int) key==55 ||(int) key==56 ||(int) key==57 )
                                        {
                                            //karbar yeki az adad 1 ta 9 ra vared karde


                                            printf("%c", key);
                                            while(secondDigit==false)
                                            {
                                                //montazer vorood dovomin dokme mimanad

                                                if(kbhit())
                                                {
                                                    char keySecond=getch();

                                                    if((int) keySecond!=13 &&( (int) keySecond==49 || (int) keySecond==50
                                                                               ||(int) keySecond==51 ||(int) keySecond==52
                                                                               ||(int) keySecond==53 ||(int) keySecond==54
                                                                               ||(int) keySecond==55 ||(int) keySecond==56
                                                                               ||(int) keySecond==48))
                                                    {
                                                        //meghdar dovomin kelid bein 0 ta 8 bashad va enter nabashad
//                                                       // yanei shomare mashin 2 raghami ast
                                                        printf("%c",keySecond);
                                                        while(enterKey==false)
                                                        {
                                                            //montazer feshar dadan enter baraye daryaft adad 2raghami
                                                            if(kbhit())
                                                            {
                                                                //kelidi fshar dade
                                                                char keyThird=getch();
                                                                if((int) keyThird==13)
                                                                {
                                                                    //enter ra feshar dade
                                                                    int result=((int) key-48 + (int) keySecond-48)+ 9;//tabdil 2kelid vared shode be adad

                                                                    if( result>=1 && result<=18 && ((int)key -48) == 1 &&  ((int)keySecond -48>=0 ||(int)keySecond -48<=8) )
                                                                    {
                                                                        //shomare mashin vared shode bein 1 ta 18
                                                                        for(i=0; i<nSelectedCar; i++)
                                                                        {
                                                                            if(selectedCar[i].carNumber== result)
                                                                            {
                                                                                gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                                                                printf(" ");

                                                                                gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                                                                printf(" ");
                                                                                for(j=0; j<18; j++)
                                                                                {
                                                                                    //mashin entekhabi ra dar bein list 18 mashin jostejoo mikonad
                                                                                    if(carlist[j].carNumber==selectedCar[i].carNumber)
                                                                                    {
                                                                                        //mashin entekhabi  dar bein list 18 mashin pieda shode
                                                                                        gotoxy(carlist[j].x,carlist[j].y);
                                                                                        printf("   ");
                                                                                        board[(carlist[j].x-1) /4][(carlist[j].y-2) /3].isFilled=false;
                                                                                        carlist[j].x=board[distLocationRow][distLocationColumn].position.x;
                                                                                        carlist[j].y=board[distLocationRow][distLocationColumn].position.y;
                                                                                        printCar(carlist[j].pelak, carlist[j].x,carlist[j].y);
                                                                                        board[(carlist[j].x-1) /4][(carlist[j].y-2) /3].isFilled=true;
                                                                                        break;

                                                                                    }

                                                                                }
                                                                                xLastPrint=xPrint;
                                                                                yLastPrint=yPrint;
                                                                                for(i=yStartPrint; i<=yLastPrint; i++)
                                                                                {
                                                                                    gotoxy(xStartPrint,i);
                                                                                    printf("                       ");
                                                                                }
                                                                                //keyNum=108;
                                                                                secondDigit=true;
                                                                                enterKey=true;
                                                                                isCarNumberEntered=true;
                                                                                break;

                                                                            }
                                                                            else if (i == nSelectedCar -1 )
                                                                            {
                                                                                //mashin entekhabi dar bein 18 mashin peida nashode
                                                                                gotoxy(xPrint,yPrint++);
                                                                                xLastPrint=xPrint;
                                                                                yLastPrint=yPrint;
                                                                                printf("car Not Found");
                                                                                delay(1000);
                                                                                isCarNumberEntered=true;
                                                                                for( i=yStartPrint; i<=yLastPrint; i++)
                                                                                {
                                                                                    gotoxy(xStartPrint,i);
                                                                                    printf("                       ");
                                                                                }
                                                                                gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                                                                printf(" ");
                                                                                gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                                                                printf(" ");
                                                                                //keyNum=108;
                                                                                secondDigit=true;
                                                                                enterKey=true;
                                                                                isCarNumberEntered=true;
                                                                                break;

                                                                            }
                                                                        }
                                                                        //keyNum=108;
//                                                                        secondDigit=true;
//                                                                        enterKey=true;
//                                                                        isCarNumberEntered=true;
                                                                        // break;




                                                                    }
                                                                    else
                                                                    { //adad 2raghami vared shode bein 1 ta 18 nemibashad
                                                                        gotoxy(xPrint,yPrint++);
                                                                        xLastPrint=xPrint;
                                                                        yLastPrint=yPrint;
                                                                        printf("car is not available");
                                                                        delay(1000);
                                                                        isCarNumberEntered=true;
                                                                        for( i=yStartPrint; i<=yLastPrint; i++)
                                                                        {
                                                                            gotoxy(xStartPrint,i);
                                                                            printf("                       ");
                                                                        }
                                                                        gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                                                        printf(" ");
                                                                        gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                                                        printf(" ");
                                                                        //keyNum=108;
                                                                        secondDigit=true;
                                                                        enterKey=true;
                                                                        isCarNumberEntered=true;
                                                                        break;









                                                                    }



//                                                                gotoxy(xPrint,yPrint++);
//                                                                printf("enter pressed");
//                                                                keyNum=108;
//                                                                enterKey=true;
//                                                                secondDigit=true;
//                                                                isCarNumberEntered=true;
//                                                                break;
                                                                }
                                                                else
                                                                {
                                                                    //enter vared nashode
                                                                    gotoxy(xPrint,yPrint++);
                                                                    xLastPrint=xPrint;
                                                                    yLastPrint=yPrint;
                                                                    printf("car canceled");
                                                                    isCarNumberEntered=true;
                                                                    for( i=yStartPrint; i<=yLastPrint; i++)
                                                                    {
                                                                        gotoxy(xStartPrint,i);
                                                                        printf("                       ");
                                                                    }
                                                                    gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                                                    printf(" ");
                                                                    gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                                                    printf(" ");
                                                                    // keyNum=108;
                                                                    secondDigit=true;
                                                                    enterKey = true;
                                                                    isCarNumberEntered=true;
                                                                    break;






                                                                }
                                                            }
                                                        }

                                                    }
                                                    else if((int) keySecond==13)
                                                    {
                                                        //agar dovomin kelid enter bashad

                                                        if( (((int) key)-48)>=1 && (((int) key)-48)<=9 )
                                                        {
                                                            //avalin character voroodi bein 1 ta 9 boode ya kheir

                                                            for(i=0; i<nSelectedCar; i++)
                                                            {

                                                                if(  selectedCar[i].carNumber== (((int)key)-48)   )
                                                                {
                                                                    //yaftan mashin entekhab shode az bein mashin haye pishnadi



                                                                    gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                                                    printf(" ");

                                                                    gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                                                    printf(" ");
                                                                    for( j=0; j<18; j++)
                                                                    {

                                                                        if(carlist[j].carNumber== selectedCar[i].carNumber)
                                                                        {
                                                                            //masin entekhabi ra da bein mashinha peida karde ast
                                                                            gotoxy(carlist[j].x,carlist[j].y);
                                                                            printf("   ");
                                                                            board[(carlist[j].x-1) /4][(carlist[j].y-2) /3].isFilled=false;//makan ghabli mashin ra dar board khali mikonad
                                                                            carlist[j].x=board[distLocationRow][distLocationColumn].position.x;
                                                                            carlist[j].y=board[distLocationRow][distLocationColumn].position.y;
                                                                            printCar(carlist[j].pelak, carlist[j].x,carlist[j].y);
                                                                            board[(carlist[j].x-1) /4][(carlist[j].y-2) /3].isFilled=true;
                                                                            break;
                                                                        }
                                                                    }

                                                                    xLastPrint=xPrint;
                                                                    yLastPrint=yPrint;
                                                                    for(i=yStartPrint; i<=yLastPrint; i++)
                                                                    {
                                                                        gotoxy(xStartPrint,i);
                                                                        printf("                       ");
                                                                    }
                                                                    //keyNum=108;
                                                                    secondDigit=true;
                                                                    isCarNumberEntered=true;
                                                                    break;



                                                                }
                                                                else if (i == nSelectedCar -1 )
                                                                {
                                                                    //hame mashinhara gashte va mashin entekhabi peida nashode
                                                                    gotoxy(xPrint,yPrint++);
                                                                    xLastPrint=xPrint;
                                                                    yLastPrint=yPrint;
                                                                    printf("car not found");
                                                                    delay(1000);
                                                                    isCarNumberEntered=true;
                                                                    for( i=yStartPrint; i<=yLastPrint; i++)
                                                                    {
                                                                        gotoxy(xStartPrint,i);
                                                                        printf("                       ");
                                                                    }
                                                                    gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                                                    printf(" ");
                                                                    gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                                                    printf(" ");
                                                                    // keyNum=108;
                                                                    secondDigit=true;
                                                                    isCarNumberEntered=true;
                                                                    break;

                                                                }

                                                            }
                                                            keyNum=108;
                                                            secondDigit=true;
                                                            isCarNumberEntered=true;
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            //agar bein 1 ta 9 nabashad ya har dokme digari
                                                            gotoxy(xPrint,yPrint++);
                                                            xLastPrint=xPrint;
                                                            yLastPrint=yPrint;
                                                            printf("car canceled");
                                                            isCarNumberEntered=true;
                                                            for( i=yStartPrint; i<=yLastPrint; i++)
                                                            {
                                                                gotoxy(xStartPrint,i);
                                                                printf("                       ");
                                                            }
                                                            gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                                            printf(" ");
                                                            gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                                            printf(" ");
                                                            keyNum=108;
                                                            secondDigit=true;
                                                            isCarNumberEntered=true;
                                                            break;
                                                        }

                                                    }

                                                }
                                            }

                                        }
                                        else if((int) key==27 || (int) key==48)
                                        {
                                            //karbar dokme esc ya 0 ra vared karde
                                            gotoxy(xPrint,yPrint++);
                                            xLastPrint=xPrint;
                                            yLastPrint=yPrint;
                                            printf("car canceled");
                                            delay(1000);
                                            isCarNumberEntered=true;
                                            for( i=yStartPrint; i<=yLastPrint; i++)
                                            {
                                                gotoxy(xStartPrint,i);
                                                printf("                       ");
                                            }
                                            gotoxy(board[beginLocationRow][beginLocationColumn].position.x,board[beginLocationRow][beginLocationColumn].position.y);
                                            printf(" ");
                                            gotoxy(board[distLocationRow][distLocationColumn].position.x,board[distLocationRow][distLocationColumn].position.y);
                                            printf(" ");

//                                            keyNum=108;
                                            break;

                                        }
                                    }


                                }
                            }
                        }
                        break;
                    }
                }
                keyNum=108;//jaygozari random mashin hara motevaghef mikonad va montazer voroodi mimanad
            }
            if(keyNum!=13 && keyNum!=108 && keyNum!=-32)
            {
                //dokmei gheir arrow keys va L va enter vared konad
                gotoxy(board[beginLocationRow][beginLocationColumn].position.x
                       ,board[beginLocationRow][beginLocationColumn].position.y);
                printf(" ");
                gotoxy(board[distLocationRow][distLocationColumn].position.x
                       ,board[distLocationRow][distLocationColumn].position.y);
                printf(" ");
                break;
            }



        }

    }



}

int main()
{




    gotoxy(startMapX,startMapY);//cursor ra be noghte 0,0 mibarad
    loadMap("map.txt");//map ra az rooye file chap mikonad
    initMapData(board);//set kardan x va y baraye har khane board
    initCarData(carlist);//meghdardehi avalie be carlist
    placeCar(carlist,board);//jaygozari random mashinha
    delay(1000);
    drawCars(carlist);//jaygozari pelak mashinha dar map
    char key ;
    srand((time(NULL)));

    while(true)
    {


        randomPlaceCars(carlist,board);//jabeja kardan mashinha betor tasadofi
        if (kbhit())
        {
            setBeginAndEnd(carlist,board);
        }


        delay(1000);





    }


//    getch();


    return 0;
}
