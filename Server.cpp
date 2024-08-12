#pragma comment (lib, "ws2_32.lib") // Ётот код используйтс€ дл€ автомотической свз€и с библиотекой сокета ws2_32.lib
#define WINSOCK_DEPREACTED_NO_WARNINGS
#include <winsock2.h> // дл€ работы с функци€ми winsock
#include <iostream>

int main() {
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) { // incilization Winsock 
		std::cout << "WSA ERROR" << std::endl;
	}
	else {
		std::cout << "SERVER STARTED" << std::endl
	}
	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP_ADDRES (127.0.0.1) - local addres PC
	addr.sin_port = htons(9123); // PORT 
	addr.sin_family = AF_INET; // family seti , in ploblem IPv4

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // created socket with listen opening
	bind(sListen, (SOCKADDR*)&addr, sizeofaddr); // bind addres with socket 
	listen(sListen, SOMAXCONN); // translate socket listen in style opening conneted
	
	SOCKET newConnection; // Socket dlya connetction with new client
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr); // Accepted connected opening
	if (newConnection == 0) {
		std::cout << "Accept error" << std::endl;
	else {
		std::cout << "Client connected!";
	}
	}
 




}
