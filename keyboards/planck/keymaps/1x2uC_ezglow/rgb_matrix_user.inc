RGB_MATRIX_EFFECT(all_keys_white)
RGB_MATRIX_EFFECT(all_keys_red)
RGB_MATRIX_EFFECT(layer_games)
RGB_MATRIX_EFFECT(layer_three)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define gamecolour RGB_GREEN

static bool all_keys_white(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(RGB_WHITE);
  return rgb_matrix_check_finished_leds(led_max);
}

static bool all_keys_red(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(RGB_RED);
  return rgb_matrix_check_finished_leds(led_max);
}

static bool layer_three(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(RGB_OFF);
  rgb_matrix_set_color(12, RGB_TEAL);
  rgb_matrix_set_color(13, 255, 0, 0);
  return rgb_matrix_check_finished_leds(led_max);
}

static bool layer_games(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(RGB_OFF);
  rgb_matrix_set_color(0, gamecolour);
  rgb_matrix_set_color(1, gamecolour);
  rgb_matrix_set_color(2, gamecolour);
  rgb_matrix_set_color(3, gamecolour);
  rgb_matrix_set_color(4, gamecolour);
  rgb_matrix_set_color(5, gamecolour);
  rgb_matrix_set_color(6, gamecolour);
  rgb_matrix_set_color(7, gamecolour);
  rgb_matrix_set_color(8, gamecolour);
  rgb_matrix_set_color(9, gamecolour);
  rgb_matrix_set_color(10, gamecolour);
  rgb_matrix_set_color(12, gamecolour);
  rgb_matrix_set_color(13, gamecolour);
  rgb_matrix_set_color(14, gamecolour);
  rgb_matrix_set_color(15, gamecolour);
  rgb_matrix_set_color(16, gamecolour);
  rgb_matrix_set_color(23, gamecolour);
  rgb_matrix_set_color(25, gamecolour);
  rgb_matrix_set_color(26, gamecolour);
  rgb_matrix_set_color(27, gamecolour);
  rgb_matrix_set_color(28, gamecolour);
  rgb_matrix_set_color(36, gamecolour);
  rgb_matrix_set_color(37, gamecolour);
  rgb_matrix_set_color(38, gamecolour);
  rgb_matrix_set_color(39, gamecolour);
  rgb_matrix_set_color(40, gamecolour);
  rgb_matrix_set_color(41, gamecolour);
  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS