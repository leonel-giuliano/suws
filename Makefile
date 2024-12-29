CC 			:= gcc

SRCDIR 		:= src
BUILDDIR 	:= build
INCLUDEDIR	:= include

CFLAGS 		:= -g -I$(INCLUDEDIR)

SRC 		:= $(wildcard $(SRCDIR)/*.c)
OBJ 		:= $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))
TARGET 		:= $(BUILDDIR)/suws


all: $(TARGET)


$(TARGET): $(OBJ) | $(BUILDDIR)
	$(CC) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(INCLUDEDIR)/*.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $@


clean:
	rm -r $(BUILDDIR)

.PHONY: all clean
