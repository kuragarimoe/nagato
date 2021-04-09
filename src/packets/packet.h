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

namespace nagato
{
    class Packet : public node::ObjectWrap
    {
    public:
        static void init(Local<Object> exports);

        // properties
        char *buffer;
        int offset;

    private:
        explicit Packet();
        explicit Packet(char *buffer);
        ~Packet();

        // constructor
        static void create(const FunctionCallbackInfo<v8::Value> &args);
        static void write(const FunctionCallbackInfo<Value> &args);
    };
}

#endif