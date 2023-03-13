> Credits to [lmichaelis/phoenix](https://github.com/lmichaelis/phoenix) for the actual reader implementations of Gothic assets.

This repository will leverage phoenix's parsing capabilities and prepares it to use within C# code.


## How to contribute
We're always looking for people with knowledge and/or spirit. Feel free to reach out to us via gothicVR(at)outlook.com or visit us at our Discord server [Gothic VR](https://discord.gg/3EzACMVx).


## Resources

* To check for exported DLL functions and dependencies being used: [Dependency Walker](https://www.dependencywalker.com/)
* Howto export complex C++ objects via "bridge": https://stackoverflow.com/questions/315051/using-a-class-defined-in-a-c-dll-in-c-sharp-code
* Marshalling:
    * Data types which are automatically marshalled between C++ and C#: https://learn.microsoft.com/en-us/dotnet/standard/native-interop/type-marshalling
    * Howto do marshalling: https://dev.to/gabbersepp/call-function-in-unmanaged-dll-from-c-and-pass-custom-data-types-marshal-5c31


* There are 3 ways of C# communicating with C++:
    1. P/Invoke
    2. COM
    3. C++/CLI (call C# from C++; wrong direction for our use case.)

* Mono documentation about DllImport: https://www.mono-project.com/docs/advanced/pinvoke/

DLL interopability:
![DLL interoperability](https://mark-borg.github.io/img/posts/pinvoke-diagram.png)



## Setup options

### Windows 10 with MinGW64

**Setup**  
```powershell
# If missed before ;-)
git submodule update --init --recursive

choco install mingw
```

**Build**  
(tested mingw-w64 version: 12.2.0)
```powershell
cmake -G "MinGW Makefiles" -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

**Copy DLL to Unity project**  
```powershell
cp ./build/libphoenix-csharp-bridge.dll ../../Assets/unZENity-VR/Dependencies/
```

### Amazon Linux 2 with Clang

**Setup**  
```sh
wget https://cmake.org/files/v3.25/cmake-3.25.3.tar.gz
tar -xvzf cmake-3.25.3.tar.gz
cd cmake-3.25.3
./bootstrap
make
sudo make install


sudo yum install clang

git clone --recursive https://github.com/GothicVRProject/phoenix-csharp-bridge.git

cd phoenix-csharp-bridge
```

**Build**  
```sh
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

cmake -B build -DCMAKE_BUILD_TYPE=Release

cmake --build build
```