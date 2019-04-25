cmake_minimum_required(VERSION 2.8)


add_library(sqlite
				sqlite-amalgamation-3240000/sqlite3.c
				sqlite-amalgamation-3240000/sqlite3.h
				sqlite-amalgamation-3240000/shell.c
				sqlite-amalgamation-3240000/sqlite3ext.h
	)
	
add_executable(testSqlite
				./main.cpp
				./mydatabase.cpp
				./mydatabase.h
				)


if(CMAKE_COMPILER_IS_GNUCXX)
	target_link_libraries(testSqlite
					sqlite
					-ldl
					"-pthread"
					)
else(MSVC)
	target_link_libraries(testSqlite
					sqlite
					)
endif()
