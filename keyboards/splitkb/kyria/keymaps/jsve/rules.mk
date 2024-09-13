OLED_ENABLE = yes
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGB_MATRIX_ENABLE = yes     # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

RGB_MATRIX_DRIVER = ws2812

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += sh1106_i2c
SRC += pedro.qgf.c
SRC += gslogo.qgf.c
SRC += thintel15.qff.c

CONVERT_TO=liatris