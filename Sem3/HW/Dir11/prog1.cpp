#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

const int SIZE = 256;
const char* ch = "10.55.128.113";


int main()
{
    char message[SIZE] = "Hello";
    char buf[SIZE];
    int sock, name;
    struct sockaddr_in addr;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        printf ("socket\n");
        return 1;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10001);
    
    if ((inet_aton (ch, &addr.sin_addr)) == 0) {
        printf("inet\n");
        return 2;
    }
    
    /*
    send(sock, message, sizeof(message), 0);
    recv(sock, buf, sizeof(message), 0);
    */
    
    
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("connect\n");
        return 3;
    }
    
    for (;strcmp(message, "exit") != 0;) {
        
        printf(":>");
        for (;scanf("%d %255[^\n]%*c", &name, message) == 0; ) {};
        
        if (strcmp(message, "exit") != 0) {if (strcmp(message, "show") != 0) {
            if (strcmp(message, "list") != 0) {
                //отправка
                send(sock, message, sizeof(message), 0);
            } else {
                //печать листа пользователей
                
            }
        } else {
            //показ сообщений
            recv(sock, buf, sizeof(message), 0);
            printf("%s\n", buf);
        }
        }
    }
    
    
    close(sock);
    
    
    return 0;
}


/*
 /Documents/GitHub/EDU/Sem3/HW/Dir11
 
 
 Ifconfig
 Посмотреть конфигурацию сети , он отображает текущую конфигурацию сетевого адаптера
 */