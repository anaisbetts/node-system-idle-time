#import <CoreFoundation/CoreFoundation.h>
#import <IOKit/IOKitLib.h>

/**
 Returns the number of seconds the machine has been idle or -1 if an error occurs.
 The code is compatible with Tiger/10.4 and later (but not iOS).
 */
int32_t SystemIdleTime(void) {
  int32_t idlesecs = -1;
  io_iterator_t iter = 0;
  if (IOServiceGetMatchingServices(kIOMasterPortDefault, IOServiceMatching("IOHIDSystem"), &iter) == KERN_SUCCESS) {
    io_registry_entry_t entry = IOIteratorNext(iter);
    if (entry) {
      CFMutableDictionaryRef dict = NULL;
      if (IORegistryEntryCreateCFProperties(entry, &dict, kCFAllocatorDefault, 0) == KERN_SUCCESS) {
        CFNumberRef obj = (CFNumberRef) CFDictionaryGetValue(dict, CFSTR("HIDIdleTime"));
        if (obj) {
          int64_t nanoseconds = 0;
          if (CFNumberGetValue(obj, kCFNumberSInt64Type, &nanoseconds)) {
            idlesecs = (int32_t) (nanoseconds / 1000L*1000L);
          }
        }
        CFRelease(dict);
      }
      IOObjectRelease(entry);
    }
    IOObjectRelease(iter);
  }
  return idlesecs;
}
