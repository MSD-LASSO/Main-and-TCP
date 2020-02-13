#include <iostream>
#include <winsock2.h>

using namespace std;

#define PORT 5010
#define SERVER_ADDR "127.0.0.1"
#define MSG_LEN 255

int main()
{
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN server_addr;

    char buffer[MSG_LEN] = "hello";

    // initialize winsock
    WSAStartup(MAKEWORD(2,0), &WSAData);

    // create socket
    server = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
 
    connect(server, (SOCKADDR *)&server_addr, sizeof(server_addr));
    cout << "Connected..." << endl;
 
    send(server, buffer, sizeof(buffer), 0);
    cout << "Message sent!" << endl;
 
    closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;
}
