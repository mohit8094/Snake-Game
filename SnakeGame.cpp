#include<iostream>
#include<conio.h>
using namespace std;
bool gameover;
int x,y;
int fruitX,fruitY,score;
 const int width=40;
 const int height=30;
 int tailX[100],tailY[100];
 int ntail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void setup()
{
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;

}
void Draw()
{
    system("cls");

    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0||j==width-1){
                cout<<"#";
            }
            if(i==y&&j==x)
                cout<<"$";
            else if(i==fruitY&&j==fruitX)
                cout<<"F";
            else
                {
                    bool print=false;
                    for(int k=0;k<ntail;k++)
                    {
                        if(tailX[k]==j&&tailY[k]==i)
                        {
                            cout<<"o";
                            print=true;
                        }
                    }
                    if(!print)
                        cout<<" ";
                }


        }
        cout<<endl;

    }

     for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"score:"<<score<<endl;

}
void Input()
{
   if(_kbhit())
   {
       switch (_getch())
       {
       case '1':
        dir=LEFT;
        break;

        case '2':
        dir=DOWN;
        break;

        case '3':
        dir=RIGHT;
        break;

        case '5':
        dir=UP;
        break;

        case 'x':
            gameover=true;
            break;
       }

   }


}
void Logic()
{

    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=0;i<ntail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];

        tailX[i]=prevX;
        tailY[i]=prevY;

        prevX=prev2X;
        prevY=prev2Y;


    }




    switch(dir)
    {
    case LEFT:
        x--;
        break;

        case RIGHT:
        x++;
        break;

        case UP:
        y--;
        break;

        case DOWN:
        y++;
        break;
    }

   // if(x>width||x<0||y<0||y>height)
     //   gameover=true;

     for(int i=0;i<ntail;i++)
     {
         if(tailX[i]==x&&tailY[i]==y)
            gameover=true;

     }
       if(x<0)x=width-1;else if(x>width)x=0;
       if(y<0)y=height-1;else if(y>width)y=0;


    if(x==fruitX&&y==fruitY)
    {
        score+=10;
         fruitX=rand()%width;
         fruitY=rand()%height;
         ntail++;
    }

}
int main()
{

    setup();
    while(!gameover)
    {
        Draw();
        Input();
        Logic();
      //  sleep(10);
    }

}
