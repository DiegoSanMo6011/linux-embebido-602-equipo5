import serial.tools.list_ports

def find_serial_ports():
    ports = serial.tools.list_ports.comports()
    available_ports = []
    for port in ports:
        available_ports.append(port.device)
    return available_ports

if __name__ == "__main__":
    ports = find_serial_ports()
    print("Puertos seriales disponibles:", ports)


