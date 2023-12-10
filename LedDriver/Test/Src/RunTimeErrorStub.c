#include "RunTimeErrorStub.h"

static const char* message = "No error";
static int parameter = -1;
static const char *file =0;
static int line  = -1;


void RunTimeErrorStub_Reset(void)
{
    message = "No error";
    parameter = -1;
}
const char * RunTimeErrorStube_GetLastError(void)
{
    return message;
}
int RunTimeErrorStub_GetLastParameter(void)
{
    return parameter;
}
void RunTimeError(const char* m, int p, const char* f, int l)
{
    message = m;
    parameter = p;
    f = file;
    line = l;
    
}
