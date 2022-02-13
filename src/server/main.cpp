#include "../../includes/common.h"

#define MAX 5

int main(void) {
  int server_fd, client_fd, client_size;
  SA_IN server_addr, client_addr;

  client_size = sizeof(SA_IN);

  if ((server_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    std::perror("\n\nERROR GETTING SOCKET.\n\n");
    return EXIT_FAILURE;
  }
  std::cout << "Created socket" << std::endl;

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  if (bind(server_fd, (SA *) &server_addr, sizeof(SA)) < 0) {
    std::perror("\n\nERROR BINDING SOCKET.\n\n");
    return EXIT_FAILURE;
  }

  if (listen(server_fd, MAX) < 0)  {
    std::perror("\n\nERROR SET SOCKET TO LISTEN.\n\n");
    return EXIT_FAILURE;
  }

  std::cout << "Waiting for connections" << std::endl;
  while ((client_fd = accept(server_fd, (SA *) &client_addr, (socklen_t *) &client_size)) >= 0) {
    char buffer[1025];
    read(client_fd, buffer, 1024);
    std::cout << "Message: " << buffer << std::endl;

    char sendBuff[1025];
    strcpy(sendBuff, "Message from server");
    write(client_fd, sendBuff, strlen(sendBuff));
    close(client_fd);

    std::cout << "Waiting for connections" << std::endl;
  }

  return EXIT_SUCCESS;
}
