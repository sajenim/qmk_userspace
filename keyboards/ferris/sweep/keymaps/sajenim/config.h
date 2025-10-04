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

#pragma once

// By default, the firmware does not know which side is which.
#define MASTER_LEFT

// Tap-Hold configuration for home row mods.
#define TAPPING_TERM 175
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define QUICK_TAP_TERM 0

// Timeouts
#define ONESHOT_TIMEOUT 5000

// Combo keys are always checked from layer 0.
#define COMBO_ONLY_FROM_LAYER 0
