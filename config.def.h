/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  =  3; /* border pixel of windows */
static const int gappx              = 15; /* gaps between windows */
static const unsigned int snap      =  8; /* snap pixel */
static const int user_bh            = 25; /* set to 0 to let dwm calculate the bar height */

static const int showbar            = 1; /* 0 means no bar */
static const int topbar             = 1; /* 0 means bottom bar */
static const int swallowfloating    = 0; /* 1 means swallow floating windows by default */

static const char *fonts[]          = { 
    "DejaVu Sans:size:pixelsize=16:antialias=true:autohint=true",
    "Font Awesome 6 Free Solid:size:pixelsize=12:antialias=true:autohint=true"
};

static const char norm_fg[] = "#e0dbd2";
static const char norm_bg[] = "#191b28";
static const char norm_border[] = "#333";

static const char sel_fg[] = "#e0dbd2";
static const char sel_bg[] = "#563d7c";
static const char sel_border[] = "#663d9c";

static const char hid_fg[] = "#808080";
static const char hid_bg[] = "#191b28";
static const char hid_border[] = "#000";

static const char *colors[][3]      = {
	/*                fg       bg       border   */
	[SchemeNorm] = { norm_fg, norm_bg, norm_border },
	[SchemeSel]  = { sel_fg,  sel_bg,  sel_border},
	[SchemeHid]  = { hid_fg,  hid_bg,  hid_border  },
};

