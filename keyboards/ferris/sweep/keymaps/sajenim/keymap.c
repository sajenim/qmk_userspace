/* Copyright 2022 @ sajenim (https://github.com/sajenim)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "features/casemodes.h"

enum layers {
    CANARY,
    NAV,
    NUM,
    SYM,
    FUN,
};

enum custom_keycodes {
    // Magic Keycodes
    MG_EFORE = SAFE_RANGE,
    MG_ON,
    MG_UST,
    MG_ENT,
    MG_ION,
    MG_MENT,
    MG_ER,
    MG_HICH,
    MG_ES,
    MG_BUT,
    MG_THE,
};

/* Thumb Keys:
 * dual role keys for accessing layers and to offload shift from pinkies */

#define NAV_REP LT(NAV, QK_REP)
#define NUM_MAG LT(NUM, QK_AREP)

/* Home Row Mods:
 * https://precondition.github.io/home-row-mods */

#define HRM_C LSFT_T(KC_C)
#define HRM_R LCTL_T(KC_R)
#define HRM_S LALT_T(KC_S)
#define HRM_T LGUI_T(KC_T)
#define HRM_N RGUI_T(KC_N)
#define HRM_E RALT_T(KC_E)
#define HRM_I RCTL_T(KC_I)
#define HRM_A RSFT_T(KC_A)
#define SYM_D LT(SYM, KC_D)
#define SYM_H LT(SYM, KC_H)

/* One Shot Keys:
 * https://github.com/qmk/qmk_firmware/blob/master/docs/one_shot_keys.md */

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

#include "g/keymap_combo.h" // layer names must be defined before engine include

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // clang-format off
  [CANARY] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                         KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        HRM_C,   HRM_R,   HRM_S,   HRM_T,    KC_G,                         KC_M,   HRM_N,   HRM_E,   HRM_I,   HRM_A,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Q,    KC_J,    KC_V,   SYM_D,    KC_K,                         KC_X,   SYM_H, KC_SLSH, KC_COMM,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          NAV_REP,  KC_SPC,    KC_BSPC, NUM_MAG
                                      //`-----------------'  `-----------------'
  ),

  [NAV] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, KC_VOLD,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [NUM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_LPRN,    KC_7,    KC_8,    KC_9, KC_RPRN,                      XXXXXXX, KC_ASTR, KC_PERC, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_0,    KC_4,    KC_5,    KC_6,  KC_DOT,                      XXXXXXX, OS_RGUI, OS_RALT, OS_RCTL, OS_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LABK,    KC_1,    KC_2,    KC_3, KC_RABK,                      XXXXXXX, KC_PLUS,  KC_EQL, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [SYM] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_GRV, KC_LABK, KC_MINS, KC_RABK, XXXXXXX,                      XXXXXXX, KC_LBRC, KC_UNDS, KC_RBRC, KC_PLUS,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_EXLM, KC_LPRN,  KC_EQL, KC_RPRN, KC_HASH,                      KC_PERC, KC_LCBR,  KC_DLR, KC_RCBR, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_PIPE, KC_AMPR, KC_CIRC,   KC_AT, XXXXXXX,                      XXXXXXX, KC_ASTR, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),

  [FUN] = LAYOUT_split_3x5_2(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_RBT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
  ),
  // clang-format on
};


/* Tri-state Layers:
 * setup FUN layer to activate when NAV & NUM is held */

layer_state_t layer_state_set_user(layer_state_t state) {
    // Activate function layer
    state = update_tri_layer_state(state, NAV, NUM, FUN);
    return state;
}

/* Caseword:
 * configure which keys are "word breaking" */

bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
            return true;
    }
    return false;
}

/* Repeat key:
 * configure additional keys */

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case NAV_REP:
            return false;
        case NUM_MAG:
            return false;
        // Forget Shift on letter keys when Shift or AltGr are the only mods.
        case KC_A ... KC_Z:
            if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            break;
    }
    return true;
}

/* Alternate repeat key:
 * dynamically adjust output based on the most recent previous keycode */

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    // clang-format off
    switch (keycode) {
        // Same Finger Bigrams
        case KC_Y:  return KC_S;     // "YS" sfb (0.123%)
        case HRM_E: return KC_O;     // "EO" sfb (0.121%)
        case HRM_R: return KC_L;     // "RL" sfb (0.114%)
        case KC_U:  return KC_I;     // "UI" sfb (0.073%)
        case KC_O:  return KC_E;     // "OE" sfb (0.060%)
        case KC_P:  return KC_T;     // "PT" sfb (0.050%)
        case HRM_S: return KC_Y;     // "SY" sfb (0.024%)
        case SYM_D: return KC_G;     // "DG" sfb (0.021%)

        // Coding shortcuts
        case KC_PLUS: return KC_EQL;
        case KC_MINS: return KC_EQL;

        // Magic Keycodes
        case KC_B:    return MG_EFORE;
        case HRM_I:   return MG_ON;
        case KC_J:    return MG_UST;
        case KC_M:    return MG_ENT;
        case HRM_N:   return MG_ION;
        case HRM_T:   return MG_MENT;
        case KC_V:    return MG_ER;
        case KC_W:    return MG_HICH;
        case KC_X:    return MG_ES;
        case KC_COMM: return MG_BUT;
        case KC_SPC:  return MG_THE;
    }
    return KC_TRNS;
    // clang-format on
}

