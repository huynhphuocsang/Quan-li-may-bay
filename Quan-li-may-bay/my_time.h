#ifndef my_time
#define my_time
#include<time.h>
#include<_mingw.h>
#include<iostream>
using namespace std;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct date_time{
	int hour;
	int min;
	int day;
	int mon;
	int year;
};
bool days_of_mon(date_time dt){
	if(dt.mon==2){
		if(dt.year%400==0 ||(dt.year%4==0 && dt.year%100!=0)){
			if(dt.day>29) return false;
			return true;
		}
		else{
			if(dt.day>28) return false;
			return true;
		}
	}
	else{
		
	if(dt.day>day[dt.mon]) return false;
	return true;
	}
	
}
bool check_depart_time(date_time dt){
	if(days_of_mon(dt)==false) {
		//cout<<"Ngay trong thang khong hop le!"<<endl;
		return false;
	}
	
	time_t now=time(0);
	tm *ltm=localtime(&now);
	date_time dt_now;
	dt_now.day=ltm->tm_mday;
	dt_now.mon=1+ltm->tm_mon;
	dt_now.year=1900+ltm->tm_year;
	dt_now.hour=ltm->tm_hour;
	dt_now.min=ltm->tm_min;
	
	
	
	if(dt.year<dt_now.year) return false;
	if(dt.year==dt_now.year){
		if(dt.mon<dt_now.mon) return false;
			if(dt.mon==dt_now.mon){
				if(dt.day<dt_now.day) return false;
					if(dt.day==dt_now.day){
						if(dt.hour<dt_now.hour) return false;
						if(dt.hour==dt_now.hour){
							if(dt.min<=dt_now.min) return false;
						}
					}
			}
	}
	return true;
}


// thoi gian tuong lai
bool is_nearer(date_time time1,date_time time2){
	if(time1.year<time2.year) return true;
	else if(time1.year>time2.year) return false;
	else if(time1.year==time2.year){
		if(time1.mon<time2.mon) return true;
		else if(time1.mon>time2.mon) return false;
		else if(time1.mon==time2.mon){
			if(time1.day<time2.day) return true;
			else if(time1.day>time2.day) return false;
			else if(time1.day==time2.day){
				if(time1.hour<time2.hour) return true;
				else if(time1.hour>time2.hour) return false;
				else if(time1.hour==time2.hour){
					if(time1.min<time2.min) return true;
					else if(time1.min>time2.min) return false;
					else if(time1.min==time2.min) return false;
				}
			}
		}
	}

}

//thoi gian qua khu
bool is_nearer2(date_time time1, date_time time2){
		if(time1.year>time2.year) return true;
	else if(time1.year<time2.year) return false;
	else if(time1.year==time2.year){
		if(time1.mon>time2.mon) return true;
		else if(time1.mon<time2.mon) return false;
		else if(time1.mon==time2.mon){
			if(time1.day>time2.day) return true;
			else if(time1.day<time2.day) return false;
			else if(time1.day==time2.day){
				if(time1.hour>time2.hour) return true;
				else if(time1.hour<time2.hour) return false;
				else if(time1.hour==time2.hour){
					if(time1.min>time2.min) return true;
					else if(time1.min<time2.min) return false;
					else if(time1.min==time2.min) return false;
				}
			}
		}
	}
}

#endif
