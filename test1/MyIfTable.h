#pragma once
#ifndef _MYIFTABLE_
#define _MYIFTABLE_

class MyIfTable {

public:
	MyIfTable();
	~MyIfTable();

	//��ǰ�������ֽ�����
	long cur_out_octets = 0;

	bool refresh_octets();

private:
	
};

#endif
