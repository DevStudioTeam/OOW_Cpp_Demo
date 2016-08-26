#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>

#include <stdio.h> 
#include <math.h>

using namespace std;

int print_uname() {

    struct utsname sysinfo;

    errno = 0;
    if (uname(&sysinfo) < 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    cout << "System Name: " << sysinfo.sysname << endl;
    cout << "Host Name: " << sysinfo.nodename << endl;
    cout << "Release(Kernel) Version: " << sysinfo.release << endl;
    cout << "Kernel Build Timestamp: " << sysinfo.version << endl;
    cout << "Machine Arch: " << sysinfo.machine << endl;

#ifdef _GNU_SOURCE
    cout << "Domain Name: " << sysinfo.domainname << endl;
#endif

    return EXIT_SUCCESS;
}

void error_prone() {
    char buffer[10];
//    sprintf(buffer, "The message is %s", "Hello World! I'm presenting you a typical overflow");
    snprintf(buffer, sizeof (buffer), "%s", "Hello World! No buffer issues here");
}

int main() {
    print_uname();
    error_prone();
}