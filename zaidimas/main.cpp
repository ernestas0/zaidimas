#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
#include <fstream>
using namespace std;
void out(string a)
{
    for(int i=0; i<10; i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    for(int i=10; i<20; i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    for(int i=20; i<30; i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}
int main()
{
    srand(time(0));
    ifstream file("file.txt");
    int j=0, s=0, k=10, f;
    string a="          D         OOOOOOOOOO";
    char key, e;
    bool r, t;
    while(true)
    {
        if(k!=10)
        {
            a[k]=' ';
            a[k-1]='#';
            k--;
            t=false;
        }
        else
        {
            t=true;
        }
        if(t)
        {
            r=(rand()%100)<10;
        }
        else
        {
            r=false;
        }
        if(j==1)
        {
            a[0]=' ';
            a[10]='D';
        }
        if(j!=0)
        {
            j--;
        }
        if(r)
        {
            a[19]='#';
            k=19;
        }
        out(a);
        std::this_thread::sleep_for(chrono::milliseconds(50));
        if(_kbhit())
        {
            key=_getch();
            if(key==' ' && j==0)
            {
                j=4;
            }
        }
         if(a[10]=='#' && a[0]!='D')
        {
            break;
        }
        if(j!=0)
        {
            a[0]='D';
            a[10]=' ';
        }
        s++;
        system("cls");
    }
    cout<<"Zaidimas baigesi"<<endl;
    cout<<"Jusu surinktu tasku skaicius: "<<s<<endl;
    file>>f;
    file.close();
    if(s>f)
    {
        ofstream file("file.txt");
        file<<s;
    }
    file.close();
    cout<<"Geriausias rezultatas: ";
    if(s>f)
    {
        cout<<s<<endl;
    }
    else
    {
        cout<<f<<endl;
    }
    cout<<"Jei norite zaisti is naujo spauskite t"<<endl;
    cin>>e;
    if(e=='t')
    {
        system("cls");
        main();
    }
    return 0;
}
