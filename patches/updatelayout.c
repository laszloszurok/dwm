/* Basically a wrapper around setlayout.
 * This function sets the layout and then 
 * calls a shell script with the chosen layout
 * as the argument, which prints the symbol
 * of the layout onto the status bar (dwmblocks). */
void
updatelayout(const Arg *arg)
{
    setlayout(arg);
    char script[] = "$HOME/source/scripts/status/layout ";
    char layout[200];
    char symbol[100];
    strcpy(symbol, ((Layout*)arg->v)->symbol);

    if (strcmp(symbol, layouts[0].symbol) == 0) 
    {
        strcpy(layout, "tiling");
    } 
    else if (strcmp(symbol, layouts[1].symbol) == 0)
    {
        strcpy(layout, "monocle");
    }
    else if (strcmp(symbol, layouts[2].symbol) == 0)
    {
        strcpy(layout, "grid");
    }
    else if (strcmp(symbol, layouts[3].symbol) == 0)
    {
        strcpy(layout, "floating");
    }
    else /* default: */
    {
        strcpy(layout, "unknown");
    }

    strcat(script, layout);

    system(script);
    system("pkill -RTMIN+14 dwmblocks");
}
