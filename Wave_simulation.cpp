#include<iostream>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<cmath>


#define PI 3.14159265
#define RADIANS(x) (x*(PI/180))
#define DEGREES(x) (x*(180/PI))

/* Origins */
#define X0 (getmaxx()/2)
#define Y0 (getmaxy()/2)

/* Place (x,y) in x-y plane */
#define X(x) (X0+(x))
#define Y(y) (Y0-(y))

/* Left and right ends of x-axis*/
#define x_left_border()  (-1*getmaxx()/2+10)
#define x_right_border() (getmaxx()/2-10)

using namespace std;

class Wave_Simul
{
    private:
        double x,y;
        double amp,freq;
        int choice,bak_color_choice;
        int font_color_choice;
        int gd,gmode;

    public:
        Wave_Simul()
        {
            gd=DETECT,gmode=0;
            x=0;
            y=0;
            amp=0;
            freq=0;
           // bak_color_choice = 15; // black
           // int font_color_choice=15; // White font color
            initwindow(1250,700,"Wave-Simulation");
           // initgraph(&gd,&gmode,"C:\\TC\\BGI");
        }
        void initialize();
        void drawxaxis();
        void drawyaxis();
        void drawSineWave();
        void drawCosineWave();
        void addWave();
        void subWave();
        void mulWave();
        void generateWave(int);
        void setOption();
        void set_background_color();
        void set_font_color();
        void printChoice();
        void check();
        void printText(int);
        void printFreAmp(double ,double);
        void printBothFreqAmp(double ,double,double,double);
       //~Wave_Simul();
};

void Wave_Simul::initialize()
{
    gd=DETECT,gmode=0;
            x=0;
            y=0;
            amp=0;
            freq=0;
            //bak_color_choice = 15; // black
            initwindow(1250,700,"Wave-Simulation");
}

