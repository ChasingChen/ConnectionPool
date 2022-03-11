src=$(wildcard *.cpp)
obj=$(patsubst %.cpp, %.o,$(src))
target=MysqlPool


%.o:%.cpp
	g++ $<  -c  -I /usr/include/mysql/


$(target):$(obj)
	g++ $^ -g -o $@  -lmysqlclient -lpthread

.PHONY:clean
clean:
	-rm $(target) *.o
