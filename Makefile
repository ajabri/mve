#LDFLAGS=-L/n/fs/hog2photo/SUNglass/root/usr/lib64
LDLIBS += -L$(SG)/root/usr/lib64 -L$(SG)/root/usr/lib
all:
	$(MAKE) -C libs
	$(MAKE) -C apps

doc:
	$(MAKE) -C docs

test:
	$(MAKE) -C tests

clean:
	$(MAKE) -C apps $@
	$(MAKE) -C libs $@
	$(MAKE) -C tests $@

.PHONY: all doc test clean
