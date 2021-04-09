#include <node.h>
#include <node_object_wrap.h>

#include "packet.h"

using v8::Context;
using v8::Exception;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::ObjectTemplate;
using v8::String;
using v8::Value;

namespace nagato {
    Packet::Packet() {
        this->offset = 0;
        this->buffer = new char[0]();
    }

    Packet::~Packet() {
        // empty
    }

    void Packet::init(Local<Object> exports) {
        Isolate* isolate = exports->GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();

        // create object template
        Local<ObjectTemplate> addon_data_tpl = ObjectTemplate::New(isolate);
        addon_data_tpl->SetInternalFieldCount(1);  // 1 field for the MyObject::New()
        Local<Object> addon_data = addon_data_tpl->NewInstance(context).ToLocalChecked();

        // prepare constructor template
        Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, Packet::create, addon_data);
        tpl->SetClassName(String::NewFromUtf8(isolate, "Packet").ToLocalChecked());
        tpl->InstanceTemplate()->SetInternalFieldCount(0);

        // Prototype

        // constructor
        Local<Function> constructor = tpl->GetFunction(context).ToLocalChecked();
        addon_data->SetInternalField(0, constructor);
        exports->Set(context, String::NewFromUtf8(
            isolate, "Packet").ToLocalChecked(),
            constructor).FromJust();
    }

    void Packet::create(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();

        if (!args.IsConstructCall()) {
            isolate->ThrowException(Exception::ReferenceError(
                        String::NewFromUtf8(isolate,
                        "Improperly tried to construct a packet.").ToLocalChecked()));
            return;
        }

        
        if (args.Length() < 1) {
            // empty contructor
            Packet* obj = new Packet();

            // wrap object around the arguments
            obj->Wrap(args.This());

            // then return it
            args.GetReturnValue().Set(args.This());
        } else {
            // handle a buffer
            Nan::MaybeLocal<v8::Object> buf = Nan::NewBuffer()(args[0]->ToObject());
        }
    }
}