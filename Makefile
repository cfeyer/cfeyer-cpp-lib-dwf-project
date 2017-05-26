all: src

src:
	make -C src

clean:
	rm -rf bin/* lib/*

.PHONY: all src clean
