# Taku (たく)

**A lightweight Electron alternative powered by GTK and Rust.**

Taku is a lean desktop runtime designed to host modern web interfaces inside a native GTK window, backed by
WebKitGTK — without the weight of Chromium or the baggage of full Electron stacks.

---

## ✨ Why Taku?

- 🧠 **Zero-bloat philosophy** — just Rust, GTK, and your own HTML/JS.
- 🪟 **Native GUI** with GTK4, no Chromium embedding.
- 🌀 **Full Tailwind + React support** via local WebKit-powered WebView.
- 📦 **Simple integration** — no Vite, no PostCSS overhead, just static files and a build script.
- 🧰 **Own your runtime** — no scaffolding magic, no hidden process trees.

---

## 🧩 Engine Details: WebKitGTK vs Electron

Electron apps use **Chromium + V8**, meaning every app bundles a full browser engine.

Taku uses **WebKitGTK**, which includes:

- 🧠 **JavaScriptCore** — the engine behind Safari (instead of V8)
- 🎨 **WebKit renderer** — like a leaner, native-flavored browser

This means your JS still runs fast — but without Node.js or V8. You're working with the **same engine** used
by GNOME Web (Epiphany), and you don't need to ship 100MB of Chromium to get a GUI.

---

## 📁 Project Layout

````shell
my-taku-app/
├── .taku/                         # Git or project hooks
│   ├── hooks/                    # hooks for Git or project events
│   │   ├── pre-commit            # Example: pre-commit hook
│   │   └── post-merge            # Example: post-merge hook
│   ├── out/                      # Replaces Cargo's 'target' dir
│   ├── tasks/                    # Custom tasks for Taku
│   │   ├── build.sh              # Build script for Taku
│   │   └── deploy.sh             # Deploy script for Taku
│   └── schema.json                 # Custom tasks for Taku
├── assets/                       # Staged assets (e.g., images, fonts, stylesheets, etc.)
├── dist/                         # Compiled code and assets
├── src/
│   ├── backend/
│   │   ├── main.rs               # Entry point (GTK init)
│   │   └── ui.rs                 # GTK window + WebView logic
│   │
│   ├── cli/                      # CLI source files (e.g., .rs or .ts)
│   │    └── main.sh              # Bootstrap script for CLI
│   └── frontend/
│       ├── input.css             # Tailwind entry
│       └── tailwind.config.js    # Tailwind setup
├── Cargo.toml                    # Root Rust dependencies
├── main.sh                       # Bootstrap script for Taku app
├── setup.sh                      # "Makefile/Dockerfile-like" `bash` setup script"
├── package.json                  # Project-level Node dependencies
├── yarn.lock                     # Yarn lockfile
└── .gitignore                    # Ignore rules for Git



---

## 🧪 Getting Started

```sh
curl https://github.com/imgnxorg/taku/raw/main/setup.sh | sh -o setup.sh    # Builds Tailwind CSS and Rust app
./setup.sh                                                              # Runs the setup script
```
This will:
- Install Rust and Node.js dependencies
- Build the Tailwind CSS styles
- Compile the Rust backend
- Prepare the project structure
---
## 🚀 Running Your Taku App

```sh
cargo run        # Launches GTK window
```

You should see your `public/index.html` rendered inside a GTK window styled with Tailwind. React works out of
the box if you include it in your HTML.

---

## 💡 Philosophy

Electron is powerful, but too heavy. Taku gives you a native runtime shell — just enough to run your ideas.
Build the rest yourself, the way you want.

> Because sometimes all you need is a window, a stylesheet, and your own mind.

---

## 🔭 What’s Next — `gittaku.com`

Taku is the local runtime. [**Gittaku**](https://gittaku.com) will be the full framework:

- 🧩 **GUI + GitHub Integration** — visual + semantic view of your repo
- 🧠 **Abstraction layer** over Git, React, and desktop logic
- 🧭 **Unified project model**: version control, UI, and local runtime under one structure
- 📡 **Web-first mindset** with optional native delivery

> Gittaku isn’t just a platform — it’s the Git-native dev console your tools never gave you.

---

**Made with 🥄** by people who like to start at the beginning.
````

Example JSON Schema for a Taku project:

```json
{
  "name": "taku",
  "description": "A lightweight Electron alternative powered by GTK and Rust.",
  "version": "1.0.0",
  "main": "src/backend/main.rs",
  "scripts": {
    "start": "cargo run",
    "build": "taku/tasks/build.sh",
    "deploy": "taku/tasks/deploy.sh"
  },
  "dependencies": {
    "tailwindcss": "^2.2.19",
    "postcss-cli": "^8.3.1"
  },
  "devDependencies": {
    "@tailwindcss/postcss7-compat": "^2.2.19"
  },
  "assets": {
    "images": ["assets/images/**/*"],
    "fonts": ["assets/fonts/**/*"],
    "stylesheets": ["assets/stylesheets/**/*"]
  }
    "hooks": {
        "pre-commit": "taku/hooks/pre-commit",
        "post-merge": "taku/hooks/post-merge"
        },
  "name": "taku-wav-editor",
  "description": "Waveform editor with CLI and GUI support.",
  "frontend": {
    "entry": "src/frontend/input.css",
    "style": "tailwind",
    "routes": ["home", "edit", "export"]
  },
  "backend": {
    "entry": "src/backend/main.rs",
    "runtime": "tao-wry",
    "bridge": "src/backend/ui.rs"
  },
  "cli": {
    "entry": "src/cli/main.sh",
    "commands": [
      { "name": "reverse", "description": "Reverse the waveform" },
      { "name": "speedup", "description": "Speed up audio (atempo)" },
      { "name": "slowdown", "description": "Slow down audio (atempo)" },
      { "name": "normalize", "description": "Normalize volume levels" },
      { "name": "compress", "description": "Apply compression to audio" }
    ]
  },
  "tasks": {
    "build": "taku/tasks/build.sh",
    "deploy": "taku/tasks/deploy.sh"
  },
  "hooks": {
    "pre-commit": "taku/hooks/pre-commit",
    "post-merge": "taku/hooks/post-merge"
  },
  "entities": {
    "AudioFile": {
      "type": "strong",
      "attributes": {
        "id": { "type": "int", "primary": true },
        "path": { "type": "string" },
        "name": { "type": "string" },
        "sampleRate": { "type": "int" },
        "duration": { "type": "float" },
        "channels": { "type": "int" }
      }
    },
    "Transform": {
      "type": "strong",
      "attributes": {
        "id": { "type": "int", "primary": true },
        "fileId": {
          "type": "int",
          "relation": { "target": "AudioFile", "mandatory": true }
        },
        "type": { "type": "string" },
        "parameters": { "type": "json", "optional": true },
        "timestamp": { "type": "datetime", "default": "now" }
      }
    }
  }
}
```
