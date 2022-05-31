add_executable(${PROJECT_NAME}
	main.c
	i2c.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

target_link_libraries(${PROJECT_NAME} 
	pico_stdlib
	arduino-compat
	# pico_neopixel
	)

pico_enable_stdio_uart(${PROJECT_NAME} 1)
pico_enable_stdio_usb(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME})
