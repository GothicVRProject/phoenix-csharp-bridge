#pragma once

//  Microsoft 
#if defined(_MSC_VER)
    #define EXPORT extern "C" __declspec(dllexport)
//  GCC
#elif defined(__GNUC__)
    #define EXPORT extern "C" __attribute__((visibility("default")))
    #warning .so function export untested so far...
#endif