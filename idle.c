#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/extensions/scrnsaver.h>

/* Report amount of X server idle time. */
/* Build with- */
/* cc xidle.c -o xidle -lX11 -lXext -lXss */


int main(int argc, char *argv[])
{
Display *display;
int event_base, error_base;
XScreenSaverInfo info;
int seconds;

display = XOpenDisplay("");

if (XScreenSaverQueryExtension(display, &event_base, &error_base)) {
XScreenSaverQueryInfo(display, DefaultRootWindow(display), &info);

seconds = info.idle/1000;
printf("%d\n",seconds);
return(0);
}
else {
fprintf(stderr,"Error: XScreenSaver Extension not present\n");
return(1);
}
}
