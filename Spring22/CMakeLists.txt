set(HEADER_FILES
	Entity.h
	SpringApp.h
)

set(SOURCE_FILES
	Entity.cpp
	SpringApp.cpp
	main.cpp
)

add_executable(Spring22 ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Indev)

target_link_libraries(Spring22 Indev)

file(COPY ../Indev/Assets DESTINATION ${PROJECT_BINARY_DIR}/Spring22)
file(COPY ../Indev/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY ../Indev/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)