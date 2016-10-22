#include "MyIfTable.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "IPHLPAPI.lib")
#include <iphlpapi.h>

#include <iostream>

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

MyIfTable::MyIfTable() {
	std::cout << "this is myiftable" << std::endl;
}

MyIfTable::~MyIfTable() {
	std::cout << "destroy myiftable" << std::endl;
}

bool MyIfTable::refresh_octets() {
	// Declare and initialize variables.

	DWORD dwSize = 0;
	DWORD dwRetVal = 0;

	unsigned int i, j;

	/* variables used for GetIfTable and GetIfEntry */
	MIB_IFTABLE *pIfTable;
	MIB_IFROW *pIfRow;

	// Allocate memory for our pointers.
	pIfTable = (MIB_IFTABLE *)MALLOC(sizeof(MIB_IFTABLE));
	if (pIfTable == NULL) {
		std::cout << "Error allocating memory needed to call GetIfTable" << std::endl;
		return FALSE;
	}
	// Make an initial call to GetIfTable to get the
	// necessary size into dwSize
	dwSize = sizeof(MIB_IFTABLE);
	if (GetIfTable(pIfTable, &dwSize, FALSE) == ERROR_INSUFFICIENT_BUFFER) {
		FREE(pIfTable);
		pIfTable = (MIB_IFTABLE *)MALLOC(dwSize);
		if (pIfTable == NULL) {
			std::cout << "Error allocating memory needed to call GetIfTable\n";
			return FALSE;
		}
	}

	// Make a second call to GetIfTable to get the actual
	// data we want.
	if ((dwRetVal = GetIfTable(pIfTable, &dwSize, FALSE)) == NO_ERROR) {
		std::cout << "Num Entries: " << pIfTable->dwNumEntries << std::endl;
		if (pIfTable->dwNumEntries < 3) {
			FREE(pIfTable);
			return FALSE;
		}
		pIfRow = (MIB_IFROW *)& pIfTable->table[2];
		this->cur_out_octets = pIfRow->dwOutOctets;
	}

	if (pIfTable != NULL) {
		FREE(pIfTable);
		pIfTable = NULL;
	}

	return TRUE;
}