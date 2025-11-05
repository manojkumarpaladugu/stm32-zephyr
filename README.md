# Getting Started

## Development Environment

Follow instructions in [VSCode-DevContainer](https://github.com/manojkumarpaladugu/VSCode-DevContainer)
to setup docker container using VS Code.

## Initialization

```bash
west init -m git@github.com:manojkumarpaladugu/stm32-zephyr --mr main stm32-zephyr-ws
cd stm32-zephyr-ws
west update
```

## Build and Run

QEMU:

1. Build

    ```bash
    clear && rm -rf _out && west build -d _out --pristine -b mps2/an521/cpu0 stm32-zephyr/app/
    ```

1. Run

    ```bash
    # QEMU through west tool
    west build -d _out -t run

    # QEMU direct
    qemu-system-arm -machine mps2-an521 -cpu cortex-m33 -nographic -kernel _out/zephyr/zephyr.elf
    ```

    Note: To kill QEMU, press 'Ctrl + a' followed by 'x'

    To start VS Code debug session with QEMU.
    Launch the `Zephyr QEMU` target from `RUN AND DEBUG` section in VS code.

STM32G491RE:

1. Build

    ```bash
    clear && rm -rf _out && west build -d _out --pristine -b nucleo_g491re stm32-zephyr/app/
    ```

1. Serial terminal to view firmware logs

    ```bash
    sudo picocom -q -b 115200 /dev/ttyACM0
    ```

    Note: To kill picocom, press and hold `Ctrl` then press 'a' followed by 'q'

1. Flash

    ```bash
    # using west tool
    west flash -d _out

    # using openocd tool direct
    sudo openocd -f interface/stlink.cfg -f target/stm32g4x.cfg -c "program _out/zephyr/zephyr.elf verify reset exit"
    ```

    To start VS Code debug session with STM32.
    Launch the `Zephyr STM32G491RE` target from `RUN AND DEBUG` section in VS code.
