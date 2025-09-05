# CC = gcc
# CFLAGS = -Wall -Wextra -pedantic
# TARGET = ej19

# all: $(TARGET)

# $(TARGET): $(TARGET).o
# 	$(CC) $(CFLAGS) $^ -o $@

# $(TARGET).o: $(TARGET).c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm *.o $(TARGET)

# .PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -MMD -MP
TARGET = ej21

all: $(TARGET)

SRCS = funca.c funcb.c ej21.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm *.o $(TARGET) *.d

.PHONY: all clean