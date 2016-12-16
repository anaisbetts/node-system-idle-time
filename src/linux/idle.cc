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
  uint32_t idle_time = 0;
  XScreenSaverInfo info;
  Window wnd;

  if (!dpy) {
    return 0;
  }

  if (has_extension == -1) {
    has_extension = XScreenSaverQueryExtension(dpy, &event_base, &error_base);
  }

  if (has_extension) {
    wnd = RootWindow(dpy, DefaultScreen(dpy));

    if (!wnd) {
      idle_time = 60*60*1000;
    } else {
      XScreenSaverQueryInfo(dpy, wnd, &info);
      idle_time = info.idle;
    }
  }

  XCloseDisplay(dpy);
  return idle_time;
}
