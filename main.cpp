#include <iostream>
#include<stdlib.h>
void DigitalClockIntToStr(int seconds, char time[11]);
int DigitalClockStrToInt(const char time[11]);
using namespace std;

int main()
{
    char time[10];
    int seconds;
    int choice;
    char want;
    while(true)
    {
    cout<<"[1] convert seconds to time"<<"\n";
    cout<<"[2] convert time to seconds"<<"\n";
    cout<<"Enter choice: ";
    cin>>choice;
    while(choice!=1&&choice!=2)
    {
        cout<<"Error choice Enter choice again: ";
        cin>>choice;
    }
    switch(choice)
    {
    case 1:
        cout<<"Enter the number of elapsed seconds starting from the previous midnight: ";
        cin>>seconds;
        DigitalClockIntToStr(seconds,time);
        break;
    case 2:
        cout<<"Enter the time such as(01:59:33pm): ";
        cin>>time;
        int hours1=time[0]-'0';
        int hours2=time[1]-'0';
        int min1=time[3]-'0';
        int min2=time[4]-'0';
        int sec1=time[6]-'0';
        int sec2=time[7]-'0';
        while(time[2]!=':'||time[5]!=':'||(time[8]!='a'&&time[8]!='p')||time[9]!='m'||hours1>1||(hours1==1&&hours2>2)||min1>5||min2>9||sec1>5||sec2>9)
        {
            cout<<"Enter time such as(01:59:33pm) again: ";
            cin>>time;
            hours1=time[0]-'0';
            hours2=time[1]-'0';
            min1=time[3]-'0';
            min2=time[4]-'0';
            sec1=time[6]-'0';
            sec2=time[7]-'0';
        }
        cout<<"seconds: "<<DigitalClockStrToInt(time)<<"\n";
        break;
      }
      cout<<"Are you want to another operation(y/n): ";
      cin>>want;
      if(want=='n')
      {
          cout<<"Thank you for using my program"<<"\n";
          break;
      }
    }
    return 0;
}
void DigitalClockIntToStr(int seconds, char time[11])
{
    string zero1[3];
    string zero2[3];
    int sec,minu,hours;
    if(seconds<0||seconds>86399)
    {
        cout<<"Invalid"<<"\n";
    }
    if(seconds<43200)
    {
        hours=seconds/60/60;
        minu=((seconds)-(hours*60*60))/60;
        sec=seconds-(minu*60)-(hours*60*60);
        if(hours<1)
        {
            hours=12;
        }
        if(hours<10)
        {
            zero1[0]="0";
        }
        if(minu<10)
        {
            zero1[1]="0";
        }
        if(sec<10)
        {
            zero1[2]="0";
        }
        cout<<"time: "<<zero1[0]<<hours<<":"<<zero1[1]<<minu<<":"<<zero1[2]<<sec<<" "<<"am \n";

   }
   if(seconds>=43200&&seconds<86400)
    {
        hours=seconds/60/60;
        minu=((seconds)-(hours*60*60))/60;
        sec=seconds-(minu*60)-(hours*60*60);
        if(hours>12)
        {
            hours=hours-12;
        }
          if(hours<10)
        {
            zero2[0]="0";
        }
        if(minu<10)
        {
            zero2[1]="0";
        }
        if(sec<10)
        {
            zero2[2]="0";
        }
        cout<<"time: "<<zero2[0]<<hours<<":"<<zero2[1]<<minu<<":"<<zero2[2]<<sec<<" "<<"pm \n";
   }

}
int DigitalClockStrToInt(const char time[10])
{
    int second;
  int hour,seco,min;
  int h1=time[0]-'0';
  int h2=time[1]-'0';
  int m1=time[3]-'0';
  int m2=time[4]-'0';
  int s1=time[6]-'0';
  int s2=time[7]-'0';
  if(h1==1)
  {
    hour=10+h2;
  }
  else if(h1==0)
  {
      hour=h2;
  }
  min=m1*10+m2;
  seco=s1*10+s2;
  if(time[8]=='a')
  {
     if(hour==12)
     {
         second=(min*60)+seco;
     }
     else if(hour!=12)
     {
         second=(hour*60*60)+(min*60)+seco;
     }
  }
  if(time[8]=='p')
  {
     if(hour==12)
     {
         second=(hour*60*60)+(min*60)+seco;
     }
     else if(hour!=12)
     {
         second=((12+hour)*60*60)+(min*60)+seco;
     }
  }
  return second;
}
