#include "item.h"


item::item(string title,

string description,

string priority,

 int day,

 int month,

 int year,

 int hour,

int minute,

 int second){


    this->title=title;

    this->description=description;

    this->priority=priority;

    this->day=day;

    this->month=month;

    this->year=year;

    this->hour=hour;

    this->minute=minute;

    this->second=second;

    done=false;


}

string item::get_title() const{

    return title;

}

string item::get_description() const{

    return description;


}

string item::get_priority() const{

    return priority;
}

 int item::get_day() const{

    return day;

}

 int item::get_month() const{

    return month;

}

 int item::get_year() const{

    return year;


}

int item::get_hour() const{

    return hour;

}

 int item::get_minute() const{

    return minute;

}

 int item::get_second() const{

    return second;

}


 void item::set_title(string title){

     this->title=title;




 }

 void item::set_description(string description){

     this->description=description;



 }

 void item::set_priority(string priority){

      this->priority=priority;

 }


 void item::set_day(int day){

     this->day=day;

 }

 void item::set_month(int month){

     this->month=month;

 }

 void item::set_year(int year){

     this->year=year;

 }

 void item::set_hour(int hour){

     this->hour=hour;

 }

 void item::set_minute(int minute){

      this->minute=minute;

 }

 void item::set_second(int second){

     this->second=second;

 }

 bool item::get_done(){

     return done;

 }

 void item::set_done(bool done){

     this->done=done;

 }
