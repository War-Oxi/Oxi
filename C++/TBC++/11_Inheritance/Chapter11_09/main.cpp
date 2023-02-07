#include <iostream>
using namespace std;

class USBDevice
{
private:
    long m_id;
public:
    USBDevice(long id) : m_id(id) {}

    long getID() { return m_id; }

    void plugAndPlay() {}
};

class NetworkDevice
{
private:
    long m_id;
public:
    NetworkDevice(long id) : m_id(id) {}

    long getID() { return m_id; }

    void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(long usb_id, long net_id)
        : USBDevice(usb_id), NetworkDevice(net_id)
    {}

    USBNetworkDevice(long id)
        : USBDevice(id), NetworkDevice(id)
    {}
};

int main() {
    USBNetworkDevice my_device(3.14, 6.022);

    my_device.plugAndPlay();
    my_device.networking();

    cout << my_device.NetworkDevice::getID() << endl;
    cout << my_device.USBDevice::getID() << endl;

    return 0;
}
