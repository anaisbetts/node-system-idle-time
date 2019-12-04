#include "module.h"
#include "idle.h"

using namespace v8;

NAN_METHOD(IdleTime::GetIdleTime) {
  Nan::HandleScope scope;

  uint32_t idle;
  idle = SystemIdleTime();
  info.GetReturnValue().Set(idle);
}

NAN_MODULE_INIT(Init) {
  Nan::SetMethod(target, "getIdleTime", IdleTime::GetIdleTime);
}

#if NODE_MAJOR_VERSION >= 10
NAN_MODULE_WORKER_ENABLED(system_idle_time, Init)
#else
NODE_MODULE(system_idle_time, Init)
#endif