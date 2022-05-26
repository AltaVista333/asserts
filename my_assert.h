#ifndef ASSERTS_MY_ASSERT_H
#define ASSERTS_MY_ASSERT_H
#ifdef DEBUG


#define ASSERT(condition, message) \
       if (!(condition)) \
        {assert_failed(__FILE__, __LINE__, message, #condition, __COUNTER__);} \
        else  {}
#else
#define ASSERT(expr,message) {}
#endif

#define Fatal_Error(condition, message, value) \
    if (condition) \
        {} \
    else \
        {fatal_error(__FILE__, __LINE__, message); \
        return value;                           \
        }

void fatal_error(char* file,int line,char* message);
void assert_failed(char *file, int line, char* message, char* condition, int counter);
void SystemOpen(int count);
void SystemClose();
#endif //ASSERTS_MY_ASSERT_H
