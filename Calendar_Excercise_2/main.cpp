using namespace std;

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:

    Date(int xyear, int xmonth, int xday ){ //set specific Date
        day = xday;
        month = xmonth;
        year = xyear;

    }
    Date(){ //set Date if the parameters are empty
        day = 01;
        month = 01;
        year = 2000;

    }

    void setYear(int ayear){ //set year
        year = ayear;
    }
    void setMonth(int amonth){ //set month
        month = amonth;
    }
    void setDay(int aday){ //set day
        day = aday;
    }
    int getDay(){ //get day out of private
        return day;
    }
    int getMonth(){ // get month out of private
        return month;
    }
    int getYear(){ // get year out of private
        return year;
    }

    void print(){ //printout the date
        cout << year << "-" << month << "-" << day << endl;
    }
    int daysSince2000(){ //every month has 30 days
        if (year - 2000 == 0){
            return month*30+day;
        }
        else{
            return ((year - 2000)*12*30)+(month*30)+day;
        }
    }
 /*   int daysUntil(){
        cout << d2.print() << endl;
    }

    */
};


int main()

{
Date d1;
d1.setYear(2000);
d1.setMonth(2);
d1.setDay(1);

d1.print();

cout << endl;
Date d2(2000, 3, 3);
d2.print();


cout << endl;
cout << d1.daysSince2000() << endl;
cout << d2.daysSince2000() << endl;

/*
cout << d1.daysUntil(&d2) << endl;

cout << d2.daysUntil(&d1) << endl;
*/}
