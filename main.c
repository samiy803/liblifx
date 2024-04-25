#include "packet.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <assert.h>

struct __attribute__((packed)) SetColor {
    struct lx_packet_t header;
    uint8_t reserved;
    uint16_t hue;
    uint16_t saturation;
    uint16_t brightness;
    uint16_t kelvin;
    uint32_t duration;
};


int main() {
    // Some compiler (MSVC) do not support the __attribute__((packed)) directive, and require
    // the use of #pragma pack(1) instead. I don't want to add IFDEFs for all the compilers
    // that do not support the __attribute__((packed)) directive, so as long as the size of
    // the struct is 49 bytes, I will assume that the compiler is packing the struct correctly.
    // If this assertion fails, you may need to use a different compiler or add a pragma to your code.
    assert(sizeof(struct SetColor) == 49
        && "Please check that your compiler respects the __attribute__((packed)) directive. If not, you may need to use a different compiler or add a pragma to your code.");

    int sockfd;
    struct sockaddr_in server_addr;

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    int broadcastEnable=1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)) < 0) {
        perror("setsockopt");
        exit(1);
    }


    // Fill in the server's address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(56700);
    server_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    // Create a SetColor packet
    struct SetColor packet;
    memset(&packet, 0, sizeof(packet));
    packet.header.size = sizeof(packet);
    packet.header.protocol = 1024;
    packet.header.addressable = 1;
    packet.header.tagged = 1;
    // packet.header.origin = 0;
    packet.header.source = 6969; // temp
    // memset(packet.header.target, 0, sizeof(packet.header.target));
    // memset(packet.header.reserved, 0, sizeof(packet.header.reserved));
    // packet.header.res_required = 0;
    // packet.header.ack_required = 0;
    packet.header.sequence = 0;
    // packet.reserved = 0;
    packet.header.type = 102;
    packet.hue = 65535;
    packet.saturation = 65535;
    packet.brightness = 65535;
    packet.kelvin = 3500;
    // packet.duration = 0;

    // const uint8_t p[] = {0x31, 0x00, 0x00, 0x34, 0xf4, 0x18, 0x53, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x72, 0xaa, 0xff, 0xff, 0xff, 0xff, 0xac, 0x0d, 0x00, 0x00, 0x00, 0x00};

    // Send the packet
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("sendto");
        exit(1);
    }

    return 0;
}
