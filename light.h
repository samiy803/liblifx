#ifndef _LIBLIFX_LIGHT_H
#define _LIBLIFX_LIGHT_H

#include "packet_header.h"

/*
 *******************
 * Get packets
 *******************
*/
struct __attribute__((packed)) GetColor {
    /**
     * Packet 101
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetLightPower {
    /**
     * Packet 116
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetInfrared {
    /**
     * Packet 120
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetHevCycle {
    /**
     * Packet 142
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetHevCycleConfiguration {
    /**
     * Packet 145
    */
    struct lx_packet_t header;
};

struct __attribute__((packed)) GetLastHevCycleResult {
    /**
     * Packet 148
    */
    struct lx_packet_t header;
};


/*
 *******************
 * Set packets
 *******************
*/
struct __attribute__((packed)) SetColor {
    /**
     * Packet 102
    */
    struct lx_packet_t header;
    uint8_t reserved;
    uint16_t hue;
    uint16_t saturation;
    uint16_t brightness;
    uint16_t kelvin;
    uint32_t duration;
};

struct __attribute__((packed)) SetWaveform {
    /**
     * Packet 103
    */
    struct lx_packet_t header;
    uint8_t reserved:1;
    uint8_t transient;
    uint16_t hue;
    uint16_t saturation;
    uint16_t brightness;
    uint16_t kelvin;
    uint32_t period;
    float cycles;
    uint16_t skew_ratio;
    uint8_t waveform; // TODO: enum
};

struct __attribute__((packed)) SetLightPower {
    /**
     * Packet 117
    */
    struct lx_packet_t header;
    uint16_t level;
    uint32_t duration;
};

struct __attribute__((packed)) SetWaveformOptional {
    /**
     * Packet 119
    */
    struct lx_packet_t header;
    uint8_t reserved;
    uint8_t transient;
    uint16_t hue;
    uint16_t saturation;
    uint16_t brightness;
    uint16_t kelvin;
    uint32_t period;
    float cycles;
    uint16_t skew_ratio;
    uint8_t waveform; // TODO: enum
    uint8_t set_hue;
    uint8_t set_saturation;
    uint8_t set_brightness;
    uint8_t set_kelvin;
};

struct __attribute__((packed)) SetInfrared {
    /**
     * Packet 122
    */
    struct lx_packet_t header;
    uint16_t brightness;
};

struct __attribute__((packed)) SetHevCycle {
    /**
     * Packet 143
     */
    struct lx_packet_t header;
    uint8_t enabled;
    uint32_t duration_s;
};

struct __attribute__((packed)) SetHevCycleConfiguration {
    /**
     * Packet 146
     */
    struct lx_packet_t header;
    uint8_t indication;
    uint32_t duration_s;
};

/*
 *******************
 * Response packets
 *******************
*/
struct __attribute__((packed)) LightState {
    /**
     * Packet 107
    */
    struct lx_packet_t header;
    uint16_t hue;
    uint16_t saturation;
    uint16_t brightness;
    uint16_t kelvin;
    uint8_t reserved[2];
    uint16_t power;
    uint8_t label[32];
    uint8_t reserved2[16];
};

struct __attribute__((packed)) StateLightPower {
    /**
     * Packet 118
    */
    struct lx_packet_t header;
    uint16_t level;
};

struct __attribute__((packed)) StateInfrared {
    /**
     * Packet 121
    */
    struct lx_packet_t header;
    uint16_t brightness;
};

struct __attribute__((packed)) StateHevCycle {
    /**
     * Packet 144
    */
    struct lx_packet_t header;
    uint32_t duration_s;
    uint32_t remaining_s;
    uint8_t lower_power;
};

struct __attribute__((packed)) StateHevCycleConfiguration {
    /**
     * Packet 147
    */
    struct lx_packet_t header;
    uint8_t indication;
    uint32_t duration_s;
};

