#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror("socket");
        return 1;
    }
    printf("Socket created successfully! fd = %d\n", fd);

    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    int result = bind(fd, (const sockaddr *)&addr, sizeof(addr));
    if (result < 0)
    {
        perror("bind");
        close(fd);
        return 1;
    }
    printf("Socket bound successfully!\n");

    result = listen(fd, 5);
    if (result < 0)
    {
        perror("listen");
        close(fd);
        return 1;
    }
    printf("Server is listening on port 1234!\n");

    int conn_fd = accept(fd, nullptr, nullptr);
    if (conn_fd < 0)
    {
        perror("accept");
        close(fd);
        return 1;
    }
    printf("Connection accepted! fd = %d\n", conn_fd);

    char buffer[1024];
    ssize_t n = read(conn_fd, buffer, sizeof(buffer) - 1);
    if (n < 0)
    {
        perror("read");
        close(conn_fd);
        close(fd);
        return 1;
    }
    buffer[n] = '\0';
    printf("Received message: %s\n", buffer);

    const char *response = "Hello from server!\n";
    ssize_t bytes_written = write(conn_fd, response, strlen(response));
    if (bytes_written < 0)
    {
        perror("write");
        close(conn_fd);
        close(fd);
        return 1;
    }
    printf("Sent response: %s", response);
    printf("Bytes written: %zd\n", bytes_written);

    close(conn_fd);
    close(fd);
    return 0;
}
