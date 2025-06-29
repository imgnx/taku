# Taku Package Manager (たく PM)

A streamlined package manager and build tool for Rust projects, inspired by Yarn for JavaScript.

## Vision

Taku Package Manager aims to simplify Rust development workflows by providing:

1. **Fast, deterministic builds** with intelligent caching
2. **Seamless CLI tool management** across development environments
3. **Workspace-aware dependency resolution** for monorepos
4. **Environment-aware builds** (dev, staging, prod)
5. **Simplified distribution** of Rust applications

## Current State

The `update` utility serves as a precursor to Taku PM functionality by:
- Watching for changes in source files
- Building/installing Rust CLI tools
- Managing binary installation in `~/bin`
- Supporting different build environments

## Roadmap

### Phase 1: Core Infrastructure (Current)
- ✅ Basic CLI tool installation (`update` utility)
- ✅ Environment-aware builds (dev/staging/prod)
- ✅ Source file watching and auto-rebuilding

### Phase 2: Enhanced Build System
- [ ] Intelligent caching of build artifacts
- [ ] Custom target directory structure
- [ ] Dependency checksumming and verification
- [ ] Parallel builds for faster compilation

### Phase 3: Package Management
- [ ] Lockfile generation for deterministic builds
- [ ] Offline mode support
- [ ] Custom registry integration
- [ ] Workspace management for monorepos

### Phase 4: Distribution System
- [ ] Binary packaging for cross-platform distribution
- [ ] Automatic versioning and changelog generation
- [ ] Update notification system
- [ ] Self-updating capabilities

### Phase 5: Developer Experience
- [ ] Interactive CLI with rich output
- [ ] Plugin system for extensibility
- [ ] Integration with IDE tools
- [ ] Interactive documentation

## Architecture

```
taku/
├── cli/                     # Command-line interface
├── core/                    # Core package management logic
├── builder/                 # Build system implementation
├── resolver/                # Dependency resolution
└── dist/                    # Distribution tools
```

## Key Differentiators from Cargo

While Cargo is an excellent package manager, Taku PM focuses on:

1. **Speed** - Smarter caching and parallel operations
2. **Simplicity** - More intuitive commands and workflows
3. **Developer Experience** - Better feedback and error messages
4. **Environment Awareness** - First-class support for different environments
5. **Toolchain Management** - Simplified management of CLI tools

## Getting Started (Future)

```bash
# Install Taku PM
curl -sSf https://get.taku.dev | sh

# Initialize a new Rust project
taku init my-project

# Add dependencies
taku add serde tokio

# Build with environment
taku build --env=prod

# Run with environment variables
taku run --env=dev

# Install a CLI tool globally
taku install ripgrep
```

## Integration with existing update utility

The current `update` utility will be integrated as a core component of Taku PM, providing:

- Backward compatibility for existing workflows
- Enhanced functionality through the Taku PM ecosystem
- Seamless migration path for users
