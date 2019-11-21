prog2: prog2.cpp
	g++ -Wall prog2.cpp -o prog2  -I/usr/include/cppconn  -L/usr/lib -lmysqlcppconn -std=c++11


%: %.cpp
	g++ -Wall $@.cpp -o $@  -I/usr/include/cppconn  -L/usr/lib -lmysqlcppconn -std=c++11


# prog1: prog1.cpp
# 	g++ -o prog1 prog1.cpp -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

