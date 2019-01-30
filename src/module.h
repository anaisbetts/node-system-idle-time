#ifndef SRC_MODULE_H_
#define SRC_MODULE_H_

#include "nan.h"

using namespace v8;

class IdleTime {
public:
  static void Init(Local<Object> exports);
  static NAN_METHOD(GetIdleTime);
};

#endif
