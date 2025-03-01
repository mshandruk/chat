#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>
#include <mutex>

class ChatRoom
{
public:
    void AddMessage(const std::string &message);

    std::vector<std::string> GetMessages();

private:
    std::vector<std::string> messages_;
    std::mutex mutex_;
};


#endif //CHATROOM_H
