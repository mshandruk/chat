#include <gtest/gtest.h>
#include "chat_room.h"

TEST(ChatRoomTest, AddMessage)
{
    ChatRoom room;
    std::string message = "Hello Maxim!";
    room.AddMessage(message);
    const auto expected = room.GetMessages();
    ASSERT_EQ(expected.size(), 1);
    EXPECT_EQ(expected[0], message);
}

