#ifndef _RUNTIMEERRORSTUB_H
#define _RUNTIMEERRORSTUB_H

#define RUNTIME_ERROR(description,parameter)\
RunTimeError(description,parameter,__FILE__,__LINE__)

void RunTimeErrorStub_Reset(void);
const char * RunTimeErrorStube_GetLastError(void);
int RunTimeErrorStub_GetLastParameter(void);
void RunTimeError(const char* m, int p, const char* f, int l);

#endif