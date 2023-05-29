#include "Date.h"

using namespace std;

Date::Date(){
    minutes = hour = day = month = year = 0;
}

Date::Date(int _minutes, int _hour, int _day, int _month, int _year){
    minutes = _minutes;
    hour = _hour;
    day = _day;
    month = _month;
    year = _year;
}




Date::Date(string _date) {
// 5/3/2010 
    string str = _date;
    int arr[4];
    string arr1[4];
    int k = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '/') k++;
        else {

            arr1[k] += str[i];
        }
    }
    arr[0] = stoi(arr1[0]);
    arr[1] = stoi(arr1[1]);
    arr[2] = stoi(arr1[2]);
    arr[3] = stoi(arr1[3]);
    hour = arr[0];
    day = arr[1];
    month = arr[2];
    year = arr[3];

}

string Date::getString1()
{
    string str;
    str = to_string(hour) + '/' + to_string(day) + '/' + to_string(month) + '/' + to_string(year);
    return str;
}

float Date::getDuration(Date _beginningDate)
{   
    float duration = 0;
    Date current = Date::getCurrentDate();
    int year = current.year;
    int month = current.month;
    while (year > _beginningDate.year && month < _beginningDate.month) {
        duration += 365 * 24;
        year--;
    }
    if (year > _beginningDate.year) {
        duration +=  (current.month + 12 - _beginningDate.month) * 24 * 30;
    }
    int day = current.day;
    while (month > _beginningDate.month && day < _beginningDate.day) {
        duration += 30 * 24;
        month--;
    }
    if (month > _beginningDate.month) {
        duration += (current.day + 30 - _beginningDate.day) * 24;
    }
    int hour = current.hour;
    while (day > _beginningDate.day && hour < _beginningDate.hour) {
        duration += 24;
        day--;
    }
    if (day > _beginningDate.day) {
        duration += (current.hour + 24 - _beginningDate.hour);
    }
    while (hour > _beginningDate.hour) {
        duration += 1;
        hour--;
    }
    return duration;
}


Date Date::getCurrentDate() {
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);
    int _minutes = local_time.tm_min;
    int _hour = local_time.tm_hour;
    int _day = local_time.tm_mday + 1;
    int _month = local_time.tm_mon + 1;
    int _year = local_time.tm_year + 1900;
    Date currentDate(_minutes, _hour, _day, _month, _year);
    return currentDate;
}

void Date::displayDate(){
    cout << day << "/" << month << "/" << year << " " << hour<<" ";
}
