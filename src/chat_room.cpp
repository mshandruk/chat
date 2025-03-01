#include "chat_room.h"


void ChatRoom::addMessage(const std::string &message)
{
    std::lock_guard<std::mutex> lock(mutex_);
    messages_.push_back(message);
}


std::vector<std::string> ChatRoom::getMessages()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return messages_;
}
