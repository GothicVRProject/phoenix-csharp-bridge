# phoenix-csharp-wrapper

> Credits to [lmichaelis/phoenix](https://github.com/lmichaelis/phoenix) for the actual reader implementations of Gothic assets.

This repository will leverage phoenix's parsing capabilities and prepares it to use within C# code.


## How to contribute
We're always looking for people with knowledge and/or spirit. Feel free to reach out to us via gothicVR(at)outlook.com or visit us at our Discord server [Gothic VR](https://discord.gg/3EzACMVx).


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

## Copy to parent folder (if used as submodule by unZENity-VR project)
```powershell
cp ./build/libphoenix-csharp-wrapper.dll ../../Assets/unZENity-VR/Dependencies/
```


## Resources

* To check for exported DLL functions and dependencies being used: [Dependency Walker](https://www.dependencywalker.com/)
* Howto export complex C++ objects via "wrapper": https://stackoverflow.com/questions/315051/using-a-class-defined-in-a-c-dll-in-c-sharp-code




## Dev logic
(interpreted from OpenGothic)

1. Load all VDF files
2. Merge them into one big chunk of vdf file (vdf_file.merge())
3. Export these values to DLL consumer
4. Free memory