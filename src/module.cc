#include "module.h"
#include "idle.h"

using namespace v8;

NAN_METHOD(IdleTime::GetIdleTime) {
  NanScope();

  uint32_t idle;
  idle = SystemIdleTime();
  NanReturnValue(idle);
}

void IdleTime::Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "getIdleTime", IdleTime::GetIdleTime);
}

NODE_MODULE(system_idle_time, IdleTime::Init)
