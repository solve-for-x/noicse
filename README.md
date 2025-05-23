# noicse

###### Random Noise Pixel Art Generator implemented using C compiled to WASM

### Compile with Emscripten
```bash
emcc pixels.c -Os -s WASM=1 \
  -s EXPORTED_FUNCTIONS='["_seed_rng", "_generate_image_data"]' \
  -s EXPORTED_RUNTIME_METHODS='["cwrap", "HEAPU8"]' \
  -o pixels.js
```

**NOTE**: Files must be served from a server in order fro WASM code to run, you can use a local server setup like `python -m http.server`.

