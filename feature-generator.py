
from micromlgen import port_wifi_indoor_positioning, port

if __name__ == '__main__':
    samples = {"__location": "Kitchen", "N1": 100, "N2": 50}
    {"__location": "Bedroom", "N3": 100, "N2": 50}
    {"__location": "Bathroom", "N1": 100, "N4": 50}
    {"__location": "Bathroom", "N5": 100, "N4": 50}
    
    X, y, classmap, converter_code = port_wifi_indoor_positioning(samples)
    print(converter_code)
