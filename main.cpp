#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>

using namespace std;

int main(void) {

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