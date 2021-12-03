/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:01:32 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 14:11:24 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# define TILE_SIZE 64

# define EEND -1

typedef enum e_status
{
	PLAY,
	WIN,
	LOSE,
	SHUTDOWN
}	t_status;

typedef enum e_keycode
{
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
	KEY_SPACE = 49,
	KEY_ENTER = 36,
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 50,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_0 = 29,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,
	KEY_MINUS = 27,
	KEY_EQUAL = 24,
	KEY_BACKSPACE = 51,
	KEY_TAB = 48,
	KEY_LEFT_BRACKET = 33,
	KEY_RIGHT_BRACKET = 30,
	KEY_BACKSLASH = 42,
	KEY_SEMICOLON = 41,
	KEY_APOSTROPHE = 39,
	KEY_GRAVE = 43,
	KEY_COMMA = 54,
	KEY_PERIOD = 55,
	KEY_SLASH = 56,
	KEY_CAPS_LOCK = 57,
}	t_keycode;

typedef enum e_mousecode
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
}	t_mousecode;

typedef enum e_x11events
{
	KeyPress = 2,
	KeyRelease,
	ButtonPress,
	ButtonRelease,
	MotionNotify,
	EnterNotify,
	LeaveNotify,
	FocusIn,
	FocusOut,
	KeymapNotify,
	Expose,
	GraphicsExpose,
	NoExpose,
	VisibilityNotify,
	CreateNotify,
	DestroyNotify,
	UnmapNotify,
	MapNotify,
	MapRequest,
	ReparentNotify,
	ConfigureNotify,
	ConfigureRequest,
	GravityNotify,
	ResizeRequest,
	CirculateNotify,
	CirculateRequest,
	PropertyNotify,
	SelectionClear,
	SelectionRequest,
	SelectionNotify,
	ColormapNotify,
	ClientMessage,
	MappingNotify,
	GenericEvent,
	LASTEvent,
}	t_x11events;

typedef enum e_x11masks
{
	NoEventMask = 0L,
	KeyPressMask = (1L<<0),
	KeyReleaseMask = (1L<<1),
	ButtonPressMask = (1L<<2),
	ButtonReleaseMask = (1L<<3),
	EnterWindowMask = (1L<<4),
	LeaveWindowMask = (1L<<5),
	PointerMotionMask = (1L<<6),
	PointerMotionHintMask = (1L<<7),
	Button1MotionMask = (1L<<8),
	Button2MotionMask = (1L<<9),
	Button3MotionMask = (1L<<10),
	Button4MotionMask = (1L<<11),
	Button5MotionMask = (1L<<12),
	ButtonMotionMask = (1L<<13),
	KeymapStateMask = (1L<<14),
	ExposureMask = (1L<<15),
	VisibilityChangeMask = (1L<<16),
	StructureNotifyMask = (1L<<17),
	ResizeRedirectMask = (1L<<18),
	SubstructureNotifyMask = (1L<<19),
	SubstructureRedirectMask = (1L<<20),
	FocusChangeMask = (1L<<21),
	PropertyChangeMask = (1L<<22),
	ColormapChangeMask = (1L<<23),
	OwnerGrabButtonMask = (1L<<24)
}	t_x11masks;

#endif