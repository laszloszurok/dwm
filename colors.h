static const char norm_fg[] = "#e0dbd2";
static const char norm_bg[] = "#191b28";
static const char norm_border[] = "#333";

static const char sel_fg[] = "#e0dbd2";
static const char sel_bg[] = "#563d7c";
static const char sel_border[] = "#663d9c";

static const char not_sel_fg[] = "#e0dbd2";
static const char not_sel_bg[]  = "#3e4050";
static const char not_sel_border[] = "#3c3933";

static const char hid_fg[] = "#e0dbd2";
static const char hid_bg[] = "#191b28";
static const char hid_border[] = "#000";

static const char *colors[][3]      = {
    /*                 fg          bg          border                         */
    [SchemeNorm]   = { norm_fg,    norm_bg,    norm_border }, 
    [SchemeSel]    = { sel_fg,     sel_bg,     sel_border },  // the focused win
	[SchemeHid]    = { hid_fg,     hid_bg,     hid_border },
    [SchemeNotSel] = { not_sel_fg, not_sel_bg, not_sel_border }  // unfocused wins
};
