#include<ESP8266WiFi.h>
#pragma once
namespace Eloquent {
    namespace Projects {
        class WifiIndoorPositioning {
            public:
                /**
                * Get feature vector
                */
                float* getFeatures() {
                    static float features[5] = {0};
                    uint8_t numNetworks = WiFi.scanNetworks();

                    for (uint8_t i = 0; i < 5; i++) {
                        features[i] = 0;
                    }

                    for (uint8_t i = 0; i < numNetworks; i++) {
                        int featureIdx = ssidToFeatureIdx(WiFi.SSID(i));

                        if (featureIdx >= 0) {
                            features[featureIdx] = WiFi.RSSI(i);
                        }
                    }

                    return features;
                }

            protected:
                /**
                * Convert SSID to featureIdx
                */
                int ssidToFeatureIdx(String ssid) {
                    if (ssid.equals("N1"))
                    return 0;

                    if (ssid.equals("N2"))
                    return 1;

                    if (ssid.equals("N3"))
                    return 2;

                    if (ssid.equals("N4"))
                    return 3;

                    if (ssid.equals("N5"))
                    return 4;

                    return -1;
                }
            };
        }
    }
