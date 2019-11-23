a1: assignment1.cpp
	g++ -Wall assignment1.cpp dist/jsoncpp.cpp -o assignment1  -I/usr/include/cppconn  -L/usr/lib -lmysqlcppconn 

a1s: assignment1s.cpp
	g++ -Wall assignment1s.cpp dist/jsoncpp.cpp -o assignment1s  -I/usr/include/cppconn  -L/usr/lib -lmysqlcppconn 

a2: assignment2.cpp
	g++ -Wall assignment2.cpp dist/jsoncpp.cpp -o assignment2  -I/usr/include/cppconn  -L/usr/lib -lmysqlcppconn 

%: %.cpp
	g++ -Wall $@.cpp dist/jsoncpp.cpp  -o $@  -I/usr/include/cppconn  -L/usr/lib -lmysqlcppconn -std=c++11


# prog1: prog1.cpp
# 	g++ -o prog1 prog1.cpp -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

