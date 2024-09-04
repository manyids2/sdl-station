```
/h700/host/lib/gcc/aarch64-buildroot-linux-gnu/12.3.0/../../../../aarch64-buildroot-linux-gnu/bin/ld: ../core/libcore.so: undefined reference to `TextureResource::bind()'
/h700/host/lib/gcc/aarch64-buildroot-linux-gnu/12.3.0/../../../../aarch64-buildroot-linux-gnu/bin/ld: ../core/libcore.so: undefined reference to `TextureResource::getPhysicalSize() const'
/h700/host/lib/gcc/aarch64-buildroot-linux-gnu/12.3.0/../../../../aarch64-buildroot-linux-gnu/bin/ld: ../core/libcore.so: undefined reference to `Scripting::fireEvent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
/h700/host/lib/gcc/aarch64-buildroot-linux-gnu/12.3.0/../../../../aarch64-buildroot-linux-gnu/bin/ld: ../core/libcore.so: undefined reference to `TextureData::loadFromVideo()'
/h700/host/lib/gcc/aarch64-buildroot-linux-gnu/12.3.0/../../../../aarch64-buildroot-linux-gnu/bin/ld: ../core/libcore.so: undefined reference to `TextureData::initSVGFromMemory(unsigned char const*, unsigned long)'
/h700/host/lib/gcc/aarch64-buildroot-linux-gnu/12.3.0/../../../../aarch64-buildroot-linux-gnu/bin/ld: ../core/libcore.so: undefined reference to `TextureResource::getTotalMemUsage(bool)'
/h700/host/lib/gcc/aarch64-buildroot-linux-gnu/12.3.0/../../../../aarch64-buildroot-linux-gnu/bin/ld: ../core/libcore.so: undefined reference to `TextureResource::get(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool, bool, bool, bool, bool, MaxSizeInfo const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
collect2: error: ld returned 1 exit status
make[4]: *** [app/CMakeFiles/sdl-station.dir/build.make:110: app/sdl-station] Error 1
make[3]: *** [CMakeFiles/Makefile2:142: app/CMakeFiles/sdl-station.dir/all] Error 2
make[2]: *** [Makefile:91: all] Error 2
make[1]: *** [package/pkg-generic.mk:283: /h700/build/sdl-station/.stamp_built] Error 2
make: *** [Makefile:23: _all] Error 2

```

- TextureResource::bind
- TextureResource::getPhysicalSize
- Scripting::fireEvent
- TextureData::loadFromVideo
- TextureData::initSVGFromMemory
- TextureResource::getTotalMemUsage
- TextureResource::get
