# Makefile for Taku Project
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -O2
LDFLAGS = 

# C Library Configuration
SOURCES = taku_config.c
HEADERS = taku_config.h
OBJECTS = $(SOURCES:.c=.o)
LIBRARY = libtaku_config.a
EXAMPLE = example
EXAMPLE_SOURCES = example.c

.PHONY: man all clean run debug memcheck format check install help c-lib

# Default target
all: c-lib man

# Build the C library and example
c-lib: $(LIBRARY) $(EXAMPLE)

# Build the static library
$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^
	@echo "Built static library: $@"

# Build the example program
$(EXAMPLE): $(EXAMPLE_SOURCES) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $< -L. -ltaku_config
	@echo "Built example program: $@"

# Compile object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Build man page
man:
	pandoc -s -t man docs/taku.md -o docs/taku.1

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(LIBRARY) $(EXAMPLE)
	@echo "Cleaned build artifacts"

# Run the example
run: $(EXAMPLE)
	./$(EXAMPLE)

# Development target for debugging
debug: CFLAGS += -g -DDEBUG
debug: clean c-lib

# Check for memory leaks (requires valgrind)
memcheck: $(EXAMPLE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXAMPLE)

# Format code (requires clang-format)
format:
	clang-format -i $(SOURCES) $(HEADERS) $(EXAMPLE_SOURCES)

# Static analysis (requires cppcheck)
check:
	cppcheck --enable=all --std=c99 $(SOURCES) $(EXAMPLE_SOURCES)

# Install the library (optional)
install: $(LIBRARY)
	@echo "Installing library and headers..."
	@mkdir -p /usr/local/lib
	@mkdir -p /usr/local/include
	@cp $(LIBRARY) /usr/local/lib/
	@cp $(HEADERS) /usr/local/include/
	@echo "Installation complete"

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build C library and man page (default)"
	@echo "  c-lib    - Build C library and example"
	@echo "  man      - Build man page"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run example program"
	@echo "  debug    - Build with debug symbols"
	@echo "  memcheck - Run example with valgrind"
	@echo "  format   - Format code with clang-format"
	@echo "  check    - Run static analysis with cppcheck"
	@echo "  install  - Install library system-wide"
	@echo "  help     - Show this help message"
