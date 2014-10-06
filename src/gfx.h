/*
 * gfx.h - General graphics and data file functions
 *
 * Copyright (C) 2012-2014  Jon Lund Steffensen <jonlst@gmail.com>
 *
 * This file is part of freeserf.
 *
 * freeserf is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * freeserf is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with freeserf.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GFX_H
#define _GFX_H

#include "SDL.h"

#define MAP_TILE_WIDTH   32
#define MAP_TILE_HEIGHT  20


/* Frame. Keeps track of a specific rectangular area of a surface.
   Multiple frames can refer to the same surface. */
typedef struct {
	SDL_Surface *surf;
	SDL_Rect clip;
} frame_t;

/* Sprite header. In the data file this is immediately followed by sprite data. */
typedef struct {
	int8_t b_x;
	int8_t b_y;
	uint16_t w;
	uint16_t h;
	int16_t x;
	int16_t y;
} sprite_t;


int gfx_init(int width, int height, int fullscreen);
void gfx_deinit();

/* Sprite functions */
void gfx_draw_sprite(int x, int y, uint sprite, frame_t *dest);
void gfx_draw_transp_sprite(int x, int y, uint sprite, int use_off, int y_off, int color_off, frame_t *dest);
void gfx_draw_masked_sprite(int x, int y, uint mask, uint sprite, frame_t *dest);
void gfx_draw_overlay_sprite(int x, int y, uint sprite, int y_off, frame_t *dest);
void gfx_draw_waves_sprite(int x, int y, uint mask, uint sprite, int mask_off, frame_t *dest);

/* Graphics functions */
void gfx_draw_rect(int x, int y, int width, int height, int color, frame_t *dest);
void gfx_fill_rect(int x, int y, int width, int height, int color, frame_t *dest);

/* Text functions */
void gfx_draw_string(int x, int y, int color, int shadow, frame_t *dest, const char *str);
void gfx_draw_number(int x, int y, int color, int shadow, frame_t *dest, int n);

/* Frame functions */
void gfx_frame_init(frame_t *frame, int x, int y, int width, int height, frame_t *dest);
void gfx_frame_deinit(frame_t *frame);
void gfx_draw_frame(int dx, int dy, frame_t *dest, int sx, int sy, frame_t *src, int w, int h);

void gfx_set_palette(int palette);

void gfx_unpack_transparent_sprite(void *dest, const void *src, size_t destlen, int offset);
void gfx_unpack_overlay_sprite(void *dest, const void *src, size_t destlen);
void gfx_unpack_mask_sprite(void *dest, const void *src, size_t destlen);


#endif /* ! _GFX_H */
