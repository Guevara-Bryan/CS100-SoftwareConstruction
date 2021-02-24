CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(googletest/include)

ADD_EXECUTABLE( test
    test/unit_test.cpp
    src/ListContainer.cpp
    src/SelectionSort.cpp
    src/vectorcontainer.cpp
    src/bubblesort.cpp
)


ADD_EXECUTABLE(mainTest
    src/mainTest.cpp
    src/ListContainer.cpp
    src/SelectionSort.cpp
    src/vectorcontainer.cpp
    src/bubblesort.cpp
    src/SelectionSort.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)