/*
 *******************
 * Get packet constructors
 *******************
*/
GetColor *GetColor_New(uint32_t source, uint8_t target[8], uint8_t reserved[6], uint8_t res_required, uint8_t ack_required, uint8_t sequence);
GetLightPower *GetLightPower_New(uint32_t source, uint8_t target[8], uint8_t reserved[6], uint8_t res_required, uint8_t ack_required, uint8_t sequence);
GetInfrared *GetInfrared_New(uint32_t source, uint8_t target[8], uint8_t reserved[6], uint8_t res_required, uint8_t ack_required, uint8_t sequence);
GetHevCycle *GetHevCycle_New(uint32_t source, uint8_t target[8], uint8_t reserved[6], uint8_t res_required, uint8_t ack_required, uint8_t sequence);
GetHevCycleConfiguration *GetHevCycleConfiguration_New(uint32_t source, uint8_t target[8], uint8_t reserved[6], uint8_t res_required, uint8_t ack_required, uint8_t sequence);
GetLastHevCycleResult *GetLastHevCycleResult_New(uint32_t source, uint8_t target[8], uint8_t reserved[6], uint8_t res_required, uint8_t ack_required, uint8_t sequence);


/*
 *******************
 * Set packet constructors
 *******************
*/
SetColor *SetColor_New(uint32_t source, uint8_t target[8], uint8_t sequence, uint16_t hue, uint16_t saturation, uint16_t brightness, uint16_t kelvin, uint32_t duration);
SetWaveform *SetWaveform_New(uint32_t source, uint8_t target[8], uint8_t sequence, uint8_t transient, uint16_t hue, uint16_t saturation, uint16_t brightness, uint16_t kelvin, uint32_t period, float cycles, uint16_t skew_ratio, uint8_t waveform);
SetLightPower *SetLightPower_New(uint32_t source, uint8_t target[8], uint8_t sequence, uint16_t level, uint32_t duration);
SetWaveformOptional *SetWaveformOptional_New(uint32_t source, uint8_t target[8], uint8_t sequence, uint8_t transient, uint16_t hue, uint16_t saturation, uint16_t brightness, uint16_t kelvin, uint32_t period, float cycles, uint16_t skew_ratio, uint8_t waveform, uint8_t set_hue, uint8_t set_saturation, uint8_t set_brightness, uint8_t set_kelvin);
SetInfrared *SetInfrared_New(uint32_t source, uint8_t target[8], uint8_t sequence, uint16_t brightness);
SetHevCycle *SetHevCycle_New(uint32_t source, uint8_t target[8], uint8_t sequence, uint8_t enabled, uint32_t duration_s);
SetHevCycleConfiguration *SetHevCycleConfiguration_New(uint32_t source, uint8_t target[8], uint8_t sequence, uint8_t indication, uint32_t duration_s);

/*
 *******************
 * Get packet destructors
 *******************
*/
void GetColor_Delete(GetColor *get_color);
void GetLightPower_Delete(GetLightPower *get_light_power);
void GetInfrared_Delete(GetInfrared *get_infrared);
void GetHevCycle_Delete(GetHevCycle *get_hev_cycle);
void GetHevCycleConfiguration_Delete(GetHevCycleConfiguration *get_hev_cycle_configuration);
void GetLastHevCycleResult_Delete(GetLastHevCycleResult *get_last_hev_cycle_result);


/*
 *******************
 * Set packet destructors
 *******************
*/
void SetColor_Delete(SetColor *set_color);
void SetWaveform_Delete(SetWaveform *set_waveform);
void SetLightPower_Delete(SetLightPower *set_light_power);
void SetWaveformOptional_Delete(SetWaveformOptional *set_waveform_optional);
void SetInfrared_Delete(SetInfrared *set_infrared);
void SetHevCycle_Delete(SetHevCycle *set_hev_cycle);
void SetHevCycleConfiguration_Delete(SetHevCycleConfiguration *set_hev_cycle_configuration);



#endif // !_LIBLIFX_LIGHT_H