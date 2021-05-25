#pragma once
namespace Eloquent {
    namespace Projects {
        class WifiIndoorPositioning {
            public:
                float features[5] = {0};

                /**
                * Get feature vector
                */
                float* scan() {
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
                    if (ssid.equals("ACT10253404966"))
                    return 0;

                    if (ssid.equals("b1001"))
                    return 1;

                    if (ssid.equals("Akjha"))
                    return 2;

                    if (ssid.equals("ACT102404834377"))
                    return 3;

                    if (ssid.equals("DIRECT-Zr-BRAVIA"))
                    return 4;

                    return -1;
                }
            };
        }
    }
