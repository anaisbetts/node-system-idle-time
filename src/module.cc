#include "module.h"
#include "idle.h"

using namespace v8;

NAN_METHOD(IdleTime::GetIdleTime) {
  Nan::HandleScope scope;

  uint32_t idle;
  idle = SystemIdleTime();
  info.GetReturnValue().Set(idle);
}

void IdleTime::Init(Handle<Object> exports) {
  Nan::SetMethod(exports, "getIdleTime", IdleTime::GetIdleTime);
}

NODE_MODULE(system_idle_time, IdleTime::Init)
