#pragma once
//封装日志：在哪个文件哪一行什么时间输出的
#define LOG(str) \
	cout << __FILE__ << ":" << __LINE__ << " " << \
	__TIMESTAMP__ << " : " << str << endl;