# Taku

**A lightweight Electron alternative powered by GTK and Rust.**

Taku is a lean desktop runtime designed to host modern web interfaces inside a native GTK window, backed by WebKitGTK — without the weight of Chromium or the baggage of full Electron stacks.

---

## ✨ Why Taku?

* 🧠 **Zero-bloat philosophy** — just Rust, GTK, and your own HTML/JS.
* 🪟 **Native GUI** with GTK4, no Chromium embedding.
* 🌀 **Full Tailwind + React support** via local WebKit-powered WebView.
* 📦 **Simple integration** — no Vite, no PostCSS overhead, just static files and a build script.
* 🧰 **Own your runtime** — no scaffolding magic, no hidden process trees.

---

## 🧩 Engine Details: WebKitGTK vs Electron

Electron apps use **Chromium + V8**, meaning every app bundles a full browser engine.

Taku uses **WebKitGTK**, which includes:

* 🧠 **JavaScriptCore** — the engine behind Safari (instead of V8)
* 🎨 **WebKit renderer** — like a leaner, native-flavored browser

This means your JS still runs fast — but without Node.js or V8.
You're working with the **same engine** used by GNOME Web (Epiphany), and you don't need to ship 100MB of Chromium to get a GUI.

---

## 📁 Project Layout

```txt
my-app/
├── src/                      # Rust source files
│   ├── main.rs               # Entry point (GTK init)
│   └── ui.rs                 # GTK window + WebView logic
├── public/                   # HTML/CSS/JS frontend
│   ├── index.html            # Entry HTML file
│   ├── tailwind.config.js    # Tailwind setup
│   ├── input.css             # Tailwind entry
│   └── package.json          # For tailwind CLI only
├── Cargo.toml                # Rust dependencies
├── setup.sh                  # Bootstrap both sides
```

---

## 🧪 Getting Started

```sh
sh ./setup.sh    # Builds Tailwind CSS and Rust app
cargo run        # Launches GTK window
```

You should see your `public/index.html` rendered inside a GTK window styled with Tailwind. React works out of the box if you include it in your HTML.

---

## 💡 Philosophy

Electron is powerful, but too heavy.
Taku gives you a native runtime shell — just enough to run your ideas. Build the rest yourself, the way you want.

> Because sometimes all you need is a window, a stylesheet, and your own mind.

---

## 🔭 What’s Next — `gittaku.com`

Taku is the local runtime. [**Gittaku**](https://gittaku.com) will be the full framework:

* 🧩 **GUI + GitHub Integration** — visual + semantic view of your repo
* 🧠 **Abstraction layer** over Git, React, and desktop logic
* 🧭 **Unified project model**: version control, UI, and local runtime under one structure
* 📡 **Web-first mindset** with optional native delivery

> Gittaku isn’t just a platform — it’s the Git-native dev console your tools never gave you.

---

**Made with 🥄** by people who like to start at the beginning.
