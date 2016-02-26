#include "osd.h"

/* OS-dependant code to get a character from the user.
 * This function must not block, and must either return an ASCII code or -1.
 */
#include <stdio.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stropts.h>

int kbhit() {
    static const int STDIN = 0;
    static int initialized = 0;

    if (! initialized) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = 1;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

int osd_get_char(void)
{
	int ch = -1;
	if(kbhit())
	{
		while(kbhit())
			ch = getchar();
	}
	return ch;
}
