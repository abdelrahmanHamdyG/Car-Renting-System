#include "Date.h"

using namespace std;

Date::Date(){
    dateInformation.minutes = dateInformation.hour = dateInformation.day = dateInformation.month = dateInformation.year = 0;
}

Date::Date(int _minutes, int _hour, int _day, int _month, int _year){
    dateInformation.minutes = _minutes;
    dateInformation.hour = _hour;
    dateInformation.day = _day;
    dateInformation.month = _month;
    dateInformation.year = _year;
}




Date::Date(string _date) {
    
    // we are making Date Instance from the String 
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
    dateInformation.hour = arr[0];
    dateInformation.day = arr[1];
    dateInformation.month = arr[2];
    dateInformation.year = arr[3];

}

string Date::getString1()
{
    // we are converting a Date to String to be printed
    string str;
    str = to_string(dateInformation.hour) + '/' + to_string(dateInformation.day) + '/' + to_string(dateInformation.month) + '/' + to_string(dateInformation.year);
    return str;
}

float Date::getDuration(Date _beginningDate)
{   
    // we are trying to get number of hourse between the given date and current date
    float duration = 0;
    Date current = Date::getCurrentDate();
    int year = current.dateInformation.year;
    int month = current.dateInformation.month;
    while (year > _beginningDate.dateInformation.year && month < _beginningDate.dateInformation.month) {
        duration += 365 * 24;
        year--;
    }
    if (year > _beginningDate.dateInformation.year) {
        duration += (current.dateInformation.month + 12 - _beginningDate.dateInformation.month) * 24 * 30;
    }
    int day = current.dateInformation.day;
    while (month > _beginningDate.dateInformation.month && day < _beginningDate.dateInformation.day) {
        duration += 30 * 24;
        month--;
    }
    if (month > _beginningDate.dateInformation.month) {
        duration += (current.dateInformation.day + 30 - _beginningDate.dateInformation.day) * 24;
    }
    int hour = current.dateInformation.hour;
    while (day > _beginningDate.dateInformation.day && hour < _beginningDate.dateInformation.hour) {
        duration += 24;
        day--;
    }
    if (day > _beginningDate.dateInformation.day) {
        duration += (current.dateInformation.hour + 24 - _beginningDate.dateInformation.hour);
    }
    while (hour > _beginningDate.dateInformation.hour) {
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
    cout << dateInformation.day << "/" << dateInformation.month << "/" << dateInformation.year << " " << dateInformation.hour<<" ";
}
