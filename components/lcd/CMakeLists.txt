file(GLOB SOURCES *.c)
set(LCD_INCLUDE_DIRS .)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS ${LCD_INCLUDE_DIRS}
                       REQUIRES lvgl)

