#ifndef BUILDING_NODE_EXTENSION
#define BUILDING_NODE_EXTENSION
#endif

#include <stdint.h>
#include <stdio.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/scrnsaver.h>
  
static int has_extension = -1;

uint32_t SystemIdleTime(void) {
  Display* dpy = XOpenDisplay(NULL);
  int event_base, error_base;

  if (!dpy) {
    return 0;
  }

  if (has_extension == -1) {
    has_extension = XScreenSaverQueryExtension(dpy, &event_base, &error_base);
  }

  if (!has_extension) {
    XCloseDisplay(dpy);
    return 0;
  }

  XScreenSaverInfo info;
  Window wnd = RootWindow(dpy, DefaultScreen(dpy));
  if (!wnd) return 60 * 60 * 1000;

  XScreenSaverQueryInfo(dpy, wnd, &info);
  XCloseDisplay(dpy);
  return (info.idle);
}
