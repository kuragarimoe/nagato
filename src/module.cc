#include <node.h>
#include <nan.h>
#include "packets/packet.h"

using v8::Local;
using v8::Object;

namespace nagato {
    void Module(Local<Object> exports) {
        Packet::init(exports);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Module);
}