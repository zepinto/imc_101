#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <UDP/DatagramSocket.h>
#define LAUVXPLORE1 (30)
using namespace IMC;

int main() {
    char localhost[] = "127.0.0.1";
    Abort abort;                // create Abort message
    abort.setTimeStamp();       // set timestamp to current time                       
    abort.setDestination(LAUVXPLORE1);   // specify destination (otherwise DUNE will reject it)
    int size = abort.getSerializationSize();    // calculate bytes required for serialization
    char buffer[size];                          // allocate same number of bytes
    
    Packet::serialize(&abort, (uint8_t *) buffer, size);    // serialize message
    DatagramSocket socket(6002, localhost, true, true);     // see https://github.com/butcherg/DatagramSocket
    socket.sendTo(buffer, size, localhost);                 // send message to 127.0.0.1:6002
}
