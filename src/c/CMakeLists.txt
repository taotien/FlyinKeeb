add_executable(${PROJECT_NAME}
	main.c
	keyboard.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	)

# target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_compile_options(${PROJECT_NAME} PRIVATE)

target_link_libraries(${PROJECT_NAME} 
	pico_stdlib
	pico_time
	hardware_i2c
	# tinyusb_common
	# tinyusb_board
	# tinyusb_additions
	tinyusb_host
	# pico_neopixel
	)

pico_enable_stdio_uart(${PROJECT_NAME} 1)
pico_enable_stdio_usb(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME})
