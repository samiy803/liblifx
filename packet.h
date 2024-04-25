#ifndef _PACKET_H
#define _PACKET_H

#include <stdint.h>

/**
 * Each packet is composed of a header and a payload. The header is composed of 
 * a frame, frame address, and protocol header. The payload is a variable length
 * field that is dependent on the protocol header.
 * 
 * https://lan.developer.lifx.com/docs/packet-contents
*/
 struct __attribute__((packed)) lx_packet_t {
  /* frame */
  uint16_t size;
  uint16_t protocol:12;
  uint8_t  addressable:1;
  uint8_t  tagged:1;
  uint8_t  origin:2;
  uint32_t source;
  /* frame address */
  uint8_t  target[8];
  uint8_t  reserved[6];
  uint8_t  res_required:1;
  uint8_t  ack_required:1;
  uint8_t  :6;
  uint8_t  sequence;
  /* protocol header */
  uint64_t :64;
  uint16_t type;
  uint16_t :16;
  /* variable length payload follows */
};

#endif // !_PACKET_H