/* Custom keycodes:
 * program the behaviour of any keycode */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    // Process our custom keys
    switch (keycode) {
        case NAV_REP:
            if (record->tap.count) {
                process_repeat_key(QK_REP, record);
                return false;
            }
            return true;
        case NUM_MAG:
            if (record->tap.count) {
                process_repeat_key(QK_AREP, record);
                return false;
            }
            return true;
    }

    // clang-format off
    if (record->event.pressed) {
        int rep_count = get_repeat_key_count();
        switch (keycode) {
            // Magic keycodes
            case MG_EFORE: SEND_STRING(/*b*/ "efore"); return false;
            case MG_ON:    SEND_STRING(/*i*/ "on"   ); return false;
            case MG_UST:   SEND_STRING(/*j*/ "ust"  ); return false;
            case MG_ENT:   SEND_STRING(/*m*/ "ent"  ); return false;
            case MG_ION:   SEND_STRING(/*n*/ "ion"  ); return false;
            case MG_MENT:  SEND_STRING(/*t*/ "ment" ); return false;
            case MG_ER:    SEND_STRING(/*v*/ "er"   ); return false;
            case MG_HICH:  SEND_STRING(/*w*/ "hich" ); return false;
            case MG_ES:    SEND_STRING(/*x*/ "es"   ); return false;
            case MG_BUT:   SEND_STRING(/*,*/ " but" ); return false;
            case MG_THE:   SEND_STRING(/* */ "the"  ); return false;
        }
        if (rep_count > 0) {
            switch (keycode) {
                // Repeat Key Overrides
                case HRM_A:   SEND_STRING(/*a*/ "nd"    ); return false; // "and"     trigram (3.293%)
                case HRM_I:   SEND_STRING(/*i*/ "ng"    ); return false; // "ing"     trigram (3.476%)
                case KC_Y:    SEND_STRING(/*y*/ "ou"    ); return false; // "you"     trigram (3.492%)
                case HRM_N:   SEND_STRING(/*n*/ "f"     ); return false; // "nf"      sfb     (0.036%)
                case KC_B:    SEND_STRING(/*b*/ "ecause"); return false; // "because" brief
                case KC_W:    SEND_STRING(/*w*/ "ould"  ); return false; // "would"   brief
                case KC_COMM: SEND_STRING(/*,*/ " and"  ); return false; // ", and"   brief
                case KC_SPC:  SEND_STRING(/* */ "for"   ); return false; // " for"    brief

                //  Miscellaneous
                case KC_GRV: SEND_STRING("\b~/"); return false;
                case KC_DOT:
                    if (rep_count > 1) {
                        SEND_STRING("../");
                        return false;
                    }
                    SEND_STRING("./");
                    return false;
            }
        }
    }
    return true;
    // clang-format on
}

/* Leader Key:
 * hit sequences of keys to trigger custom functionality */

void leader_end_user() {
    if (leader_sequence_one_key(KC_ESC)) {
        layer_clear();

        // shortcuts
    } else if (leader_sequence_one_key(KC_Y)) { // yank
        tap_code16(C(KC_C));
    } else if (leader_sequence_one_key(KC_P)) { // paste
        tap_code16(C(KC_V));
    } else if (leader_sequence_one_key(KC_D)) { // delete
        tap_code16(C(KC_X));
    } else if (leader_sequence_one_key(KC_U)) { // undo
        tap_code16(C(KC_Z));
    } else if (leader_sequence_one_key(KC_W)) { // write
        tap_code16(C(KC_S));

        // casemodes
    } else if (leader_sequence_one_key(KC_C)) { // camelCase
        enable_xcase_with(OSM(MOD_LSFT));
    } else if (leader_sequence_one_key(KC_S)) { // snake_case
        enable_xcase_with(KC_UNDS);
    } else if (leader_sequence_one_key(KC_K)) { // kebab-case
        enable_xcase_with(KC_MINS);
    } else if (leader_sequence_one_key(KC_M)) { // MACRO_CASE
        enable_caps_word();
        enable_xcase_with(KC_UNDS);

        // toggle layers
    } else if (leader_sequence_two_keys(KC_L, KC_E)) { // e for extend as n for num is taken
        layer_on(NAV);
    } else if (leader_sequence_two_keys(KC_L, KC_N)) {
        layer_on(NUM);
    } else if (leader_sequence_two_keys(KC_L, KC_S)) {
        layer_on(SYM);
    } else if (leader_sequence_two_keys(KC_L, KC_F)) {
        layer_on(FUN);
    }
}