void Wave_Simul::setOption()
{
    int opChoice;
 suboption:
    system("cls");

    cout<<"\n\n\t\t\t1.Set to Default"
        <<"\n\t\t\t2.Change Background Color and font color"
        <<"\n\t\t\t3.Go to previous menu";
    cout<<"\n\t\tPlease Enter your choice:-> ";
    cin>>opChoice;
    switch(opChoice)
    {
        case 1:
               bak_color_choice = 15; // black
             font_color_choice=15; // White font color
             cout<<"Default font color set";
            break;
        case 2:
            int opChoiceColor;
                cout<<"\n\n\n\t\t\t1.Background color";
                cout<<"\n\t\t\t2.Font Color";
                cout<<"\n\t\t\tany key to previous menu";
                cout<<"\n\t\t\tPleaase Enter the choice:";
                cin>>opChoiceColor;
                switch(opChoiceColor)
                {
                    case 1:
                        set_background_color();
                        break;
                    case 2:
                        set_font_color();
                        break;
                    default:
                      goto suboption;
                }
            break;
        case 3:
            break;
        default:
            break;
    }
}
void Wave_Simul::set_background_color()
{
    int bkcolor;
    cout<<"\n\t\t\t0.BLACK"
        <<"\n\t\t\t1.Blue"
        <<"\n\t\t\t2.GREEN"
        <<"\n\t\t\t3.CYAN"
        <<"\n\t\t\t4.RED"
        <<"\n\t\t\t5.MAGENTA"
        <<"\n\t\t\t6.BROWN"
        <<"\n\t\t\t7.LIGHTGRAY"
        <<"\n\t\t\t8.DARKGRAY"
        <<"\n\t\t\t9.LIGHTBLUE"
        <<"\n\t\t\t10.LIGHTGREEN"
        <<"\n\t\t\t11.LIGHTCYAN"
        <<"\n\t\t\t12.LIGHTRED"
        <<"\n\t\t\t13.LIGHTMAGENTA"
        <<"\n\t\t\t14.YELLOW"
        <<"\n\t\t\t15.MAGENTA";

    cout<<"\n\t\t\tEnter color value:";
    cin>>bkcolor;
    setbkcolor(bkcolor);
}
void Wave_Simul::set_font_color()
{
    int fontcolor;
        cout<<"\n\t\t\t0.BLACK"
        <<"\n\t\t\t1.Blue"
        <<"\n\t\t\t2.GREEN"
        <<"\n\t\t\t3.CYAN"
        <<"\n\t\t\t4.RED"
        <<"\n\t\t\t5.MAGENTA"
        <<"\n\t\t\t6.BROWN"
        <<"\n\t\t\t7.LIGHTGRAY"
        <<"\n\t\t\t8.DARKGRAY"
        <<"\n\t\t\t9.LIGHTBLUE"
        <<"\n\t\t\t10.LIGHTGREEN"
        <<"\n\t\t\t11.LIGHTCYAN"
        <<"\n\t\t\t12.LIGHTRED"
        <<"\n\t\t\t13.LIGHTMAGENTA"
        <<"\n\t\t\t14.YELLOW"
        <<"\n\t\t\t15.MAGENTA";
        cout<<"\n\t\t\tEnter the font color:";
        cin>>fontcolor;


}
void Wave_Simul::drawSineWave()
{
    x=0;y=0;
    printText(30);
    cout<<"Enter the Amplitude and Frequency of the Sine_Wave:";
    cin>>amp>>freq;

    cleardevice();
    drawxaxis();
    drawyaxis();
    printFreAmp(freq,amp);
    freq=freq/10;
    for (x = x_left_border(); x < x_right_border(); x += 0.1) {
  /* Drawing speed */
    delay(0.5);

  /*Calculate y for given x degrees*/
  y = amp * sin(RADIANS(x*freq));

  /* Draw pixel at x,y */
  putpixel(X(x), Y(y), 15);

 }
 getch();
 closegraph();
}
void Wave_Simul::drawCosineWave()
{
    x=0;y=0;
    printText(30);
    cout<<"Enter the Amplitude and Frequency of the Sine_Wave:";
    cin>>amp>>freq;

    cleardevice();
    drawxaxis();
    drawyaxis();
    printFreAmp(freq,amp);
    freq=freq/10;
    for (x = x_left_border(); x < x_right_border(); x += 0.1) {
  /* Drawing speed */
    delay(0.5);

  /*Calculate y for given x degrees*/
  y = amp * cos(RADIANS(x*freq));

  /* Draw pixel at x,y */
  putpixel(X(x), Y(y), 15);

 }

 getch();
 closegraph();
}
void Wave_Simul::subWave()
{
    x=0;y=0;
    double sfreq,cfreq,samp,camp;
    cout<<"\nEnter the  Amplitude and Frequency of Sine Wave:";
    cin>>samp>>sfreq;
    cout<<"\nEnter the Amplitude and frequency of Cosine Wave:";
    cin>>camp;
    cin>>cfreq;
    cleardevice();
    printBothFreqAmp(sfreq,samp,cfreq,camp);
    sfreq=sfreq/10;
    cfreq = cfreq/10;
    drawxaxis();
    drawyaxis();


    if(camp>samp)
    {
        for (x = x_left_border(); x < x_right_border(); x += 0.1) {
        /* Drawing speed */
        delay(0.5);

        /*Calculate y for given x degrees*/

        y = (camp - samp)*( (sin(RADIANS(x*sfreq))) -( cos(RADIANS(x*cfreq))));

        /* Draw pixel at x,y */
        putpixel(X(x), Y(y), 15);

       }

    }else
    {
      for (x = x_left_border(); x < x_right_border(); x += 0.1) {
        /* Drawing speed */
        delay(0.5);

        /*Calculate y for given x degrees*/

        y = (samp - camp)*( (sin(RADIANS(x*sfreq))) -( cos(RADIANS(x*cfreq)))) ;

        /* Draw pixel at x,y */
        putpixel(X(x), Y(y), 15);
      }

   }
   getch();
   closegraph();

}
void Wave_Simul::addWave()
{
   x=0;y=0;
    double sfreq,cfreq,samp,camp;
    cout<<"\nEnter the  Amplitude and Frequency of Sine Wave:";
    cin>>samp>>sfreq;
    cout<<"\nEnter the Amplitude and Frequency of Cosine Wave:";
    cin>>camp>>cfreq;
    cleardevice();
    printBothFreqAmp(sfreq,samp,cfreq,camp);
    sfreq=sfreq/10;
    cfreq = cfreq/10;
    drawxaxis();
    drawyaxis();


    if(camp>samp)
    {
        for (x = x_left_border(); x < x_right_border(); x += 0.1) {
        /* Drawing speed */
        delay(0.5);

        /*Calculate y for given x degrees*/

        y = ((camp +samp)* (cos(RADIANS(x*cfreq))) + ( sin(RADIANS(x*sfreq))));

        /* Draw pixel at x,y */
        putpixel(X(x), Y(y), 15);

       }

    }else
    {
      for (x = x_left_border(); x < x_right_border(); x += 0.1) {
        /* Drawing speed */
        delay(0.5);

        /*Calculate y for given x degrees*/

        y = ((samp +camp)* (cos(RADIANS(x*cfreq))) + ( sin(RADIANS(x*sfreq)))) ;

        /* Draw pixel at x,y */
        putpixel(X(x), Y(y), 15);
      }

   }
   getch();
   closegraph();
}

