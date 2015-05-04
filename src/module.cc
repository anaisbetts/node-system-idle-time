#include <node.h>
#include "idle.h"

#if OS == WIN
#include <stdint.h>
#endif

using namespace v8;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  uint32_t idle = SystemIdleTime();
  args.GetReturnValue().Set(Integer::New(isolate, idle));
}

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "getIdleTime", Method);
}

NODE_MODULE(addon, init)
