.PHONY: man

man:
	pandoc -s -t man docs/taku.md -o docs/taku.1
