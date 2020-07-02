
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <UDP/DatagramSocket.h>

using namespace IMC;

int main(int argc, char** argv) {
	std::cout << "What??" << std::endl;

    char localhost[] = "127.0.0.1";
    int i = 0;
    DatagramSocket socket(30101, localhost, true, true);     // see https://github.com/butcherg/DatagramSocket
    unsigned char data[64*1024];

    while (1) {
    	long bytes_read = socket.receive((char*)data, 64*1024);
    	if (bytes_read > 0) {
    	  	Message * received = Packet::deserialize(data, (int) bytes_read);
    	  	received->toJSON(std::cout);
    	}
    }
}
