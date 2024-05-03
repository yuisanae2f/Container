cmake_minimum_required(VERSION 3.10)

# C Shared Project
project(ae2f_Container VERSION 1.0 LANGUAGES C)

# Sources List for Project
set(SOURCES
    src/Context.c
    src/Dimension.c
    src/Dynamic.c
    src/Map.c
    src/Pair.c
)

# Headers for library
set(HEADERS
    include/ae2fLib/Container/Context.h
    include/ae2fLib/Container/Dimension.h
    include/ae2fLib/Container/Dynamic.h
    include/ae2fLib/Container/Map.h
    include/ae2fLib/Container/Pair.h

    include/ae2fLib/Container/Context.hpp
    include/ae2fLib/Container/Dynamic.hpp
    include/ae2fLib/Container/Map.hpp
    include/ae2fLib/Container/Pair.hpp
)

# Build lib set
add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# include directory
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# install set
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(FILES ${HEADERS} DESTINATION include/ae2fLib/Container)