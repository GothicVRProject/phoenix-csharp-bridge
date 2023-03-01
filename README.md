test
# phoenix-csharp-wrapper

> Credits to [lmichaelis/phoenix](https://github.com/lmichaelis/phoenix) for the actual reader implementations of Gothic assets.

This repository will leverage phoenix's parsing capabilities and prepares it to use within C# code.


## Pre-setup
(tested mingw-w64 version: 12.2.0)

```powershell
choco install mingw
```


## Compile

```powershell
cmake -G "MinGW Makefiles" -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```


## Resources

* To check for exported DLL functions and dependencies being used: [Dependency Walker](https://www.dependencywalker.com/)
* Howto export complex C++ objects via "wrapper": https://stackoverflow.com/questions/315051/using-a-class-defined-in-a-c-dll-in-c-sharp-code