#pragma once
#ifndef _MYIFTABLE_
#define _MYIFTABLE_

class MyIfTable {

public:
	MyIfTable();
	~MyIfTable();

	//当前出网的字节总量
	long cur_out_octets = 0;
	//上一次记录的字节总量
	long last_out_octets = 0;

	bool refresh_octets();

	//网路速度
	long speed(long milli_seconds);

private:
	
};

#endif
