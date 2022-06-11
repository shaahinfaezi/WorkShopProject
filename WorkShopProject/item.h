#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using std::string;

//clasi baraye zakhire item haye liste task ha
class item{

private:

    string title;

    string description;

    string priority;

     int day;

     int month;

    int year;

    int hour;

    int minute;

    int second;

public:

        item(){};

        item(string,string,string, int, int, int, int, int, int);

        string get_title() const;

        string get_description() const;

        string get_priority() const;

        int get_day() const;

        int get_month() const;

        int get_year() const;

        int get_hour() const;

        int get_minute() const;

        int get_second() const;

        void set_title(string);

        void set_description(string);

        void set_priority(string);

        void set_day(int);

        void set_month(int);

        void set_year(int);

        void set_hour(int);

        void set_minute(int);

        void set_second(int);
};






#endif // ITEM_H
