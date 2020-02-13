#include <iostream>
#include <winsock2.h>
 
using namespace std;

#define PORT 5010
#define MSG_LEN 255
 
int main()
{
    WSADATA WSAData;
 
    SOCKET server, client;
 
    SOCKADDR_IN server_addr, client_addr;
    int clientaddr_size = sizeof(client_addr);
 
    char buffer[MSG_LEN];

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
 
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
 
    bind(server, (SOCKADDR *)&server_addr, sizeof(server_addr));
    listen(server, 0);
 
    cout << "Waiting for client..." << endl;

    if((client = accept(server, (SOCKADDR *)&client_addr, &clientaddr_size)) != INVALID_SOCKET)
    {
        cout << "connected..." << endl;
        recv(client, buffer, sizeof(buffer), 0);
        cout << "Client: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));
 
        closesocket(client);
    }
}