void Wave_Simul::generateWave(int gen) // generate square or triangular
{

   if(gen ==1)
   {
    printText(30);
    cout<<"enter the amplitude of Square wave:";
    cin>>amp;
    cout<<"Enter the frequency of Square Wave:";
    cin>>freq;

    cleardevice();
    printFreAmp(freq,amp);

    drawxaxis();
    drawyaxis();
               x=0;y=Y0;
                for(int t1=0;t1<x_right_border();t1++)
                {
                    line(x,y+amp,x,y-amp);
                    delay(100);
                    line(x,y-amp,x+freq,y-amp);
                    delay(100);

                    x=x+freq;
                    line(x,y-amp,x,y+amp);
                    delay(100);
                    line(x,y+amp,x+freq,y+amp);
                    delay(100);
                    x=x+freq;
                }
   }
   else
   {

       printText(40);
       cout<<"Enter the amplitude of traingular wave:";
       cin>>amp;
       cout<<"ENter the freq of the traingular wave:";
       cin>>freq;

       cleardevice();
       printFreAmp(freq,amp);
       drawxaxis();
       drawyaxis();
       x=0;y=Y0;

        //setfillstyle(HATCH_FILL,WHITE);
       //setfillstyle(SOLID_FILL, YELLOW);
       while(x< getmaxx())
       {

           //line(x,y,x+freq,amp);
          // delay(100);
           //x +=freq;
           line(x,fabs(amp-Y0),x+freq,(Y0+amp));
           x+=freq;

    //Change RED to WHITE.
          // floodfill(x+freq,fabs(amp-Y0),WHITE);
           line(x,(Y0+amp),x+freq,fabs(amp-Y0));
           x+=freq;



       }
   }
   getch();
   closegraph();
}
void Wave_Simul::printFreAmp(double fq,double am)
{
    char msg[15];
    sprintf(msg,"f=%d  A=%d",(int)fq,(int)am);
    settextstyle(3,HORIZ_DIR, 0);
    settextjustify(RIGHT_TEXT,TOP_TEXT);
    outtextxy(200,10,msg);
}
void Wave_Simul::printBothFreqAmp(double sfq,double sam,double cfq,double cam)
{
    char msg[40];
    sprintf(msg,"Sin(f=%d,A=%d) Cos(f=%d,A=%d)",(int)sfq,(int)sam,(int)cfq,(int)cam);
    settextstyle(3,HORIZ_DIR, 0);
    settextjustify(RIGHT_TEXT,TOP_TEXT);
    outtextxy(500,10,msg);
}
void Wave_Simul::printText(int size)
{
    cleardevice();
    settextstyle(3,HORIZ_DIR, size);// size is given between 30 and 40
    outtextxy(200,200,"Enter amplitude and Frequency ");
    getch();
}
void Wave_Simul::check()
{
    int i=0,xtext,ytext;
    char msg[80];
 //   settextjustify(CENTER_TEXT, CENTER_TEXT);

    xtext = getmaxx() / 2;
   ytext= getmaxy() / 2;
    int j=5;
    while(i++ <=15)
    {
        setbkcolor(i);
        if(i<=13)setcolor(i+1);
        sprintf(msg, "Background color: %d", i);
        outtextxy(x, y, msg);
        printText(j);
        j = j+5;
        getch();
    }
    getch();
}
void Wave_Simul::drawxaxis() {
 line(5, getmaxy() / 2, 12, getmaxy() / 2 - 7);
 line(5, getmaxy() / 2, 12, getmaxy() / 2 + 7);

 line(5, getmaxy() / 2, getmaxx() - 5, getmaxy() / 2);

 line(getmaxx()-5, getmaxy() / 2, getmaxx() - 12, getmaxy() / 2 - 5);
 line(getmaxx()-5, getmaxy() / 2, getmaxx() - 12, getmaxy() / 2 + 5);
}

