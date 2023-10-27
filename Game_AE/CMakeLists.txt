set(HEADER_FILES 
	
)
set(SOURCE_FILES 
	main.cpp
)

add_executable(Game_AE ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(Game_AE VividVerse)
include_directories(../VividVerse/include)