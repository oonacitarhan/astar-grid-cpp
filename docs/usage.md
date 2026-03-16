# Build and run

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j2
./build/experiment_cli examples/warehouse.map 0 0 5 9
./build/demo
```

Invalid configuration or unreadable input returns exit code 2. Numeric arguments are in the units described in the architecture guide.
