#include "nan.h"
#include "idle.h"

using namespace v8;

static NAN_METHOD(Method) {
  NanScope();

  uint32_t idle = SystemIdleTime();
  NanReturnValue(idle);
}

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "getIdleTime", Method);
}

NODE_MODULE(addon, init)
