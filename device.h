#ifndef _LIBLIFX_DEVICE_H
#define _LIBLIFX_DEVICE_H

#include "packet_header.h"

/*
 *******************
 * Get packets
 *******************
*/
struct __attribute__((packed)) GetHostFirmware {
    /**
     * Packet 14
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetWifiInfo {
    /**
     * Packet 16
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetWifiFirmware {
    /**
     * Packet 18
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetPower {
    /**
     * Packet 20
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetLabel {
    /**
     * Packet 23
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetVersion {
    /**
     * Packet 32
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetInfo {
    /**
     * Packet 34
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetLocation {
    /**
     * Packet 48
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetGroup {
    /**
     * Packet 51
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) EchoRequest {
    /**
     * Packet 58
    */
    struct lx_packet_t header;
    uint8_t payload[64];
};


/*
 *******************
 * Set packets
 *******************
*/
struct __attribute__((packed)) SetPower {
    /**
     * Packet 21
    */
    struct lx_packet_t header;
    uint16_t level;
};

struct __attribute__((packed)) SetLabel {
    /**
     * Packet 24
    */
    struct lx_packet_t header;
    uint8_t label[32];
};


struct __attribute__((packed)) SetReboot {
    /**
     * Packet 38
    */
    struct lx_packet_t header;
};


struct __attribute__((packed)) SetLocation {
    /**
     * Packet 49
    */
    struct lx_packet_t header;
    uint8_t location[16];
    uint8_t label[32];
    uint64_t updated_at;
};

struct __attribute__((packed)) SetGroup {
    /**
     * Packet 52
    */
    struct lx_packet_t header;
    uint8_t group[16];
    uint8_t label[32];
    uint64_t updated_at;
};

/*
 *******************
 * Response packets
 *******************
*/
struct __attribute__((packed)) StateHostFirmware {
    /**
     * Packet 15
    */
    struct lx_packet_t header;
    uint64_t build;
    uint8_t reserved[8];
    uint16_t version_minor;
    uint16_t version_major;
};

/*
Pseudo code for StateWifiInfo
rssi = int(floor(10 * Log10(signal) + 0.5))

if rssi < 0 or rssi == 200:
    if rssi == 200:
        status = "No signal"
    else if rssi <= -80:
        status = "Very bad signal"
    else if rssi <= -70:
        status = "Somewhat bad signal"
    else if rssi <= -60:
        status = "Alright signal"
    else:
        status = "Good signal"

if rssi == 4 or rssi == 5 or rssi == 6:
    status = "Very bad signal"

elif rssi >= 7 and rssi <= 11:
    status = "Somewhat bad signal"

elif rssi >= 12 and rssi <= 16:
    status = "Alright signal";

elif rssi > 16:
    status = "Good signal"

else:
    status = "No signal"
*/

struct __attribute__((packed)) StateWifiInfo {
    /**
     * Packet 17
    */
    struct lx_packet_t header;
    float signal; // varies by product. see the pseudo code above
    uint8_t reserved[10];
};

struct __attribute__((packed)) StateWifiFirmware {
    /**
     * Packet 19
    */
    struct lx_packet_t header;
    uint64_t build;
    uint8_t reserved[8];
    uint16_t version_minor;
    uint16_t version_major;
};

struct __attribute__((packed)) StatePower {
    /**
     * Packet 22
    */
    struct lx_packet_t header;
    uint16_t level;
};

struct __attribute__((packed)) StateLabel {
    /**
     * Packet 25
    */
    struct lx_packet_t header;
    uint8_t label[32];
};

struct __attribute__((packed)) StateVersion {
    /**
     * Packet 33
    */
    struct lx_packet_t header;
    uint32_t vendor;
    uint32_t product;
    uint8_t reserved[4];
};

struct __attribute__((packed)) StateInfo {
    /**
     * Packet 35
    */
    struct lx_packet_t header;
    uint64_t time;
    uint64_t uptime;
    uint64_t downtime;
};

struct __attribute__((packed)) StateLocation {
    /**
     * Packet 50
    */
    struct lx_packet_t header;
    uint8_t location[16];
    uint8_t label[32];
    uint64_t updated_at;
};

struct __attribute__((packed)) StateGroup {
    /**
     * Packet 53
    */
    struct lx_packet_t header;
    uint8_t group[16];
    uint8_t label[32];
    uint64_t updated_at;
};

struct __attribute__((packed)) EchoResponse {
    /**
     * Packet 59
    */
    struct lx_packet_t header;
    uint8_t payload[64];
};

struct __attribute__((packed)) StateUnhandled {
    /**
     * Packet 223
    */
    struct lx_packet_t header;
    uint16_t type;
};

/*
 *******************
 * Get packet constructors
 *******************
*/
GetHostFirmware *GetHostFirmware_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetWifiInfo *GetWifiInfo_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetWifiFirmware *GetWifiFirmware_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetPower *GetPower_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetLabel *GetLabel_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetVersion *GetVersion_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetInfo *GetInfo_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetLocation *GetLocation_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
GetGroup *GetGroup_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
EchoRequest *EchoRequest_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);


/*
 *******************
 * Set packet constructors
 *******************
*/
SetPower *SetPower_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence, uint16_t level = 0);
SetLabel *SetLabel_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence, uint8_t label[32] = 0);
SetReboot *SetReboot_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence);
SetLocation *SetLocation_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence, uint8_t location[16] = 0, uint8_t label[32] = 0, uint64_t updated_at = 0);
SetGroup *SetGroup_New(bool tagged, uint32_t source, uint8_t target[8], uint8_t sequence, uint8_t group[16] = 0, uint8_t label[32] = 0, uint64_t updated_at = 0);


/*
 *******************
 * Get packet destructors
 *******************
*/
void GetHostFirmware_Delete(GetHostFirmware *get_host_firmware);
void GetWifiInfo_Delete(GetWifiInfo *get_wifi_info);
void GetWifiFirmware_Delete(GetWifiFirmware *get_wifi_firmware);
void GetPower_Delete(GetPower *get_power);
void GetLabel_Delete(GetLabel *get_label);
void GetVersion_Delete(GetVersion *get_version);
void GetInfo_Delete(GetInfo *get_info);
void GetLocation_Delete(GetLocation *get_location);
void GetGroup_Delete(GetGroup *get_group);
void EchoRequest_Delete(EchoRequest *echo_request);


/*
 *******************
 * Set packet destructors
 *******************
*/
void SetPower_Delete(SetPower *set_power);
void SetLabel_Delete(SetLabel *set_label);
void SetReboot_Delete(SetReboot *set_reboot);
void SetLocation_Delete(SetLocation *set_location);
void SetGroup_Delete(SetGroup *set_group);



#endif // !_LIBLIFX_DEVICE_H