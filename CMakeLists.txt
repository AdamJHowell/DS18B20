cmake_minimum_required( VERSION 3.24 )
project( DS19B20 )

set( CMAKE_CXX_STANDARD 17 )

add_executable( DS19B20
		DS18B20.ino )

set_target_properties( DS19B20 PROPERTIES LINKER_LANGUAGE CXX )
