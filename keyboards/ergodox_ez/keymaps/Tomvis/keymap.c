#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
// #include <print.h>

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_86_255_128,
  HSV_27_255_255,
  PRN,
  BRACKET,
  CBR,
  SELECT_ALL_COPY,
  COPY,
  PASTE,
  EXIT,
  TD_SHIFT_CAPSLOCK = 0,
  TD_PRN_RPRN,
  TD_BRACKET_RBRACKET,
  TD_CBR_RCBR,
  TD_ESCAPE_QUIT,
  TD_F_FIND,
  TD_R_REPLACE,
  TD_U_UNDO_REDO,
  TD_C_COMMENT_TOGGLE,
  TD_UP_RUN,
  TD_J_EQUAL,
  TD_K_UNDERSCORE,
  
  // TD_SHIFT_CAPSLOCK_ONESHOT
};


void dance_escape_quit (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING(SS_TAP(X_ESCAPE));
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING(SS_RALT(SS_TAP(X_F4)));
    reset_tap_dance (state);
  }
}

void dance_prn_rprn (qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		SEND_STRING("()"SS_TAP(X_LEFT));
		reset_tap_dance (state);
	}
	else if (state->count == 2) {
		SEND_STRING(")");
		reset_tap_dance (state);
	}
}

void dance_bracket_rbracket (qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		SEND_STRING("[]"SS_TAP(X_LEFT));
		reset_tap_dance (state);
	}
	else if (state->count == 2) {
		SEND_STRING("]");
		reset_tap_dance (state);
	}
}

void dance_cbr_rcbr (qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		SEND_STRING("{}"SS_TAP(X_LEFT));
		reset_tap_dance (state);
	}
	else if (state->count == 2) {
		SEND_STRING("}");
		reset_tap_dance (state);
	}
}

void dance_f_find (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("f");
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING(SS_LCTRL("f"));
    reset_tap_dance (state);
  }
}

void dance_r_replace (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("r");
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING(SS_LCTRL("r"));
    reset_tap_dance (state);
  }
}

void dance_u_undo_redo (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("u");
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING(SS_LCTRL("z"));
    reset_tap_dance (state);
  }
  else if (state->count == 3) {
    SEND_STRING(SS_LCTRL(SS_LSFT("z")));
    reset_tap_dance (state);
  }
}


void dance_c_comment_toggle (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("c");
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING(SS_LCTRL("/"));
    reset_tap_dance (state);
  }
}

void dance_up_run (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING(SS_TAP(X_UP));
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING(SS_RSFT(SS_TAP(X_F10)));
    reset_tap_dance (state);
  }
}

void dance_j_equal (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("j");
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING("=");
    reset_tap_dance (state);
  }
}

void dance_k_underscore (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("k");
    reset_tap_dance (state);
  }
  else if (state->count == 2) {
    SEND_STRING("_");
    reset_tap_dance (state);
  }
}

// void dance_shift_capslock_oneshot (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     SEND_STRING(SS_TAP(X_RSHIFT));
//     reset_tap_dance (state);
//   }
//   else if (state->count == 2) {

//   }
// }


qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_SHIFT_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT, KC_CAPSLOCK),
	[TD_ESCAPE_QUIT] = ACTION_TAP_DANCE_FN(dance_escape_quit),
  	[TD_PRN_RPRN] = ACTION_TAP_DANCE_FN(dance_prn_rprn),
  	[TD_BRACKET_RBRACKET] = ACTION_TAP_DANCE_FN(dance_bracket_rbracket),
  	[TD_CBR_RCBR] = ACTION_TAP_DANCE_FN(dance_cbr_rcbr),
    [TD_F_FIND] = ACTION_TAP_DANCE_FN(dance_f_find),
    [TD_R_REPLACE] = ACTION_TAP_DANCE_FN(dance_r_replace),
    [TD_U_UNDO_REDO] = ACTION_TAP_DANCE_FN(dance_u_undo_redo),
    [TD_C_COMMENT_TOGGLE] = ACTION_TAP_DANCE_FN(dance_c_comment_toggle),
    [TD_UP_RUN] = ACTION_TAP_DANCE_FN(dance_up_run),
    [TD_J_EQUAL] = ACTION_TAP_DANCE_FN(dance_j_equal),
    [TD_K_UNDERSCORE] = ACTION_TAP_DANCE_FN(dance_k_underscore),

  // [TD_SHIFT_CAPSLOCK] = ACTION_TAP_DANCE_FN(dance_shift_capslock_oneshot)
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           SELECT_ALL_COPY,                                        EXIT,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TILD,        KC_Q,           KC_W,           KC_E,           TD(TD_R_REPLACE),           KC_T,           KC_LCBR,                                        TD(TD_PRN_RPRN),        KC_Y,           TD(TD_U_UNDO_REDO),           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_DELETE,      KC_A,           KC_S,           KC_D,           TD(TD_F_FIND),           KC_G,                                                                           KC_H,           TD(TD_J_EQUAL),           TD(TD_K_UNDERSCORE),           KC_L,           KC_SCOLON,      LGUI_T(KC_QUOTE),
    TD(TD_SHIFT_CAPSLOCK),LCTL_T(KC_Z),   KC_X,           TD(TD_C_COMMENT_TOGGLE),           KC_V,           KC_B,           COPY,                                PASTE,         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSHIFT,
    LT(1,KC_GRAVE), KC_LALT,        LALT(KC_LSHIFT),KC_LEFT,        KC_RIGHT,                                                                                                       TD(TD_UP_RUN),          KC_DOWN,        TD(TD_BRACKET_RBRACKET),    TD(TD_CBR_RCBR),    MO(1),
                                                                                                    KC_LALT,MO(2),          TT(2),          TD(TD_ESCAPE_QUIT),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_END,         KC_PGDOWN,      KC_TAB,         KC_ENTER
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        DYN_REC_STOP,                                   KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        DYN_REC_START1,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    RGB_MOD,        RGB_TOG,        KC_TRANSPARENT, RGB_SLD,
                                                                                                                    HSV_86_255_128, KC_TRANSPARENT,
                                                                                    RGB_VAD,        RGB_VAI,        HSV_27_255_255, KC_TRANSPARENT, TOGGLE_LAYER_COLOR,RGB_HUI
  ),
  [2] = LAYOUT_ergodox_pretty(
    RESET, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(TD_PRN_RPRN)

  ),

};


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // #ifdef CONSOLE_ENABLE
  //   uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  //   #endif 
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(86,255,128);
        #endif
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(27,255,255);
        #endif
      }
      return false;
    case PRN:
      if (record->event.pressed) {
        SEND_STRING("()"SS_TAP(X_LEFT));
      }
      break;
    case BRACKET:
      if (record->event.pressed) {
        SEND_STRING("[]"SS_TAP(X_LEFT));
      }
      break;
    case CBR:
      if (record->event.pressed) {
        SEND_STRING("{}"SS_TAP(X_LEFT));
      }    
      break;
       case SELECT_ALL_COPY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("ac"));
      }    
      break;
      case COPY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c"));
      }
      break;
      case PASTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("v"));
      }
      break;
      case EXIT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("d"));
      }
      break;
}
  
  return true;
   }
uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case 1:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(150,245,130);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(39,241,224);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;

};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
    // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
