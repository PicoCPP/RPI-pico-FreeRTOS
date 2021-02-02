cmake_minimum_required(VERSION 3.12)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)
add_subdirectory(pico-cpp)
project(hello_world)

# initialize the Pico SDK
pico_sdk_init()


add_executable(hello_world
    src/main.cpp 
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(hello_world pico_stdlib)
add_library(FreeRTOS STATIC FreeRTOS-Kernel/croutine.c
FreeRTOS-Kernel/event_groups.c
FreeRTOS-Kernel/list.c
FreeRTOS-Kernel/queue.c
FreeRTOS-Kernel/stream_buffer.c
FreeRTOS-Kernel/tasks.c
FreeRTOS-Kernel/timers.c FreeRTOS-Kernel/portable/GCC/ARM_CM0/port.c FreeRTOS-Kernel/portable/MemMang/heap_4.c src/FreeRTOS_Support_Files/IdleMemory.c)
target_include_directories(FreeRTOS PUBLIC FreeRTOS-Kernel/include include/ FreeRTOS-Kernel/portable/GCC/ARM_CM0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(hello_world)
target_link_libraries(hello_world FreeRTOS pico-cpp)
add_custom_command(TARGET hello_world
        POST_BUILD
        COMMAND arm-none-eabi-size hello_world.elf
        )
# rest of your project