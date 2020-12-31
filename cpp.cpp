// Smith's True IP Grabber
// (C) 2006
//
// Use this code as you wish

#include <stdio.h>
#include <windows.h>
#include <wininet.h>

#pragma comment (lib, "wininet.lib")
#pragma comment (lib, "urlmon.lib")

#define URL "http://www.whatismyip.org"

// It doesnt actually parse the file it just reads it into a buffer :P
// I discovered that this particular site saves only the ip to a html file
// Pretty sweet ey? No parsing nessicary

VOID ParseFile(LPSTR lpPath)
{
	LPSTR lpBuffer = new char[MAX_PATH]; ZeroMemory(lpBuffer,MAX_PATH);

	HANDLE hFile = CreateFile(lpPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwRet = 0;
		ReadFile(hFile, lpBuffer, MAX_PATH, &dwRet, NULL);
		CloseHandle(hFile);

		printf("Your IP: %s\n",lpBuffer);
	}

	delete lpBuffer;
}

int main()
{
	// Return values //
	DWORD   dwResult = 0;
	HRESULT uRet     = 0;

	SetConsoleTitle("True Ip Grabber - by Smith");

	// Check for internet connection //
	if(!InternetGetConnectedState(&dwResult, 0)){
		printf("No internet connection detected!\n");
		return 0;
	}

	// Get temporary directory //
	LPSTR lpTemp = new char[MAX_PATH]; ZeroMemory(lpTemp,MAX_PATH);
	GetTempPath(MAX_PATH,lpTemp);

	// Create a temp name //
	LPSTR lpTempFileName = new char[MAX_PATH]; ZeroMemory(lpTempFileName,MAX_PATH);
	GetTempFileName(lpTemp,"Temp",0,lpTempFileName);

	// Download the page //
	uRet = URLDownloadToFile(NULL,URL,lpTempFileName,0,NULL);
	if(uRet == S_OK) ParseFile(lpTempFileName);
	else printf("Unable to retrieve your ip address\n");

	// Free the buffers //
	delete lpTemp,lpTempFileName;

	// No system calls, oh yeah! //
	printf("\nPress escape to quit\n");
	while(!GetAsyncKeyState(VK_ESCAPE)) Sleep(80);

	return 0;
}
