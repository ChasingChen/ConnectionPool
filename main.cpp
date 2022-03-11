#include "pch.h"
#include <iostream>
using namespace std;
#include "Connection.h"
#include "CommonConnectionPool.h"

int main()
{
	//事先连接以下
	Connection conn;
	conn.connect("127.0.0.1", 3306, "alex", "123", "chat");

	/*Connection conn;
	char sql[1024] = { 0 };
	sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
		"zhang san", 20, "male");
	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	conn.update(sql);*/

	clock_t begin = clock();
	
/*	thread t1([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san1", 0, "male");
			conn.connect("127.0.0.1", 3306, "alex", "123", "chat");
			conn.update(sql);
		}
	});
	thread t2([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san2", 10, "male");
			conn.connect("127.0.0.1", 3306, "alex", "123", "chat");
			conn.update(sql);
		}
	});
	thread t3([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san3", 20, "male");
			conn.connect("127.0.0.1", 3306, "alex", "123", "chat");
			conn.update(sql);
		}
	});
	thread t4([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san4", 30, "male");
			conn.connect("127.0.0.1", 3306, "alex", "123", "chat");
			conn.update(sql);
		}
	});*/
	thread t5([]() {    //直接用lambda表达式
	ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san5", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
	
		}
	});
	thread t6([]() {
		ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san6", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);

		}
	});
	thread t7([]() {
		ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san7", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
	
		}
	});
	thread t8([]() {
		ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san8", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		
		}
	});

/*	t1.join();
	t2.join();
	t3.join();
	t4.join();*/
	
	t5.join();
	t6.join();
	t7.join();
	t8.join();

	clock_t end = clock();
	cout << (end - begin) << "us" << endl;


#if 0
	for (int i = 0; i < 10000; ++i)
	{
		Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			"zhang san", 20, "male");
		conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
		conn.update(sql);

		/*shared_ptr<Connection> sp = cp->getConnection();
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			"zhang san", 20, "male");
		sp->update(sql);*/
	}
#endif

	return 0;
}
