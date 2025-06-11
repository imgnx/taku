#!/bin/bash

# Pseudocode
# This script initializes a new project with a structured setup including frontend, backend, and CLI components.
# It prompts the user for various configurations and sets up the project structure accordingly.
# This script is intended to be run in a terminal environment with bash or zsh.

# initialize git
# prompt user for name of project (defaults to name of directory — like U.P.D.A.T.E.)
# Other prompts...
#   - frontend framework (ie. react)
#     - dependencies (npm, yarn, etc.)
#   - backend framework (ie. rust)
#     - dependencies (cargo, etc.)
#   - cli framework (ie. shellscript, javascript, etc.)
#     - dependencies (brew, apt, apt-get, etc.)
# initialize frontend into frontend/ (just do yarn, webpack, tailwindcss, react, etc.)
# initialize backend into backend/ (use cargo)
# initialize CLI into cli/ (use zsh/bash for now and place shebang at the top of `cli/main.[sh/js/rs]`)
# create main.sh in root and add `source src/main.[sh/js/rs]` and also the attached script.*
# install husky
# install and/or test ggshield
# create .gitignore
# create README.md with KaTex Big O notation (defaults to CLI Parser formula)
# prompt user for frontend
# prompt user for backend
# prompt user for cli
# create package.json with name, version, deps, etc.
# configure husky
# configure `git` hooks
#   - commit
#     - assertion: semantic commits
#       - fallback: failure
#     - assertion: ggshield — no secrets
#       - fallback: failure

echo "Project initialized successfully."