void Wave_Simul::drawyaxis() {
 line(getmaxx() / 2, 5, getmaxx() / 2 - 7, 12);
 line(getmaxx() / 2, 5, getmaxx() / 2 + 7, 12);

 line(getmaxx() / 2, 5, getmaxx() / 2, getmaxy() - 5);

 line(getmaxx() / 2, getmaxy() - 5, getmaxx()/ 2- 7, getmaxy() - 12);
 line(getmaxx() / 2, getmaxy() - 5, getmaxx()/ 2+ 7, getmaxy() - 12);

}
int main()
{

    Wave_Simul wave;

        cleardevice();
        system("COLOR 43");
    //clrscr();
    int choice;

    do
    {
        preMenu:

        system("cls");
        cout<<"\n\n\n\t\t1.Draw Sine Signal"
            <<"\n\t\t2.Draw Cosine Signal"
            <<"\n\t\t3.Add the Signal"
            <<"\n\t\t4.Subtract the Signal"
            <<"\n\t\t5.Generates Waves"
            <<"\n\t\t6.Option"
            <<"\n\t\t7.Exit";

        cout<<"\n\t\tPlease ENter your choice ->";
        cin>>choice;
        cleardevice();
        switch(choice)
       {
        case 1:
            wave.drawSineWave();
            break;
        case 2:
            wave.drawCosineWave();
            break;

        case 3:
            wave.addWave();
            break;
        case 4:
            wave.subWave();
            break;
        case 5:
            int choiceGen;
            system("cls");//clear screen
            cout<<"\n\n\n\t\t1.Generate Square Wave"
                <<"\n\t\t2.Generate Traingular Wave"
                <<"\n\t\t3.On Previous Menu"
                <<"\n\t\t\tENter you Choice";
                    cin>>choiceGen;
                    switch(choiceGen)
                    {
                        case 1:
                            wave.generateWave(1);


                            break;

                        case 2:
                            wave.generateWave(2);

                            break;

                        case 3:

                            goto preMenu;
                            break;
                        default:
                            cout<<"\n\nEnter Correct choice ";
                            break;
                    }


            break;
        case 6:
            wave.setOption();
            break;
        default:
            cout<<"Please ENter the correct Choice";
       }
       wave.initialize();
    }while(choice != 7);


    //wave.check();
    //wave.drawSineWave();
    //wave.drawCosineWave();
    //wave.addWave();
    getch();
}

