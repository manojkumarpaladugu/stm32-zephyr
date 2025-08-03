# Getting Started

## Initialization

```bash
west init -m git@github.com:manojkumarpaladugu/stm32-zephyr --mr main stm32-zephyr-ws
cd stm32-zephyr-ws
west update
```

## Build and Running

To build the application for QEMU:

```bash
west build -d _out/ast1030 --pristine -b ast1030_evb stm32-zephyr/app/
```

To run the application on QEMU:

```bash
qemu-system-arm -machine ast1030-evb -cpu cortex-m4 -nographic -kernel _out/ast1030/zephyr/zephyr.elf
```

To terminate QEMU, press Ctrl + A followed by X

To build the application for STM32G491RE:

```bash
west build -d _out/nucleo_g491re --pristine -b nucleo_g491re stm32-zephyr/app/
```

To run the application on target:

```bash
INTERFACE=interface/stlink-v2.cfg
TARGET=target/stm32g4x.cfg
FIRMWARE_ELF=_out/nucleo_g491re/zephyr/zephyr.elf
openocd -f $INTERFACE -f $TARGET -c "program $FIRMWARE_ELF verify reset exit"
```

UART output:

```bash
picocom -b 115200 /dev/ttyACM0
```
