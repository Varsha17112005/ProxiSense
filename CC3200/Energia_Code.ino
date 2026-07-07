#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "simplelink.h"

// WiFi Credentials
#define SSID "Ypur_Wifi"
#define PASSWORD "Your_Password"

// ThingSpeak Details
#define API_KEY "JJUF09947W8YEHQW"
#define SERVER_IP SL_IPV4_VAL(184,106,153,149)

// Generate RSSI value (simulation)
int getRSSI()
{
    return -50 - (rand() % 30);
}

// Convert RSSI to Distance
float calculateDistance(int rssi)
{
    int txPower = -59;
    float n = 2.0;

    return pow(10.0, ((txPower - rssi) / (10 * n)));
}

// Convert Distance to Zone
int getZone(float distance)
{
    if(distance < 2)
        return 1;
    else if(distance < 5)
        return 2;
    else
        return 3;
}

// Send Data to ThingSpeak
void sendData(int rssi, float dist, int zone)
{
    int sock;
    SlSockAddrIn_t addr;
    char request[256];

    sprintf(request,
        "GET /update?api_key=%s&field1=%d&field2=%.2f&field4=%d\r\n\r\n",
        API_KEY,
        rssi,
        dist,
        zone);

    sock = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, 0);

    addr.sin_family = SL_AF_INET;
    addr.sin_port = sl_Htons(80);
    addr.sin_addr.s_addr = sl_Htonl(SERVER_IP);

    sl_Connect(sock, (SlSockAddr_t *)&addr, sizeof(addr));
    sl_Send(sock, request, strlen(request), 0);
    sl_Close(sock);
}

int main(void)
{
    int rssi, zone;
    float distance;

    // Start CC3200
    sl_Start(0, 0, 0);

    // Connect WiFi
    sl_WlanConnect(SSID, strlen(SSID), 0,
                   PASSWORD, strlen(PASSWORD));

    while(1)
    {
        // Step 1: Read RSSI
        rssi = getRSSI();

        // Step 2: Calculate Distance
        distance = calculateDistance(rssi);

        // Step 3: Identify Zone
        zone = getZone(distance);

        // Step 4: Send Data
        sendData(rssi, distance, zone);

        // Delay
        for(int i = 0; i < 8000000; i++);
    }

    return 0;
}
