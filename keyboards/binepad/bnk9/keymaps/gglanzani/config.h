// Copyright 2023 binepad (@binepad)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Default PIO0 cases flickering in this board.  Setting to PIO1 resolves this issue.
#define WS2812_PIO_USE_PIO1

// Timing for SK6812
#define WS2812_T1H 650
#define RGBLIGHT_LAYERS
#define LED_MIN 1
#define LED_MAX 9
