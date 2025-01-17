#include<iostream>
using namespace std;

string w_days[7] = {"sunday","Monday","Tuesday","wednesday","Thursday","Friday","saturday"};
string arr1[12] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
int arr2[12] = {0,3,3,6,1,4,6,2,5,0,3,5};

bool find(string m)
{
    for(int i = 0; i < 12; i++)
    {
        if( arr1[i] == m)
        {
            return true;
            break;
        }
    }
    return false;
}

int cen__code(int cen)
{
    if(((cen+100)/100)%4 == 2){return 4;}
   else if((cen/100)%4==0){return 6;}
   else if((cen/100)%2==0){return 2;}
   else{return 0; }
    
}
int week_day(int d,string m,int y,int cen)
{
    int month_code;
    
    for(int i = 0; i<12;i++)
    {
        if(arr1[i] == m){month_code = i;break;}
    }
     int odd_days = ( d + arr2[month_code] + cen__code(cen) + y + (y/4) ) % 7;
     if((m == "jan" || m == "feb") && y%4==0)
     {
        cout<<w_days[odd_days-1]<<endl;
     }
        else{cout<<w_days[odd_days]<<endl;}
    cout<<endl;cout<<endl;
     return 0;
}

int main(){
    int date = 0,year = 0,cen = 0;
    string month;
    cout<<endl;
    cout<<"\t\t***---W E E K  D A Y  C A L C U L A T O R---***"<<endl;
    cout<<endl;

    cout<<"Enter date = ";cin>>date;
    if(date<1 || date>32){cout<<"Enter a date that exists!!!\nEnter date = ";cin>>date;cout<<endl;}
    cout<<endl;

    cout<<"(like this 'jan-dec')"<<endl;
    cout<<"Enter month = ";cin>>month;
    if(!find(month)){cout<<"Enter month like the example given above!!!\nEnter month = ";cin>>month;cout<<endl;}
    cout<<endl;


    cout<<"(like this '1-99' )"<<endl;
    cout<<"Enter year = ";cin>>year;
    if(year<1 || year>99){cout<<"Enter year like the example given above!!!\nEnter year = ";cin>>year;cout<<endl;}
    cout<<endl;

    cout<<"(1100-2100 0r any other)"<<endl;
    cout<<"Enter century = ";cin>>cen;
    if(!(cen%100==0)){cout<<"Enter a proper century!!!\nEnter century = ";cin>>cen;cout<<endl;}
    cout<<endl;cout<<endl;

    cout<<"On "<<date<<" "<<month<<", "<<cen+year<<" the day was: "<<week_day(date,month,year,cen);
    
    cout<<"***************---------------E N D---------------***************";
    return 0;
}