cmake_minimum_required(VERSION 3.10)

add_executable(chat_room_test chat_room_test.cpp ../src/chat_room.cpp)
target_link_libraries(chat_room_test PRIVATE gtest gtest_main ${Boost_LIBRARIES} pthread)

enable_testing()

add_test(NAME ChatRoomTest COMMAND chat_room_test)
