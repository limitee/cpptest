#pragma once
#ifndef _MYIFTABLE_
#define _MYIFTABLE_

class MyIfTable {

public:
	MyIfTable();
	~MyIfTable();

	//��ǰ�������ֽ�����
	long cur_out_octets = 0;
	//��һ�μ�¼���ֽ�����
	long last_out_octets = 0;

	bool refresh_octets();

	//��·�ٶ�
	long speed(long milli_seconds);

private:
	
};

#endif
