# ESP-IDF component file for make based commands

COMPONENT_SRCDIRS := . \
                  src \
                  src/core \
                  src/draw \
                  src/extra \
                  src/font \
                  src/gpu \
                  src/hal \
                  src/misc \
                  src/widgets \
                  src/extra/layouts \
                  src/extra/layouts/flex \
                  src/extra/layouts/grid \
                  src/extra/themes \
                  src/extra/themes/basic \
                  src/extra/themes/default \
                  src/extra/widgets/calendar \
                  src/extra/widgets/animimg \
                  src/extra/widgets/colorwheel \
                  src/extra/widgets \
                  src/extra/widgets/imgbtn \
                  src/extra/widgets/keyboard \
                  src/extra/widgets/led \
                  src/extra/widgets/list \
                  src/extra/widgets/msgbox \
                  src/extra/widgets/spinbox \
                  src/extra/widgets/spinner \
                  src/extra/widgets/tabview \
                  src/extra/widgets/tileview \
                  src/extra/widgets/chart \
                  src/extra/widgets/meter \
                  examples/widgets/img \
                  examples/assets \
                  src/extra/widgets/win

CFLAGS += -DLV_LVGL_H_INCLUDE_SIMPLE

COMPONENT_ADD_INCLUDEDIRS := $(COMPONENT_SRCDIRS) .
