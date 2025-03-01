#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;

void startClient(const char *address, uint16_t port);

int main()
{
    startClient("127.0.0.1", 12889);
}

void startClient(const char *address, const uint16_t port)
{
    io_context io;
    tcp::socket socket(io);
    try
    {
        socket.connect(tcp::endpoint(ip::address::from_string(address), port));
        std::string message;
        while (true)
        {
            std::cout << "Enter message: ";
            std::getline(std::cin, message);
            write(socket, buffer(message));

            char response[1024]{};
            std::memset(response, 0, sizeof(response));
            socket.read_some(buffer((response)));
            std::cout << "Server" << response << std::endl;
        }
    } catch (const std::exception &err)
    {
        std::cerr << "Client error: " << err.what() << std::endl;
    }
}
