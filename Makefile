# Nombre del archivo objetivo (sin extensión)
TARGET = Leds

# Compilador y opciones
CC = avr-gcc
CFLAGS = -Os -mmcu=atmega328p -I/usr/lib/avr/include

# Regla para compilar el archivo fuente
$(TARGET).o: Leds.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para enlazar y generar el archivo ELF
$(TARGET).elf: $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $<

# Regla para convertir a formato Intel HEX
$(TARGET).hex: $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $< $@

# Regla para programar el microcontrolador
program: $(TARGET).hex
	sudo avrdude -c usbasp -p m328p -U flash:w:$<

# Regla para limpiar archivos temporales
clean:
	rm -f $(TARGET).o $(TARGET).elf $(TARGET).hex

