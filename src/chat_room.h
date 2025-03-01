#ifndef CHATROOM_H
#define CHATROOM_H

#include <mutex>
#include <string>
#include <vector>

class ChatRoom
{
public:
    void addMessage(const std::string &message);

    std::vector<std::string> getMessages();

private:
    std::vector<std::string> messages_;
    std::mutex mutex_;
};


#endif // CHATROOM_H
