# Contributing to Taku

Thank you for your interest in contributing to Taku! This document provides guidelines and instructions for contributing to this project.

## 🌱 Getting Started

1. **Fork the repository** on GitHub
2. **Clone your fork**:
   ```bash
   git clone https://github.com/YOUR-USERNAME/taku.git
   cd taku
   ```
3. **Set up the development environment**:
   ```bash
   ./setup.sh
   ```

## 🏗️ Project Structure

```
taku/
├── .github/                     # GitHub-specific files
├── .taku/                       # Git or project hooks
├── assets/                      # Staged assets
├── dist/                        # Compiled code and assets
├── docs/                        # Documentation
├── src/
│   ├── back/                    # Rust backend
│   └── front/                   # Web frontend
└── ... (other project files)
```

## 🔄 Development Workflow

1. **Create a branch** for your feature or bugfix:
   ```bash
   git checkout -b feature/your-feature-name
   ```

2. **Make changes** to the codebase

3. **Test your changes**:
   ```bash
   # For backend changes
   cargo test
   
   # For frontend changes
   yarn test
   ```

4. **Commit your changes** using conventional commit messages:
   ```
   feat: add new feature
   fix: resolve bug in XYZ
   docs: update README
   style: format code
   refactor: restructure component
   test: add tests for feature
   chore: update dependencies
   ```

5. **Push your branch** to your fork:
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Create a pull request** from your branch to the main repository

## 📋 Pull Request Process

1. Ensure your PR addresses a specific issue or adds valuable functionality
2. Update documentation to reflect your changes
3. Include tests for new functionality
4. Make sure your code follows the project's style and linting rules
5. Wait for code review and address any requested changes
6. Once approved, a maintainer will merge your PR

## 🧪 Testing Guidelines

- **Backend tests**: Use the Rust standard testing framework
- **Frontend tests**: Use Jest for JavaScript/TypeScript testing
- **Integration tests**: Ensure your changes work with both backend and frontend

## 🔤 Code Style

- **Rust**: Follow Rust's standard style conventions (rustfmt)
- **JavaScript/TypeScript**: Follow the project's ESLint rules
- **Documentation**: Maintain clear and concise documentation

## 📝 License

By contributing to this project, you agree that your contributions will be licensed under the same license as the project (see LICENSE file).

## 🙏 Thank You

Your contributions help make Taku better for everyone. We appreciate your time and effort!
