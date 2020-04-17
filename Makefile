CC           = gcc 
CCFLAGS      = -g # -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wformat-security
LFLAGS       = -lncurses
SRCDIR       = src
BINDIR       = bin
INCLUDEDIR   = inc
OBJDIR       = obj
SRCDIR       = src
BINNAME      = main
BIN          = $(BINDIR)/$(BINNAME)
C            = $(wildcard $(SRCDIR)/*.c)
OBJS         = $(C:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS         = $(C:$(SRCDIR)/%.c=$(OBJDIR)/%.d)
vpath %.c   $(SRCDIR)
vpath %.o   $(OBJDIR)
vpath %.h   $(INCLUDEDIR)

all: $(BIN)

$(BIN) : $(OBJS)
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) $^ -o $@

-include $(DEPS)

$(OBJDIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -MMD -c $< -o $@ -I$(INCLUDEDIR)

.PHONY:
	clean
	halfclean
	cheat
	help

clean:
	@- rm bin/clife
	@- rm obj/*

halfclean:
	rm -r arch/svf/*.rtf

cheat:
	echo -n "[w];[t];" > arch/svf/inv.rtf

help:
	cat Makefile

