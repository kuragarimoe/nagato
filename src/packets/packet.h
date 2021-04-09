#include <node.h>
#include <node_object_wrap.h>

#ifndef PACKET_H
#define PACKET_H

using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

namespace nagato {
    class Packet : public node::ObjectWrap {
    public:
        static void init(Local<Object> exports);

    private:
        explicit Packet();
        ~Packet();

        // properties
        char* buffer;
        int offset;

        // constructor
        static void create(const v8::FunctionCallbackInfo<v8::Value>& args);
    };
}

#endif