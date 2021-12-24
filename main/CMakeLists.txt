file(GLOB SOURCES *.c)
set(MAIN_INCLUDE_DIRS .)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS ${MAIN_INCLUDE_DIRS})

target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")
