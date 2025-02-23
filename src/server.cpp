#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using namespace boost::asio;
using ip::tcp;

void handleClient(tcp::socket socket);


int main()
{
    try
    {
        io_context io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 12345));
        std::cout << "Server started on port 12345" << std::endl;
        while (true)
        {
            tcp::socket socket(io);
            acceptor.accept(socket);
            std::cout << "New client connected!" << std::endl;
            std::thread(handleClient, std::move(socket)).detach();
        }
    } catch (const std::exception &err)
    {
        std::cout << "Server error: " << err.what() << std::endl;
    }

    return 0;
}

void handleClient(tcp::socket socket)
{
    char data[1024]{};
    try
    {
        while (true)
        {
            std::memset(data, 0, sizeof(data));
            const size_t length = socket.read_some(buffer(data));
            if (length > 0)
            {
                std::cout << "Received: " << data << std::endl;
                write(socket, buffer("Message Received\n"));
            }
        }
    } catch (const std::exception &err)
    {
        std::cerr << "Client disconnected: " << err.what() << std::endl;
    }
}
