#include "chat_room.h"


void ChatRoom::AddMessage(const std::string &message)
{
    std::lock_guard<std::mutex> lock(mutex_);
    messages_.push_back(message);
}


std::vector<std::string> ChatRoom::GetMessages()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return messages_;
}