static const char *const autostart[] = {
    "setwallpaper", NULL,
    "setxkbmap", "us", "-option", "caps:escape", NULL,
    "unclutter", "--timeout", "15", "--ignore-scrolling", "--jitter", "35", NULL,
    "clipmenud", NULL,
    "picom", NULL,
    "numlockx", NULL,
    "lxpolkit", NULL,
    "inactivity", NULL,
    "dwmblocks", NULL,
    "wmname", "LG3D", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
    /* class | instance | title | tags mask | switchtotag | isfloating | isterminal | noswallow | monitor */

    /* no specific tag */
    { NULL,          NULL, "Event Tester", 0, 0, 0, 0, 1, -1 },
    { "Yad",         NULL, NULL,           0, 0, 1, 1, 0, -1 },
    { "st-256color", NULL, NULL,           0, 0, 0, 1, 0, -1 },

    /* tag 1 */
    { "firefox",       NULL, NULL,       1, 1, 0, 0, 0, -1 },
    { "qutebrowser",   NULL, NULL,       1, 1, 0, 0, 0, -1 },
    { "Brave-browser", NULL, NULL,       1, 1, 0, 0, 0, -1 },
    { "st-256color",   NULL, "newsboat", 1, 1, 0, 0, 0, -1 },

    /* tag 2 */
    { "com.oracle.javafx.scenebuipp.ScederApp",
                            NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "jetbrains-webstorm", NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "jetbrains-clion",    NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "jetbrains-idea",     NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "jetbrains-idea-ce",  NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "jetbrains-studio",   NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "code-oss",           NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "VSCodium",           NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "Pcmanfm",            NULL, NULL,     1 << 1, 1, 0, 0, 0, -1 },
    { "st-256color",        NULL,"vifm",    1 << 1, 1, 0, 1, 0, -1 },
    { "st-256color",        NULL,"nvim",    1 << 1, 1, 0, 1, 0, -1 },
    { "st-256color",        NULL,"nvr",     1 << 1, 1, 0, 1, 0, -1 },
    { "st-256color",        NULL,"lazygit", 1 << 1, 1, 0, 1, 0, -1 },

    /* tag 3 */
    { "DesktopEditors", NULL, NULL, 1 << 2, 1, 0, 0, 0, -1 },
    { "libreoffice",    NULL, NULL, 1 << 2, 1, 0, 0, 0, -1 },
    { "Soffice",        NULL, NULL, 1 << 2, 1, 0, 0, 0, -1 },
    { "Zathura",        NULL, NULL, 1 << 2, 1, 0, 0, 0, -1 },

    /* tag 4 */
    { "Gimp",     NULL, NULL, 1 << 3, 1, 0, 0, 0, -1 },
    { "Blender",  NULL, NULL, 1 << 3, 1, 0, 0, 0, -1 },
    { "Inkscape", NULL, NULL, 1 << 3, 1, 0, 0, 0, -1 },
    { "draw.io",  NULL, NULL, 1 << 3, 1, 0, 0, 0, -1 },
    
    /* tag 5 */
    { NULL,          NULL, "Spotify", 1 << 4, 1, 0, 0, 0, -1 },
    { "st-256color", NULL, "ncspot",  1 << 4, 1, 0, 1, 0, -1 },

    /* tag 6 */
    { "Skype",       NULL, NULL,      1 << 5, 1, 0, 0, 0, -1 },
    { "zoom",        NULL, NULL,      1 << 5, 1, 0, 0, 0, -1 },
    { "discord",     NULL, NULL,      1 << 5, 1, 0, 0, 0, -1 },
    { "Signal",      NULL, NULL,      1 << 5, 1, 0, 0, 0, -1 },
    { "Element",     NULL, NULL,      1 << 5, 1, 0, 0, 0, -1 },
    { "st-256color", NULL, "aerc",    1 << 5, 1, 0, 0, 0, -1 },
    { "st-256color", NULL, "weechat", 1 << 5, 1, 0, 0, 0, -1 },

    /* tag 7 */
    { "Virt-manager",       NULL, NULL, 1 << 6, 1, 0, 0, 0, -1 },
    { "VirtualBox Manager", NULL, NULL, 1 << 6, 1, 0, 0, 0, -1 },
    { "Genymotion",         NULL, NULL, 1 << 6, 1, 0, 0, 0, -1 },

    /* tag 8 */
    { "st-256color", NULL, "bluetoothctl", 1 << 7, 1, 0, 0,  0, -1 },
    { "st-256color", NULL, "iwctl",        1 << 7, 1, 0, 0,  0, -1 },
    { "st-256color", NULL, "pulsemixer",   1 << 7, 1, 0, 0,  0, -1 },
    { "st-256color", NULL, "pavucontrol",  1 << 7, 1, 0, 0,  0, -1 },
    { "st-256color", NULL, "btm",          1 << 7, 1, 0, 0,  0, -1 },

    /* tag 9 */
    { "KeePassXC",   NULL, NULL, 1 << 8, 1, 0, 0, 0, -1 },
    { "qBittorrent", NULL, NULL, 1 << 8, 1, 0, 0, 0, -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      monocle },
	{ "",      NULL },    /* no layout function means floating behavior */
    { NULL,     NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static const char *dmenu[]        = { "dmenu_hist", NULL };
static const char *dmenu_sudo[]   = { "dmenu_hist", "sudo", NULL };
static const char *powermenu[]    = { "powermenu", NULL };
static const char *clipmenu[]     = { "clipmenu_wrapper", NULL };
static const char *bookmarkmenu[] = { "bookmarkmenu", NULL };
static const char *repolist[]     = { "repolist", NULL };
static const char *blockmenu[]    = { "blockmenu", NULL };
static const char *passmenu[]     = { "keepmenu-sh", NULL };
static const char *togglekb[]     = { "togglekb", NULL };

static const char *term[]     = { "st", NULL };
static const char *vifmrun[]  = { "st", "vifmrun", NULL };
static const char *newsboat[] = { "st", "newsboat", NULL };
static const char *aerc[]     = { "st", "aerc", NULL };
static const char *lazygit[]  = { "st", "-t", "lazygit", "lg", NULL };
static const char *calcurse[] = { "st", "calcurse", NULL };
static const char *mailsync[] = { "mailsync", NULL };
static const char *iwctl[]    = { "st", "iwctl", NULL };

static const char *volup[]   = { "dwm-volup", NULL };
static const char *voldown[] = { "dwm-voldown", NULL };
static const char *volmute[] = { "dwm-volmute", NULL };
static const char *micmute[] = { "dwm-micmute", NULL };

static const char *audioplay[] = { "playerctl", "play-pause", NULL };
static const char *audionext[] = { "playerctl", "next", NULL };
static const char *audioprev[] = { "playerctl", "previous", NULL };

static const char *brightup[]   = { "brightness_notify", "inc", NULL };
static const char *brightdown[] = { "brightness_notify", "dec", NULL };

static const char *printscr[] = { "flameshot", "gui", NULL };


static Key keys[] = {
	/* modifier, key, function, argument */
	{ MODKEY, XK_Return, spawn, { .v = term } },
    { MODKEY, XK_v,      spawn, { .v = vifmrun } },
    { MODKEY, XK_n,      spawn, { .v = newsboat } },
    { MODKEY, XK_m,      spawn, { .v = aerc } },
    { MODKEY, XK_g,      spawn, { .v = lazygit } },
    { MODKEY, XK_c,      spawn, { .v = calcurse } },
    { MODKEY, XK_s,      spawn, { .v = mailsync } },
    { MODKEY, XK_w,      spawn, { .v = iwctl } },

	{ MODKEY,           XK_r,     spawn, {.v = dmenu} },
	{ MODKEY|ShiftMask, XK_r,     spawn, {.v = dmenu_sudo} },
	{ MODKEY,           XK_p,     spawn, {.v = powermenu} },
	{ MODKEY|ShiftMask, XK_c,     spawn, {.v = clipmenu} },
	{ MODKEY|ShiftMask, XK_b,     spawn, {.v = bookmarkmenu} },
	{ MODKEY,           XK_b,     spawn, {.v = blockmenu} },
	{ MODKEY|ShiftMask, XK_g,     spawn, {.v = repolist} },
	{ MODKEY|ShiftMask, XK_p,     spawn, {.v = passmenu} },
	{ MODKEY,           XK_space, spawn, {.v = togglekb} },

	{ MODKEY, XK_t, togglebar, {0} },

	{ MODKEY,             XK_j, focusstackvis, {.i = +1 } },
	{ MODKEY,             XK_k, focusstackvis, {.i = -1 } },
	{ MODKEY|ControlMask, XK_j, focusstackhid, {.i = +1 } },
	{ MODKEY|ControlMask, XK_k, focusstackhid, {.i = -1 } },

	{ MODKEY|ShiftMask, XK_i, incnmaster, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_d, incnmaster, {.i = -1 } },

	{ MODKEY, XK_Left,  setmfact, {.f = -0.05} },
	{ MODKEY, XK_Right, setmfact, {.f = +0.05} },

	{ MODKEY|ShiftMask, XK_Return, zoom,       {0} },
	{ MODKEY,           XK_q,      killclient, {0} },

	{ MODKEY|ShiftMask, XK_t,     setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask, XK_m,     setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask, XK_f,     setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask, XK_space, togglefloating, {0} },

    { MODKEY|ShiftMask, XK_k, shiftview, {.i = +1} },
    { MODKEY|ShiftMask, XK_j, shiftview, {.i = -1} },    

	{ MODKEY,           XK_Tab,    view,     {0} },
	{ MODKEY,           XK_0,      view,     {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0,      tag,      {.ui = ~0 } },
	{ MODKEY,           XK_comma,  focusmon, {.i = -1 } },
	{ MODKEY,           XK_period, focusmon, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_comma,  tagmon,   {.i = -1 } },
	{ MODKEY|ShiftMask, XK_period, tagmon,   {.i = +1 } },

    { MODKEY|ShiftMask, XK_s, show, {0} },
	{ MODKEY|ShiftMask, XK_h, hide, {0} },

	{ MODKEY,           XK_minus, setgaps, {.i = -5 } },
	{ MODKEY,           XK_equal, setgaps, {.i = +5 } },
	{ MODKEY|ShiftMask, XK_equal, setgaps, {.i = 0  } },

	{ MODKEY|ControlMask, XK_q, quit, {0} },
	{ MODKEY|ControlMask, XK_r, quit, {1} }, 

    { 0, XF86XK_AudioPlay, spawn, { .v = audioplay } },
    { 0, XF86XK_AudioPrev, spawn, { .v = audioprev } },
    { 0, XF86XK_AudioNext, spawn, { .v = audionext } },

    { 0, XF86XK_AudioRaiseVolume, spawn, { .v = volup } },
    { 0, XF86XK_AudioLowerVolume, spawn, { .v = voldown } },
    { 0, XF86XK_AudioMute,        spawn, { .v = volmute } },
    { 0, XF86XK_AudioMicMute,     spawn, { .v = micmute } },

    { 0, XF86XK_MonBrightnessUp,   spawn, { .v = brightup } },
    { 0, XF86XK_MonBrightnessDown, spawn, { .v = brightdown } },

    { 0, XK_Print, spawn, { .v = printscr } },

	TAGKEYS( XK_1, 0 )
	TAGKEYS( XK_2, 1 )
	TAGKEYS( XK_3, 2 )
	TAGKEYS( XK_4, 3 )
	TAGKEYS( XK_5, 4 )
	TAGKEYS( XK_6, 5 )
	TAGKEYS( XK_7, 6 )
	TAGKEYS( XK_8, 7 )
	TAGKEYS( XK_9, 8 )
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = +1} },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1} },
    { ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

