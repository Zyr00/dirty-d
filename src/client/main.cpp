#include "../../includes/common.h"

int main(void) {
  int server_fd, bytes_size;
  SA_IN serv_addr;
  char buffer[1025];
  std::string hello = "THIS IS THE MESSAGE";

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(server_fd, (SA *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  write(server_fd, hello.c_str(), hello.size());
  std::cout << "Message sended\n" << std::endl;

  bytes_size = read(server_fd, buffer, 1024);
  buffer[bytes_size] = '\0';
  std::cout << buffer << std::endl;
  return 0;
}
