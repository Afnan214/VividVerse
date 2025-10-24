# OpenGL Game Engine

Small, fast‑to‑read engine scaffold using **GLFW**, **GLAD**, and **OpenGL**.

---

## Why 🎯
- I wanted a clean base to learn graphics and build tiny demos.
- No heavy framework. Just the pieces needed to open a window, draw, and iterate.
- Easy to extend: camera, textures, shaders, input, scenes.

---

## What 🧩
- **GLFW** — window + input + context creation.
- **GLAD** — OpenGL function loader.
- **stb_image** — quick image loading for textures.
- **CMake** project with folders for assets, engine code, and third‑party libs.

```
.
├─ Assets/
├─ Game_AE/
├─ VividVerse/           # engine / app code
├─ glad/
├─ glfw/ (submodule)
├─ stbi/
├─ CMakeLists.txt
└─ Game_AE.sln
```

---

## How 🛠️
### Build (CMake)
```bash
# clone with submodules
git clone --recurse-submodules https://github.com/<you>/<repo>.git
cd <repo>

# generate + build (example: out-of-source, Release)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

### Run ▶️
```bash
# binary location may vary by generator
./build/<target_name>   # or build/Release/<target_name>.exe on Windows
```

---

## Features ✅
- Window + OpenGL context
- Input handling (keyboard / mouse)
- Shader loading helpers
- Texture loading via stb
- Simple render loop

> Start small: draw a triangle, add a camera, then textures and lighting.

---

## Notes 📝
- Use **VSync** while developing; disable for benchmarking.
- Keep drivers up to date. Some laptops default to the integrated GPU.
- If submodules didn’t pull: `git submodule update --init --recursive`.

---

## Credits 🙏
- [GLFW](https://www.glfw.org/)
- [GLAD](https://glad.dav1d.de/)
- [stb](https://github.com/nothings/stb)



