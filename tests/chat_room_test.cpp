#include <gtest/gtest.h>
#include "chat_room.h"

TEST(ChatRoomTest, AddMessage)
{
    ChatRoom room;
    std::string message = "Hello Maxim!";
    room.addMessage(message);
    const auto expected = room.getMessages();
    ASSERT_EQ(expected.size(), 1);
    EXPECT_EQ(expected[0], message);
}

