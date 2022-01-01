/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>
#include "colors.h"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 15;       /* gap pixel between windows */
static const unsigned int snap      = 8;       /* snap pixel */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 7;        /* vertical padding for statusbar */
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;

static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]          = { 
    "DejaVu Sans:size:pixelsize=16:antialias=true:autohint=true",
    "Font Awesome 5 Free Solid:size:pixelsize=13:antialias=true:autohint=true"
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeHid] = { OPAQUE, baralpha, borderalpha },
	[SchemeNotSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeSeparator]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
/* static const char *tags[] = { "", "", "", "", "", "",  "", "", "" }; */
static const char *tags[] = { "1", "2", "3", "4", "5", "6",  "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */

    /* class | instance | title | tags mask | switchtotag | isfloating | isterminal | noswallow | monitor */

    /* no specific tag */
    { NULL,                 NULL, "Event Tester", 0, 0, 0, 0,  1, -1 },
    { "Yad",                NULL, NULL,           0, 0, 1, 1,  0, -1 },
    { "st-256color",        NULL, NULL,           0, 0, 0, 1,  0, -1 },

    /* tag 1 */
    { "firefox",            NULL, NULL,           1, 1, 0, 0, 0, -1 },
    { "qutebrowser",        NULL, NULL,           1, 1, 0, 0, 0, -1 },
    { "Brave-browser",      NULL, NULL,           1, 1, 0, 0, 0, -1 },
    { "st-256color",        NULL, "newsboat",     1, 1, 0, 0, 0, -1 },

    /* tag 2 */
    { "com.oracle.javafx.scenebuipp.ScederApp",
                            NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "jetbrains-webstorm", NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "jetbrains-clion",    NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "jetbrains-idea",     NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "jetbrains-idea-ce",  NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "jetbrains-studio",   NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "code-oss",           NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "VSCodium",           NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "Pcmanfm",            NULL, NULL,      1 << 1, 1, 0, 0,  0, -1 },
    { "st-256color",        NULL,"vifm",     1 << 1, 1, 0, 1,  0, -1 },
    { "st-256color",        NULL,"nvim",     1 << 1, 1, 0, 1,  0, -1 },
    { "st-256color",        NULL,"nvr",      1 << 1, 1, 0, 1,  0, -1 },
    { "st-256color",        NULL,"lazygit",  1 << 1, 1, 0, 1,  0, -1 },

    /* tag 3 */
    { "DesktopEditors",     NULL, NULL,      1 << 2, 1, 0, 0,  0, -1 },
    { "libreoffice",        NULL, NULL,      1 << 2, 1, 0, 0,  0, -1 },
    { "Soffice",            NULL, NULL,      1 << 2, 1, 0, 0,  0, -1 },
    { "Zathura",            NULL, NULL,      1 << 2, 1, 0, 0,  0, -1 },

    /* tag 4 */
    { "Gimp",               NULL, NULL,      1 << 3, 1, 0, 0,  0, -1 },
    { "Blender",            NULL, NULL,      1 << 3, 1, 0, 0,  0, -1 },
    { "Inkscape",           NULL, NULL,      1 << 3, 1, 0, 0,  0, -1 },
    { "draw.io",            NULL, NULL,      1 << 3, 1, 0, 0,  0, -1 },
    
    /* tag 5 */
    { "Spotify",            NULL, NULL,      1 << 4, 1, 0, 0,  0, -1 },
    { "st-256color",        NULL, "ncspot",  1 << 4, 1, 0, 1,  0, -1 },

    /* tag 6 */
    { "Skype",              NULL, NULL,      1 << 5, 1, 0, 0,  0, -1 },
    { "zoom",               NULL, NULL,      1 << 5, 1, 0, 0,  0, -1 },
    { "discord",            NULL, NULL,      1 << 5, 1, 0, 0,  0, -1 },
    { "Signal",             NULL, NULL,      1 << 5, 1, 0, 0,  0, -1 },
    { "Element",            NULL, NULL,      1 << 5, 1, 0, 0,  0, -1 },
    { "st-256color",        NULL, "aerc",    1 << 5, 1, 0, 0,  0, -1 },
    { "st-256color",        NULL, "weechat", 1 << 5, 1, 0, 0,  0, -1 },

    /* tag 7 */
    { "Virt-manager",       NULL, NULL,      1 << 6, 1, 0, 0,  0, -1 },
    { "VirtualBox Manager", NULL, NULL,      1 << 6, 1, 0, 0,  0, -1 },
    { "Genymotion",         NULL, NULL,      1 << 6, 1, 0, 0,  0, -1 },

    /* tag 8 */
    { "qBittorrent",        NULL, NULL,      1 << 7, 1, 0, 0,  0, -1 },

    /* tag 9 */
    { "st-256color",        NULL, "kmon",    1 << 8, 1, 0, 0,  0, -1 },
    { "st-256color",        NULL, "btm",     1 << 8, 1, 0, 0,  0, -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "",      tile },
    { "",      monocle },
    { "",      gaplessgrid },
    { "",      NULL },
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* make sure these are in $PATH */
static const char *dmenucmd[] = { "dmenu_hist", NULL }; // dmenu script which remembers history
static const char *dmenu_sudo_cmd[] = { "dmenu_hist", "sudo", NULL }; // running programs with sudo
static const char *passmenucmd[] = { "keepmenu-sh", NULL }; // passmenu script which remembers history
static const char *confmenucmd[] = { "confmenu", NULL }; // script that pipes the contents of the ~/.config dir into dmenu and opens the picked entry in $EDITOR
static const char *powermenucmd[] = { "powermenu", NULL }; // options to reboot, shutdown, suspend, etc 
static const char *clipmenucmd[] = { "clipmenu_wrapper", NULL }; // clipboard history
static const char *bookmarkmenucmd[] = { "bookmarkmenu", NULL }; // saved urls
static const char *repolist[] = { "repolist", NULL }; // open a git repository in ~/source/ in lazygit
static const char *wifi[] = { "networkmanager_dmenu", "-l", "20", "-lh", "26", "-c", "-i", NULL }; // manage wifi networks
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
    { MODKEY|ControlMask,           XK_d,      spawn,          {.v = dmenu_sudo_cmd } },
    { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = passmenucmd } },
    { MODKEY,                       XK_p,      spawn,          {.v = powermenucmd } },
    { MODKEY,                       XK_w,      spawn,          {.v = wifi } },
    { MODKEY|ShiftMask,             XK_e,      spawn,          {.v = confmenucmd } },
    { MODKEY|ShiftMask,             XK_c,      spawn,          {.v = clipmenucmd } },
    { MODKEY|ShiftMask,             XK_b,      spawn,          {.v = bookmarkmenucmd } },
    { MODKEY|ShiftMask,             XK_g,      spawn,          {.v = repolist } },

    { MODKEY,                       XK_t,      togglebar,      {0} },

    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },

    { MODKEY,                       XK_q,      killclient,     {0} },

	{ Mod1Mask,                     XK_t,      setlayout,      {.v = &layouts[0]} },
	{ Mod1Mask,                     XK_m,      setlayout,      {.v = &layouts[1]} },
	{ Mod1Mask,                     XK_g,      setlayout,      {.v = &layouts[2]} },
	{ Mod1Mask,                     XK_f,      setlayout,      {.v = &layouts[3]} },
    { Mod1Mask,                     XK_space,  setlayout,      {0} }, /* toggle between this and the last used layout */
    { Mod1Mask|ShiftMask,           XK_space,  togglefloating, {0} }, /* toggle floating for the active window */

    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },

    { MODKEY|ControlMask,           XK_j,      movestack,      {.i = +1} },
    { MODKEY|ControlMask,           XK_k,      movestack,      {.i = -1} },

    { MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },

    { MODKEY|ShiftMask,             XK_k,      shiftview,      {.i = +1} },
    { MODKEY|ShiftMask,             XK_j,      shiftview,      {.i = -1} },

    { MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },

    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

    { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },

    { Mod1Mask|ShiftMask,           XK_r,      quit,           {1} }, // restarting dwm in place
    { Mod1Mask|ShiftMask,           XK_q,      quit,           {0} }, // kill the x server

    { 0, XF86XK_AudioPrev,         spawn, SHCMD("playerctl previous") },
    { 0, XF86XK_AudioPlay,         spawn, SHCMD("playerctl play-pause") },
    { 0, XF86XK_AudioNext,         spawn, SHCMD("playerctl next") },

    /* Use 'pactl list sinks' to get sink names */
    { 0, XF86XK_AudioRaiseVolume,  spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioLowerVolume,  spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioMute,         spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioMicMute,      spawn, SHCMD("pactl set-source-mute 1 toggle; pkill -RTMIN+12 dwmblocks") },

    { 0, XF86XK_MonBrightnessUp,   spawn, SHCMD("brightness_notify inc") },
    { 0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightness_notify dec") },

    { 0, XK_Print,                 spawn, SHCMD("flameshot gui") },

    { MODKEY,  XK_b,     spawn, SHCMD("$BROWSER") },
    { MODKEY,  XK_v,     spawn, SHCMD("$TERMINAL vifmrun") },
    { MODKEY,  XK_n,     spawn, SHCMD("$TERMINAL newsboat") },
    { MODKEY,  XK_m,     spawn, SHCMD("$TERMINAL aerc") },
    { MODKEY,  XK_s,     spawn, SHCMD("dunstify \"Running mailsync...\"; mailsync") },
    { MODKEY,  XK_e,     spawn, SHCMD("$TERMINAL $EDITOR") },
    { MODKEY,  XK_g,     spawn, SHCMD("$TERMINAL lazygit --git-dir=$HOME/.cfg --work-tree=$HOME") },
    { MODKEY,  XK_c,     spawn, SHCMD("st -f 'mono:pixelsize=20:antialias=true:autohint=true' -e calcurse") },
    { MODKEY,  XK_o,     spawn, SHCMD("togglecompositor") },
    { MODKEY,  XK_space, spawn, SHCMD("togglekb; pkill -RTMIN+14 dwmblocks") },

    { Mod1Mask,           XK_c, spawn, SHCMD("dunstctl close") },
    { Mod1Mask|ShiftMask, XK_c, spawn, SHCMD("dunstctl close-all") },
    { Mod1Mask,           XK_h, spawn, SHCMD("dunstctl history-pop") },

    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

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
/* click can be ClkTagBar, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = +1} },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1} },
    { ClkWinTitle,          0,              Button1,        togglewin,      {0} },
    { ClkWinTitle,          0,              Button2,        killclient,     {0} },
    { ClkWinTitle,          0,              Button3,        toggleshowhide, {0} },
    { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

