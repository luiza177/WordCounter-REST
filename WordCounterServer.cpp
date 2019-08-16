#include "WordCounterServer.h"

int main(int argc, char const *argv[])
{
    Address addr(Ipv4::any(), Port(9080));

    WordCounterServer server(addr);
   
    server.init();
    server.start();

    return 0;
}