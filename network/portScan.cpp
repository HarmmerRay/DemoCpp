#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// 函数声明
bool scanPort(const char *target, int port);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <target_ip> <port>" << std::endl;
        return 1;
    }

    const char *target = argv[1];
    int port = std::atoi(argv[2]);

    if (scanPort(target, port)) {
        std::cout << "Port " << port << " is open on " << target << std::endl;
    } else {
        std::cout << "Port " << port << " is closed on " << target << std::endl;
    }

    return 0;
}

bool scanPort(const char *target, int port) {   
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return false;
    }

    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, target, &(addr.sin_addr)) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return false;
    }

    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
        // 连接成功，端口开放
        close(sockfd);
        return true;
    } else {
        // 连接失败，端口关闭
        close(sockfd);
        return false;
    }
}
